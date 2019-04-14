/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: SocketNode.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/30 10:46:58
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include <string>
#include "communication_global.h"

#define PACKAGE_MAX_SIZE 65535
/*!
 * @class	: CSocketNode
 * @brief	: ͨ�����ݽڵ�
 * @author	: liuk
 * @date	: 2017/04/30 10:47
 */
class COMMUNICATION_EXPORT CSocketNode
{
public:
	CSocketNode();
	CSocketNode(const CSocketNode& rObj);
	~CSocketNode();

	CSocketNode& operator=(const CSocketNode& rObj);

public:
	const unsigned char* GetDataBuffer() const;
	int GetDataSize() const;
	std::string GetSrcIp() const;
	int GetSrcPort() const;

	void SetData(const unsigned char* pData, int nlen);
	void SetSrcAddr(const std::string& strIp, unsigned short usPort);
private:
	void Clear();
private:
	std::string m_strSrcIp;
	unsigned short m_usSrcPort;

	unsigned char* m_pData;
	int m_nSize;

};

