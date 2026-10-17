struct PS_Output_Single
{
    float4 Color : SV_TARGET;
};

cbuffer Transform : register(b0)
{
    matrix gmatWorld;
    matrix gmatView;
    matrix gmatProj;
    matrix gmatWV;
    matrix gmatWVP;
    float3 gPivot;
    float gTransformEmpty;
}

cbuffer Material : register(b1)
{
    float4 gMtrlBaseColor;
    float gMtrlOpacity;
    int gMtrlTextureWidth;
    int gMtrlTextureHeight;
    float gMtrlEmpty;
}

cbuffer Animation2D : register(b2)
{
    float2 gAnim2DLTUV;
    float2 gAnim2DRBUV;
    int gAnim2DEnable;
    int gAnim2DFlip;
    float2 Empty;
}

SamplerState gBaseSampler : register(s0);

Texture2D gBaseTexture : register(t0);

float2 UpdateAnimation2D(float2 UV)
{
    if (gAnim2DEnable == 0) return UV;
    float2 Result = (float2) 0.f;
    if (UV.x == 0.f) Result.x = gAnim2DLTUV.x;
    else Result.x = gAnim2DRBUV.x;
    if (UV.y == 0.f) Result.y = gAnim2DLTUV.y;
    else Result.y = gAnim2DRBUV.y;
    return Result;
}


