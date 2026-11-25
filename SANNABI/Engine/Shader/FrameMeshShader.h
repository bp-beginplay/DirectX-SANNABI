#pragma once

#include "Engine/Shader/GraphicShader.h"

class CFrameMeshShader : public CGraphicShader
{
    friend class CShaderManager;

protected:
    CFrameMeshShader();
    virtual ~CFrameMeshShader();

public:
    bool Init();
};