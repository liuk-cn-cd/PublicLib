/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/

/**
 * @file	: Task.h
 * @brief	: �����������ļ�
 * @author	: liuk
 * @date	: 2016/12/18 15:26:50
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _TASK_H
#define  _TASK_H

#include "Thread.h"
class CTask;
/*!
 * @class	: CTaskUser
 * @brief	: ����۲��ߣ�ʵ�������ִ�з�����
 * @author	: liuk
 * @date	: 2016/12/18 15:27
 */
class TASKLIB_EXPORT CTaskUser
{
public:
	CTaskUser() {}
	virtual ~CTaskUser() {}
public:
	/**
	 * @fn		: OnRunTask
	 * @brief	: ����ʵ�ִ˺�������ʵ�ϵ�������
	 * @access	: virtual public 
	 * @return	: void
	 */
	virtual void OnRunTask(CTask* pTask) = 0;
};

/*!
 * @class	: CTask
 * @brief	: �����࣬����һ�������������߳�
 * @author	: liuk
 * @date	: 2016/12/18 15:29
 */
class TASKLIB_EXPORT CTask : public CThread
{
public:
	CTask();
	~CTask();
public:
	/**
	 * @fn		: Attach
	 * @brief	: ������۲���
	 * @access	: public 
	 * @param	: CTaskUser * pUser
	 * @return	: void
	 */
	void Attach(CTaskUser* pUser);
protected:
	/**
	 * @fn		: run
	 * @brief	: ����ִ���߼�
	 * @access	: virtual protected 
	 * @return	: void
	 */
	virtual void run();
private:
	CTaskUser* m_pUser;
};
#endif // !_TASK_H


