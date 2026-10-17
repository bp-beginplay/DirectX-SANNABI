#include "Timer.h"

LARGE_INTEGER CTimer::mSecond = {};
LARGE_INTEGER CTimer::mTime = {};
float CTimer::mDeltaTime = 0.f;

void CTimer::Init()
{
    QueryPerformanceFrequency(&mSecond);
    QueryPerformanceCounter(&mTime);
}

float CTimer::Update()
{
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);
    mDeltaTime = (time.QuadPart - mTime.QuadPart) / (float)mSecond.QuadPart;
    mTime = time;
    return mDeltaTime;
}

float CTimer::GetDeltaTime()
{
    return mDeltaTime;
}