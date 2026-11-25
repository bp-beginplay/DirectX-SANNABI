#pragma once
#include "Engine/Shader/GraphicShader.h"

class CUIShader :
    public CGraphicShader
{
    friend class CShaderManager;

protected:
    CUIShader();
    virtual ~CUIShader();

public:
    bool Init();
};

