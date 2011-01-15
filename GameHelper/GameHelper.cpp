// GameHelper.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "GameHelper.h"
#include "DialogMain.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//


// CGameHelperApp

BEGIN_MESSAGE_MAP(CGameHelperApp, CWinApp)
END_MESSAGE_MAP()


// CGameHelperApp 构造

CGameHelperApp::CGameHelperApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CGameHelperApp 对象

CGameHelperApp theApp;


// CGameHelperApp 初始化

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

//*********************************全局函数********************************
/* HOOK函数原型
HHOOK WINAPI SetWindowsHookEx(
		  __in  int idHook, //WH_KEYBOARD 键盘HOOK
		  __in  HOOKPROC lpfn, //回调函数
		  __in  HINSTANCE hMod, //DLL实例句柄
		  __in  DWORD dwThreadId //要HOOK的主线程ID
		  );*/
	
//LRESULT CALLBACK KeyboardProc(  //键盘回调函数原型
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
//设置钩子
void SetHook()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//尝试找到游戏窗口
	HWND hwnd = ::FindWindow(NULL,L"YB_OnlineClient");
	if(NULL == hwnd)
		return;//未找到游戏窗口则直接返回
	//获取游戏进程ID
	DWORD tid = ::GetWindowThreadProcessId(hwnd,NULL);
	//设置钩子
	SetWindowsHookEx(WH_KEYBOARD,&KbProc,::GetModuleHandle(L"GameHelper.dll"),tid);
}
int  SupportVersion()
{
	//TODO:支持的版本,每次更新后需要修改
	return 50017;
}