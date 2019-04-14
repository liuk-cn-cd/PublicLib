/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: XmlElement.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/09 12:05:36
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "XmlElement.h"
#include "tinyxml.h"
#include <stdlib.h>

CXmlElement::CXmlElement(const std::string& strName /*= ""*/)
	: m_nCursor(-1)
{
	m_pXmlNode = new TiXmlElement(strName.c_str());
}

CXmlElement::~CXmlElement()
{
	// tinyXml有自动销毁功能，只需要析构最顶级节点即可，不需要自己一层层析构

	Clear();

}

void CXmlElement::FromTiXmlElement(TiXmlElement* pTiElement)
{
	Clear();
	if(NULL == pTiElement)
	{
		return;
	}
	m_pXmlNode = pTiElement;
	TiXmlElement* pChildElement = m_pXmlNode->FirstChildElement();
	while (pChildElement)
	{
		CXmlElement* pNewElement = new CXmlElement;
		pNewElement->FromTiXmlElement(pChildElement);
//		PushChild(pNewElement);
		m_vecChildNode.push_back(pNewElement);
		pChildElement = pChildElement->NextSiblingElement();
	}

	
}

void CXmlElement::SetName(const std::string& strName)
{
	m_pXmlNode->SetValue(strName.c_str());
}

std::string CXmlElement::GetName()
{
	return m_pXmlNode->Value();
}

bool CXmlElement::GetValue(int& nValue)
{
	std::string strValue;
	if (GetValue(strValue))
	{
		nValue = atoi(strValue.c_str());
		return true;
	}
	return false;
}

bool CXmlElement::GetValue(double& dValue)
{
	std::string strValue;
	if (GetValue(strValue))
	{
		dValue = atof(strValue.c_str());
		return true;
	}
	return false;
}


bool CXmlElement::GetValue(float& fValue)
{
	std::string strValue;
	if (GetValue(strValue))
	{
		fValue = atof(strValue.c_str());
		return true;
	}
	return false;
}

bool CXmlElement::GetValue(std::string& strValue)
{
	if (m_pXmlNode->GetText() == NULL)
	{
		return false;
	}
	strValue = m_pXmlNode->GetText();
	return true;
}

void CXmlElement::SetValue(const std::string& strText)
{
	TiXmlText* pText = new TiXmlText(strText.c_str());
	m_pXmlNode->LinkEndChild(pText);
}

void CXmlElement::SetValue(const float fValue)
{
	char szValue[32];
	memset(szValue, 0, 32);
	sprintf(szValue, "%f", fValue);
	std::string strValue = szValue;
	SetValue(strValue);
}

void CXmlElement::SetValue(const double dValue)
{
	char szValue[32];
	memset(szValue, 0, 32);
	sprintf(szValue, "%lf", dValue);
	std::string strValue = szValue;
	SetValue(strValue);
}

void CXmlElement::SetValue(const int nValue)
{
	char szValue[32];
	memset(szValue, 0, 32);
	sprintf(szValue, "%d", nValue);
	std::string strValue = szValue;
	SetValue(strValue);
}

void CXmlElement::SetAttribute(const std::string& strName, const std::string& strValue)
{
	m_pXmlNode->SetAttribute(strName.c_str(), strValue.c_str());
}

void CXmlElement::SetAttribute(const std::string& strName, int nValue)
{
	char szValue[32];
	memset(szValue, 0, 32);
	sprintf(szValue, "%d", nValue);
	std::string strValue = szValue;
	SetAttribute(strName, strValue);
}

void CXmlElement::SetAttribute(const std::string& strName, double dValue)
{
	char szValue[32];
	memset(szValue, 0, 32);
	sprintf(szValue, "%lf", dValue);
	std::string strValue = szValue;
	SetAttribute(strName, strValue);
}

void CXmlElement::SetAttribute(const std::string& strName, float fValue)
{
	char szValue[32];
	memset(szValue, 0, 32);
	sprintf(szValue, "%f", fValue);
	std::string strValue = szValue;
	SetAttribute(strName, strValue);
}

bool CXmlElement::GetAttribute(const std::string& strName, std::string& strValue)
{
	strValue = m_pXmlNode->Attribute(strName.c_str());
	return !strValue.empty();
}

bool CXmlElement::GetAttribute(const std::string& strName, int& nValue)
{
	std::string strValue = m_pXmlNode->Attribute(strName.c_str());
	if (strValue.empty())
	{
		return false;
	}

	nValue = atoi(strValue.c_str());
	return true;
}

bool CXmlElement::GetAttribute(const std::string& strName, double& dValue)
{
	std::string strValue = m_pXmlNode->Attribute(strName.c_str());
	if (strValue.empty())
	{
		return false;
	}

	dValue = atof(strValue.c_str());
	return true;
}

bool CXmlElement::GetAttribute(const std::string& strName, float& fValue)
{
	std::string strValue = m_pXmlNode->Attribute(strName.c_str());
	if (strValue.empty())
	{
		return false;
	}

	fValue = atof(strValue.c_str());
	return true;
}

CXmlElement* CXmlElement::NextChildElement()
{
	m_nCursor++;
	if (m_vecChildNode.size() <= m_nCursor)
	{
		return NULL;
	}
	return m_vecChildNode[m_nCursor];
}

CXmlElement* CXmlElement::FirstChildElement()
{
	m_nCursor = 0;
	if(m_vecChildNode.empty())
	{
		return NULL;
	}

	return m_vecChildNode[0];
}

void CXmlElement::PushChild(CXmlElement* pChild)
{
	m_vecChildNode.push_back(pChild);
	m_pXmlNode->LinkEndChild(pChild->m_pXmlNode);
}

bool CXmlElement::IsEnd()
{
	return m_nCursor >= m_vecChildNode.size();
}

TiXmlElement* CXmlElement::CurrentElement()
{
	return m_pXmlNode;
}

void CXmlElement::Clear()
{
	for (int i = 0; i < m_vecChildNode.size(); i++)
	{
		CXmlElement* pElement = m_vecChildNode[i];
		if (NULL != pElement)
		{
			delete pElement;
			pElement = NULL;
		}
	}

	m_vecChildNode.clear();
}

int CXmlElement::ChildCount()
{
	return m_vecChildNode.size();
}
