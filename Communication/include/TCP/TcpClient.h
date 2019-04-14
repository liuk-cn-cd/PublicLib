/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: TcpClient.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/06 10:03:58
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _TCPCLIENT_H__
#define _TCPCLIENT_H__
#include "Thread.h"
#include <string>
#include "CommuDefine.h"


/*!
 * @class	: CTcpClient
 * @brief	: TCP客户端
 * @author	: liuk
 * @date	: 2018/04/06 15:44
 */
class CTcpClient : public CThread
{
public:
	CTcpClient();
	~CTcpClient();
public:
	/**
	 * @fn		: ConnectServer
	 * @brief	: 连接服务器
	 * @access	: public 
	 * @param	: [in] const std::string & strServerIp 服务器IP
	 * @param	: [in] unsigned short usPort 服务器端口
	 * @return	: bool 成功返回true，失败返回false
	 */
	bool ConnectServer(const std::string& strServerIp, unsigned short usPort);

	/**
	 * @fn		: DisConnect
	 * @brief	: 断开与服务器的连接
	 * @access	: public 
	 * @return	: bool
	 */
	bool DisConnect();

	/**
	 * @fn		: IsConnectServer
	 * @brief	: 是否连接到服务器
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsConnectServer();

	/**
	 * @fn		: SendData2Server
	 * @brief	: 发送数据到服务器
	 * @access	: public 
	 * @param	: [in] const char * pBuf 数据地址
	 * @param	: [in] unsigned int nBufLen 数据长度
	 * @return	: bool
	 */
	bool SendData2Server(const char* pBuf, unsigned int nBufLen);
public:
	virtual void run();
protected:
	/**
	 * @fn		: SetSendRecvBufferSize
	 * @brief	: 设置收发buffer大小
	 * @access	: protected 
	 * @param	: int nSendSize
	 * @param	: int nRecvSize
	 * @return	: bool
	 */
	bool SetSendRecvBufferSize(int nSendSize, int nRecvSize);
private:
	SocketHandle m_hSocket;

	char* m_pRecvBuffer;

	std::string m_strIp;
	unsigned short m_usPort;

	bool m_bConnected;
};
#endif // _TCPCLIENT_H__