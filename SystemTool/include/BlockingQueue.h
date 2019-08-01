/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: BlockingQueue.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/07 14:15:05
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _BLOCKINGQUEUE_H__
#define _BLOCKINGQUEUE_H__
#include <queue>
#include <utility>
#include "ThreadSemaphore.h"
#include "ThreadMutex.h"
#include "ThreadLock.h"

template<typename T> class CBlockingQueue
{
public:
#ifdef WIN32
	CBlockingQueue():m_taskSemaphore(0, 1024 * 1024 * 1024 / sizeof(T)){}
#elif linux
    CBlockingQueue():m_taskSemaphore(0){}
#endif
	~CBlockingQueue(){}
	/**
	* @fn		: Dequeue
	* @brief	:
	* @access	: public
	* @return	: T
	*/
	/**
	 * @fn		: Dequeue
	 * @brief	:  ���ӣ������ǰû��������
	 * @access	: public 
	 * @param	: int nMillis �ȴ�ʱ�䣬 INFINITE��һֱ����
	 * @param	: bool* bGet  �Ƿ�ȵ�����
	 * @return	: T
	 */
	inline T Dequeue(bool* bGet = nullptr, int nMillis = INFINITE);

	/**
	* @fn		: Enqueue
	* @brief	: ������ӣ�����ﵽ���������(65535)������
	* @access	: public
	* @param	: const T & dataObj ���е�����
	* @return	: void
	*/
	inline void Enqueue(const T& dataObj);

	/**
	 * @fn		: Size
	 * @brief	: ��ȡ���г���
	 * @access	: public 
	 * @return	: int ���г���
	 */
	inline int Size();
private:
	// �����ź���
	CThreadSemaphore m_taskSemaphore;
	// �������
	std::queue<T > m_queData;

	CThreadMutex m_lockData;
};

template<typename T>
int CBlockingQueue<T>::Size()
{
	return m_queData.size();
}

template<typename T>
void CBlockingQueue<T>::Enqueue(const T& dataObj)
{
	GUARD(CThreadMutex, m_lockData)
	m_queData.push(dataObj);
	m_taskSemaphore.Release();
}

template<typename T>
T CBlockingQueue<T>::Dequeue(bool* bGet, int nMillis)
{
    if (m_taskSemaphore.Acquire(nMillis) != E_WAIT_SIGNAL || m_queData.empty())
	{
		if(nullptr != bGet)
			*bGet = false;
        return T();
	}
	if (nullptr != bGet)
		*bGet = true;
	GUARD(CThreadMutex, m_lockData)
	T objRet = m_queData.front();
	m_queData.pop();
	return objRet;
}

#endif // _BLOCKINGQUEUE_H__
