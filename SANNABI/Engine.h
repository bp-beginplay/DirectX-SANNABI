#pragma once

#include <Windows.h>
#include <vector>
#include <list> 
#include <map>
#include <unordered_map>
#include <crtdbg.h>
#include <functional>
#include <string>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <d2d1.h>
#include <algorithm>
#include <dwrite_3.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")	
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")

#include "DirectXTex.h"
#ifdef _DEBUG
#pragma comment(lib, "../Bin/DirectXTex_Debug.lib")
#else
#pragma comment(lib, "../Bin/DirectXTex.lib")
#endif

#include "Math.h"
#include "Object.h"
#include "SharedPtr.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "Matrix.h"
#include "CollisionChannel.h"
#include "Log.h"

using namespace std;



#define SAFE_DELETE(p) if(p) { delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) { delete[] p; p = nullptr;}
#define SAFE_RELEASE(p) if(p) {p->Release(); p = nullptr;}

#define DECLARE_SINGLETON(ClassName) \
private: \
	ClassName(); \
	~ClassName(); \
public: \
	static ClassName* GetInst() \
	{ \
		static ClassName instance; \
		return &instance; \
	} \

extern	TCHAR gRootPath[MAX_PATH];
extern	char gRootPathMultibyte[MAX_PATH];

struct FResolution
{
	unsigned int Width = 0;
	unsigned int Height = 0;
};

struct FVertexBuffer
{
	ID3D11Buffer* Buffer = nullptr;
	int Size = 0;
	int Count = 0;
	void* Data = nullptr;

	FVertexBuffer() = default;
	~FVertexBuffer()
	{
		SAFE_RELEASE(Buffer);
		SAFE_DELETE_ARRAY(Data);
	}
};

struct FIndexBuffer
{
	ID3D11Buffer* Buffer = nullptr;
	int Size = 0;
	int Count = 0;
	DXGI_FORMAT Fmt = DXGI_FORMAT_UNKNOWN;
	void* Data = nullptr;

	FIndexBuffer() = default;
	~FIndexBuffer()
	{
		SAFE_RELEASE(Buffer);
		SAFE_DELETE_ARRAY(Data);
	}
};

struct FVertexTexture
{
	FVector3D Pos;
	FVector2D UV;

	FVertexTexture() = default;
	FVertexTexture(float x, float y, float z, float u, float v) : Pos(x, y, z), UV(u, v) {}
};

struct FVertexColor
{
	FVector3D Pos;
	FVector4D Color;

	FVertexColor() {}
	FVertexColor(const FVector3D& _pos, const FVector4D& _Color) : Pos(_pos), Color(_Color) {}
	FVertexColor(float x, float y, float z, float r, float g, float b, float a) : Pos(x, y, z), Color(r, g, b, a) {}
};

namespace EShaderBufferType
{
	enum Type
	{
		Vertex = 0x1,
		Pixel = 0x2,
		Hull = 0x4,
		Domain = 0x8,
		Geometry = 0x10,
		Compute = 0x20,
		Graphic = Vertex | Pixel | Hull | Domain | Geometry,
		All = Vertex | Pixel | Hull | Domain | Geometry | Compute
	};
}

enum class EColliderType
{
	Collider2D,
	Collider3D
};

enum class EColliderShape
{
	AABB2D,
	Sphere2D,
	OBB2D,
	Line2D,
	Point
};

struct FAABB2D
{
	FVector2D Min;
	FVector2D Max;
};

struct FOBB2D
{
	FVector2D Center;
	FVector2D Axis[2];
	FVector2D HalfSize;
};

struct FLine2D
{
	FVector2D Start;
	FVector2D End;
};

namespace ECollisionInteraction
{
	enum Type : unsigned char
	{
		Ignore,
		Collision,
		End
	};
}

struct FCollisionProfile
{
	std::string Name; 
	ECollisionChannel::Type Channel = ECollisionChannel::Default;
	bool Enable = true;
	ECollisionInteraction::Type Interaction[ECollisionChannel::End];
};

enum class EAssetType
{
	Mesh,
	Texture,
	Material,
	Animation2D,
	Sound
};

namespace ERenderStateType
{
	enum Type
	{
		Blend,
		Rasterizer,
		DepthStencil
	};
}

enum class EComponentRender
{
	None,
	Render
};

enum class ERenderSortType
{
	None,
	Y,
	Alpha 
};

enum class EAnimationTextureType
{
	SpriteSheet,
	Frame
};

struct FMaterialPixelShader
{
	ID3DBlob* Blob = nullptr;
	ID3D11PixelShader* PS = nullptr;

	~FMaterialPixelShader()
	{
		SAFE_RELEASE(Blob);
		SAFE_RELEASE(PS);
	}
};

struct FTransformCBufferInfo
{
	FMatrix matWorld;
	FMatrix matView;
	FMatrix matProj;
	FMatrix matWV;
	FMatrix matWVP;
	FVector3D Pivot;
	float Empty;
};

struct FUICBufferInfo
{
	//텍스쳐에 대한 보정 색상 
	FVector4D BrushTint = FVector4D::White;      //16
	//Widget에 대한 보정 색상 
	FVector4D Color = FVector4D::White;     //16
	//LT Left-Top
	FVector2D LTUV; //8
	//RB Right-Bottom
	FVector2D RBUV; //8
	// 애니메이션 사용 여부
	int BrushAnimEnable; // 4
	// 텍스쳐 사용 여부 
	int BrushTextureEnable; // 4
	//UI 플립
	int UIFlip;
	//Empty
	float BrushEmpty;     //8
};


struct FMaterialCBufferInfo
{
	FVector4D BaseColor;
	float Opacity;
	int TextureWidth;
	int TextureHeight;
	float Empty;
};

struct FAnimation2DBufferInfo
{
	FVector2D LTUV;
	FVector2D RBUV;
	int AnimEnable;
	int AnimFlip;
	FVector2D Empty;
};

struct FSpriteCBufferInfo
{
	FVector4D Tint;
};

struct FColliderCBufferInfo
{
	FVector4D Color;
};

struct FTextureInfo
{
	DirectX::ScratchImage* Image = nullptr;
	ID3D11ShaderResourceView* SRV = nullptr;
	unsigned int Width = 0;
	unsigned int Height = 0;
	TCHAR FileName[MAX_PATH] = {};
	~FTextureInfo()
	{
		SAFE_DELETE(Image);
		SAFE_RELEASE(SRV);
	}
};

namespace ETextureSamplerType
{
	enum Type
	{
		Point,
		Linear,
		Anisotropic,
		End
	};
}

//머티리얼이 들고있을 텍스쳐 정보
struct FMaterialTextureInfo
{
	//텍스쳐 이름 
	std::string Name;
	//사용할 텍스쳐
	TSharedPtr<class CTexture> Texture;
	//텍스쳐를 넣을 레지스터 번호
	int Register = 0;
	// ShaderBufferType 쉐이더 타입도 넣어준다. 
	int ShaderBufferType = (int)EShaderBufferType::Pixel;
	// 텍스쳐 인덱스
	int TextureIndex = 0;
};

struct FAnimationFrame
{
	FVector2D Start;    // 이미지 시작 좌표
	FVector2D Size;     // 한 프레임 이미지에 크기 
};

struct FUIBrush
{
	//이미지
	TSharedPtr<class CTexture> Texture;
	//색상
	FVector4D Tint = FVector4D::White;
	//애니메이션 정보
	std::vector<FAnimationFrame> Frames;
	bool	AnimationEnable = false;
	int		Frame = 0;
	float	Time = 0.f;
	float	FrameTime = 0.f;
	float	PlayTime = 1.f;
	float	PlayRate = 1.f;
};