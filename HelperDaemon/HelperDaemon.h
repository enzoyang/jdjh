// HelperDaemon.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHelperDaemonApp:
// �йش����ʵ�֣������ HelperDaemon.cpp
//

class CHelperDaemonApp : public CWinApp
{
public:
	CHelperDaemonApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CHelperDaemonApp theApp;