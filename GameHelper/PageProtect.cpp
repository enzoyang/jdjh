// PageProtect.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GameHelper.h"
#include "PageProtect.h"


// CPageProtect �Ի���

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


// CPageProtect ��Ϣ�������
