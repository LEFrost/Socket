
// SocketServer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "SocketServers.h"

// CSocketServerApp: 
// �йش����ʵ�֣������ SocketServer.cpp
//

class CSocketServerApp : public CWinApp
{
public:
	CSocketServerApp();

// ��д
public:
	virtual BOOL InitInstance();
private:
	CSocketServer *m_Socket;
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSocketServerApp theApp;
