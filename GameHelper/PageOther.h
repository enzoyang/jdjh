#pragma once


// CPageOther �Ի���

class CPageOther : public CDialog
{
	DECLARE_DYNAMIC(CPageOther)

public:
	CPageOther(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPageOther();

// �Ի�������
	enum { IDD = IDD_PAGE_OTHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
