/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: TcpServer.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/06 10:01:47
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _TCPSERVER_H__
#define _TCPSERVER_H__
#include <string>
#include <map>
#include "communication_global.h"
#include "Thread.h"
#include "CommuDefine.h"
#include "SocketNode.h"
#include "BlockingQueue.h"
#include "TcpClientInfo.h"
#include "ThreadMutex.h"

/*!
 * @class	: ITcpServerObserver
 * @brief	: tcp服务器观察者，
 *			  当服务器有状态变化时，通过注册的观察者通知给外界
 * @author	: liuk
 * @date	: 2017/07/06 15:15
 */
class ITcpServerObserver
{
public:
	ITcpServerObserver() {}
	virtual ~ITcpServerObserver() {}
public:
	/**
	 * @fn		: OnTcpRead
	 * @brief	: 读取到客户端的消息
	 * @access	: virtual public 
	 * @param	: [in] CSocketNode socketNode
	 *			  客户端的信息，包括地址、端口及发送过来的数据
	 * @return	: void
	 */
	virtual void OnTcpRead(const CSocketNode& socketNode) = 0;

	/**
	 * @fn		: OnClinetConnected
	 * @brief	: 有客户端连接上来
	 * @access	: virtual public 
	 * @param	: [in] const std::string strIp
				  客户端IP
	 * @param	: [in] unsigned short usPort
				  客户端端口
	 * @return	: void
	 */
	virtual void OnClinetConnected(const std::string& strIp, unsigned short usPort) = 0;

	/**
	 * @fn		: OnClientDisconnetcted
	 * @brief	: 有客户端断开连接
	 * @access	: virtual public 
	 * @param	: [in] const std::string& strIp
				  客户端ip
	 * @param	: [in] unsigned short usPort
				  客户端端口
	 * @return	: void
	 */
	virtual void OnClientDisconnetcted(const std::string& strIp, unsigned short usPort) = 0;

};

/*!
 * @class	: 
 * @brief	: 
 * @author	: liuk
 * @date	: 2017/05/06 15:15
 */
class COMMUNICATION_EXPORT CTcpServer : public CThread
{
public:
	CTcpServer();
	~CTcpServer();
public:
	/**
	 * @fn		: InitServer
	 * @brief	: 初始化服务器
	 * @access	: public 
	 * @param	: std::string strServerIp 服务器 IP
	 * @param	: unsigned short usPort, 服务端口号
	 * @return	: bool
	 */
	bool InitServer(std::string strServerIp, unsigned short usPort);
	/**
	 * @fn		: StartService
	 * @brief	: 启动服务
	 * @access	: public 
	 * @return	: bool
	 */
	bool StartService();

	/**
	 * @fn		: SendDataToClient
	 * @brief	: 发送数据到指定客户端
	 * @access	: public 
	 * @param	: std::string strIp 
	 * @param	: unsigned short usPort
	 * @param	: char * szBuffer
	 * @param	: int nLen
	 * @return	: bool 失败或未完全发送返回false
	 */
	bool SendDataToClient(std::string strIp, unsigned short usPort, char* szBuffer, int nLen);

	/**
	 * @fn		: SetSendRecvBufferSize
	 * @brief	: 设置接收、发送缓冲区大小
	 * @access	: public 
	 * @param	: int nSendSize
	 * @param	: int nRecvSize
	 * @return	: bool 失败返回false
	 */
	bool SetSendRecvBufferSize(int nSendSize, int nRecvSize);

	/**
	 * @fn		: CloseService
	 * @brief	: 关闭服务器
	 * @access	: public 
	 * @return	: void
	 */
	void CloseService();

	/**
	 * @fn		: RegisterObserver
	 * @brief	: 注册服务观察者
	 * @access	: public 
	 * @param	: ITcpServerObserver * pUser
	 * @return	: void
	 */
	void RegisterObserver(ITcpServerObserver* pUser);

	/**
	 * @fn		: IsService
	 * @brief	: 是否已开启TCP服务
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsService();
public:
	virtual void run();

protected:
	/**
	 * @fn		: SendData
	 * @brief	: 发送数据到指定客户端
	 * @access	: protected 
	 * @param	: CTcpClientInfo clinet
	 * @param	: char * szBuffer
	 * @param	: int nLen
	 * @return	: bool 失败或未完全发送返回false
	 */
	bool SendData(CTcpClientInfo clinet, char* szBuffer, int nLen);

	/**
	 * @fn		: DeleteClient
	 * @brief	: 删除客户端
	 * @access	: protected 
	 * @param	: [in] SocketHandle hClinet 要删除的客户端
	 * @return	: void
	 */
	void DeleteClient(SocketHandle hClinet);
private:
	SocketHandle m_hSocket;
	unsigned short m_usPort;
	std::string m_strError;

	// 客户端套接字和客户端地址的映射
	std::map<SocketHandle, CTcpClientInfo> m_mapSocketAddr;

	ITcpServerObserver* m_pUser;

	CBlockingQueue<CSocketNode> m_queRecvData;

	CThreadMutex m_mutextSocket;

	char* m_pRecvBuffer;
	int m_nRecvBufferLen;

	bool m_bIsService;
	
};

#endif // _TCPSERVER_H__