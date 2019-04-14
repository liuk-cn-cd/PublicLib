/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
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
	 * @brief	: �����׽���
	 * @access	: public 
	 * @param	: SocketHandle hSocket
	 * @return	: void
	 */
	void SetHandle(SocketHandle hSocket);

	/**
	 * @fn		: SetIp
	 * @brief	: ����ip
	 * @access	: public 
	 * @param	: std::string strIp
	 * @return	: void
	 */
	void SetIp(std::string strIp);

	/**
	 * @fn		: SetPort
	 * @brief	: ���ö˿�
	 * @access	: public 
	 * @param	: unsigned short usPort
	 * @return	: void
	 */
	void SetPort(unsigned short usPort);

	/**
	 * @fn		: GetHandle
	 * @brief	: ��ȡsocket�׽���
	 * @access	: public 
	 * @return	: SocketHandle �ͻ����׽���
	 */
	SocketHandle GetHandle() const;

	/**
	 * @fn		: GetIp
	 * @brief	: ��ȡ�ͻ���IP
	 * @access	: public 
	 * @return	: std::string �ͻ���IP
	 */
	std::string GetIp() const;

	/**
	 * @fn		: GetPort
	 * @brief	: ��ȡ�ͻ���Port
	 * @access	: public 
	 * @return	: unsigned short �ͻ���port
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