#pragma once


// CPageBasic �Ի���

class CPageBasic : public CDialog
{
	DECLARE_DYNAMIC(CPageBasic)

public:
	CPageBasic(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPageBasic();

// �Ի�������
	enum { IDD = IDD_PAGE_BASIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
