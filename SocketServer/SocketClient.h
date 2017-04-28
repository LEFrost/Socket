#pragma once
#include"stdafx.h"
#include"Header.h"
class CSocketClient: public CSocket
{
public:
	CPtrList *pList;

public:

	CSocketClient(CPtrList* list);
	CSocketClient();
	~CSocketClient();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode); // ’µΩ
	void OnLogoIN(char* buff, int nlen, char from_user[20]);
private:
};
