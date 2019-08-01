/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: MsgKey.h
 * @brief	: ��Ϣ�������ļ�
 * @author	: liuk
 * @date	: 2016/12/24 15:33:46
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef MSGKEY_H
#define MSGKEY_H
#include "ThreadBase.h"
/*!
 * @class	: CMsgKey
 * @brief	: ��Ϣ����
 * @author	: liuk
 * @date	: 2016/12/24 15:34
 */
class TASKLIB_EXPORT CMsgKey
{
public:
	CMsgKey(unsigned int nCode = 0, unsigned int nFlag1 = 0, unsigned int nFlag2 = 0, unsigned int nFlag3 = 0);
	~CMsgKey();

public:
	unsigned int GetMsgCode()const;
	unsigned int GetFlag1() const;
	unsigned int GetFlag2() const;
	unsigned int GetFlag3() const;
	CMsgKey& operator=(const CMsgKey& rObj);
private:
	unsigned int m_nMsgCode;
	unsigned int m_nFlag1;
	unsigned int m_nFlag2;
	unsigned int m_nFlag3;
};

#endif // MSGKEY_H