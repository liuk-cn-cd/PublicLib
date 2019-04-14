/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/

/**
 * @file	: ThreadLock.h
 * @brief	: �߳���������
 * @author	: liuk
 * @date	: 2016/12/24 14:15:33
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _THREADLOCK_H
#define _THREADLOCK_H
#include "ThreadBase.h"

class CSyncBase;

#define GUARD(ClassName, ObjName) \
	CThreadLock lock##ClassName##ObjName((ObjName));


/*!
 * @class	: CThreadLock
 * @brief	: �߳����࣬����ʱ����������ʱ�ͷ�
 * @author	: liuk
 * @date	: 2016/12/24 14:19
 */
class TASKLIB_EXPORT CThreadLock
{
public:
	CThreadLock(CSyncBase& syncObj);
	~CThreadLock();
private:
	CSyncBase& m_syncObj;
};

#endif // !_THREADLOCK_H