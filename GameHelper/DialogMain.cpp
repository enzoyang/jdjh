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
	this->m_btnToggle.Create(L"开始挂机",BS_PUSHBUTTON,CRect(0,0,20,20),this,IDC_BTN_TOGGLE);
}

CDialogMain::~CDialogMain()
{
}

BOOL CDialogMain::InitPages()
{

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
END_MESSAGE_MAP()


// CDialogMain 消息处理程序
