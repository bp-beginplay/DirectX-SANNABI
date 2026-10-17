#pragma once

#include "Asset.h"

class CTexture : public CAsset
{
    friend class CTextureManager;

private:
    CTexture();
    ~CTexture();

public:
    bool LoadTexture(const TCHAR* FileName);
    bool LoadTextureFullPath(const TCHAR* FullPath);
    bool LoadTexture(const std::vector<const TCHAR*>& FileName);
    bool LoadTextureFullPath(const std::vector<const TCHAR*>& FullPath);
    bool LoadTexture(const TCHAR* FileName, const TCHAR* Ext, int Count);
    void SetShader(int Register, int ShaderBufferType, int TextureIndex);
    void ResetShader(int Register, int ShaderBufferType);

protected:
    bool CreateResourceView(int Index = 0);

public:
    const FTextureInfo* GetTexture(int Index = 0) { return mTextureList[Index]; }
    int GetTextureCount() const { return (int)mTextureList.size(); }

private:
    std::vector<FTextureInfo*> mTextureList;
};

