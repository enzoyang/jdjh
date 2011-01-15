// GameHelper.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "GameHelper.h"
#include "DialogMain.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//


// CGameHelperApp

BEGIN_MESSAGE_MAP(CGameHelperApp, CWinApp)
END_MESSAGE_MAP()


// CGameHelperApp ����

CGameHelperApp::CGameHelperApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CGameHelperApp ����

CGameHelperApp theApp;


// CGameHelperApp ��ʼ��

BOOL CGameHelperApp::InitInstance()
{
	CWinApp::InitInstance();
	
	return TRUE;
}

void CGameHelperApp::ShowWnd()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CDialogMain* main = new CDialogMain;
	main->Create(IDD_DLG_MAIN);
	main->ShowWindow(SW_SHOW);
}

//*********************************ȫ�ֺ���********************************
/* HOOK����ԭ��
HHOOK WINAPI SetWindowsHookEx(
		  __in  int idHook, //WH_KEYBOARD ����HOOK
		  __in  HOOKPROC lpfn, //�ص�����
		  __in  HINSTANCE hMod, //DLLʵ�����
		  __in  DWORD dwThreadId //ҪHOOK�����߳�ID
		  );*/
	
//LRESULT CALLBACK KeyboardProc(  //���̻ص�����ԭ��
//							  __in  int code,
//							  __in  WPARAM wParam,
//							  __in  LPARAM lParam
//							  );
LRESULT CALLBACK KbProc(int code,WPARAM wParam,LPARAM lParam)
{
	if(VK_HOME == wParam && (lParam & (1<<31))==0)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		//theApp = new CGameHelperApp;
		theApp.ShowWnd();
	}
	return ::CallNextHookEx(0,code,wParam,lParam);
}
//���ù���
void SetHook()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//�����ҵ���Ϸ����
	HWND hwnd = ::FindWindow(NULL,L"YB_OnlineClient");
	if(NULL == hwnd)
		return;//δ�ҵ���Ϸ������ֱ�ӷ���
	//��ȡ��Ϸ����ID
	DWORD tid = ::GetWindowThreadProcessId(hwnd,NULL);
	//���ù���
	SetWindowsHookEx(WH_KEYBOARD,&KbProc,::GetModuleHandle(L"GameHelper.dll"),tid);
}
int  SupportVersion()
{
	//TODO:֧�ֵİ汾,ÿ�θ��º���Ҫ�޸�
	return 50017;
}