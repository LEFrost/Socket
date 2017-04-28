#pragma once
#include "SocketClient.h"
class CSocketServer: public CSocket
{
public:
	CPtrList m_listSockets;//记录连接的socket
public:
	CSocketServer();
	~CSocketServer();
	virtual void OnAccept(int nErrorCode); //接受

private:

};

