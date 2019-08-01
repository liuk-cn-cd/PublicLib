/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: ThreadEvent.h
 * @brief	: �߳��¼��������ļ�
 * @author	: liuk
 * @date	: 2016/12/24 10:43:40
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _THREADEVENT_H
#define  _THREADEVENT_H
#include "SyncBase.h"
/*!
 * @class	: CThreadEvent
 * @brief	: �߳��¼�
 * @author	: liuk
 * @date	: 2016/12/24 10:43
 */
class TASKLIB_EXPORT CThreadEvent : public CSyncBase
{
public:
#ifdef WIN32
	CThreadEvent(bool bInitEvent = false);
#elif linux
    CThreadEvent();
#endif
	~CThreadEvent();
	/**
	 * @fn		: Wait
	 * @brief	: �ȴ��ź�
	 * @access	: public 
	 * @param	: nMillisecond ���ȴ�nMillisecond���룬δ�ȵ��򷵻أ������ΪINFINITE��һֱ����
	 * @return	: E_WAIT_ABANDONED, �������� 
	 *			  E_WAIT_SIGNAL, �ȵ����ź�
	 *			  E_WAIT_TIMEOUT,��ʱ
	 *			  E_WAIT_FAILED, ����
	 */
    E_WAIT_STATUS Wait(uint32 nMillisecond = INFINITE);

	/**
	 * @fn		: Signal
	 * @brief	: �����źţ�Wait�����ӵ����ź��򷵻�E_WAIT_SIGNAL
	 * @access	: public 
	 * @return	: void
	 */
	void Signal();

	/**
	 * @fn		: Acquire
	 * @brief	: �ȴ��¼�
	 * @access	: virtual public 
	 * @return	: void
	 */
    virtual E_WAIT_STATUS Acquire(uint32 nMilliseconds = INFINITE);

	/**
	 * @fn		: Release
	 * @brief	: �����¼�
	 * @access	: virtual public 
	 * @return	: void
	 */
	virtual void Release();
private:
	HEVENT m_hEvent;
    HMUTEX m_hMutex;
};

#endif // _THREADEVENT_H
