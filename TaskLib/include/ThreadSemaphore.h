/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: ThreadSemaphore.h
 * @brief	:
 * @author	: liuk
 * @date	: 2016/12/23 20:58:55
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _THREADSEMAPHORE_H
#define _THREADSEMAPHORE_H
#include "SyncBase.h"
/*!
 * @class	: CThreadSemaphore
 * @brief	: �߳��ź���
 * @author	: liuk
 * @date	: 2016/12/23 20:59
 */
class TASKLIB_EXPORT CThreadSemaphore : public CSyncBase
{
public:
	CThreadSemaphore(int nInitCount = 1, int nMaxCount = 1);
	~CThreadSemaphore();
#ifdef LINUX
	/**
	 * @fn		: Acquire
	 * @brief	: ʹ���ź���
	 * @access	: public 
	 * @param	: nAcquireCount��ʹ�õ��ź������������ź����������������˲�����windows����Ч��windowsֻ��һ��ʹ��һ���ź���
	 * @return	: void
	 */
	void Acquire(int nAcquireCount);
#endif

	/**
	 * @fn		: Acquire
	 * @brief	: �ź���ʹ��һ����û����Դ������
	 * @access	: public 
	 * @return	: void
	 */
	virtual E_WAIT_STATUS Acquire(int nMilliseconds = INFINITE);

	/**
	 * @fn		: Release
	 * @brief	: �ͷ��ź���
	 * @access	: public 
	 * @param	: nReleaseCount���ͷŵ��ź��������������������������
	 * @return	: void
	 */
	void Release(int nReleaseCount);

	/**
	 * @fn		: Release
	 * @brief	: �ͷ�һ���ź�������Դ����������
	 * @access	: public 
	 * @return	: void
	 */
	virtual void Release();
private:
	HSEMAPHORE m_hSemaphore;
};

#endif // !_THREADSEMAPHORE_H