#pragma once

#include "SceneComponent.h"

class CAudioComponent :
	public CSceneComponent
{
	friend class CScene;
	friend class AActor;

protected:
	CAudioComponent();
	CAudioComponent(const CAudioComponent& Com);
	CAudioComponent(CAudioComponent&& Com);
	virtual ~CAudioComponent();

protected:
	TSharedPtr<class CSound> Sound;

public:
	void SetSound(const std::string& Name);
	void SetSound(const std::string& Name, const std::string& GroupName, bool Loop, const char* FileName);
	void LoadSoundFullPath(const std::string& Name, const std::string& GroupName, bool Loop, const char* FullPath);

public:
	virtual bool Init();
	virtual bool Init(const char* FileName);
	virtual void Update(float DeltaTime);
	virtual CAudioComponent* Clone();
};