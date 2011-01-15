#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "PageAuto.h"
#include "PageBasic.h"
#include "PageOther.h"
#include "PageProtect.h"

// CDialogMain �Ի���

class CDialogMain : public CDialog
{
	DECLARE_DYNAMIC(CDialogMain)

public:
	CDialogMain(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogMain();
	BOOL InitPages();
// �Ի�������
	enum { IDD = IDD_DLG_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	//�ؼ�
	CButton m_btnToggle;
	CTabCtrl m_tabMain;
	//TABS
	CPageAuto m_pageAuto;
	CPageBasic m_pageBasic;
	CPageOther m_pageOther;
	CPageProtect m_pageProtect;
	//TAB[]
	CDialog* m_Pages[4];
	//ѡ���TAB
	int m_iCurrentPage;

public:
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
};
