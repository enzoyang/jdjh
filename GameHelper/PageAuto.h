#pragma once


// CPageAuto �Ի���

class CPageAuto : public CDialog
{
	DECLARE_DYNAMIC(CPageAuto)

public:
	CPageAuto(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPageAuto();

// �Ի�������
	enum { IDD = IDD_PAGE_AUTO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
