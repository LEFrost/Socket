#pragma once
#include "SocketClient.h"
class CSocketServer: public CSocket
{
public:
	CPtrList m_listSockets;//��¼���ӵ�socket
public:
	CSocketServer();
	~CSocketServer();
	virtual void OnAccept(int nErrorCode); //����

private:

};

