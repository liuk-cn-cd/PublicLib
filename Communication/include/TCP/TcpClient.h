/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: TcpClient.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/06 10:03:58
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _TCPCLIENT_H__
#define _TCPCLIENT_H__
#include "Thread.h"
#include <string>
#include "CommuDefine.h"


/*!
 * @class	: CTcpClient
 * @brief	: TCP�ͻ���
 * @author	: liuk
 * @date	: 2018/04/06 15:44
 */
class CTcpClient : public CThread
{
public:
	CTcpClient();
	~CTcpClient();
public:
	/**
	 * @fn		: ConnectServer
	 * @brief	: ���ӷ�����
	 * @access	: public 
	 * @param	: [in] const std::string & strServerIp ������IP
	 * @param	: [in] unsigned short usPort �������˿�
	 * @return	: bool �ɹ�����true��ʧ�ܷ���false
	 */
	bool ConnectServer(const std::string& strServerIp, unsigned short usPort);

	/**
	 * @fn		: DisConnect
	 * @brief	: �Ͽ��������������
	 * @access	: public 
	 * @return	: bool
	 */
	bool DisConnect();

	/**
	 * @fn		: IsConnectServer
	 * @brief	: �Ƿ����ӵ�������
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsConnectServer();

	/**
	 * @fn		: SendData2Server
	 * @brief	: �������ݵ�������
	 * @access	: public 
	 * @param	: [in] const char * pBuf ���ݵ�ַ
	 * @param	: [in] unsigned int nBufLen ���ݳ���
	 * @return	: bool
	 */
	bool SendData2Server(const char* pBuf, unsigned int nBufLen);
public:
	virtual void run();
protected:
	/**
	 * @fn		: SetSendRecvBufferSize
	 * @brief	: �����շ�buffer��С
	 * @access	: protected 
	 * @param	: int nSendSize
	 * @param	: int nRecvSize
	 * @return	: bool
	 */
	bool SetSendRecvBufferSize(int nSendSize, int nRecvSize);
private:
	SocketHandle m_hSocket;

	char* m_pRecvBuffer;

	std::string m_strIp;
	unsigned short m_usPort;

	bool m_bConnected;
};
#endif // _TCPCLIENT_H__