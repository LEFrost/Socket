
// SocketClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SocketClient.h"
#include "SocketClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSocketClientDlg �Ի���



CSocketClientDlg::CSocketClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SOCKETCLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSocketClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSocketClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CSocketClientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSocketClientDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSocketClientDlg ��Ϣ�������

BOOL CSocketClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSocketClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSocketClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSocketClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSocketClientDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	AfxSocketInit();
	CSocket asocket;
	if (!asocket.Create())
	{

	}
	asocket.Connect(_T("192.168.1.142"), UINT(5001));
	Header phead;
	char*a = "23232323";
	phead.type = MSG_LOGIN;
	phead.ContentLength = 9;
	memset(phead.from_user, 0, sizeof(phead.from_user));
	memset(phead.to_user, 0, sizeof(phead.to_user));
	strcpy_s(phead.from_user, "");
	strcpy_s(phead.to_user, "");
	//phead.from_user=
	char szRecValue[1024] = { 0 };
	asocket.Send(&phead, sizeof(phead));
	asocket.Send(a, 9);
	asocket.Close();
}


void CSocketClientDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	if (!AfxSocketInit())
	{

	}
	CSocket aSocket, serverSocket;
	if (!aSocket.Socket())
	{

	}
	aSocket.Bind(5001);
	aSocket.Listen(10);
	/*while (true)
	{*/
	if (!aSocket.Accept(serverSocket))
	{
		//continue;
	}
	else
	{
		char szRecvMSG[256] = { 0 };
		char szOutvMSG[256] = { 0 };
		serverSocket.Receive(szRecvMSG, 256);
		GetDlgItem(xianshi)->SetWindowTextW(CString(szRecvMSG));
		serverSocket.Send("OK,HHHH", 50);
		serverSocket.Close();
		aSocket.Close();
	}
	//}
}
