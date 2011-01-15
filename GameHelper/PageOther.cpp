// PageOther.cpp : 实现文件
//

#include "stdafx.h"
#include "GameHelper.h"
#include "PageOther.h"


// CPageOther 对话框

IMPLEMENT_DYNAMIC(CPageOther, CDialog)

CPageOther::CPageOther(CWnd* pParent /*=NULL*/)
	: CDialog(CPageOther::IDD, pParent)
{

}

CPageOther::~CPageOther()
{
}

void CPageOther::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPageOther, CDialog)
END_MESSAGE_MAP()


// CPageOther 消息处理程序
