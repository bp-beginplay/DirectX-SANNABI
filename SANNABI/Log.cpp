#include "Log.h"

std::vector<std::string> CLog::mvecLog;
HANDLE CLog::hConsole;

bool CLog::Init()
{
#ifdef _DEBUG
	AllocConsole();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND hWndConsole = GetConsoleWindow();
	SetWindowPos(hWndConsole, NULL, 1000, 500, 0, 0, SWP_NOSIZE);
#else
#endif
	mvecLog.reserve(10000);
	return true;
}

void CLog::Destroy()
{
#ifdef _DEBUG
	FreeConsole();
#else
#endif
}

void CLog::PrintLog(const std::string& Text, ELogPrintType PrintType)
{
	std::string OutputText = Text;
	OutputText += "\n";
	mvecLog.emplace_back(OutputText);
	DWORD Number = 0;
	switch (PrintType)
	{
	case ELogPrintType::Console:
		WriteConsoleA(hConsole, OutputText.c_str(), (DWORD)OutputText.length(), &Number, nullptr);
		break;
	case ELogPrintType::VisualOutput:
		OutputDebugStringA(OutputText.c_str());
		break;
	case ELogPrintType::All:
		WriteConsoleA(hConsole, OutputText.c_str(), (DWORD)OutputText.length(), &Number, nullptr);
		OutputDebugStringA(OutputText.c_str());
		break;
	}
}

void CLog::SaveLog()
{
	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	char TimeText[256] = {};
	sprintf_s(TimeText, "../Bin/Log/[%d_%d_%d %d_%d_%d_%d].txt",
		sysTime.wYear, sysTime.wMonth, sysTime.wDay, sysTime.wHour,
		sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);
	FILE* File = nullptr;
	fopen_s(&File, TimeText, "wt");
	if (!File) return;
	size_t Size = mvecLog.size();
	for (size_t i = 0; i < Size; ++i)
	{
		fputs(mvecLog[i].c_str(), File);
	}
	fclose(File);
}
