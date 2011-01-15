#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "PageAuto.h"
#include "PageBasic.h"
#include "PageOther.h"
#include "PageProtect.h"

// CDialogMain 对话框

class CDialogMain : public CDialog
{
	DECLARE_DYNAMIC(CDialogMain)

public:
	CDialogMain(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogMain();
	BOOL InitPages();
// 对话框数据
	enum { IDD = IDD_DLG_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	//控件
	CButton m_btnToggle;
	CTabCtrl m_tabMain;
	//TABS
	CPageAuto m_pageAuto;
	CPageBasic m_pageBasic;
	CPageOther m_pageOther;
	CPageProtect m_pageProtect;
	//TAB[]
	CDialog* m_Pages[4];
	//选择的TAB
	int m_iCurrentPage;

public:
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
};
