#pragma once


// CPageOther 对话框

class CPageOther : public CDialog
{
	DECLARE_DYNAMIC(CPageOther)

public:
	CPageOther(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPageOther();

// 对话框数据
	enum { IDD = IDD_PAGE_OTHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
