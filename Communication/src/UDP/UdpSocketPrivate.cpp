#include "UdpSocketPrivate.h"
#include "Task.h"
CUdpSocketPrivate::CUdpSocketPrivate()
    : m_pUdpUser(nullptr)
    , m_strDefaultDestIp("")
    , m_uDefaultPort(0)
{
    m_pProcessTask = new CTask;
    m_pRecvTask = new CTask;
    m_pRecvBuffer = new byte[65536];
}

CUdpSocketPrivate::~CUdpSocketPrivate()
{
    if(nullptr != m_pProcessTask)
    {
        delete m_pProcessTask;
        m_pProcessTask = nullptr;
    }

    if(nullptr != m_pRecvTask)
    {
        m_pRecvTask = new CTask;
        m_pRecvTask = nullptr;
    }

    if(nullptr != m_pRecvBuffer)
    {
        delete [] m_pRecvBuffer;
        m_pRecvBuffer = nullptr;
    }
}
