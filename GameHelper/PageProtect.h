#pragma once


// CPageProtect �Ի���

class CPageProtect : public CDialog
{
	DECLARE_DYNAMIC(CPageProtect)

public:
	CPageProtect(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPageProtect();

// �Ի�������
	enum { IDD = IDD_PAGE_PROTECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
