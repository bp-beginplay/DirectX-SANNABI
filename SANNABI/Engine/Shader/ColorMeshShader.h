#include "Engine/Shader/GraphicShader.h"

class CColorMeshShader : public CGraphicShader
{
    friend class CShaderManager;

protected:
    CColorMeshShader();
    virtual ~CColorMeshShader();

public:
    bool Init();
};