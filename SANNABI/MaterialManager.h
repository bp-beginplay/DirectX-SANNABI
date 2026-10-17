#pragma once

#include "Engine.h"

class CMaterialManager
{
	friend class CAssetManager;

private:
	CMaterialManager();
	~CMaterialManager();

public:
	bool Init();
	bool CreateMaterial(const std::string& Name);
	class CMaterial* FindMaterial(const std::string& Name);
	void ReleaseMaterial(class CAsset* Material);

private:
	std::unordered_map<std::string, TSharedPtr<class CMaterial>> mMaterialMap;
};