#pragma once
#include "Engine/Shader/GraphicShader.h"

class CSpriteShader : public CGraphicShader
{
    friend class CShaderManager;

protected:
    CSpriteShader();
    virtual ~CSpriteShader();

public:
    bool Init();
};