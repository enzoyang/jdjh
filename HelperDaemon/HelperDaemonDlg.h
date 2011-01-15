// HelperDaemonDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CHelperDaemonDlg �Ի���
class CHelperDaemonDlg : public CDialog
{
// ����
public:
	CHelperDaemonDlg(CWnd* pParent = NULL);	// ��׼���캯��
	
	void GameIsRunning();
	void ShowVersion();
// �Ի�������
	enum { IDD = IDD_HELPERDAEMON_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	

// ʵ��
protected:
	HICON m_hIcon;
    //��д
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	// ���ɵ���Ϣӳ�亯��
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
