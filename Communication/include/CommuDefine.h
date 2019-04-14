/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: CommuDefine.h
 * @brief	: ͨ�ö���
 * @author	: liuk
 * @date	: 2017/04/30 10:39:32
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */


#ifndef COMMUDEFINE_H__
#define COMMUDEFINE_H__
#ifdef WIN32
#include <WinSock.h>
typedef SOCKET SocketHandle;
#elif LINUX
#include <sys.socket.h>
#include <arpa/inet.h>
typedef int SocketHandle;
#endif // WIN32

#endif