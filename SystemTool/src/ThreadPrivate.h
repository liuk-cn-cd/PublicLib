#ifndef CTHREADPRIVATE_H
#define CTHREADPRIVATE_H
#include "ThreadBase.h"
#include "ThreadEvent.h"
class CThreadPrivate
{
    friend class CThread;
private:
    CThreadPrivate()
        : m_hThread(0)
        , m_bQuit(true)
        , m_bRunning(false)
    {
#ifdef WIN32
        m_hThread = 0;
#endif // WIN32
    }
    ~CThreadPrivate(){}
private:
    THREADID m_hThread;
    CThreadEvent m_hEvent;
    bool m_bQuit;
    bool m_bRunning;

#ifdef WIN32
    bool m_bPause;
    unsigned m_unThreadAddress;
#endif
};

#endif // CTHREADPRIVATE_H
