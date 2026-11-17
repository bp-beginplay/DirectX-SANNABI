#pragma once

#include "Engine.h"

class CAnimation2DManager
{
    friend class CAssetManager;

private:
    CAnimation2DManager();
    ~CAnimation2DManager();

public:
    bool Init();
    bool CreateAnimation(const std::string& Name);
    class CAnimation2DData* FindAnimation(const std::string& Name);
    void ReleaseAnimation(class CAsset* Animation);
    bool SetAnimationTextureType(const std::string& Name, EAnimationTextureType Type);
    bool SetTexture(const std::string& Name, class CTexture* Texture);
    bool SetTexture(const std::string& Name, const std::string& TextureName);
    bool SetTexture(const std::string& Name, const std::string& TextureName, const TCHAR* FileName);
    bool SetTexture(const std::string& Name, const std::string& TextureName, std::vector<const TCHAR*> FileName);
    bool SetTexture(const std::string& Name, const std::string& TextureName, const TCHAR* FileName, const TCHAR* Ext, int Count);
    bool SetTextureFullPath(const std::string& Name, const std::string& TextureName, const TCHAR* FullPath);
    bool SetTextureFullPath(const std::string& Name, const std::string& TextureName, const std::vector<const TCHAR*>& FullPath);

    bool AddFrame(const std::string& Name, const FVector2D& Start, const FVector2D& Size);
    bool AddFrame(const std::string& Name, float StartX, float StartY, float SizeX, float SizeY);
    bool AddFrameCount(const std::string& Name, int Count, const FVector2D& Start, const FVector2D& Size);
    bool AddFrameCount(const std::string& Name, int Count, float StartX, float StartY, float SizeX, float SizeY);

private:
    std::unordered_map<std::string, TSharedPtr<class CAnimation2DData>> mAnimationMap;
};