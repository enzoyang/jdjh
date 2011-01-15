// HelperDaemonDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HelperDaemon.h"
#include "HelperDaemonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


const int m_Timer =1985;
const int m_TimerOfProcessWatcher =2011;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

// CHelperDaemonDlg 对话框




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


// CHelperDaemonDlg 消息处理程序

BOOL CHelperDaemonDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	SetTimer(m_Timer,1000,NULL);//启动计时器
	SetTimer(m_TimerOfProcessWatcher,1000,NULL);
	m_editStatus.SetWindowText(_T("进入游戏后按HOME键呼出外挂."));
	this->ShowVersion();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CHelperDaemonDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
		CDialog::OnSysCommand(nID, lParam);
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHelperDaemonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
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
			m_editStatus.SetWindowText("没有找到动态链接库,\r\n请前往我的博客,下载缺失的文件.");
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
		m_editStatus.SetWindowText("没有找到动态链接库,\r\n请前往我的博客,下载缺失的文件.");
		return;
	}
	fv= (FuncV)GetProcAddress(hm,"SupportVersion");
	int version = fv();

	char v[10];
	char oldTitle[20]="简单江湖 支持版本:";
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
				AfxMessageBox(_T("请退出游戏后再结束外挂."),MB_ICONQUESTION);
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
