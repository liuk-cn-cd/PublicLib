/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: TcpServer.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/06 10:01:56
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "TcpServer.h"
#include <string.h>
#include <set>
enum
{
	E_TCP_SEND_BUFFER_SIZE = 1024 * 1024,
	E_TCP_RECV_BUFFER_SIZE = 1024 * 1024
};

CTcpServer::CTcpServer()
	: m_hSocket(INVALID_SOCKET)
	, m_strError("")
	, m_usPort(0)
	, m_pUser(nullptr)
	, m_bIsService(false)
{
	m_pRecvBuffer = new char[E_TCP_RECV_BUFFER_SIZE];
	m_nRecvBufferLen = 0;
}


CTcpServer::~CTcpServer()
{
	if(IsService())
	{
		CloseService();
	}

	if(nullptr != m_pRecvBuffer)
	{
		delete [] m_pRecvBuffer;
		m_pRecvBuffer = nullptr;
	}
}

bool CTcpServer::InitServer(std::string strServerIp, unsigned short usPort)
{
	m_usPort = usPort;
#ifdef WIN32 //这段全局只调用一次，不应该写在此处
	unsigned short usVersion;
	WSADATA wsaData;

	usVersion = MAKEWORD(2, 2);
	if (WSAStartup(usVersion, &wsaData) != 0)
	{
		char szError[256];
		memset(szError, 0, 256);
		sprintf(szError, "WSAStartup() called failed!, error code is: %d", WSAGetLastError());
		m_strError = szError;
		return false;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		//若不是所请求的版本号2.2,则终止WinSock库的使用  
		WSACleanup();
		m_strError = "Version failed, version isn't 2.2!";
		return false;
	}
#endif
	GUARD(CThreadMutex, m_mutextSocket)
	m_hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_hSocket == INVALID_SOCKET)
	{
		char szError[256];
		memset(szError, 0, 256);
#ifdef WIN32
		sprintf(szError, "socket() called failed!, error code is: %d", WSAGetLastError());
#endif // WIN32
		m_strError = szError;
		return false;
	}
	// 设置调用close(socket)后,仍可继续重用该socket。
	// 调用close(socket)一般不会立即关闭socket，而经历TIME_WAIT的过程。
	// 使用SO_REUSEADDR可使端口被重用。
	int nVal = 1;
	if (setsockopt(m_hSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&nVal, sizeof(int)) != 0)
	{
		return false;
	}
	if(!SetSendRecvBufferSize(E_TCP_SEND_BUFFER_SIZE, E_TCP_RECV_BUFFER_SIZE))
	{
		return false;
	}

		//填充服务器端套接字结构  
    SOCKADDR_IN addrServer;

	//将主机字节顺序转换为TCP/IP网络字节顺序  
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(m_usPort);
#ifdef WIN32
	if (strServerIp.empty())
	{
		addrServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	}
	else
	{
		addrServer.sin_addr.S_un.S_addr = inet_addr(strServerIp.c_str());
	}
#elif linux
    if (strServerIp.empty())
    {
        addrServer.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    else
    {
        addrServer.sin_addr.s_addr = inet_addr(strServerIp.c_str());
    }
#endif

	//将套接字绑定到一个本地地址和端口上  
	if (bind(m_hSocket, (SOCKADDR*)&addrServer, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		char szError[256];
		memset(szError, 0, 256);
#ifdef WIN32
		sprintf(szError, "bind() called failed!, error code is: %d", WSAGetLastError());
#endif // WIN32
		m_strError = szError;
		return false;
	}
	return true;
}

bool CTcpServer::StartService()
{
	GUARD(CThreadMutex, m_mutextSocket)
	if (listen(m_hSocket, 5) == SOCKET_ERROR)
	{
		return false;
	}
	m_bIsService = true;
	Active();
	return true;
}

bool CTcpServer::SendDataToClient(std::string strIp, unsigned short usPort, char* szBuffer, int nLen)
{
	for (std::map<SocketHandle, CTcpClientInfo>::iterator itr = m_mapSocketAddr.begin()
		; itr != m_mapSocketAddr.end(); itr++)
	{
		if ((itr->second.GetIp() == strIp)
			&& (itr->second.GetPort() == usPort))
		{
			return SendData(itr->second, szBuffer, nLen);
		}
	}
	return false;
}

bool CTcpServer::SendData(CTcpClientInfo clinet, char* szBuffer, int nLen)
{
	int nSurSize = nLen;
	int nAlready = 0;
	while (nSurSize > 0)
	{
		int nSize = send(clinet.GetHandle(), szBuffer + nAlready, nSurSize, 0);
		if(nSize < 0)
		{
			return false;
		}
		nSurSize -= nSize;
		nAlready += nSize;
	}
	return true;
}

void CTcpServer::DeleteClient(SocketHandle hClinet)
{
	std::map<SocketHandle, CTcpClientInfo>::iterator itr = m_mapSocketAddr.find(hClinet);
	if (itr == m_mapSocketAddr.end())
	{
		return;
	}
#ifdef WIN32
	closesocket(hClinet);
#elif linux
    close(hClinet);
#endif
	m_mapSocketAddr.erase(itr);
}

bool CTcpServer::SetSendRecvBufferSize(int nSendSize, int nRecvSize)
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

void CTcpServer::CloseService()
{
	if(!m_bIsService)
	{
		return;
	}

	if (m_hSocket != INVALID_SOCKET)
	{
		shutdown(m_hSocket, 1);
#ifdef WIN32
        closesocket(m_hSocket);
#elif linux
        close(m_hSocket);
#endif
		if (IsRunning())
		{
			//  关闭后退出线程
			Quit();
			// 等待线程真正退出
			Wait();
		}

		m_hSocket = INVALID_SOCKET;
	}
	m_bIsService = false;
}

void CTcpServer::RegisterObserver(ITcpServerObserver* pUser)
{
	m_pUser = pUser;
}

bool CTcpServer::IsService()
{
	return false;
}

void CTcpServer::run()
{
	// 所有套接字集合
	fd_set allSet;
	// 活动套接字集合
	fd_set activeSet;

	FD_ZERO(&allSet);
	FD_ZERO(&activeSet);
	// 加入本地套接字
	FD_SET(m_hSocket, &allSet);
	
	
	while (!IsQuit())
	{
		int nMaxId = -1;
		activeSet = allSet;
#ifdef linux

#endif
		timeval tm;
		tm.tv_sec = 0;
		tm.tv_usec = 200000;
		// windows中，第一个参数已经无用，为了保持接口一致而留存
		// 检查套接字动作，有动作的套接字会放入activeSet
		int nRet = select(nMaxId + 1, &activeSet, nullptr, nullptr,  &tm);
		if (nRet < 0)
		{
			Quit();
			continue;
		}
		else if(nRet == 0)
		{
			continue;
		}
		
		{
			GUARD(CThreadMutex, m_mutextSocket)
			// 如果本地套接字也在活动套接字中
			// 则说明有新连接加入进来
			if (FD_ISSET(m_hSocket, &activeSet) != 0)
			{
				sockaddr_in addrClient;
                socklen_t nLen;
				SocketHandle hClientSock;
				if ((hClientSock = accept(m_hSocket, (sockaddr*)&addrClient, &nLen)) < 0)
				{
					continue;
				}
				FD_SET(hClientSock, &allSet);
				CTcpClientInfo clientInfo;
				clientInfo.SetHandle(hClientSock);
				clientInfo.SetIp(inet_ntoa(addrClient.sin_addr));
				clientInfo.SetPort(ntohs(addrClient.sin_port));
				m_mapSocketAddr[hClientSock] = clientInfo;
				if (nullptr != m_pUser)
				{
					m_pUser->OnClinetConnected(clientInfo.GetIp(), clientInfo.GetPort());
				}

				FD_CLR(m_hSocket, &activeSet);
			}

			// 接收数据部分
            for (int i = 0; i < 1024; ++i)
            {
#ifdef WIN32
                SocketHandle handleClient = activeSet.fd_array[i];
#elif linux
                if(0 == FD_ISSET(i, &activeSet))
                {

                }
                SocketHandle handleClient = i;
#endif
                if (m_mapSocketAddr.find(handleClient) == m_mapSocketAddr.end())
				{
					continue;
				}

				CTcpClientInfo clientInfo = m_mapSocketAddr[handleClient];

				memset(m_pRecvBuffer, 0, E_TCP_RECV_BUFFER_SIZE);
                m_nRecvBufferLen = recv(handleClient, m_pRecvBuffer, E_TCP_RECV_BUFFER_SIZE, 0);
                if(m_nRecvBufferLen == 0)
                {
                    continue;
                }

				// 收到的数据长度小于0，则说明客户端掉线
				if (m_nRecvBufferLen < 0)
				{
					FD_CLR(handleClient, &allSet);
					if (nullptr != m_pUser)
					{
						m_pUser->OnClientDisconnetcted(clientInfo.GetIp(), clientInfo.GetPort());
					}
					DeleteClient(handleClient);
					continue;
				}
				CSocketNode node;
				node.SetSrcAddr(clientInfo.GetIp(), clientInfo.GetPort());
				node.SetData((unsigned char*)m_pRecvBuffer, m_nRecvBufferLen);
				if (nullptr != m_pUser)
				{
					m_pUser->OnTcpRead(node);
				}
			}
			FD_ZERO(&activeSet);
		}
		
	}
}
