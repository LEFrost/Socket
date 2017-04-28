#include"stdafx.h"
#include"Header.h"
#include"SocketClients.h"
CClientSocket::CClientSocket()
{

}
CClientSocket::~CClientSocket()
{

}
void CClientSocket::OnClose(int nErrorCode)
{
	CSocket::OnClose(nErrorCode);
}
void CClientSocket::OnReceive(int nErrorCode)
{
	Header head;
	int nlen = sizeof(head);
	char * pHead = new char[nlen];
	if (!pHead)
	{
		return;
	}
	memset(pHead, 0, sizeof(char)* nlen);
	Receive(pHead, nlen);
	head.type = ((Header*)pHead)->type;
	head.ContentLength = ((Header*)pHead)->ContentLength;
	memset(head.to_user, 0, sizeof(head.to_user));
	strcpy_s(head.to_user, ((Header*)pHead)->to_user);
	
	memset(head.from_user, 0, sizeof(head.from_user));
	strcpy_s(head.from_user, ((Header*)pHead)->from_user);
	delete pHead;
	pHead = NULL;
	pHead = new char[head.ContentLength];
	if (!pHead)
	{
		return;
	}
	if (Receive(pHead, head.ContentLength) != head.ContentLength)
	{
		delete pHead;
		return;
	}

	switch (head.type)
	{
	case MSG_LOGIN:
		OnLogoIN(pHead, head.ContentLength, head.from_user);
		break;
	default:
		break;
	}
	delete pHead;
	CSocket::OnReceive(nErrorCode);
}

void CClientSocket::OnLogoIN(char * buff, int nlen, char from_user[20])
{
	
}
