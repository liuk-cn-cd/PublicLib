/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: BinaryFunc.h
 * @brief	: 序列化函数声明
 * @author	: liuk
 * @date	: 2017/08/19 9:51:12
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _BInARTFUNC_H
#define _BInARTFUNC_H
#include <vector>
#include <assert.h>
/**
 * @fn		: SerializeVar
 * @brief	: 序列化一个基本类型对象
 * @access	: public
 * @param	: unsigned char * pBuf 要序列化的内存的位置
 * @param	:  T& tVar 序列化的对象
 * @param	: bool bStore  序列化方向，true为对象序列化到内存，false为从内存中读取到对象
 * @return	: int 序列化长度
 */
template<typename T>
int SerializeVar(unsigned char* pBuf, T& tVar, bool bStore)
{
	assert(pBuf != NULL);
	if (bStore)
	{
		memcpy(pBuf, &tVar, sizeof(tVar));
	}
	else
	{
		memcpy(&tVar, pBuf, sizeof(tVar));
	}
	return sizeof(tVar);
}

/**
 * @fn		: SerializeVarArr
 * @brief	: 序列化一个标准类型数组
 * @access	: public 
 * @param	: unsigned char * pBuf  要序列化的内存的位置
 * @param	: T * arrVar 数组地址
 * @param	: int nArrSize 数组大小
 * @param	: bool bStore   序列化方向，true为对象序列化到内存，false为从内存中读取到对象
 * @return	: int 序列化大小
 */
template<typename T> 
int SerializeVarArr(unsigned char* pBuf, T* arrVar, int nArrSize, bool bStore)
{
	assert(pBuf != NULL);

	int nRet = 0;
	for (int i = 0; i < nArrSize; i++)
	{
		nRet += SerializeVar(pBuf + nRet, arrVar[i], bStore);
	}
	return nRet;
}

/**
* @fn		: SerializeVarArr
* @brief	: 序列化一个基本类型标准容器
* @access	: public
* @param	: unsigned char * pBuf  要序列化的内存的位置
* @param	: std::vector<T>& stlVar 容器对象
* @param	: bool bStore   序列化方向，true为对象序列化到内存，false为从内存中读取到对象
* @return	: int 序列化大小
*/
template<typename T>
int SerializeVarStl(unsigned char* pBuf, std::vector<T>& stlVar, bool bStore)
{
	assert(pBuf != NULL);

	int nRet = 0;
	if (bStore)
	{
		int nSize = stlVar.size();
		nRet += SerializeVar(pBuf + nRet, nSize, bStore);

		for (int i = 0; i < nSize; i++)
		{
			T val = stlVar[i];
			nRet += SerializeVar(pBuf + nRet, val, bStore);
		}

	}
	else
	{
		stlVar.clear();
		int nSize = 0;
		nRet += SerializeVar(pBuf + nRet, nSize, bStore);

		for (int i = 0; i < nSize; i++)
		{
			T val;
			nRet += SerializeVar(pBuf + nRet, val, bStore);
			stlVar.push_back(val);
		}
	}
	return nRet;
}

/**
* @fn		: SerializeStrVar
* @brief	: 序列化一个标准string
* @access	: public
* @param	: unsigned char * pBuf 要序列化的内存的位置
* @param	: std::string& strVar 序列化的对象
* @param	: bool bStore  序列化方向，true为对象序列化到内存，false为从内存中读取到对象
* @return	: int 序列化长度
*/
inline int SerializeStrVar(unsigned char* pBuf, std::string& strVar, bool bStore)
{
	assert(pBuf != NULL);

	if (bStore)
	{
		strcpy((char*)pBuf, strVar.c_str());
	}
	else
	{
		strVar = (char*)pBuf;
	}
	return strVar.size() + 1;
}

/**
* @fn		: SerializeStrArr
* @brief	: 序列化一个标准string数组
* @access	: public
* @param	: unsigned char * pBuf  要序列化的内存的位置
* @param	: std::string * arrVar 数组地址
* @param	: int nArrSize 数组大小
* @param	: bool bStore   序列化方向，true为对象序列化到内存，false为从内存中读取到对象
* @return	: int 序列化大小
*/
inline int SerializeStrArr(unsigned char* pBuf, std::string* arrVar, int nArrSize, bool bStore)
{
	assert(pBuf != NULL);

	int nRet = 0;
	for (int i = 0; i < nArrSize; i++)
	{
		nRet += SerializeStrVar(pBuf + nRet, arrVar[i], bStore);
	}
	return nRet;
}

/**
* @fn		: SerializeVarArr
* @brief	: 序列化一个标准string标准容器
* @access	: public
* @param	: unsigned char * pBuf  要序列化的内存的位置
* @param	: std::vector<T>& stlVar 容器对象
* @param	: bool bStore   序列化方向，true为对象序列化到内存，false为从内存中读取到对象
* @return	: int 序列化大小
*/
inline int SerializeStrStl(unsigned char* pBuf, std::vector<std::string>& stlVar, bool bStore)
{
	assert(pBuf != NULL);

	int nRet = 0;
	if (bStore)
	{
		int nSize = stlVar.size();
		nRet += SerializeVar(pBuf + nRet, nSize, bStore);

		for (int i = 0; i < nSize; i++)
		{
			std::string val = stlVar[i];
			nRet += SerializeStrVar(pBuf + nRet, val, bStore);
		}

	}
	else
	{
		stlVar.clear();
		int nSize = 0;
		nRet += SerializeVar(pBuf + nRet, nSize, bStore);

		for (int i = 0; i < nSize; i++)
		{
			std::string val;
			nRet += SerializeStrVar(pBuf + nRet, val, bStore);
			stlVar.push_back(val);
		}
	}
	return nRet;
}

#endif // _BInARTFUNC_H