#include "CommandExecutor.h"

CCommandExecutor::CCommandExecutor()
    : m_pUser(nullptr)

{
	m_cmdTask.Attach(this);
	m_cmdTask.Active();
}


CCommandExecutor::~CCommandExecutor()
{
}

void CCommandExecutor::OnRunTask(CTask* pTask)
{
    if(pTask != &m_cmdTask)
    {
        return;
    }

	while (true)
	{
		CDataObject dataObj;
		CMsgKey msgKey;
		m_queCommand.DequeueCommand(dataObj, msgKey);
		
        if(nullptr != m_pUser)
		{
			m_pUser->OnCommadExecute(this, dataObj, msgKey);
		}
	}
}

void CCommandExecutor::PutCmd(const CDataObject& dataObj, const CMsgKey& msgKey)
{
	m_queCommand.EnqueueCommand(dataObj, msgKey);
}

void CCommandExecutor::Attach(ICommandExecutorUser * pUser)
{
	m_pUser = pUser;
}

ICommandExecutorUser::ICommandExecutorUser()
{

}

ICommandExecutorUser::~ICommandExecutorUser()
{

}
