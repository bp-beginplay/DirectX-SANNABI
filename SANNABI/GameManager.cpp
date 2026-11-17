#include "GameManager.h"
#include "Log.h"
#include "Device.h"
#include "Timer.h"
#include "ShaderManager.h"
#include "RenderManager.h"
#include "AssetManager.h"
#include "ProfileManager.h"
#include "SceneManager.h"
#include "resource.h"
#include "SoundManager.h"
#include "Widget.h"

TCHAR gRootPath[MAX_PATH];
char gRootPathMultibyte[MAX_PATH];
bool CGameManager::Loop = true;

CGameManager::CGameManager() {}

CGameManager::~CGameManager()
{
	CLog::Destroy();
	ReleaseDC(mhWnd, mhDC);
}

bool CGameManager::Init(HINSTANCE _hInst)
{
	mhInst = _hInst;

	lstrcpy(ClassName, TEXT("산나비"));
	lstrcpy(TitleName, TEXT("산나비"));

	//레지스터 클래스 등록 
	RegisterWindowClass();

	if (!Create())
	{
		return false;
	}

	//if (!CLog::Init()) { return false; }



	//디바이스 컨텍스트 얻어오기
	//인자로 들어간 윈도우에 출력할 수 있는 DC가 만들어진다. 
	mhDC = GetDC(mhWnd);

	//디바이스 초기화 
	if (!CDevice::GetInst()->Init(mhWnd, 1920, 1080, true))
	{
		return false;
	}

	//Shader 관리자 초기화 
	if (!CShaderManager::GetInst()->Init())
	{
		return false;
	}

	//Render 매니져
	if (!CRenderManager::GetInst()->Init())
	{
		return false;
	}

	//에셋 매니져 초기화
	if (!CAssetManager::GetInst()->Init())
	{
		return false;
	}

	//Collision Profile 매니져 초기화
	if (!CProfileManager::GetInst()->Init())
	{
		return false;
	}

	//타이머 초기화 
	CTimer::Init();

	//장면관리자 
	if (!CSceneManager::GetInst()->Init())
	{
		return false;
	}

	//이때 UI전용 Proj 행렬 초기화
	FResolution RS = CDevice::GetInst()->GetResolution();
	CWidget::CreateUIProjection(static_cast<float>(RS.Width), static_cast<float>(RS.Height), 1000.f);

	return true;
}

void CGameManager::RegisterWindowClass()
{
	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = mhInst;
	wcex.hIcon = LoadIcon(mhInst, MAKEINTRESOURCE(IDI_ICON2));
	wcex.hCursor = LoadCursor(nullptr, IDC_CROSS);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = ClassName;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON2));
	RegisterClassExW(&wcex);
}

bool CGameManager::Create()
{
	mhWnd = CreateWindowW(ClassName, TitleName, WS_OVERLAPPEDWINDOW, 
		0, 0, 1280, 720, nullptr, nullptr, mhInst, nullptr);
	if (!mhWnd) return FALSE;
	RECT WindowRC = { 0, 0, 1920, 1080 };
	AdjustWindowRect(&WindowRC, WS_OVERLAPPEDWINDOW, FALSE);
	SetWindowPos(mhWnd, HWND_TOPMOST, 100, 100, WindowRC.right - WindowRC.left, WindowRC.bottom - WindowRC.top, SWP_NOMOVE | SWP_NOZORDER);
	ShowWindow(mhWnd, SW_SHOW);
	UpdateWindow(mhWnd);
	return TRUE;
}

LRESULT CGameManager::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SYSKEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			Loop = false;
			DestroyWindow(hWnd);
		}
		break;
	case WM_DESTROY:
		Loop = false;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

int CGameManager::Run()
{
	MSG msg = {};
	while (Loop)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Logic();
		}
	}
	return (int)msg.wParam;
}

void CGameManager::Logic()
{
	float DeltaTime = CTimer::Update();
	Input(DeltaTime);
	Update(DeltaTime);
	Render(DeltaTime);
	Collision(DeltaTime);
	CAssetManager::GetInst()->GetSoundManager()->Update();
}

void CGameManager::Input(float DeltaTime)
{
	CSceneManager::GetInst()->Input(DeltaTime);
}

void CGameManager::Update(float DeltaTime)
{
	CSceneManager::GetInst()->Update(DeltaTime);
	static bool push = false;
	if (GetAsyncKeyState(VK_RETURN) & 0x8000) push = true;
	else if (push)
	{
		push = false;
		CLog::SaveLog();
	}
}

void CGameManager::Render(float DeltaTime)
{
	CDevice::GetInst()->ClearBackBuffer(ClearColor);
	CDevice::GetInst()->ClearDepthStencill(1.f, 0);
	CDevice::GetInst()->SetTarget();


	CSceneManager::GetInst()->Render();

	CRenderManager::GetInst()->Render();

	CSceneManager::GetInst()->EndFrame();

	CDevice::GetInst()->Render();
}

void CGameManager::Collision(float DeltaTime) { CSceneManager::GetInst()->Collision(DeltaTime); }