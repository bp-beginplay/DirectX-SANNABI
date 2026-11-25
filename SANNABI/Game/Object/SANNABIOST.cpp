#include "Game/Object/SANNABIOST.h"
#include "Engine/Component/SpriteComponent.h"
#include "Engine/Animation/Animation2D.h"
#include "Engine/Component/AudioComponent.h"
#include "Engine/Scene/Scene.h"
#include "Engine/Input/Input.h"
#include "Engine/Scene/SceneManager.h"
#include "Game/Scene/SceneStart.h"
#include "Engine/Asset/AssetManager.h"
#include "Engine/Asset/SoundManager.h"

CSANNABIOST::CSANNABIOST()
{
}

CSANNABIOST::CSANNABIOST(const CSANNABIOST& Obj)
{
}

CSANNABIOST::CSANNABIOST(CSANNABIOST&& Obj)
{
}

CSANNABIOST::~CSANNABIOST()
{
}

bool CSANNABIOST::Init()
{
	AActor::Init();
	CAssetManager::GetInst()->GetSoundManager()->Stop("SceneMainBGM");
	mAudio->SetSound("SANNABIOST");
	Sprite->SetTint(1.f, 1.f, 1.f);
	Sprite->SetPivot(0.5f, 0.5f);
	Sprite->SetOpacity(1.f);
	Sprite->SetUseTime(true);
	mAnimation = Sprite->CreateAnimation2D<CAnimation2D>();
	mAnimation->AddSequence("ostVideo", 250.f, 1.f, false, false);
	//mAnimation->AddSequence("ostVideo", 25.f, 1.f, false, false);
	mAnimation->ChangeAnimation("ostVideo");

	mScene->GetInput()->AddBindKey("ESC", VK_ESCAPE);
	mScene->GetInput()->AddBindFunction("ESC", EInputType::Down, this, &CSANNABIOST::BackStartScene);

	return true;
}

void CSANNABIOST::Update(float DeltaTime)
{
	AActor::Update(DeltaTime);

	if (CountDown(241.f, DeltaTime))
	{
		CSceneManager::GetInst()->CreateLoadScene<CSceneStart>();
	}
}

void CSANNABIOST::BackStartScene()
{
	CSceneManager::GetInst()->CreateLoadScene<CSceneStart>();
}

//void CSANNABIOST::StopSound()
//{
//	CAssetManager::GetInst()->GetSoundManager()->Stop("SANNABIOST");
//}
