#include "AssetManager.h"
#include "MaterialManager.h"
#include "MeshManager.h"
#include "TextureManager.h"
#include "Animation2DManager.h"
#include "SoundManager.h"
#include "Asset.h"

CAssetManager::CAssetManager() {}

CAssetManager::~CAssetManager()
{
	SAFE_DELETE(Animation2DManager);
	SAFE_DELETE(MeshManager);
	SAFE_DELETE(MaterialManager);
	SAFE_DELETE(TextureManager);
	SAFE_DELETE(SoundManager);
}

bool CAssetManager::Init()
{
	GetModuleFileName(0, gRootPath, MAX_PATH);
	int Length = lstrlen(gRootPath);
	for (int i = Length - 1; i >= 0; --i)
	{
		if (gRootPath[i] == '/' || gRootPath[i] == '\\')
		{
			memset(&gRootPath[i + 1], 0, sizeof(TCHAR) * (Length - (i + 1)));
			break;
		}
	}
	Length = WideCharToMultiByte(CP_ACP, 0, gRootPath, -1, nullptr, 0, nullptr, nullptr);
	WideCharToMultiByte(CP_ACP, 0, gRootPath, -1, gRootPathMultibyte, Length, nullptr, nullptr);
	MaterialManager = new CMaterialManager;
	if (!MaterialManager->Init())
	{
		SAFE_DELETE(MaterialManager);
		return false;
	}
	MeshManager = new CMeshManager;
	if (!MeshManager->Init())
	{
		SAFE_DELETE(MeshManager);
		return false;
	}
	TextureManager = new CTextureManager;
	if (!TextureManager->Init())
	{
		SAFE_DELETE(TextureManager);
		return false;
	}
	Animation2DManager = new CAnimation2DManager;
	if (!Animation2DManager->Init())
	{
		SAFE_DELETE(Animation2DManager);
		return false;
	}
	SoundManager = new CSoundManager;
	if (!SoundManager->Init())
	{
		SAFE_DELETE(SoundManager);
		return false;
	}
	return true;
}

void CAssetManager::ReleaseAsset(class CAsset* Asset)
{
	switch (Asset->GetAssetType())
	{
	case EAssetType::Mesh:
		MeshManager->ReleaseMesh(Asset);
		break;
	case EAssetType::Texture:
		TextureManager->ReleaseTexture(Asset);
		break;
	case EAssetType::Material:
		MaterialManager->ReleaseMaterial(Asset);
		break;
	case EAssetType::Animation2D:
		Animation2DManager->ReleaseAnimation(Asset);
		break;
	case EAssetType::Sound:
		SoundManager->ReleaseSound(Asset);
		break;
	}
}