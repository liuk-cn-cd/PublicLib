/**********************************************************************
* @�ر�����
*     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
* ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
*     ������������ϵ���ߡ�
* @�ر���������
********************************************************************/
/**
* @file	: TaskLib_Global.h
* @brief	: �߳̿⵼��ͷ�ļ�
* @author	: liuk
* @date	: 2016/12/18 15:27:01
* @version : 1.0.0.0
* @contact	: liukangx@hotmail.com
*
*/
#ifndef _TASKLIB_GLOBAL_H
#define _TASKLIB_GLOBAL_H

#ifdef WIN32

#ifdef TASKLIB_LIB
#define TASKLIB_EXPORT _declspec(dllexport)
#else
#define TASKLIB_EXPORT _declspec(dllimport)
#endif // TASKLIB_LIB

#elif LINUX
#define TASKLIB_EXPORT
#endif

#endif