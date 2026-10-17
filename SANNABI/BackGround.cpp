#include "BackGround.h"
#include "SpriteComponent.h"
#include "Animation2D.h"
#include "AudioComponent.h"

CBackGround::CBackGround()
{
}

CBackGround::CBackGround(const CBackGround& Obj)
{
}

CBackGround::CBackGround(CBackGround&& Obj)
{
}

CBackGround::~CBackGround()
{
}

bool CBackGround::Init()
{
	AActor::Init();

	Sprite->SetTexture("BackGround", TEXT("Map/BackGround/BackGroundAnim (1).png"), 0);
	Sprite->SetTint(1.f, 1.f, 1.f);
	Sprite->SetPivot(0.5f, 0.5f);
	Sprite->SetOpacity(1.f);
	Sprite->SetUseTime(true);
	mAnimation = Sprite->CreateAnimation2D<CAnimation2D>();
	mAnimation->AddSequence("BackGroundAnim", 1.f, 0.3f, true, false);
	mAnimation->ChangeAnimation("BackGroundAnim");

	BackGroundSprite = CreateComponent<CSpriteComponent>("BackGround");
	BackGroundSprite->SetTexture("Building", TEXT("Map/BackGround/BackGroundBuilding.png"), 0);
	BackGroundSprite->SetTint(1.2f, 1.2f, 1.2f);
	BackGroundSprite->SetPivot(0.5f, 0.5f);
	BackGroundSprite->SetOpacity(1.f);
	Root->AddChild(BackGroundSprite);

	return true;
}