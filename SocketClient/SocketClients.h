#pragma once
#include"Header.h"
#include<afxsock.h>
class CClientSocket :public CSocket
{
public:
	CClientSocket();
	~CClientSocket();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode); // ’µΩ
	void OnLogoIN(char* buff, int nlen, char from_user[20]);

};