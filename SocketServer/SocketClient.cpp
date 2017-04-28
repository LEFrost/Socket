#include"stdafx.h"
#include "SocketClient.h"

CSocketClient::CSocketClient(CPtrList * list) :pList(list)
{

}

CSocketClient::CSocketClient()
{
}

CSocketClient::~CSocketClient()
{
}

void CSocketClient::OnClose(int nErrorCode)
{
}

void CSocketClient::OnReceive(int nErrorCode)
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
	/*memset(head.to_user, 0, sizeof(head.to_user));
	strcpy_s(head.to_user, ((Header*)pHead)->to_user);*/
	head.pList.AddTail(&(((Header*)pHead)->pList));
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

void CSocketClient::OnLogoIN(char * buff, int nlen, char from_user[20])
{
	Header head;
	head.type = MSG_SEND;
	head.ContentLength = nlen;
	strcpy_s(head.from_user, from_user);
   CSocketClient temp;

	//temp.Send(&head, sizeof(Header));
	temp.Send(buff, nlen);
}
