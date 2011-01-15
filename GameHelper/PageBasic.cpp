// PageBasic.cpp : 实现文件
//

#include "stdafx.h"
#include "GameHelper.h"
#include "PageBasic.h"


// CPageBasic 对话框

IMPLEMENT_DYNAMIC(CPageBasic, CDialog)

CPageBasic::CPageBasic(CWnd* pParent /*=NULL*/)
	: CDialog(CPageBasic::IDD, pParent)
{

}

CPageBasic::~CPageBasic()
{
}

void CPageBasic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPageBasic, CDialog)
END_MESSAGE_MAP()


// CPageBasic 消息处理程序
