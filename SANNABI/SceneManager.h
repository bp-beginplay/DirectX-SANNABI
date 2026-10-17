#pragma once

#include"Engine.h"

class CSceneManager
{
	DECLARE_SINGLETON(CSceneManager)

public:
	bool Init();
	void Input(float DeltaTime);
	void Update(float DeltaTime);
	void Render();
	void Collision(float DeltaTime);

	void RenderUI();
	void EndFrame();

	template <typename T>
	T* CreateScene();

	template <typename T>
	T* CreateLoadScene()
	{
		T* Scene = new T;

		if (!Scene->Init())
		{
			SAFE_DELETE(Scene);
			return nullptr;
		}

		mLoadScene = Scene;

		return Scene;
	}

private:
	class CScene* mCurrentScene = nullptr;
	class CScene* mLoadScene = nullptr;
};

template<typename T>
inline T* CSceneManager::CreateScene()
{
	T* Scene = new T;
	if (!Scene->Init())
	{
		SAFE_DELETE(Scene);
		return nullptr;
	}
	return Scene;
}