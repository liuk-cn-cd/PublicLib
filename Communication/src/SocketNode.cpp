/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: SocketNode.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/30 10:47:14
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "SocketNode.h"



CSocketNode::CSocketNode()
	: m_usSrcPort(-1)
	, m_strSrcIp("")
	, m_nSize(0)
	, m_pData(NULL)
{
}


CSocketNode::CSocketNode(const CSocketNode& rObj)
{
	*this = rObj;
}

CSocketNode::~CSocketNode()
{
	Clear();
}

const unsigned char* CSocketNode::GetDataBuffer() const
{
	return m_pData;
}

int CSocketNode::GetDataSize() const
{
	return m_nSize;
}

std::string CSocketNode::GetSrcIp() const
{
	return m_strSrcIp;
}

int CSocketNode::GetSrcPort() const
{
	return m_usSrcPort;
}

void CSocketNode::SetData(const unsigned char* pData, int nlen)
{
	m_nSize = nlen;
	m_pData = new unsigned char[nlen];
	memcpy(m_pData, pData, nlen);
}

void CSocketNode::SetSrcAddr(const std::string& strIp, unsigned short usPort)
{
	m_strSrcIp = strIp;
	m_usSrcPort = usPort;
}

void CSocketNode::Clear()
{
	if (NULL != m_pData)
	{
		delete m_pData;
		m_pData = NULL;
		
	}
	m_nSize = 0;
	m_strSrcIp = "";
	m_usSrcPort = 0;
}

CSocketNode& CSocketNode::operator=(const CSocketNode& rObj)
{
	Clear();
	m_strSrcIp = rObj.m_strSrcIp;
	m_usSrcPort = rObj.m_usSrcPort;
	m_nSize = rObj.m_nSize;
	m_pData = new unsigned char[rObj.m_nSize];
	return *this;
}
