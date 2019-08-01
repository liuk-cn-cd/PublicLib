/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/

/**
 * @file	: Thread.h
 * @brief	: �߳��������ļ�
 * @author	: liuk
 * @date	: 2016/12/18 15:57:28
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _THREAD_H
#define  _THRED_H
#include "ThreadBase.h"
#include "ThreadEvent.h"
class CThreadPrivate;
/*!
 * @class	: CThread
 * @brief	: �߳��࣬���飬ʹ��ʱ�̳д���
 * @author	: liuk
 * @date	: 2016/12/18 15:58
 */
class TASKLIB_EXPORT CThread
{
public:
	CThread();
	virtual ~CThread();
public:
	/**
	 * @fn		: Start
	 * @brief	: �߳̿�ʼ
	 * @access	: public 
	 * @return	: void
	 */
	bool Active();
#ifdef WIN32
	/**
	 * @fn		: Pause
	 * @brief	: ��ͣ�߳�
	 * @access	: public 
	 * @return	: �ɹ�����true
	 */
	bool Pause();
#endif
	void Quit();
#ifdef WIN32
	/**
	 * @fn		: Continue
	 * @brief	: ������ͣ���߳�
	 * @access	: public 
	 * @return	: void
	 */
	void Continue();
#endif
	/**
	 * @fn		: Signal
	 * @brief	: �����ź�
	 * @access	: public 
	 * @return	: void
	 */
	void Signal();

	/**
	 * @fn		: Wait
	 * @brief	: CThread::Wait
	 * @access	: public 
	 * @param	: unsigned int nMillisecond
	 * @param	: nMillisecond ���ȴ�nMillisecond���룬δ�ȵ��򷵻أ������ΪINFINITE��һֱ����
	 * @return	: E_WAIT_ABANDONED, ��������
	 *			  E_WAIT_SIGNAL, �ȵ����ź�
	 *			  E_WAIT_TIMEOUT,��ʱ
	 *			  E_WAIT_FAILED, ����
	 */
    E_WAIT_STATUS Wait(uint32 nMillisecond = INFINITE);

	/**
	 * @fn		: Terminate
	 * @brief	: �ж��߳�
	 * @access	: public 
	 * @param	: unsigned int nExitCode�� �˳���
	 * @return	: void
	 */
    void Terminate(uint32 nExitCode = -1);
#ifdef WIN32
	/**
	 * @fn		: IsPause
	 * @brief	: �߳��Ƿ���ͣ
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsPause() const;
#endif
	/**
	 * @fn		: IsQuit
	 * @brief	: �߳��Ƿ����˳�
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsQuit() const;

	/**
	 * @fn		: IsRunning
	 * @brief	: �߳��Ƿ���������
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsRunning() const;
public:
	/**
	 * @fn		: run
	 * @brief	: �߳��߼���������̳д˺���
	 * @access	: virtual public 
	 * @return	: void
	 */
	virtual void run() = 0;
private:
#ifdef WIN32
	static unsigned __stdcall StartRun(CThread * thread_ptr);
#elif linux
    static void* StartRun(CThread* thread_ptr);
#endif
private:
    CThreadPrivate* _data_;
};

#endif
