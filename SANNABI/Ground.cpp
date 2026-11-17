#include "Ground.h"
#include "SpriteComponent.h"
#include "ColliderAABB2D.h"
#include "ColliderLine2D.h"

AGround::AGround() : AActor() {}
AGround::AGround(const AGround& Obj) : AActor() {}
AGround::AGround(AGround&& Obj) noexcept : AActor() {}
AGround::~AGround() {}

bool AGround::Init()
{
	AActor::Init();


	Sprite->SetTexture("TestGround", TEXT("Map/Tile/Tile360x360.png"), 0);
	Sprite->SetTint(1.f, 1.f, 1.f);
	Sprite->SetPivot(0.5f, 0.5f);
	Sprite->SetOpacity(1.f);

	Colli->SetCollisionProfile("Ground");

	return true;
}

void AGround::SetColliderScale()
{
	AActor::SetColliderScale();
}
