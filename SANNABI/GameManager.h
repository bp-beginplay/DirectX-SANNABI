#pragma once

#include "Engine.h"

class CGameManager
{
	DECLARE_SINGLETON(CGameManager)

public:
	bool Init(HINSTANCE hInst);
	int Run();

private:
	void RegisterWindowClass();
	bool Create();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Logic();
	void Input(float DeltaTime);
	void Update(float DeltaTime);
	void Render(float DeltaTime);
	void Collision(float DeltaTime);

public:
	HINSTANCE GetWindowInstance() const { return mhInst; }
	HWND GetWindowHandle() const { return mhWnd; }

private:
	static bool Loop;
	HINSTANCE mhInst = 0;
	HWND mhWnd = 0;
	HDC mhDC = 0;
	TCHAR ClassName[256] = {};
	TCHAR TitleName[256] = {};
	float ClearColor[4] = { 0.f, 0.f, 0.f, 1.f };
};

