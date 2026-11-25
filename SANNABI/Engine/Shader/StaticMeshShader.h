#pragma once

#include "Engine/Shader/GraphicShader.h"

class CStaticMeshShader : public CGraphicShader
{
    friend class CShaderManager;

protected:
    CStaticMeshShader();
    virtual ~CStaticMeshShader();

public:
    bool Init();
};