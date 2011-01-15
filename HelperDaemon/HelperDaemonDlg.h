// HelperDaemonDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CHelperDaemonDlg 对话框
class CHelperDaemonDlg : public CDialog
{
// 构造
public:
	CHelperDaemonDlg(CWnd* pParent = NULL);	// 标准构造函数
	
	void GameIsRunning();
	void ShowVersion();
// 对话框数据
	enum { IDD = IDD_HELPERDAEMON_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	

// 实现
protected:
	HICON m_hIcon;
    //重写
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnLinkGpl();
public:
	afx_msg void OnBnClickedBtnLinkBlog();
public:
	afx_msg void OnBnClickedBtnLinkSrc();
public:
	CEdit m_editStatus;
};
