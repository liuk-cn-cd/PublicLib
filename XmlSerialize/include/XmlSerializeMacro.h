
/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/

/**
 * @file	: XmlSerializeMacro.h
 * @brief	: XML���л��궨��
 * @author	: liuk
 * @date	: 2017/04/09 10:51:36
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef XMLSERIALIZEMACRO_H
#define XMLSERIALIZEMACRO_H
#include "XmlElement.h"
#include "XmlDocument.h"
#include "string"
 /**
 * @fn		: DECLARE_XML_SERIALIZE(className, nodeName)
 * @brief	: ���л������꣬����������
 * @access	: macro
 * @param	: className,����
 * @param	: nodeName,�ڵ�����
 */
#define DECLARE_XML_SERIALIZE() \
	public:\
		CXmlElement* GetCurrentElement(){return m_pXmlElement;}\
		virtual CXmlElement*  XMLSerialize(bool bStore, CXmlElement* pRootXmlElement); \
//		virtual bool Store2XmlFile(const std::string& strFile);\
//		virtual bool LoadFromXmlFile(const std::string& strFile);\

 /**
 * @fn		: BEGIN_XML_SERIALIZE(className, nodeName)
 * @brief	: ���л�ʵ�ֺ꣬��cpp��ʵ��
 * @access	: macro
 * @param	: className,����
 * @param	: nodeName,�ڵ�����
 */
#define BEGIN_XML_SERIALIZE(className, nodeName)\
CXmlElement*  className::XMLSerialize(bool bStore, CXmlElement* pRootXmlElement)\
{\
	std::string strNodeName = #nodeName;\
	if(bStore)\
	{\
		pRootXmlElement->SetName(strNodeName);\
	}\

 /**
 * @fn		: XML_SER_VAR(name, var)
 * @brief	: ���л�һ����������
 * @access	: macro
 * @param	: name,�ڵ���
 * @param	: var,����
 */
#define XML_SER_VAR(name, var)\
	if(bStore)\
	{\
		CXmlElement* pElement = new CXmlElement;\
		pElement->SetName(#name);\
		pElement->SetValue(var);\
		pRootXmlElement->PushChild(pElement);\
	}\
	else\
	{\
		CXmlElement* pElement = pRootXmlElement->NextChildElement();\
		if(pElement->GetName() == std::string(#name))\
			pElement->GetValue(var);\
	}\
	
 /**
 * @fn		: XML_SER_STL_VAR(name, subName, var)\
 * @brief	: ���л�һ���������͵ı�׼����
 * @access	: macro
 * @param	: name,������
 * @param	: subName,�ӽڵ���
 * @param	: var,����
 */
#define XML_SER_STL_VAR(name, subName, var)\
	if(bStore)\
	{\
		CXmlElement* pParent = new CXmlElement;\
		pParent->SetName(#name);\
		for(int i = 0; i < var.size(); i++)\
		{\
			CXmlElement* pSubElement = new CXmlElement;\
			pSubElement->SetName(#subName);\
			pSubElement->SetValue(var[i]);\
			pParent->PushChild(pSubElement);\
		}\
		pRootXmlElement->PushChild(pParent);\
	}\
	else\
	{\
		CXmlElement* pParent = pRootXmlElement->NextChildElement();\
		if(pParent->GetName() == std::string(#name))\
		{\
			CXmlElement* pSubElement = pParent->FirstChildElement();\
			var.resize(pParent->ChildCount());\
			int i = 0;\
			while(pSubElement)\
			{\
				pSubElement->GetValue(var[i++]);\
				pSubElement = pParent->NextChildElement();\
			}\
		}\
	}\
	
 /**
 * @fn		: XML_SER_OBJECT(name, var)\
 * @brief	: ���л�xml����
 * @access	: macro
 * @param	: name,�ڵ�����
 * @param	: var,����
 */
#define XML_SER_OBJECT(name, var)\
	if(bStore)\
	{ \
		CXmlElement* pObjElement = var.XMLSerialize(bStore, new CXmlElement);\
		pObjElement->SetName(#name);\
		pRootXmlElement->PushChild(pObjElement);\
	}\
	else\
	{\
		var.XMLSerialize(bStore, pRootXmlElement->NextChildElement());\
	}\

 /**
 * @fn		: XML_SER_STL_OBJECT(name, subName, var)\
 * @brief	: ���л�һ��xml����ı�׼����
 * @param	: name,������
 * @param	: subName,�ӽڵ���
 * @param	: var,����
 */
#define XML_SER_STL_OBJECT(name, subName, var)\
	if(bStore)\
	{\
		CXmlElement* pParent = new CXmlElement;\
		pParent->SetName(#name);\
		for(int i = 0; i < var.size(); i++)\
		{\
			CXmlElement* pObjElement = var[i].XMLSerialize(bStore, new CXmlElement);\
			pObjElement->SetName(#name);\
			pParent->PushChild(pObjElement);\
		}\
		pRootXmlElement->PushChild(pParent);\
	}\
	else\
	{\
		CXmlElement* pParent = pRootXmlElement->NextChildElement();\
		if(pParent->GetName() == std::string(#name))\
		{\
			CXmlElement* pSubElement = pParent->FirstChildElement();\
			var.resize(pParent->ChildCount());\
			int i = 0;\
			while(pSubElement)\
			{\
				var[i++].XMLSerialize(bStore,pSubElement);\
				pSubElement = pParent->NextChildElement();\
			}\
		}\
	}\

 /**
 * @fn		: XML_SER_OBJECT(name, var)\
 * @brief	: ���л�xml����
 * @access	: macro
 * @param	: name,������
 * @param	: var,���Զ���
 */
#define  XML_SER_ATTR(name, var)\
	if(bStore)\
	{\
		pRootXmlElement->SetAttribute(#name, var);\
	}\
	else\
	{\
		pRootXmlElement->GetAttribute(#name, var);\
	}\

#define  END_XML_SERIALIZE()\
	return pRootXmlElement;\
	}

#endif // XMLSERIALIZEMACRO_H
