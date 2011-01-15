#pragma once


// CPageProtect 对话框

class CPageProtect : public CDialog
{
	DECLARE_DYNAMIC(CPageProtect)

public:
	CPageProtect(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPageProtect();

// 对话框数据
	enum { IDD = IDD_PAGE_PROTECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
