/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: UdpMulticast.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/06 10:10:09
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _UDPMULTICAST_H__
#define _UDPMULTICAST_H__
#include "UdpSocket.h"
class CUdpMulticast :
	public CUdpSocket
{
public:
	CUdpMulticast();
	~CUdpMulticast();
};

#endif // _UDPMULTICAST_H__