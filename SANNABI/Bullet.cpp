#include "Bullet.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"
#include "AudioComponent.h"
#include "BulletExplodeEffect.h"
#include "Scene.h"
#include "VendingMachine.h"

ABullet::ABullet()
{
}

ABullet::ABullet(const ABullet& Obj)
{
}

ABullet::ABullet(ABullet&& Obj) noexcept
{
}

ABullet::~ABullet()
{
}

void ABullet::Fire(float Angle)
{
	SetWorldRotationZ(Angle);
	MovementComponent->SetMoveAxis(EAxis::Y);
	MovementComponent->SetYSpeed(600.f);
	MovementComponent->SetXSpeed(600.f);
}


bool ABullet::Init()
{
	AActor::Init();

	Sprite->SetTexture("Bullet", TEXT("Texture/Test_Bullet.png"), 0);
	Sprite->SetTint(1.f, 1.f, 1.f);
	Sprite->SetWorldScale(15.f, 40.f);
	Sprite->SetPivot(0.5f, 1.f);
	Sprite->SetOpacity(1.f);
	mLifeTime = 10.f;
	MovementComponent = CreateComponent<CMovementComponent>();
	MovementComponent->SetUpdateComponent(Root);

	Colli->SetCollisionProfile("Bullet");
	Colli->SetBoxSize(10.f, 10.f);
	Colli->SetCollisionBeginFunc<ABullet>(this, &ABullet::Destroy);

	return true;
}

void ABullet::Update(float DeltaTime)
{
	AActor::Update(DeltaTime);
}

void ABullet::Destroy()
{
	AActor::Destroy();
}

void ABullet::Destroy(const FVector3D& HitPoint, CColliderBase* Dest)
{
	EBulletExplodeEffect* Effect = mScene->CreateObj<EBulletExplodeEffect>("ExplodeEffect");
	float Angle = GetWorldPosition().GetViewTargetAngle(HitPoint);
	Effect->SetWorldRotationZ(Angle + 180.f);
	Effect->SetAnimation("Bullet_Boom");
	Effect->SetWorldPos(HitPoint);
	Effect->SetWorldScale(100.f, 100.f);

	Destroy();
}