#pragma once

#include "Engine.h"

class CAssetManager
{
	DECLARE_SINGLETON(CAssetManager)

public:
	bool Init();
	void ReleaseAsset(class CAsset* Asset);

	class CMeshManager* GetMeshManager() const { return MeshManager; }
	class CTextureManager* GetTextureManager() const { return TextureManager; }
	class CMaterialManager* GetMaterialManager() const { return MaterialManager; }
	class CAnimation2DManager* GetAnimationManager() const { return Animation2DManager; }
	class CSoundManager* GetSoundManager() const { return SoundManager; }

private:
	class CMeshManager* MeshManager = nullptr;
	class CTextureManager* TextureManager = nullptr;
	class CMaterialManager* MaterialManager = nullptr;
	class CAnimation2DManager* Animation2DManager = nullptr;
	class CSoundManager* SoundManager = nullptr;
};