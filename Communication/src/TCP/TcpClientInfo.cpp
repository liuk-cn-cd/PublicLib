/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: TcpClientInfo.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/13 7:45:36
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "TCP\TcpClientInfo.h"



CTcpClientInfo::CTcpClientInfo()
	: m_hSocket(INVALID_SOCKET)
	, m_strIp("")
	, m_usPort(0)
{
}


CTcpClientInfo::~CTcpClientInfo()
{
}

void CTcpClientInfo::SetHandle(SocketHandle hSocket)
{
	m_hSocket = hSocket;
}

void CTcpClientInfo::SetIp(std::string strIp)
{
	m_strIp = strIp;
}

void CTcpClientInfo::SetPort(unsigned short usPort)
{
	m_usPort = usPort;
}

SocketHandle CTcpClientInfo::GetHandle() const
{
	return m_hSocket;
}

std::string CTcpClientInfo::GetIp() const
{
	return m_strIp;
}

unsigned short CTcpClientInfo::GetPort() const
{
	return m_usPort;
}

bool CTcpClientInfo::operator==(const CTcpClientInfo& rObj)
{
	return m_hSocket == rObj.m_hSocket;
}

CTcpClientInfo& CTcpClientInfo::operator=(const CTcpClientInfo& rObj)
{
	m_hSocket = rObj.m_hSocket;
	m_usPort = rObj.m_usPort;
	m_strIp = rObj.m_strIp;
	return *this;
}
