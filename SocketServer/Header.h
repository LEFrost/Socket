#pragma once
#include"stdafx.h"
const int MSG_LOGIN = 0x01;//登陆
const int MSG_SIGNOUT = 0x02;//注销
const int MSG_SEND = 0x03;//发送消息

typedef struct tagHeader
{
	int type;
	int ContentLength;
	char from_user[20];
	char to_user[20];
}  Header;