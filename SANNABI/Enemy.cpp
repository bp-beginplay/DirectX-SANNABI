#include "Enemy.h"
#include "SpriteComponent.h"
#include "ColliderSphere2D.h"
#include "ExplodeEffect.h"
#include "Scene.h"
#include "AudioComponent.h"
#include "Player.h"
#include "Bullet.h"
#include <random>

AEnemy::AEnemy() {}
AEnemy::AEnemy(const AEnemy& Obj) {}
AEnemy::AEnemy(AEnemy&& Obj) noexcept {}
AEnemy::~AEnemy() {}

bool AEnemy::Init()
{
	AActor::Init();

	Sprite->SetTexture("TestEnemy", TEXT("Enemy/TestEnemy.png"), 0);
	Sprite->SetTint(1.f, 1.f, 1.f);
	Sprite->SetPivot(0.5f, 0.5f);
	Sprite->SetOpacity(1.f);

	Colli->SetCollisionProfile("Enemy");

	AimSprite = CreateComponent<CSpriteComponent>();
	AimSprite->SetTexture("EnemyAim", TEXT("Texture/Solid_white.png"));
	AimSprite->SetPivot(0.5f, 0.f);
	AimSprite->SetOpacity(1.f);
	Root->AddChild(AimSprite);

	Player = mScene->FindObjectFromName<APlayer>("Player");
	FireTime = RandomRange(2.f, 6);
	return true;
}

void AEnemy::Update(float DeltaTime)
{
	AActor::Update(DeltaTime);
}

void AEnemy::SetColliderScale()
{
	AActor::SetColliderScale();
}

void AEnemy::Destroy()
{
	EExplodeEffect* Effect = mScene->CreateObj<EExplodeEffect>("ExplodeEffect");
	Effect->SetAnimation("Enemy_Explode");
	Effect->SetWorldPos(GetWorldPosition());
	Effect->SetWorldScale(100.f, 100.f);
	mScene->Point += 1;

	AActor::Destroy();
}


float AEnemy::RandomRange(float Range, float AimAngle)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(-Range, Range);
	double random_double = dis(gen);
	return AimAngle + random_double;
}
