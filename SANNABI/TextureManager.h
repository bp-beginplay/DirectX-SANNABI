#pragma once

#include "Engine.h"

class CTextureManager
{
	friend class CAssetManager;

private:
	CTextureManager();
	~CTextureManager();

public:
	bool Init();

public:
	bool LoadTexture(const std::string& Name, const TCHAR* FileName);
	bool LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath);
	bool LoadTexture(const std::string& Name, const std::vector<const TCHAR*>& FileName);
	bool LoadTextureFullPath(const std::string& Name, const std::vector<const TCHAR*>& FullPath);
	bool LoadTexture(const std::string& Name, const TCHAR* FileName, const TCHAR* Ext, int Count);
	class CTexture* FindTexture(const std::string& Name);
	void ReleaseTexture(class CAsset* Texture);

private:
	std::unordered_map<std::string, TSharedPtr<class CTexture>> mTextureMap;
};