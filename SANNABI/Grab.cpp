#include "Grab.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"
#include "Player.h"
#include "Scene.h"
#include "Input.h"
#include "PlayerMovement.h"
#include "GrabAnimation.h"
#include "AudioComponent.h"

AGrab::AGrab() : AActor() {}
AGrab::AGrab(const AGrab& Obj) : AActor(Obj) {}
AGrab::AGrab(AGrab&& Obj) noexcept : AActor(Obj) {}
AGrab::~AGrab() {}

bool AGrab::Init()
{
	AActor::Init();

	Sprite->SetTexture("SNBGrab", TEXT("SNB/Grab/SNBGrab_Idle.png"), 0);
	Sprite->SetTint(1.f, 1.f, 1.f);
	Sprite->SetPivot(0.5f, 0.5f);
	Sprite->SetOpacity(1.f);
	Sprite->SetWorldScale(20.f, 20.f);

	Colli->SetBoxSize(20.f, 20.f);
	Colli->SetCollisionProfile("Grab");
	Colli->SetOverlapFunc<AGrab>(this, &AGrab::OnHook);
	Colli->SetCollisionEndFunc<AGrab>(this, &AGrab::OffHook);

	MovementComponent = CreateComponent<CMovementComponent>();
	MovementComponent->SetUpdateComponent(Root);

	mAnimation = Sprite->CreateAnimation2D<CAnimation2D>();
	GrabAnimation = new CGrabAnimation;
	GrabAnimation->SetGrab(this);

	return true;
}

void AGrab::Update(float DeltaTime)
{
	AActor::Update(DeltaTime);

	if (IsReturn)
	{
		float Angle = GetWorldPosition().GetViewTargetAngle(Player->GetWorldPosition());
		Angle += 180.f;
		SetWorldRotationZ(Angle);
		MovementComponent->SetXSpeed(-Player->GetFireSpeed());
		MovementComponent->SetYSpeed(-Player->GetFireSpeed());
		if (GetWorldPosition().Distance(Player->GetWorldPosition()) < 1.f)
		{
			mAudio->SetSound("ReturnGrab");
			IsFire = false;
			IsReturn = false;
		}
	}

	if (IsFire)
	{
		if ( GetWorldPosition().Distance(Player->GetWorldPosition())>= Player->GetFireDistance())
		{
			IsReturn = true;
		}
	}

	GrabAnimation->PlayAnimation();
}

void AGrab::Fire(FVector3D _FirePoint)
{
	IsFire = true;
	mAudio->SetSound("Shoot");
	float Angle = GetWorldPosition().GetViewTargetAngle(_FirePoint);
	SetWorldRotationZ(Angle);
	MovementComponent->SetMoveAxis(EAxis::Y);
}

void AGrab::OnHook(const FVector3D& HitPoint, CColliderBase* Dest)
{
	if (Dest)
	{
		if (string(Dest->GetOwner()->GetName()) == "Enemy")
		{
			IsOnHook = true;
			MovementComponent->SetXSpeed(0.f);
			MovementComponent->SetYSpeed(0.f);
		}
		else
		{
			Player->SetIsFireJump(false);
			if (Player->GetIsHoldClick())
			{
				MovementComponent->SetXSpeed(0.f);
				MovementComponent->SetYSpeed(0.f);
				IsOnHook = true;
			}
			else
			{
				IsReturn = true;
			}
		}
	}
}

void AGrab::OffHook(CColliderBase* Dest)
{
	IsOnHook = false;
}