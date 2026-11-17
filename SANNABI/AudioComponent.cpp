#include "AudioComponent.h"

#include "Sound.h"
#include "SoundManager.h"
#include "Scene.h"
#include "SceneAssetManager.h"
#include "AssetManager.h"


CAudioComponent::CAudioComponent()
{
}

CAudioComponent::CAudioComponent(const CAudioComponent& Com)
	: CSceneComponent(Com)
{
}

CAudioComponent::CAudioComponent(CAudioComponent&& Com)
	: CSceneComponent(Com)
{
}

CAudioComponent::~CAudioComponent()
{
	if (Sound)
	{
		Sound->Stop();
	}
}

void CAudioComponent::SetSound(const std::string& Name)
{
	if (mScene)
	{
		Sound = mScene->GetAssetManager()->FindSound(Name);
	}
	else
	{
		Sound = CAssetManager::GetInst()->GetSoundManager()->FindSound(Name);
	}


	if (Sound)
	{
		Sound->Play();
	}
}

void CAudioComponent::SetSound(const std::string& Name, const std::string& GroupName, bool Loop, const char* FileName)
{
	if (mScene)
	{
		if (!mScene->GetAssetManager()->LoadSound(Name, GroupName, Loop, FileName))
		{
			return;
		}
		Sound = mScene->GetAssetManager()->FindSound(Name);

	}
	else
	{
		if (!CAssetManager::GetInst()->GetSoundManager()->LoadSound(Name, GroupName, Loop, FileName))
		{
			return;
		}
		Sound = CAssetManager::GetInst()->GetSoundManager()->FindSound(Name);
	}

	if (Sound)
	{
		Sound->Play();
	}
}

void CAudioComponent::LoadSoundFullPath(const std::string& Name, const std::string& GroupName, bool Loop,
	const char* FullPath)
{
	if (mScene)
	{
		if (!mScene->GetAssetManager()->LoadSoundFullPath(Name, GroupName, Loop, FullPath))
		{
			return;
		}
		Sound = mScene->GetAssetManager()->FindSound(Name);

	}
	else
	{
		if (!CAssetManager::GetInst()->GetSoundManager()->LoadSoundFullPath(Name, GroupName, Loop, FullPath))
		{
			return;
		}
		Sound = CAssetManager::GetInst()->GetSoundManager()->FindSound(Name);
	}

	if (Sound)
	{
		Sound->Play();
	}
}

bool CAudioComponent::Init()
{
	return CSceneComponent::Init();
}

bool CAudioComponent::Init(const char* FileName)
{
	return CSceneComponent::Init(FileName);
}

void CAudioComponent::Update(float DeltaTime)
{
	CSceneComponent::Update(DeltaTime);
}

CAudioComponent* CAudioComponent::Clone()
{
	return new CAudioComponent(*this);
}
