// GameHelper.h : GameHelper DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGameHelperApp
// �йش���ʵ�ֵ���Ϣ������� GameHelper.cpp
//

class CGameHelperApp : public CWinApp
{
public:
	CGameHelperApp();
	void ShowWnd();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
