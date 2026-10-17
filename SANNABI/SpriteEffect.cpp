#include "SpriteEffect.h"
#include "SpriteComponent.h"
#include "AudioComponent.h"
#include "Animation2D.h"


ESpriteEffect::ESpriteEffect() {}
ESpriteEffect::ESpriteEffect(const ESpriteEffect& Obj) : AActor(Obj) {}
ESpriteEffect::ESpriteEffect(ESpriteEffect&& Obj) : AActor(Obj) {}
ESpriteEffect::~ESpriteEffect() 
{ 

}

bool ESpriteEffect::Init()
{
	mRoot = CreateComponent<CSpriteComponent>();
	SetRootComponent(mRoot);
	mRoot->SetPivot(0.5f, 0.5f);
	
	mAudio = CreateComponent<CAudioComponent>();
	mRoot->AddChild(mAudio);
	mAnimation = mRoot->CreateAnimation2D<CAnimation2D>();
	return true;
}

void ESpriteEffect::Update(float DeltaTime)
{
	AActor::Update(DeltaTime);
}

void ESpriteEffect::AnimationEnd()
{
	if (!mLoop)
	{
		Destroy();
	}
}

void ESpriteEffect::SetAnimation(const std::string& Name, float PlayTime, float PlayRate, bool Loop, bool Reverse)
{
	mLoop = Loop;
	mAnimation->AddSequence(Name, PlayTime, PlayRate, Loop, Reverse);
	mAnimation->SetEndFunction<ESpriteEffect>(Name, this, &ESpriteEffect::AnimationEnd);
}