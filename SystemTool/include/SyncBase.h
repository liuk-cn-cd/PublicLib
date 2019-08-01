/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/

/**
 * @file	: SyncBase.h
 * @brief	: �߳�ͬ����������
 * @author	: liuk
 * @date	: 2016/12/24 14:06:18
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _SYNCBASE_H
#define _SYNCBASE_H
#include "ThreadBase.h"
/*!
 * @class	: CSyncBase
 * @brief	: �߳�ͬ�������
 * @author	: liuk
 * @date	: 2016/12/24 14:06
 */
class TASKLIB_EXPORT CSyncBase
{
public:
	CSyncBase();
	virtual ~CSyncBase();
public:
    virtual E_WAIT_STATUS Acquire(uint32 nMilliseconds = INFINITE) = 0;
	virtual void Release() = 0;
};

#endif // _SYNCBASE_H
