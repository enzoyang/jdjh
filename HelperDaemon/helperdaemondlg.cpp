// HelperDaemonDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HelperDaemon.h"
#include "HelperDaemonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


const int m_Timer =1985;
const int m_TimerOfProcessWatcher =2011;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

// CHelperDaemonDlg �Ի���




CHelperDaemonDlg::CHelperDaemonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHelperDaemonDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);	
}

void CHelperDaemonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_STATUS, m_editStatus);
}

BEGIN_MESSAGE_MAP(CHelperDaemonDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_LINK_GPL, &CHelperDaemonDlg::OnBnClickedBtnLinkGpl)
	ON_BN_CLICKED(IDC_BTN_LINK_BLOG, &CHelperDaemonDlg::OnBnClickedBtnLinkBlog)
	ON_BN_CLICKED(IDC_BTN_LINK_SRC, &CHelperDaemonDlg::OnBnClickedBtnLinkSrc)
END_MESSAGE_MAP()


// CHelperDaemonDlg ��Ϣ�������

BOOL CHelperDaemonDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	SetTimer(m_Timer,1000,NULL);//������ʱ��
	SetTimer(m_TimerOfProcessWatcher,1000,NULL);
	m_editStatus.SetWindowText(_T("������Ϸ��HOME���������."));
	this->ShowVersion();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CHelperDaemonDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
		CDialog::OnSysCommand(nID, lParam);
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHelperDaemonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CHelperDaemonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



typedef void(__cdecl* FuncS)(HWND);

void CHelperDaemonDlg::GameIsRunning()
{
	HINSTANCE hm = LoadLibrary("GameHelper.dll");
		if(NULL == hm)
		{
			m_editStatus.SetWindowText("û���ҵ���̬���ӿ�,\r\n��ǰ���ҵĲ���,����ȱʧ���ļ�.");
			return;
		}
		FuncS showWndFunc = (FuncS)GetProcAddress(hm,"SetHook");
		showWndFunc(NULL);
}

typedef int(__stdcall* FuncV)(void); 
void CHelperDaemonDlg::ShowVersion()
{
	FuncV fv;
	HINSTANCE hm = LoadLibrary("GameHelper.dll");
	if(NULL == hm)
	{
		m_editStatus.SetWindowText("û���ҵ���̬���ӿ�,\r\n��ǰ���ҵĲ���,����ȱʧ���ļ�.");
		return;
	}
	fv= (FuncV)GetProcAddress(hm,"SupportVersion");
	int version = fv();

	char v[10];
	char oldTitle[20]="�򵥽��� ֧�ְ汾:";
	char title[40]={0};
	strcat_s(title,oldTitle);
	_itoa_s(version,v,10);
	strcat_s(title,v);
	this->SetWindowText(title);
}

void CHelperDaemonDlg::OnTimer(UINT_PTR nIDEvent)
{
	HWND hwnd = ::FindWindow(NULL,_T("YB_OnlineClient"));
	switch(nIDEvent)
	{
	case m_Timer:
		{
			if(NULL != hwnd)
			{
				KillTimer(m_Timer);
				this->GameIsRunning();
			}
		}
		break;
	case m_TimerOfProcessWatcher:
		{
			if(NULL == hwnd)
			{
				SetTimer(m_Timer,1000,NULL);
			}
		}
		break;
	default:break;
	}
	
	
	
}
BOOL CHelperDaemonDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if(IDOK == LOWORD(wParam) || IDCANCEL == LOWORD(wParam))
	{
		HWND hwndGame = ::FindWindow(NULL,"YB_OnlineClient");
			if ( NULL != hwndGame)
			{
				AfxMessageBox(_T("���˳���Ϸ���ٽ������."),MB_ICONQUESTION);
				return TRUE;
			}
		}
	return CDialog::OnCommand(wParam,lParam);
}
void CHelperDaemonDlg::OnBnClickedBtnLinkGpl()
{
	::ShellExecute(NULL,_T("open"),_T("http://wiki.debian.org.hk/w/GPLv3"),NULL,NULL,SW_SHOWNORMAL);
}

void CHelperDaemonDlg::OnBnClickedBtnLinkBlog()
{
	::ShellExecute(NULL,_T("open"),_T("http://sharpcoder.cnblogs.com"),NULL,NULL,SW_SHOWNORMAL);
}

void CHelperDaemonDlg::OnBnClickedBtnLinkSrc()
{
	::ShellExecute(NULL,_T("open"),_T("https://github.com/yzb2002/jdjh"),NULL,NULL,SW_SHOWNORMAL);
}
