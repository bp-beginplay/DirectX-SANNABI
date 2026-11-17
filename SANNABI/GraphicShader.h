#pragma once
#include "Shader.h"

class CGraphicShader abstract : public CShader
{
	friend class CShaderManager;

protected:
	CGraphicShader();
	virtual ~CGraphicShader();

public:
	virtual bool Init();
	virtual void SetShader() final;
	void AddInputLayoutDesc(const char* Semantic, unsigned int SemanticIndex, DXGI_FORMAT Fmt, unsigned int InputSlot, unsigned int Size, D3D11_INPUT_CLASSIFICATION InPutSlotClass, unsigned int InstanceDataStepRate);
	bool CreateInputLayout();
	bool LoadVertexShader(const char* EntryName, const TCHAR* FileName);
	bool LoadPixelShader(const char* EntryName, const TCHAR* FileName);
	bool LoadHullShader(const char* EntryName, const TCHAR* FileName);
	bool LoadDomainShader(const char* EntryName, const TCHAR* FileName);
	bool LoadGeometryShader(const char* EntryName, const TCHAR* FileName);

private:
	ID3D11InputLayout* mInputLayout = nullptr;
	std::vector<D3D11_INPUT_ELEMENT_DESC> mvecDesc;
	unsigned int mInputLayerSize = 0;
	ID3D11VertexShader* mVS = nullptr;
	ID3DBlob* mVSBlob = nullptr;
	ID3D11PixelShader* mPS = nullptr;
	ID3DBlob* mPSBlob = nullptr;
	ID3D11HullShader* mHS = nullptr;
	ID3DBlob* mHSBlob = nullptr;
	ID3D11DomainShader* mDS = nullptr;
	ID3DBlob* mDSBlob = nullptr;
	ID3D11GeometryShader* mGS = nullptr;
	ID3DBlob* mGSBlob = nullptr;
};

