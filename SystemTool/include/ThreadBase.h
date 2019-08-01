/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: ThreadBase.h
 * @brief	: �߳̿�������Ͷ����ļ�
 * @author	: liuk
 * @date	: 2016/12/24 10:49:20
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _THREADBASE_H
#define  _THREADBASE_H
#include "TaskLib_Global.h"
#include "TypeDef.h"
#ifdef WIN32
#include <windows.h>
typedef uintptr_t THREADID;
typedef HANDLE HEVENT;
typedef HANDLE HSEMAPHORE;
typedef CRITICAL_SECTION HMUTEX;
#elif linux
#include <pthread.h>
#include <semaphore.h>
typedef pthread_t THREADID;
typedef pthread_cond_t HEVENT;
typedef sem_t HSEMAPHORE;
typedef pthread_mutex_t HMUTEX;
typedef pthread_rwlock_t HRWMUTEX;
#endif

#ifndef INFINITE
#define  INFINITE 0xFFFFFFFF
#endif // !INFINITEINFINITE

enum E_WAIT_STATUS
{
	E_WAIT_ABANDONED = 0x00000080L, // �������� 
	E_WAIT_SIGNAL = 0x00000000L,	// �ȵ����ź�
	E_WAIT_TIMEOUT = 0x00000102L,	// ��ʱ
	E_WAIT_FAILED = 0xFFFFFFFFL,	// ����
};

#endif
