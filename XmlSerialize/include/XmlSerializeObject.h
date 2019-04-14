/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/

 /**
 * @file	: XmlSerializeObject.h
 * @brief	: xml���л������������
 * @author	: liuk
 * @date	: 2017/04/09 10:31:34
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 *
 */
#ifndef _XMLSERIALIZEOBJECT_H
#define _XMLSERIALIZEOBJECT_H
#include "XmlSerialize_Global.h"
#include <string>

class CXmlElement;
class CXmlDocument;
/*!
 * @class	: CXmlSerializeObject
 * @brief	: xml���л����࣬�������л���Ӵ˴�����
 * @author	: liuk
 * @date	: 2017/04/09 10:35
 */
class XMLSERILIZE_EXPORT CXmlSerializeObject
{
public:
	CXmlSerializeObject();
	virtual ~CXmlSerializeObject();
protected:
	/**
	 * @fn		: ReadDataFromXmlFile
	 * @brief	: ��xml�ļ����ȡ����
	 * @access	: protected 
	 * @return	: void
	 */
	bool ReadXmlFile(const std::string& strFile);

	/**
	 * @fn		: WriteData2XmlFile
	 * @brief	: �������ݵ�xml�ļ�
	 * @access	: protected 
	 * @return	: void
	 */
	bool StoreXmlFile(const std::string& strFile);
protected:
	virtual CXmlElement* XMLSerialize(bool bStore, CXmlElement* pRootXmlElement) = 0;
//	virtual bool Store2XmlFile(const std::string& strFile) = 0;
//	virtual bool LoadFromXmlFile(const std::string& strFile) = 0;

protected:
	CXmlElement* m_pXmlElement;
	CXmlDocument* m_pXmlDocument;
};

#endif // _XMLSERIALIZEOBJECT_H