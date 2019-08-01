#include "MsgKey.h"

CMsgKey::CMsgKey(unsigned int nCode /*= 0*/, unsigned int nFlag1 /*= 0*/, unsigned int nFlag2 /*= 0*/, unsigned int nFlag3)
	: m_nMsgCode(nCode)
	, m_nFlag1(nFlag1)
	, m_nFlag2(nFlag2)
	, m_nFlag3(nFlag3)
{

}

CMsgKey::~CMsgKey()
{
}

unsigned int CMsgKey::GetMsgCode() const
{
	return m_nMsgCode;
}

unsigned int CMsgKey::GetFlag1() const
{
	return m_nFlag1;
}

unsigned int CMsgKey::GetFlag2() const
{
	return m_nFlag2;
}

unsigned int CMsgKey::GetFlag3() const
{
	return m_nFlag3;
}

CMsgKey& CMsgKey::operator=(const CMsgKey& rObj)
{
	m_nMsgCode	 = rObj.m_nMsgCode;
	m_nFlag1 = rObj.m_nFlag1;
	m_nFlag2 = rObj.m_nFlag2;
	m_nFlag3 = rObj.m_nFlag3;
	return *this;
}
