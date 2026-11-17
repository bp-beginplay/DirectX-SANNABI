#include "ExplodeEffect.h"
#include "Animation2D.h"
#include "AudioComponent.h"

EExplodeEffect::EExplodeEffect()
{
}

EExplodeEffect::EExplodeEffect(const EExplodeEffect& Obj) : ESpriteEffect(Obj)
{
}

EExplodeEffect::EExplodeEffect(EExplodeEffect&& Obj) : ESpriteEffect(Obj)
{
}

EExplodeEffect::~EExplodeEffect()
{
}

bool EExplodeEffect::Init()
{
	ESpriteEffect::Init();



    return true;
}

void EExplodeEffect::Update(float DeltaTime)
{
	ESpriteEffect::Update(DeltaTime);
}

void EExplodeEffect::AnimationEnd()
{
	ESpriteEffect::AnimationEnd();
}

void EExplodeEffect::SetAnimation(const std::string& Name, float PlayTime, float PlayRate, bool Loop, bool Reverse)
{
	mLoop = Loop;
	mAnimation->AddSequence(Name, PlayTime, PlayRate, Loop, Reverse);
	mAnimation->SetEndFunction<EExplodeEffect>(Name, this, &EExplodeEffect::AnimationEnd);
}