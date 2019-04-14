#include "CommandExecutor.h"

CCommandExecutor::CCommandExecutor()
	: m_pUser(NULL)

{
	m_cmdTask.Attach(this);
	m_cmdTask.Active();
}


CCommandExecutor::~CCommandExecutor()
{
}

void CCommandExecutor::OnRunTask(CTask* pTask)
{
	while (true)
	{
		CDataObject dataObj;
		CMsgKey msgKey;
		m_queCommand.DequeueCommand(dataObj, msgKey);
		
		if(NULL != m_pUser)
		{
			m_pUser->OnCommadExecute(this, dataObj, msgKey);
		}
	}
}

void CCommandExecutor::PutCmd(const CDataObject& dataObj, const CMsgKey& msgKey)
{
	m_queCommand.EnqueueCommand(dataObj, msgKey);
}

void CCommandExecutor::Attach(CCommandExecutorUser * pUser)
{
	m_pUser = pUser;
}
