/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
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
* @brief	: 二进制序列化基类
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
	* @brief	: 序列化实现，在子类中重写此函数
	* @access	: virtual protected
	* @return	: int 序列化的内存大小
	*/
	virtual int Serialize();

	/**
	* @fn		: CBinarySerializeObject::GetByteNum
	* @brief	:
	* @access	: virtual protected
	* @return	: int 序列化大小
	*/
	virtual int GetByteNum();

protected:
	/**
	* @fn		: CBinarySerializeObject::Serialize_Begin
	* @brief	: 开始序列化，在Serialize的实现中调用
	* @access	: protected
	* @return	: void
	*/
	void Serialize_Begin();

	/**
	* @fn		: CBinarySerializeObject::Serialize_End
	* @brief	: 结束序列化，在Serialize的实现中调用
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
	// 序列化偏移量，用来记录当前序列化的偏移量，不允许在子类中访问，也不被序列化
	int m_nSerSeek;
	// 序列化方向，用来记录当前序列化的方向，不允许在子类中访问，也不被序列化
	bool m_bStore;

	// 序列化内存位置
	unsigned char* m_pBuffer;
	// 序列化内存大小
	int m_nBufCnt;
};


#endif // BinarySerializeObject_h__