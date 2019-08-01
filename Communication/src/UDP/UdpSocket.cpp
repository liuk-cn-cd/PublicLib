/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: UdpSocket.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/06 10:06:29
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "UdpSocket.h"
#include <string.h>
#include "UdpSocketPrivate.h"
#include "IUdpUser.h"

CUdpSocket::CUdpSocket()
{
    _data_ = new CUdpSocketPrivate;
    _data_->m_pRecvTask->Attach(this);
    _data_->m_pProcessTask->Attach(this);
}


CUdpSocket::~CUdpSocket()
{
    _data_->m_pRecvTask->Attach(nullptr);
    _data_->m_pProcessTask->Attach(nullptr);
    if(nullptr != _data_)
    {
        delete _data_;
        _data_ = nullptr;
    }
}

void CUdpSocket::AttachUser(IUdpUser *pUser)
{
    _data_->m_pUdpUser = pUser;
}

bool CUdpSocket::InitSocket(const std::string &strLocalIp, uint16 uLocalPort, const std::string &strRemoteIp, uint16 uRemotePort)
{
    _data_->m_hSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (_data_->m_hSocket == INVALID_SOCKET)
    {
        return false;
    }

    // 设置调用close(socket)后,仍可继续重用该socket。
    // 调用close(socket)一般不会立即关闭socket，而经历TIME_WAIT的过程。
    // 使用SO_REUSEADDR可使端口被重用。
    int nVal = 1;
    if (setsockopt(_data_->m_hSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&nVal, sizeof(int)) != 0)
    {
        return false;
    }
    //填充服务器端套接字结构
    SOCKADDR_IN addrLocal;

    //将主机字节顺序转换为TCP/IP网络字节顺序
    addrLocal.sin_family = AF_INET;
    addrLocal.sin_port = htons(uLocalPort);
    #ifdef WIN32
    if (strLocalIp.empty())
    {
        addrLocal.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    }
    else
    {
        addrLocal.sin_addr.S_un.S_addr = inet_addr(strLocalIp.c_str());
    }
    #elif linux
    if (strLocalIp.empty())
    {
        addrLocal.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    else
    {
        addrLocal.sin_addr.s_addr = inet_addr(strLocalIp.c_str());
    }
    #endif

    //将套接字绑定到一个本地地址和端口上
    if (bind(_data_->m_hSocket, (SOCKADDR*)&addrLocal, sizeof(SOCKADDR)) == SOCKET_ERROR)
    {
        return false;
    }

    _data_->m_strDefaultDestIp = strRemoteIp;
    _data_->m_uDefaultPort = uRemotePort;
    return true;
}

bool CUdpSocket::SendDataTo(const std::string &strDestIp, uint16 uDestPort, byte *arrData, uint16 uDataSize)
{
    //填充服务器端套接字结构
    SOCKADDR_IN addrDest;

    //将主机字节顺序转换为TCP/IP网络字节顺序
    addrDest.sin_family = AF_INET;
    addrDest.sin_port = htons(uDestPort);
#ifdef WIN32
    if (strDestIp.empty())
    {
		addrDest.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    }
    else
    {
		addrDest.sin_addr.S_un.S_addr = inet_addr(strDestIp.c_str());
    }
	return (sendto(_data_->m_hSocket, (const char*)arrData, uDataSize, 0, (SOCKADDR*)&addrDest, sizeof(addrDest)) >= 0);
#elif linux
    if (strDestIp.empty())
    {
        addrDest.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    else
    {
        addrDest.sin_addr.s_addr = inet_addr(strDestIp.c_str());
    }
	return (sendto(_data_->m_hSocket, arrData, uDataSize, 0, (SOCKADDR*)&addrDest, sizeof(addrDest)) >= 0);
#endif
    
}

bool CUdpSocket::SendData(byte *arrData, uint16 uDataSize)
{
    return SendDataTo(_data_->m_strDefaultDestIp, _data_->m_uDefaultPort, arrData, uDataSize);
}

void CUdpSocket::OnRunTask(CTask *pTask)
{
    if(pTask == _data_->m_pRecvTask)
    {
        while (!pTask->IsQuit())
        {
            memset(_data_->m_pRecvBuffer, 0, 65536);

            SOCKADDR_IN addrSrc;
            socklen_t nLen = sizeof(addrSrc);
#ifdef WIN32
            long nBufLen = recvfrom(_data_->m_hSocket, (char*)_data_->m_pRecvBuffer, 65536, 0, (SOCKADDR*)&addrSrc,&nLen);
			if (nBufLen == SOCKET_ERROR)
			{
				pTask->Quit();
				continue;
			}
#elif linux
			long nBufLen = recvfrom(_data_->m_hSocket, _data_->m_pRecvBuffer, 65536, 0, (SOCKADDR*)&addrSrc, &nLen);
			if (nBufLen < 0)
			{
				pTask->Quit();
				continue;
			}
#endif

            if(nBufLen == 0)
            {
                continue;
            }

            CSocketNode node;
            node.SetSrcAddr(inet_ntoa(addrSrc.sin_addr), ntohs(addrSrc.sin_port));
            node.SetData(_data_->m_pRecvBuffer, nBufLen);
            _data_->m_queueRecvNode.Enqueue(node);
        }
    }
    else if (pTask == _data_->m_pProcessTask)
    {
        while (!pTask->IsQuit())
        {
            bool bGet = false;
            CSocketNode node = _data_->m_queueRecvNode.Dequeue(&bGet, 200);
            if(!bGet)
            {
                continue;
            }
            if(nullptr != _data_->m_pUdpUser)
            {
                _data_->m_pUdpUser->OnDataProcess(node);
            }
        }
    }
}
