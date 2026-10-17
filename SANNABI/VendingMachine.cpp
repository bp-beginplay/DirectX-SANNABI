#include "VendingMachine.h"
#include "SpriteComponent.h"
#include "Animation2D.h"
#include "SceneManager.h"
#include "EndScene.h"
#include "AudioComponent.h"

AVendingMachine::AVendingMachine()
{
}

AVendingMachine::AVendingMachine(const AVendingMachine& Obj)
{
}

AVendingMachine::AVendingMachine(AVendingMachine&& Obj) noexcept
{
}

AVendingMachine::~AVendingMachine()
{
}

bool AVendingMachine::Init()
{
	AActor::Init();
	mAudio->SetSound("Vending");
	//Sprite->SetTexture("Machine", TEXT("VendingMachine/VendingMachine_Idle (1).png"), 0);
	Sprite->SetTint(1.f, 1.f, 1.f);
	Sprite->SetPivot(0.5f, 0.5f);
	Sprite->SetOpacity(1.f);
	Colli->SetCollisionProfile("VendingMachine");
	Colli->SetCollisionBeginFunc<AVendingMachine>(this, &AVendingMachine::EndScene);
	mAnimation = Sprite->CreateAnimation2D<CAnimation2D>();
	mAnimation->AddSequence("VendingMachine_Idle", 3.f, 1.f, true, false);
	mAnimation->ChangeAnimation("VendingMachine_Idle");
	return true;
}

void AVendingMachine::Update(float DeltaTime)
{
	AActor::Update(DeltaTime);
}

void AVendingMachine::EndScene(const FVector3D& HitPoint, CColliderBase* Dest)
{
	//CLog::PrintLog("Active");
	CSceneManager::GetInst()->CreateLoadScene<CEndScene>();
}
