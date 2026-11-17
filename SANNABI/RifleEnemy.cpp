#include "RifleEnemy.h"
#include "Bullet.h"
#include "Scene.h"
#include "Player.h"
#include "SpriteComponent.h"
#include "AudioComponent.h"

ARifleEnemy::ARifleEnemy()
{
}

ARifleEnemy::ARifleEnemy(const ARifleEnemy& Obj)
{
}

ARifleEnemy::ARifleEnemy(ARifleEnemy&& Obj) noexcept
{
}

ARifleEnemy::~ARifleEnemy()
{
}

bool ARifleEnemy::Init()
{
	AEnemy::Init();
	return true;
}

void ARifleEnemy::Update(float DeltaTime)
{
	AEnemy::Update(DeltaTime);

	float AimSpriteAngle;
	float AimSpriteLength;

	if (CountDown(FireTime, DeltaTime))
	{
		IsFire = true;
		BulletCount = 0;
		AimPosition = Player->GetWorldPosition();		
	}

	if (!IsFire)
	{
		AimSprite->SetTint(1.f, 0.5f, 0.f);
		AimSprite->SetOpacity(0.5f);
		AimSpriteAngle = GetWorldPosition().GetViewTargetAngle(Player->GetWorldPosition());
		AimSprite->SetWorldRotationZ(AimSpriteAngle);
		AimSpriteLength = GetWorldPosition().Distance(Player->GetWorldPosition());
		AimSprite->SetWorldScale(5.f, AimSpriteLength);
	}
	else
	{
		AimSprite->SetOpacity(0.f);
	}

	if (IsFire)
	{
		if (CountDown(0.3f, DeltaTime))
		{
			float Angle = GetWorldPosition().GetViewTargetAngle(AimPosition);
			ABullet* Bullet = mScene->CreateObj<ABullet>("Bullet");
			Bullet->SetWorldPos(GetWorldPosition());
			Bullet->Fire(RandomRange(1.f, Angle));
			mAudio->SetSound("RifleFire");
			BulletCount += 1;
		}

		if (BulletCount == 5)
		{
			FireTime = RandomRange(2.f, 6);
			IsFire = false;
		}
	}
}