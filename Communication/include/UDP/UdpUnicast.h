/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: UdpUnicast.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/06 10:12:11
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _UDPUNICAST_H__
#define _UDPUNICAST_H__
#include "UdpSocket.h"
class CUdpUnicast :
	public CUdpSocket
{
public:
	CUdpUnicast();
	~CUdpUnicast();
};

#endif // _UDPUNICAST_H__