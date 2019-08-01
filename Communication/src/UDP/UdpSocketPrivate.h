#ifndef UDPSOKETPRIVATE_H
#define UDPSOKETPRIVATE_H
#include "BlockingQueue.h"
#include "SocketNode.h"
#include "CommuDefine.h"

class CTask;
class IUdpUser;
class CUdpSocketPrivate
{
    friend class CUdpSocket;
private:
    CUdpSocketPrivate();
    ~CUdpSocketPrivate();
private:
    CTask* m_pRecvTask;
    CTask* m_pProcessTask;

    CBlockingQueue<CSocketNode> m_queueRecvNode;

    SocketHandle m_hSocket;

    IUdpUser* m_pUdpUser;

    std::string m_strDefaultDestIp;
    uint16 m_uDefaultPort;

    byte* m_pRecvBuffer;
};

#endif // UDPSOKETPRIVATE_H
