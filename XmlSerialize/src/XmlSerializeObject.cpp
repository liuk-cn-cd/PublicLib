/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: XmlSerializeObject.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/09 10:53:19
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "XmlSerializeObject.h"
#include "XmlDocument.h"
#include "XmlElement.h"

CXmlSerializeObject::CXmlSerializeObject()
	: m_pXmlElement(NULL)
	, m_pXmlDocument(NULL)
{
}


CXmlSerializeObject::~CXmlSerializeObject()
{
	if (NULL != m_pXmlDocument)
	{
		delete m_pXmlDocument;
		m_pXmlDocument = NULL;
	}
}

bool CXmlSerializeObject::ReadXmlFile(const std::string& strFile)
{
	if (NULL == m_pXmlDocument)
	{
		m_pXmlDocument = new CXmlDocument;
	}

	if (!m_pXmlDocument->LoadFile(strFile))
	{
		return false;
	}

	return XMLSerialize(false, m_pXmlDocument->RootElement());
}

bool CXmlSerializeObject::StoreXmlFile(const std::string& strFile)
{
	CXmlElement* pXmlElement = new CXmlElement;
	XMLSerialize(true, pXmlElement);
	if (NULL == pXmlElement)
	{
		return false;
	}

	if (NULL == m_pXmlDocument)
	{
		m_pXmlDocument = new CXmlDocument;
	}

	m_pXmlDocument->SetRootElement(pXmlElement);
	bool bRet = m_pXmlDocument->SaveFile(strFile);
	if(NULL != pXmlElement)
	{
		delete pXmlElement;
		pXmlElement = NULL;
	}
	return bRet;
}
