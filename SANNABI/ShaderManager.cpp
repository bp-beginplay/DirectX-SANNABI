#include "ShaderManager.h"
#include "ColorMeshShader.h"
#include "FrameMeshShader.h"
#include "StaticMeshShader.h"
#include "SpriteShader.h"
#include "ConstantBuffer.h"
#include "Device.h"
#include "UIShader.h"

CShaderManager::CShaderManager() {}

CShaderManager::~CShaderManager()
{
	auto iter = mPixelShaderMap.begin();
	auto iterEnd = mPixelShaderMap.end();
	for (; iter != iterEnd; ++iter)
	{
		SAFE_DELETE(iter->second);
	}
}

bool CShaderManager::Init()
{
	CreateShader<CColorMeshShader>("ColorMeshShader");
	CreateShader<CFrameMeshShader>("FrameMeshShader");
	CreateShader<CStaticMeshShader>("StaticMeshShader");
	CreateShader<CSpriteShader>("SpriteShader");
	CreateShader<CUIShader>("UIShader");
	if (!LoadPixelShader("DefaultMaterialShader", "DefaultMaterialPS", TEXT("Mesh.fx")))
	{
		return false;
	}
	CreateContantBuffer("Transform", sizeof(FTransformCBufferInfo), 0, EShaderBufferType::Vertex);
	CreateContantBuffer("Material", sizeof(FMaterialCBufferInfo), 1, EShaderBufferType::Pixel);
	CreateContantBuffer("Animation2D", sizeof(FAnimation2DBufferInfo), 2, EShaderBufferType::Vertex);
	CreateContantBuffer("Sprite", sizeof(FSpriteCBufferInfo), 3, EShaderBufferType::Pixel);
	CreateContantBuffer("UI", sizeof(FUICBufferInfo), 3, EShaderBufferType::Vertex | EShaderBufferType::Pixel);
	CreateContantBuffer("Collider", sizeof(FColliderCBufferInfo), 4, EShaderBufferType::Pixel);
	return true;
}

CShader* CShaderManager::FindShader(const std::string& Name)
{
	auto iter = mShaderMap.find(Name);
	if (iter == mShaderMap.end()) return nullptr;
	return (CShader*)iter->second.Get();
}

void CShaderManager::ReleaseShader(const std::string& Name)
{
	auto iter = mShaderMap.find(Name);
	if (iter != mShaderMap.end()) mShaderMap.erase(iter);
}

bool CShaderManager::CreateContantBuffer(const std::string& Name, int Size, int Register, int ShaderBufferType)
{
	CConstantBuffer* CBuffer = FindCBuffer(Name);
	if (CBuffer) return true;
	CBuffer = new CConstantBuffer;
	if (!CBuffer->Init(Size, Register, ShaderBufferType))
	{
		SAFE_DELETE(CBuffer);
		return false;
	}
	mCBufferMap.insert(std::make_pair(Name, CBuffer));
	return true;
}

CConstantBuffer* CShaderManager::FindCBuffer(const std::string& Name)
{
	auto iter = mCBufferMap.find(Name);
	if (iter == mCBufferMap.end()) return nullptr;
	return (CConstantBuffer*)iter->second.Get();
}

void CShaderManager::ReleaseCBuffer(const std::string& Name)
{
	auto iter = mCBufferMap.find(Name);
	if (iter != mCBufferMap.end()) mCBufferMap.erase(iter);
}

bool CShaderManager::LoadPixelShader(const std::string& Name, const char* EntryName, const TCHAR* FileName)
{
	if (FindPixelShader(Name)) return true;
	TCHAR FullPath[MAX_PATH] = {};
	lstrcpy(FullPath, TEXT("../Bin/Shader/"));
	lstrcat(FullPath, FileName);
	ID3DBlob* ErrorBlob = nullptr;
	unsigned int Flag = 0;
#ifdef _DEBUG
	Flag = D3DCOMPILE_DEBUG;
#endif
	FMaterialPixelShader* mps = new FMaterialPixelShader;
	if (FAILED(D3DCompileFromFile(FullPath, nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, EntryName, "ps_5_0", Flag, 0, &mps->Blob, &ErrorBlob)))
	{
#ifdef _DEBUG
		char ErrorText[512] = {};
		strcpy_s(ErrorText, (const char*)ErrorBlob->GetBufferPointer());
		strcat_s(ErrorText, "\n");
		OutputDebugStringA(ErrorText);
#endif
		return false;
	}
	if (FAILED(CDevice::GetInst()->GetDevice()->CreatePixelShader(mps->Blob->GetBufferPointer(), mps->Blob->GetBufferSize(), nullptr, &mps->PS)))
	{
		return false;
	}
	mPixelShaderMap.insert(std::make_pair(Name, mps));
	return true;
}

const FMaterialPixelShader* CShaderManager::FindPixelShader(const std::string& Name)
{
	auto iter = mPixelShaderMap.find(Name);
	if (iter == mPixelShaderMap.end()) return nullptr;
	return iter->second;
}