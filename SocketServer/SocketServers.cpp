#include"stdafx.h"
#include "SocketServers.h"


 CSocketServer::CSocketServer()
{
}

CSocketServer::~CSocketServer()
{
}

void CSocketServer::OnAccept(int nErrorCode)
{

	CSocketClient *cSocket = new CSocketClient(&m_listSockets);
	if (!cSocket)
	{
		AfxMessageBox(_T("�ڴ治��,�ͻ����ӷ�����ʧ�ܣ�"));
		return;
	}
	Accept(*cSocket); //����
	//����list�б��ڹ���
	m_listSockets.AddTail(cSocket);
	CSocket::OnAccept(nErrorCode);
}
