#pragma once

#include "Engine.h"

class CTimer
{
	friend class CGameManager;

private:
	static void Init();
	static float Update();

public:
	static float GetDeltaTime();

private:
	static LARGE_INTEGER mSecond;
	static LARGE_INTEGER mTime;
	static float mDeltaTime;
};

