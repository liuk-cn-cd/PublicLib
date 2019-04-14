/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: TcpServer.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/06 10:01:47
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _TCPSERVER_H__
#define _TCPSERVER_H__
#include <string>
#include <map>
#include "communication_global.h"
#include "Thread.h"
#include "CommuDefine.h"
#include "SocketNode.h"
#include "BlockingQueue.h"
#include "TcpClientInfo.h"
#include "ThreadMutex.h"

/*!
 * @class	: ITcpServerObserver
 * @brief	: tcp�������۲��ߣ�
 *			  ����������״̬�仯ʱ��ͨ��ע��Ĺ۲���֪ͨ�����
 * @author	: liuk
 * @date	: 2017/07/06 15:15
 */
class ITcpServerObserver
{
public:
	ITcpServerObserver() {}
	virtual ~ITcpServerObserver() {}
public:
	/**
	 * @fn		: OnTcpRead
	 * @brief	: ��ȡ���ͻ��˵���Ϣ
	 * @access	: virtual public 
	 * @param	: [in] CSocketNode socketNode
	 *			  �ͻ��˵���Ϣ��������ַ���˿ڼ����͹���������
	 * @return	: void
	 */
	virtual void OnTcpRead(const CSocketNode& socketNode) = 0;

	/**
	 * @fn		: OnClinetConnected
	 * @brief	: �пͻ�����������
	 * @access	: virtual public 
	 * @param	: [in] const std::string strIp
				  �ͻ���IP
	 * @param	: [in] unsigned short usPort
				  �ͻ��˶˿�
	 * @return	: void
	 */
	virtual void OnClinetConnected(const std::string& strIp, unsigned short usPort) = 0;

	/**
	 * @fn		: OnClientDisconnetcted
	 * @brief	: �пͻ��˶Ͽ�����
	 * @access	: virtual public 
	 * @param	: [in] const std::string& strIp
				  �ͻ���ip
	 * @param	: [in] unsigned short usPort
				  �ͻ��˶˿�
	 * @return	: void
	 */
	virtual void OnClientDisconnetcted(const std::string& strIp, unsigned short usPort) = 0;

};

/*!
 * @class	: 
 * @brief	: 
 * @author	: liuk
 * @date	: 2017/05/06 15:15
 */
class COMMUNICATION_EXPORT CTcpServer : public CThread
{
public:
	CTcpServer();
	~CTcpServer();
public:
	/**
	 * @fn		: InitServer
	 * @brief	: ��ʼ��������
	 * @access	: public 
	 * @param	: std::string strServerIp ������ IP
	 * @param	: unsigned short usPort, ����˿ں�
	 * @return	: bool
	 */
	bool InitServer(std::string strServerIp, unsigned short usPort);
	/**
	 * @fn		: StartService
	 * @brief	: ��������
	 * @access	: public 
	 * @return	: bool
	 */
	bool StartService();

	/**
	 * @fn		: SendDataToClient
	 * @brief	: �������ݵ�ָ���ͻ���
	 * @access	: public 
	 * @param	: std::string strIp 
	 * @param	: unsigned short usPort
	 * @param	: char * szBuffer
	 * @param	: int nLen
	 * @return	: bool ʧ�ܻ�δ��ȫ���ͷ���false
	 */
	bool SendDataToClient(std::string strIp, unsigned short usPort, char* szBuffer, int nLen);

	/**
	 * @fn		: SetSendRecvBufferSize
	 * @brief	: ���ý��ա����ͻ�������С
	 * @access	: public 
	 * @param	: int nSendSize
	 * @param	: int nRecvSize
	 * @return	: bool ʧ�ܷ���false
	 */
	bool SetSendRecvBufferSize(int nSendSize, int nRecvSize);

	/**
	 * @fn		: CloseService
	 * @brief	: �رշ�����
	 * @access	: public 
	 * @return	: void
	 */
	void CloseService();

	/**
	 * @fn		: RegisterObserver
	 * @brief	: ע�����۲���
	 * @access	: public 
	 * @param	: ITcpServerObserver * pUser
	 * @return	: void
	 */
	void RegisterObserver(ITcpServerObserver* pUser);

	/**
	 * @fn		: IsService
	 * @brief	: �Ƿ��ѿ���TCP����
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsService();
public:
	virtual void run();

protected:
	/**
	 * @fn		: SendData
	 * @brief	: �������ݵ�ָ���ͻ���
	 * @access	: protected 
	 * @param	: CTcpClientInfo clinet
	 * @param	: char * szBuffer
	 * @param	: int nLen
	 * @return	: bool ʧ�ܻ�δ��ȫ���ͷ���false
	 */
	bool SendData(CTcpClientInfo clinet, char* szBuffer, int nLen);

	/**
	 * @fn		: DeleteClient
	 * @brief	: ɾ���ͻ���
	 * @access	: protected 
	 * @param	: [in] SocketHandle hClinet Ҫɾ���Ŀͻ���
	 * @return	: void
	 */
	void DeleteClient(SocketHandle hClinet);
private:
	SocketHandle m_hSocket;
	unsigned short m_usPort;
	std::string m_strError;

	// �ͻ����׽��ֺͿͻ��˵�ַ��ӳ��
	std::map<SocketHandle, CTcpClientInfo> m_mapSocketAddr;

	ITcpServerObserver* m_pUser;

	CBlockingQueue<CSocketNode> m_queRecvData;

	CThreadMutex m_mutextSocket;

	char* m_pRecvBuffer;
	int m_nRecvBufferLen;

	bool m_bIsService;
	
};

#endif // _TCPSERVER_H__