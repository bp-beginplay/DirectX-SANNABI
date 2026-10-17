#include "BackGroundBuilding.h"
#include "SpriteComponent.h"

CBackGroundBuilding::CBackGroundBuilding()
{
}

CBackGroundBuilding::CBackGroundBuilding(const CBackGroundBuilding& Obj)
{
}

CBackGroundBuilding::CBackGroundBuilding(CBackGroundBuilding&& Obj)
{
}

CBackGroundBuilding::~CBackGroundBuilding()
{
}

bool CBackGroundBuilding::Init()
{
	AActor::Init();

	Sprite->SetTexture("Building", TEXT("Map/BackGround/BackGroundBuilding.png"), 0);
	Sprite->SetTint(1.f, 1.f, 1.f);
	Sprite->SetPivot(0.5f, 0.5f);
	Sprite->SetOpacity(1.f);

	return true;
}