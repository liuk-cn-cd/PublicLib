/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
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
	 * @brief	:  出队，如果当前没有则阻塞
	 * @access	: public 
	 * @param	: int nMillis 等待时间， INFINITE则一直阻塞
	 * @param	: bool* bGet  是否等到数据
	 * @return	: T
	 */
	inline T Dequeue(bool* bGet = nullptr, int nMillis = INFINITE);

	/**
	* @fn		: Enqueue
	* @brief	: 命令入队，如果达到最大命令数(65535)则阻塞
	* @access	: public
	* @param	: const T & dataObj 入列的数据
	* @return	: void
	*/
	inline void Enqueue(const T& dataObj);

	/**
	 * @fn		: Size
	 * @brief	: 获取队列长度
	 * @access	: public 
	 * @return	: int 队列长度
	 */
	inline int Size();
private:
	// 命令信号量
	CThreadSemaphore m_taskSemaphore;
	// 命令队列
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
