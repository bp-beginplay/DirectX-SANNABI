#include "Game/Enemy/BulletExplodeEffect.h"
#include "Engine/Animation/Animation2D.h"
#include "Engine/Component/AudioComponent.h"

EBulletExplodeEffect::EBulletExplodeEffect()
{
}

EBulletExplodeEffect::EBulletExplodeEffect(const EBulletExplodeEffect& Obj)
{
}

EBulletExplodeEffect::EBulletExplodeEffect(EBulletExplodeEffect&& Obj)
{
}

EBulletExplodeEffect::~EBulletExplodeEffect()
{
}

bool EBulletExplodeEffect::Init()
{
	ESpriteEffect::Init();

	mAudio->SetSound("EnemyExplode");

	return true;
}

void EBulletExplodeEffect::Update(float DeltaTime)
{
	ESpriteEffect::Update(DeltaTime);
}

void EBulletExplodeEffect::AnimationEnd()
{
	ESpriteEffect::AnimationEnd();
}

void EBulletExplodeEffect::SetAnimation(const std::string& Name, float PlayTime, float PlayRate, bool Loop, bool Reverse)
{
	mLoop = Loop;
	mAnimation->AddSequence(Name, PlayTime, PlayRate, Loop, Reverse);
	mAnimation->SetEndFunction<EBulletExplodeEffect>(Name, this, &EBulletExplodeEffect::AnimationEnd);
}
