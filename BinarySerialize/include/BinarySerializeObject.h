/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: BinarySerializeObject.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/08/19 11:30:21
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef BinarySerializeObject_h__
#define BinarySerializeObject_h__
#include "binaryserialize_global.h"
#include <string>
#include <vector>
/*!
* @class	: CBinarySerialize
* @brief	: ���������л�����
* @author	: liuk
* @date	: 2017/08/19 9:40
*/
class BINARYSERIALIZE_EXPORT CBinarySerializeObject
{
public:
	CBinarySerializeObject();
	virtual ~CBinarySerializeObject();
protected:
	/**
	* @fn		: CBinarySerializeObject::Serialize
	* @brief	: ���л�ʵ�֣�����������д�˺���
	* @access	: virtual protected
	* @return	: int ���л����ڴ��С
	*/
	virtual int Serialize();

	/**
	* @fn		: CBinarySerializeObject::GetByteNum
	* @brief	:
	* @access	: virtual protected
	* @return	: int ���л���С
	*/
	virtual int GetByteNum();

protected:
	/**
	* @fn		: CBinarySerializeObject::Serialize_Begin
	* @brief	: ��ʼ���л�����Serialize��ʵ���е���
	* @access	: protected
	* @return	: void
	*/
	void Serialize_Begin();

	/**
	* @fn		: CBinarySerializeObject::Serialize_End
	* @brief	: �������л�����Serialize��ʵ���е���
	* @access	: protected
	* @return	: void
	*/
	void Serialize_End();

	void Serialize_Var(char& chVal);

	void Serialize_Var(unsigned char& ucVal);

	void Serialize_Var(short& sVal);

	void Serialize_Var(unsigned short& usVal);

	void Serialize_Var(int& nVal);

	void Serialize_Var(unsigned int& unVal);

	void Serialize_Var(float& fVal);

	void Serialize_Var(double& dVal);

	void Serialize_Var(std::string& strVal);

	void Serialize_Arr(char* pVal, int nSize);

	void Serialize_Arr(unsigned char* pVal, int nSize);

	void Serialize_Arr(short* pVal, int nSize);

	void Serialize_Arr(unsigned short* pVal, int nSize);

	void Serialize_Arr(int* pVal, int nSize);

	void Serialize_Arr(unsigned int* pVal, int nSize);

	void Serialize_Arr(float* pVal, int nSize);

	void Serialize_Arr(double* pVal, int nSize);

	void Serialize_Arr(std::string* pVal, int nSize);

	void Serialize_Stl(std::vector<char>& stlVal);

	void Serialize_Stl(std::vector<unsigned char>& stlVal);

	void Serialize_Stl(std::vector<short>& stlVal);

	void Serialize_Stl(std::vector<unsigned short>& stlVal);

	void Serialize_Stl(std::vector<int>& stlVal);

	void Serialize_Stl(std::vector<unsigned int>& stlVal);

	void Serialize_Stl(std::vector<float>& stlVal);

	void Serialize_Stl(std::vector<double>& stlVal);

	void Serialize_Stl(std::vector<std::string>& stlVal);

	void Serialize_Object(CBinarySerializeObject& chVal);

	void Serialize_Object_Arr(CBinarySerializeObject* pVal, int nSize);

	void Serialize_Object_Stl(std::vector<CBinarySerializeObject>& stlVal);

private:
	void Store(unsigned char* pBuf, int nSize, bool bStore);

private:
	// ���л�ƫ������������¼��ǰ���л���ƫ�������������������з��ʣ�Ҳ�������л�
	int m_nSerSeek;
	// ���л�����������¼��ǰ���л��ķ��򣬲������������з��ʣ�Ҳ�������л�
	bool m_bStore;

	// ���л��ڴ�λ��
	unsigned char* m_pBuffer;
	// ���л��ڴ��С
	int m_nBufCnt;
};


#endif // BinarySerializeObject_h__