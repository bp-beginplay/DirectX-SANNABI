#pragma once

#include "Engine.h"
#include "Shader.h"

class CShaderManager
{
	DECLARE_SINGLETON(CShaderManager);

public:
	bool Init();

	class CShader* FindShader(const std::string& Name);
	void ReleaseShader(const std::string& Name);

	bool CreateContantBuffer(const std::string& Name, int Size, int Register, int ShaderBufferType);
	class CConstantBuffer* FindCBuffer(const std::string& Name);
	void ReleaseCBuffer(const std::string& Name);

	bool LoadPixelShader(const std::string& Name, const char* EntryName, const TCHAR* FileName);
	const FMaterialPixelShader* FindPixelShader(const std::string& Name);
	
	template <typename T>
	bool CreateShader(const std::string& Name);

private:
	std::unordered_map<std::string, TSharedPtr<CShader>> mShaderMap;
	std::unordered_map<std::string, TSharedPtr<class CConstantBuffer>> mCBufferMap;
	std::unordered_map<std::string, FMaterialPixelShader*> mPixelShaderMap;
};

template<typename T>
inline bool CShaderManager::CreateShader(const std::string& Name)
{
	CShader* Shader = FindShader(Name);
	if (Shader) return true;
	Shader = new T;
	if (!Shader->Init())
	{
		SAFE_DELETE(Shader);
		return false;
	}
	mShaderMap.insert(std::make_pair(Name, Shader));
	return true;
}