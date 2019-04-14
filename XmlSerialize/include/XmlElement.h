
/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
 /**
 * @file	: XmlElement.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/09 12:04:59
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _XMLELEMENT_H
#define _XMLELEMENT_H
#include "XmlSerialize_Global.h"
class TiXmlElement;
/**
 * @file	: XmlElement.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/09 12:05:12
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */

#include <vector>

/*!
 * @class	: CXmlElement
 * @brief	: 
 * @author	: liuk
 * @date	: 2017/04/09 12:05
 */
class XMLSERILIZE_EXPORT CXmlElement
{
public:
	CXmlElement(const std::string& strName = "");
	~CXmlElement();
	
public:

	/**
	 * @fn		: FromTiXmlElement
	 * @brief	: ��tixml�м���ת��
	 * @access	: public 
	 * @param	: TiXmlElement * pTiElement
	 * @return	: void
	 */
	void FromTiXmlElement(TiXmlElement* pTiElement);

	/**
	 * @fn		: SetName
	 * @brief	: ���ýڵ�����
	 * @access	: public 
	 * @param	: const std::string & strName
	 * @return	: void
	 */
	void SetName(const std::string& strValue);

	/**
	 * @fn		: GetName
	 * @brief	: ��ȡ�ڵ�����
	 * @access	: public 
	 * @return	: std::string
	 */
	std::string GetName();

	/**
	 * @fn		: SetValue
	 * @brief	: ���ýڵ�ֵ
	 * @access	: public 
	 * @param	: const int nValue
	 * @return	: void
	 */
	void SetValue(const int nValue);

	/**
	* @fn		: SetValue
	* @brief	: ���ýڵ�ֵ
	* @access	: public
	* @param	: const double dValue
	* @return	: void
	*/
	void SetValue(const double dValue);

	/**
	* @fn		: SetValue
	* @brief	: ���ýڵ�ֵ
	* @access	: public
	* @param	: const float fValue
	* @return	: void
	*/
	void SetValue(const float fValue);

	/**
	* @fn		: SetValue
	* @brief	: ���ýڵ�ֵ
	* @access	: public
	* @param	: const std::string & strText
	* @return	: void
	*/
	void SetValue(const std::string& strText);

	/**
	 * @fn		: GetValue
	 * @brief	: CXmlElement::GetValue
	 * @access	: public 
	 * @param	: [out] int & nValue
	 * @return	: bool
	 */
	bool GetValue(int& nValue);

	/**
	 * @fn		: GetValue
	 * @brief	: CXmlElement::GetValue
	 * @access	: public 
	 * @param	: [out] double & dValue
	 * @return	: bool
	 */
	bool GetValue(double& dValue);

	/**
	 * @fn		: GetValue
	 * @brief	: CXmlElement::GetValue
	 * @access	: public 
	 * @param	: [out] float & fValue
	 * @return	: bool
	 */
	bool GetValue(float& fValue);

	/**
	 * @fn		: GetValue
	 * @brief	: CXmlElement::GetValue
	 * @access	: public 
	 * @param	: [out] std::string & strValue
	 * @return	: bool
	 */
	bool GetValue(std::string& strValue);


	/**
	 * @fn		: SetAttribute
	 * @brief	: ����һ������
	 * @access	: public 
	 * @param	: const std::string & strName
	 * @param	: const std::string & strValue
	 * @return	: void
	 */
	void SetAttribute(const std::string& strName, const std::string& strValue);

	/**
	* @fn		: SetAttribute
	* @brief	: ����һ������
	* @access	: public
	* @param	: const std::string & strName ������
	* @param	:  int nValue ֵ
	* @return	: void
	*/
	void SetAttribute(const std::string& strName, int nValue);

	/**
	* @fn		: SetAttribute
	* @brief	: ����һ������
	* @access	: public
	* @param	: const std::string & strName
	* @param	: double dValue
	* @return	: void
	*/
	void SetAttribute(const std::string& strName, double dValue);

	/**
	* @fn		: SetAttribute
	* @brief	: ����һ������
	* @access	: public
	* @param	: const std::string & strName
	* @param	: float fValue
	* @return	: void
	*/
	void SetAttribute(const std::string& strName, float fValue);

	/**
	 * @fn		: GetAttribute
	 * @brief	: ��ȡһ������
	 * @access	: public 
	 * @param	: const std::string & strName
	 * @param	: [out] std::string & strValue
	 * @return	: bool
	 */
	bool GetAttribute(const std::string& strName, std::string& strValue);

	/**
	* @fn		: GetAttribute
	* @brief	: ��ȡһ������
	* @access	: public
	* @param	: const std::string & strName
	* @param	: [out] int& nValue
	* @return	: bool
	*/
	bool GetAttribute(const std::string& strName, int& nValue);

	/**
	* @fn		: GetAttribute
	* @brief	: ��ȡһ������
	* @access	: public
	* @param	: const std::string & strName
	* @param	: [out] double& dValue
	* @return	: bool
	*/
	bool GetAttribute(const std::string& strName, double& dValue);

	/**
	* @fn		: GetAttribute
	* @brief	: ��ȡһ������
	* @access	: public
	* @param	: const std::string & strName
	* @param	: [out] float& fValue
	* @return	: bool
	*/
	bool GetAttribute(const std::string& strName, float& fValue);

	/**
	 * @fn		: NextChildElement
	 * @brief	: ��ȡ��һ���ӽڵ�
	 * @access	: public 
	 * @return	: CXmlElement*
	 */
	CXmlElement* NextChildElement();
	
	/**
	 * @fn		: FirstChildElement
	 * @brief	: ��ȡ��һ���ӽڵ㣬�����α�����ͷ
	 * @access	: public 
	 * @return	: CXmlElement*
	 */
	CXmlElement* FirstChildElement();


	/**
	 * @fn		: PushChild
	 * @brief	: ����β���ӽڵ�
	 * @access	: public 
	 * @param	: CXmlElement * pChild
	 * @return	: void
	 */
	void PushChild(CXmlElement* pChild);

	/**
	 * @fn		: IsEnd
	 * @brief	: �Ƿ��Ѿ����������һ���ڵ�
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsEnd();

	/**
	 * @fn		: CurrentElement
	 * @brief	: ��ȡ��ǰ�ڵ������tixml����
	 * @access	: public 
	 * @return	: TiXmlElement*
	 */
	TiXmlElement* CurrentElement();

	/**
	 * @fn		: Clear
	 * @brief	: ����ڵ�
	 * @access	: public 
	 * @return	: void
	 */
	void Clear();

	/**
	 * @fn		: ChildCount
	 * @brief	: ��ȡ�ֳ�Ա����
	 * @access	: public 
	 * @return	: int
	 */
	int ChildCount();


private:
	/// �ӽڵ�
	std::vector<CXmlElement*> m_vecChildNode;
	// ��ǰ�ӽڵ�
	int m_nCursor;

	TiXmlElement* m_pXmlNode;

};

#endif //_XMLELEMENT_H