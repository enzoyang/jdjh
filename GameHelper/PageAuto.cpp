// PageAuto.cpp : 实现文件
//

#include "stdafx.h"
#include "GameHelper.h"
#include "PageAuto.h"


// CPageAuto 对话框

IMPLEMENT_DYNAMIC(CPageAuto, CDialog)

CPageAuto::CPageAuto(CWnd* pParent /*=NULL*/)
	: CDialog(CPageAuto::IDD, pParent)
{

}

CPageAuto::~CPageAuto()
{
}

void CPageAuto::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPageAuto, CDialog)
END_MESSAGE_MAP()


// CPageAuto 消息处理程序
