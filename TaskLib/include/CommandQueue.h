/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: CommandQueue.h
 * @brief	: ������������ļ�
 * @author	: liuk
 * @date	: 2016/12/24 15:27:01
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _COMMANDQUEUE_H
#define _COMMANDQUEUE_H
#include <queue>
#include <utility>
#include "ThreadSemaphore.h"
#include "ThreadMutex.h"
#include "DataObject.h"
#include "MsgKey.h"
#include "ThreadLock.h"

typedef std::pair<CDataObject, CMsgKey> CCommand;

/*!
 * @class	: CCommandQueue
 * @brief	: �������
 * @author	: liuk
 * @date	: 2016/12/24 15:27
 */
class TASKLIB_EXPORT CCommandQueue
{
public:
	CCommandQueue();
	~CCommandQueue();

	/**
	 * @fn		: DequeueCommand
	 * @brief	: ������ӣ������ǰû��������
	 * @access	: public 
	 * @param	: CDataObject & dataObj
	 * @param	: const CMsgKey &
	 * @return	: void
	 */
	void DequeueCommand(CDataObject& dataObj, CMsgKey& msgKey);

	/**
	 * @fn		: EnqueueCommand
	 * @brief	: ������ӣ�����ﵽ���������(65535)������
	 * @access	: public 
	 * @param	: const CDataObject & dataObj
	 * @return	: void
	 */
	void EnqueueCommand(const CDataObject& dataObj, const CMsgKey& msgKey);
private:
	// �����ź���
	CThreadSemaphore m_taskSemaphore;
	// �������
	std::queue<CCommand > m_queCmd;

	CThreadMutex m_queCommandLock;
};

#endif // _COMMANDQUEUE_H