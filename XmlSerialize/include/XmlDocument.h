/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: XmlDocument.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/16 10:10:26
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */

#ifndef _XMLDOCUMENT_H
#define _XMLDOCUMENT_H
#include <string>
#include "XmlSerialize_Global.h"
class CXmlElement;

/*!
 * @class	: CXmlDocument
 * @brief	: xml�ĵ��࣬����xml�Ķ�ȡ�����
 * @author	: liuk
 * @date	: 2017/04/16 10:53
 */
class XMLSERILIZE_EXPORT CXmlDocument
{
public:
	CXmlDocument();
	~CXmlDocument();

public:

	/**
	 * @fn		: SaveFile
	 * @brief	: ��xml�ĵ����浽�����ļ���
	 * @access	: public 
	 * @param	: const std::string & strFile �ļ���
	 * @return	: bool
	 */
	bool SaveFile(const std::string& strFile);

	/**
	 * @fn		: LoadFile
	 * @brief	: �����ļ��м���xml�ĵ�
	 * @access	: public 
	 * @param	: const std::string & strFile
	 * @return	: bool
	 */
	bool LoadFile(const std::string& strFile);

	/**
	 * @fn		: RootElement
	 * @brief	: ��ȡ���ڵ�
	 * @access	: public 
	 * @return	: CXmlElement*
	 */
	CXmlElement* RootElement();

	/**
	 * @fn		: SetVersion
	 * @brief	:���ð汾���ڵ��ñ���ǰ����
	 * @access	: public 
	 * @param	: const std::string & strVersion
	 * @return	: void
	 */
	void SetVersion(const std::string& strVersion);

	/**
	 * @fn		: SetCodec
	 * @brief	: �����ַ����룬�ڵ��ñ���ǰ����
	 * @access	: public 
	 * @param	: const std::string & strCodec
	 * @return	: void
	 */
	void SetCodec(const std::string& strCodec);

	/**
	 * @fn		: SetStandalone
	 * @brief	: ���ñ�׼���ڵ��ñ���ǰ����
	 * @access	: public 
	 * @param	: const std::string & strStandalone
	 * @return	: void
	 */
	void SetStandalone(const std::string& strStandalone);

	/**
	 * @fn		: SetRootElement
	 * @brief	: ����Ҫ���浽�ļ���xml�ڵ㣬�ýڵ���Ϊxnl�ļ��ĸ��ڵ�
	 * @access	: public 
	 * @param	: CXmlElement * pSrcElement
	 * @return	: void
	 */
	void SetRootElement(CXmlElement* pSrcElement);
private:
	CXmlElement* m_pRootElement;

	// �汾
	std::string m_strVersion;
	// �ַ�����
	std::string m_strCodec;
	//��׼
	std::string m_strStandalone;
};

#endif // _XMLDOCUMENT_H