#pragma once


// CPageAuto 对话框

class CPageAuto : public CDialog
{
	DECLARE_DYNAMIC(CPageAuto)

public:
	CPageAuto(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPageAuto();

// 对话框数据
	enum { IDD = IDD_PAGE_AUTO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
