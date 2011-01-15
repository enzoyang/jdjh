// DialogMain.cpp : 实现文件
//

#include "stdafx.h"
#include "GameHelper.h"
#include "DialogMain.h"


// CDialogMain 对话框

IMPLEMENT_DYNAMIC(CDialogMain, CDialog)

CDialogMain::CDialogMain(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogMain::IDD, pParent)
{
}

CDialogMain::~CDialogMain()
{
	
}

BOOL CDialogMain::InitPages()
{
	m_tabMain.InsertItem(0,_T("基本"));
	m_tabMain.InsertItem(1,_T("保护"));
	m_tabMain.InsertItem(2,_T("挂机"));
	m_tabMain.InsertItem(3,_T("其他"));

	m_pageBasic.Create(IDD_PAGE_BASIC,GetDlgItem(IDC_TAB_MAIN));
	m_pageProtect.Create(IDD_PAGE_PROTECT,GetDlgItem(IDC_TAB_MAIN));
	m_pageAuto.Create(IDD_PAGE_AUTO,GetDlgItem(IDC_TAB_MAIN));
	m_pageOther.Create(IDD_PAGE_OTHER,GetDlgItem(IDC_TAB_MAIN));
	
	m_Pages[0]=&m_pageBasic;
	m_Pages[1]=&m_pageProtect;
	m_Pages[2]=&m_pageAuto;
	m_Pages[3]=&m_pageOther;

	RECT rc;
	m_tabMain.GetWindowRect(&rc);

	rc.top-=30;
	rc.right+=10;
	rc.left-=20;
	rc.bottom -=10;

	m_pageBasic.MoveWindow(&rc);
	m_pageProtect.MoveWindow(&rc);
	m_pageAuto.MoveWindow(&rc);
	m_pageOther.MoveWindow(&rc);

	m_pageBasic.ShowWindow(SW_SHOW);
	
	m_iCurrentPage =0;
	return true;
}

BOOL CDialogMain::OnInitDialog()
{
	CDialog::OnInitDialog();
	this->InitPages();
	return true;
}

void CDialogMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_TOGGLE, m_btnToggle);
	DDX_Control(pDX, IDC_TAB_MAIN, m_tabMain);
}


BEGIN_MESSAGE_MAP(CDialogMain, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CDialogMain::OnTcnSelchangeTabMain)
END_MESSAGE_MAP()


// CDialogMain 消息处理程序

void CDialogMain::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	m_Pages[m_iCurrentPage]->ShowWindow(SW_HIDE);
	m_iCurrentPage = this->m_tabMain.GetCurSel();
	m_Pages[m_iCurrentPage]->ShowWindow(SW_SHOW);
}
