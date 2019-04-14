/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: BinarySerializeObject.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/08/19 11:30:30
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "BinarySerializeObject.h"
#include "BinaryFunc.h"



CBinarySerializeObject::CBinarySerializeObject()
	: m_bStore(false)
	, m_nSerSeek(0)
	, m_nBufCnt(0)
	, m_pBuffer(0)
{
}


CBinarySerializeObject::~CBinarySerializeObject()
{
}

int CBinarySerializeObject::Serialize()
{
	return m_nSerSeek;
}

int CBinarySerializeObject::GetByteNum()
{
	return m_nSerSeek;
}

void CBinarySerializeObject::Serialize_Begin()
{
	m_nSerSeek = 0;
}

void CBinarySerializeObject::Serialize_End()
{
	m_nSerSeek = 0;
}

void CBinarySerializeObject::Serialize_Var(char & chVal)
{
	m_nSerSeek += SerializeVar(m_pBuffer + m_nSerSeek, chVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Var(unsigned char & ucVal)
{
	m_nSerSeek += SerializeVar(m_pBuffer + m_nSerSeek, ucVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Var(short & sVal)
{
	m_nSerSeek += SerializeVar(m_pBuffer + m_nSerSeek, sVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Var(unsigned short & usVal)
{
	m_nSerSeek += SerializeVar(m_pBuffer + m_nSerSeek, usVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Var(int & nVal)
{
	m_nSerSeek += SerializeVar(m_pBuffer + m_nSerSeek, nVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Var(unsigned int & unVal)
{
	m_nSerSeek += SerializeVar(m_pBuffer + m_nSerSeek, unVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Var(float & fVal)
{
	m_nSerSeek += SerializeVar(m_pBuffer + m_nSerSeek, fVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Var(double & dVal)
{
	m_nSerSeek += SerializeVar(m_pBuffer + m_nSerSeek, dVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Var(std::string & strVal)
{
	m_nSerSeek += SerializeStrVar(m_pBuffer, strVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Arr(char* pVal, int nSize)
{
	m_nSerSeek += SerializeVarArr(m_pBuffer + m_nSerSeek, pVal, nSize, m_bStore);
}

void CBinarySerializeObject::Serialize_Arr(unsigned char* pVal, int nSize)
{
	m_nSerSeek += SerializeVarArr(m_pBuffer + m_nSerSeek, pVal, nSize, m_bStore);
}

void CBinarySerializeObject::Serialize_Arr(short* pVal, int nSize)
{
	m_nSerSeek += SerializeVarArr(m_pBuffer + m_nSerSeek, pVal, nSize, m_bStore);
}

void CBinarySerializeObject::Serialize_Arr(unsigned short* pVal, int nSize)
{
	m_nSerSeek += SerializeVarArr(m_pBuffer + m_nSerSeek, pVal, nSize, m_bStore);
}

void CBinarySerializeObject::Serialize_Arr(int* pVal, int nSize)
{
	m_nSerSeek += SerializeVarArr(m_pBuffer + m_nSerSeek, pVal, nSize, m_bStore);
}

void CBinarySerializeObject::Serialize_Arr(unsigned int* pVal, int nSize)
{
	m_nSerSeek += SerializeVarArr(m_pBuffer + m_nSerSeek, pVal, nSize, m_bStore);
}

void CBinarySerializeObject::Serialize_Arr(float* pVal, int nSize)
{
	m_nSerSeek += SerializeVarArr(m_pBuffer + m_nSerSeek, pVal, nSize, m_bStore);
}

void CBinarySerializeObject::Serialize_Arr(double* pVal, int nSize)
{
	m_nSerSeek += SerializeVarArr(m_pBuffer + m_nSerSeek, pVal, nSize, m_bStore);
}

void CBinarySerializeObject::Serialize_Arr(std::string* pVal, int nSize)
{
	m_nSerSeek += SerializeStrArr(m_pBuffer + m_nSerSeek, pVal, nSize, m_bStore);
}

void CBinarySerializeObject::Serialize_Stl(std::vector<char>& stlVal)
{
	m_nSerSeek += SerializeVarStl(m_pBuffer + m_nSerSeek,stlVal, m_bStore );
}

void CBinarySerializeObject::Serialize_Stl(std::vector<unsigned char>& stlVal)
{
	m_nSerSeek += SerializeVarStl(m_pBuffer + m_nSerSeek, stlVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Stl(std::vector<short>& stlVal)
{
	m_nSerSeek += SerializeVarStl(m_pBuffer + m_nSerSeek, stlVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Stl(std::vector<unsigned short>& stlVal)
{
	m_nSerSeek += SerializeVarStl(m_pBuffer + m_nSerSeek, stlVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Stl(std::vector<int>& stlVal)
{
	m_nSerSeek += SerializeVarStl(m_pBuffer + m_nSerSeek, stlVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Stl(std::vector<unsigned int>& stlVal)
{
	m_nSerSeek += SerializeVarStl(m_pBuffer + m_nSerSeek, stlVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Stl(std::vector<float>& stlVal)
{
	m_nSerSeek += SerializeVarStl(m_pBuffer + m_nSerSeek, stlVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Stl(std::vector<double>& stlVal)
{
	m_nSerSeek += SerializeVarStl(m_pBuffer + m_nSerSeek, stlVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Stl(std::vector<std::string>& stlVal)
{
	m_nSerSeek += SerializeStrStl(m_pBuffer + m_nSerSeek, stlVal, m_bStore);
}

void CBinarySerializeObject::Serialize_Object(CBinarySerializeObject & objVal)
{
	objVal.Store(m_pBuffer + m_nSerSeek, m_nBufCnt - m_nSerSeek, m_bStore);
	m_nSerSeek += objVal.Serialize();
}

void CBinarySerializeObject::Serialize_Object_Arr(CBinarySerializeObject* pVal, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		CBinarySerializeObject& objVal = pVal[i];
		objVal.Store(m_pBuffer + m_nSerSeek, m_nBufCnt - m_nSerSeek, m_bStore);
		m_nSerSeek += objVal.Serialize();
	}
}

void CBinarySerializeObject::Serialize_Object_Stl(std::vector<CBinarySerializeObject>& stlVal)
{
	if (m_bStore)
	{
		int nSize = stlVal.size();
		m_nSerSeek += SerializeVar(m_pBuffer + m_nSerSeek, nSize, m_bStore);
		for (int i = 0; i < nSize; ++i)
		{
			CBinarySerializeObject& objVal = stlVal[i];
			objVal.Store(m_pBuffer + m_nSerSeek, m_nBufCnt - m_nSerSeek, m_bStore);
			m_nSerSeek += objVal.Serialize();
		}
		
	}
	else
	{
		int nSize = 0;
		m_nSerSeek += SerializeVar(m_pBuffer + m_nSerSeek, nSize, m_bStore);
		for (int i = 0; i < nSize; ++i)
		{
			CBinarySerializeObject objVal;
			objVal.Store(m_pBuffer + m_nSerSeek, m_nBufCnt - m_nSerSeek, m_bStore);
			m_nSerSeek += objVal.Serialize();
			stlVal.push_back(objVal);
		}
	}
}

void CBinarySerializeObject::Store(unsigned char* pBuf, int nSize, bool bStore)
{
	m_pBuffer = pBuf;
	m_nBufCnt = nSize;
	m_bStore = bStore;
}
