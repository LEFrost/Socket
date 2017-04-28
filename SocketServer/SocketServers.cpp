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
		AfxMessageBox(_T("内存不足,客户连接服务器失败！"));
		return;
	}
	Accept(*cSocket); //接受
	//加入list中便于管理
	m_listSockets.AddTail(cSocket);
	CSocket::OnAccept(nErrorCode);
}
