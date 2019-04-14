/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: BinaryFunc.h
 * @brief	: ���л���������
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
 * @brief	: ���л�һ���������Ͷ���
 * @access	: public
 * @param	: unsigned char * pBuf Ҫ���л����ڴ��λ��
 * @param	:  T& tVar ���л��Ķ���
 * @param	: bool bStore  ���л�����trueΪ�������л����ڴ棬falseΪ���ڴ��ж�ȡ������
 * @return	: int ���л�����
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
 * @brief	: ���л�һ����׼��������
 * @access	: public 
 * @param	: unsigned char * pBuf  Ҫ���л����ڴ��λ��
 * @param	: T * arrVar �����ַ
 * @param	: int nArrSize �����С
 * @param	: bool bStore   ���л�����trueΪ�������л����ڴ棬falseΪ���ڴ��ж�ȡ������
 * @return	: int ���л���С
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
* @brief	: ���л�һ���������ͱ�׼����
* @access	: public
* @param	: unsigned char * pBuf  Ҫ���л����ڴ��λ��
* @param	: std::vector<T>& stlVar ��������
* @param	: bool bStore   ���л�����trueΪ�������л����ڴ棬falseΪ���ڴ��ж�ȡ������
* @return	: int ���л���С
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
* @brief	: ���л�һ����׼string
* @access	: public
* @param	: unsigned char * pBuf Ҫ���л����ڴ��λ��
* @param	: std::string& strVar ���л��Ķ���
* @param	: bool bStore  ���л�����trueΪ�������л����ڴ棬falseΪ���ڴ��ж�ȡ������
* @return	: int ���л�����
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
* @brief	: ���л�һ����׼string����
* @access	: public
* @param	: unsigned char * pBuf  Ҫ���л����ڴ��λ��
* @param	: std::string * arrVar �����ַ
* @param	: int nArrSize �����С
* @param	: bool bStore   ���л�����trueΪ�������л����ڴ棬falseΪ���ڴ��ж�ȡ������
* @return	: int ���л���С
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
* @brief	: ���л�һ����׼string��׼����
* @access	: public
* @param	: unsigned char * pBuf  Ҫ���л����ڴ��λ��
* @param	: std::vector<T>& stlVar ��������
* @param	: bool bStore   ���л�����trueΪ�������л����ڴ棬falseΪ���ڴ��ж�ȡ������
* @return	: int ���л���С
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