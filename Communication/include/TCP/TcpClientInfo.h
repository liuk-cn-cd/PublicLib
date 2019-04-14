/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: TcpClientInfo.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/13 7:45:29
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _TCPCLIENTINFO_H__
#define _TCPCLIENTINFO_H__
#include <string>
#include "CommuDefine.h"

class CTcpClientInfo
{
public:
	CTcpClientInfo();
	~CTcpClientInfo();

public:
	/**
	 * @fn		: SetHandle
	 * @brief	: 设置套接字
	 * @access	: public 
	 * @param	: SocketHandle hSocket
	 * @return	: void
	 */
	void SetHandle(SocketHandle hSocket);

	/**
	 * @fn		: SetIp
	 * @brief	: 设置ip
	 * @access	: public 
	 * @param	: std::string strIp
	 * @return	: void
	 */
	void SetIp(std::string strIp);

	/**
	 * @fn		: SetPort
	 * @brief	: 设置端口
	 * @access	: public 
	 * @param	: unsigned short usPort
	 * @return	: void
	 */
	void SetPort(unsigned short usPort);

	/**
	 * @fn		: GetHandle
	 * @brief	: 获取socket套接字
	 * @access	: public 
	 * @return	: SocketHandle 客户端套接字
	 */
	SocketHandle GetHandle() const;

	/**
	 * @fn		: GetIp
	 * @brief	: 获取客户端IP
	 * @access	: public 
	 * @return	: std::string 客户端IP
	 */
	std::string GetIp() const;

	/**
	 * @fn		: GetPort
	 * @brief	: 获取客户端Port
	 * @access	: public 
	 * @return	: unsigned short 客户端port
	 */
	unsigned short GetPort() const;

public:
	CTcpClientInfo& operator=(const CTcpClientInfo& rObj);
	bool operator==(const CTcpClientInfo& rObj);
private:
	SocketHandle m_hSocket;
	std::string m_strIp;
	unsigned short m_usPort;
};


#endif // _TCPCLIENTINFO_H__