// PageAuto.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GameHelper.h"
#include "PageAuto.h"


// CPageAuto �Ի���

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


// CPageAuto ��Ϣ�������
