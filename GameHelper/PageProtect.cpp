// PageProtect.cpp : 实现文件
//

#include "stdafx.h"
#include "GameHelper.h"
#include "PageProtect.h"


// CPageProtect 对话框

IMPLEMENT_DYNAMIC(CPageProtect, CDialog)

CPageProtect::CPageProtect(CWnd* pParent /*=NULL*/)
	: CDialog(CPageProtect::IDD, pParent)
{

}

CPageProtect::~CPageProtect()
{
}

void CPageProtect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPageProtect, CDialog)
END_MESSAGE_MAP()


// CPageProtect 消息处理程序
