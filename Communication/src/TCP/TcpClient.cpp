/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: TcpClient.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/06 10:04:07
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "TCP\TcpClient.h"
#include "SocketNode.h"

enum
{
	E_TCP_SEND_BUFFER_SIZE = 1024 * 1024,
	E_TCP_RECV_BUFFER_SIZE = 1024 * 1024
};

CTcpClient::CTcpClient()
	: m_bConnected(false)
	, m_hSocket(INVALID_SOCKET)
{
	m_pRecvBuffer = new char[E_TCP_RECV_BUFFER_SIZE];
}


CTcpClient::~CTcpClient()
{
	DisConnect();
	if(nullptr != m_pRecvBuffer)
	{
		delete m_pRecvBuffer;
		m_pRecvBuffer = nullptr;
	}
}

bool CTcpClient::ConnectServer(const std::string& strServerIp, unsigned short usPort)
{
	SOCKADDR_IN addrSer;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(usPort);
	addrSer.sin_addr.S_un.S_addr = inet_addr(strServerIp.c_str());

	m_hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_hSocket == INVALID_SOCKET)
	{
		return false;
	}
	
	if (!SetSendRecvBufferSize(E_TCP_SEND_BUFFER_SIZE, E_TCP_RECV_BUFFER_SIZE))
	{
		return false;
	}

	if(SOCKET_ERROR == connect(m_hSocket, (sockaddr*)&addrSer, sizeof(addrSer)))
	{
		return false;
	}
	m_strIp = strServerIp;
	m_usPort = usPort;

	m_bConnected = true;
	Active();
	return true;
}

bool CTcpClient::DisConnect()
{
	if (m_hSocket != INVALID_SOCKET)
	{
		shutdown(m_hSocket, 1);
		closesocket(m_hSocket);
		if (IsRunning())
		{
			//  关闭后退出线程
			Quit();
			// 等待线程真正退出
			Wait();
		}

		m_hSocket = INVALID_SOCKET;
	}
	m_bConnected = false;
	return true;
}

bool CTcpClient::IsConnectServer()
{
	return m_bConnected;
}

bool CTcpClient::SetSendRecvBufferSize(int nSendSize, int nRecvSize)
{
	if (setsockopt(m_hSocket, SOL_SOCKET, SO_RCVBUF, (char*)&nSendSize, sizeof(int)) != 0)
	{
		return false;
	}
	if (setsockopt(m_hSocket, SOL_SOCKET, SO_RCVBUF, (char*)&nSendSize, sizeof(int)) != 0)
	{
		return false;
	}
	return true;
}

bool CTcpClient::SendData2Server(const char * szBuf, unsigned int nBufLen)
{
	if(!m_bConnected)
	{
		return false;
	}
	int nSurSize = nBufLen;
	int nAlready = 0;
	while (nSurSize > 0)
	{
		int nSize = send(m_hSocket, szBuf + nAlready, nSurSize, 0);
		if (nSize < 0)
		{
			return false;
		}
		nSurSize -= nSize;
		nAlready += nSize;
	}
	return true;
}

void CTcpClient::run()
{
	while (!IsQuit())
	{
		memset(m_pRecvBuffer, 0, E_TCP_RECV_BUFFER_SIZE);

		int nBufLen = recv(m_hSocket, m_pRecvBuffer, E_TCP_RECV_BUFFER_SIZE, 0);
		if (nBufLen < 0)
		{
			Quit();
			continue;
		}
		CSocketNode node;
		node.SetSrcAddr(m_strIp, m_usPort);
		node.SetData((unsigned char*)m_pRecvBuffer, nBufLen);
	}
}