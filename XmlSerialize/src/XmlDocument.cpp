/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: XmlDocument.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/16 10:10:36
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "XmlDocument.h"
#include "tinyxml.h"
#include "XmlElement.h"


CXmlDocument::CXmlDocument()
	: m_strVersion("1.0")
	, m_strCodec("GBK")
	, m_strStandalone("")
	, m_pRootElement(NULL)
{

}


CXmlDocument::~CXmlDocument()
{
}

bool CXmlDocument::SaveFile(const std::string& strFile)
{
	TiXmlDocument* pXmlDoc = new TiXmlDocument;
	TiXmlDeclaration* pXmlDec = new TiXmlDeclaration(m_strVersion.c_str(), m_strCodec.c_str(), m_strStandalone.c_str());
	if (NULL == m_pRootElement)
	{
		return false;
	}

	TiXmlElement* pRootTiElement = m_pRootElement->CurrentElement();
	if(NULL == pRootTiElement)
	{
		return false;
	}

	pXmlDoc->LinkEndChild(pXmlDec);
	pXmlDoc->LinkEndChild(pRootTiElement);

	return pXmlDoc->SaveFile(strFile.c_str());
}

bool CXmlDocument::LoadFile(const std::string& strFile)
{
	TiXmlDocument* pXmlDoc = new TiXmlDocument;
	if(!pXmlDoc->LoadFile(strFile.c_str()))
	{
		return false;
	}
	TiXmlNode* pFirstNode = pXmlDoc->FirstChild();
	if (NULL == pFirstNode)
	{
		return false;
	}

	TiXmlDeclaration* pXmlDec = pFirstNode->ToDeclaration();

	TiXmlElement* pRootElement = pXmlDoc->RootElement();
	if(NULL == pRootElement)
	{
		return false;
	}

	if(NULL != m_pRootElement)
	{
		delete m_pRootElement;
		m_pRootElement = NULL;
	}

	m_pRootElement = new CXmlElement;
	m_pRootElement->FromTiXmlElement(pRootElement);
	return true;
}

CXmlElement* CXmlDocument::RootElement()
{
	return m_pRootElement;
}

void CXmlDocument::SetVersion(const std::string& strVersion)
{
	m_strVersion = strVersion;
}

void CXmlDocument::SetCodec(const std::string& strCodec)
{
	m_strCodec = strCodec;
}

void CXmlDocument::SetStandalone(const std::string& strStandalone)
{
	m_strStandalone = strStandalone;
}

void CXmlDocument::SetRootElement(CXmlElement* pSrcElement)
{
	m_pRootElement = pSrcElement;
}
