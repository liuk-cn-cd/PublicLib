/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: communication_global.h
 * @brief	: ͨ�ſ⵼������
 * @author	: liuk
 * @date	: 2017/04/30 10:37:46
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef COMMUNICATION_GLOBAL_H
#define COMMUNICATION_GLOBAL_H

#ifdef WIN32

#ifdef COMMUNICATION_LIB
#define COMMUNICATION_EXPORT _declspec(dllexport)
#else
#define COMMUNICATION_EXPORT _declspec(dllimport)
#endif // COMMUNICATION_LIB

#elif LINUX
#define COMMUNICATION_EXPORT
#endif


#endif // COMMUNICATION_GLOBAL_H
