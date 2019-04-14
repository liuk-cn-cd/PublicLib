/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/

/**
 * @file	: CommandExecutor.h
 * @brief	: ����ִ��������
 * @author	: liuk
 * @date	: 2016/12/24 15:11:37
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _COMMANDEXECUTOR_H
#define _COMMANDEXECUTOR_H
#include "Task.h"
#include "CommandQueue.h"
#include "ThreadLock.h"
#include "ThreadMutex.h"
class CCommandExecutor;

/*!
 * @class	: CCommandExecutorUser
 * @brief	: ����ִ�����۲���
 * @author	: liuk
 * @date	: 2016/12/24 15:15
 */
class TASKLIB_EXPORT CCommandExecutorUser
{
public:
	CCommandExecutorUser() {}
	virtual ~CCommandExecutorUser() {}
public:
	/**
	 * @fn		: OnCommadExecute
	 * @brief	: �������������ʵ�ִ˺�������ʵ������
	 * @access	: virtual private 
	 * @param	: CCommandExecutor * pCmdExecutor
	 * @return	: bool
	 */
	virtual bool OnCommadExecute(CCommandExecutor* pCmdExecutor, const CDataObject& dataObj, const CMsgKey& msgKey) = 0;
};

/*!
 * @class	: CCommandExecutor
 * @brief	: ����ִ����
 * @author	: liuk
 * @date	: 2016/12/24 15:15
 */
class TASKLIB_EXPORT CCommandExecutor :
	public CTaskUser
{
public:
	CCommandExecutor();
	~CCommandExecutor();
public:
	/**
	* @fn		: OnRunTask
	* @brief	: ����ʵ�ִ˺�������ʵ�ϵ�������
	* @access	: virtual public
	* @return	: void
	*/
	virtual void OnRunTask(CTask* pTask);

	/**
	 * @fn		: PutCmd
	 * @brief	: ���һ������
	 * @access	: public 
	 * @param	: const CDataObject &
	 * @param	: const CMsgKey & msgKey
	 * @return	: void
	 */
	void PutCmd(const CDataObject&, const CMsgKey& msgKey);

	void Attach(CCommandExecutorUser* pUser);
private:
	CTask m_cmdTask;
	CCommandExecutorUser* m_pUser;
	CCommandQueue m_queCommand;
};

#endif // !_COMMANDEXECUTOR_H