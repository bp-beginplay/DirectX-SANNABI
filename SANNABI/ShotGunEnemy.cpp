#include "ShotGunEnemy.h"
#include "Bullet.h"
#include "Scene.h"
#include "Player.h"
#include "SpriteComponent.h"
#include "AudioComponent.h"

AShotGunEnemy::AShotGunEnemy()
{
}

AShotGunEnemy::AShotGunEnemy(const AShotGunEnemy& Obj)
{
}

AShotGunEnemy::AShotGunEnemy(AShotGunEnemy&& Obj) noexcept
{
}

AShotGunEnemy::~AShotGunEnemy()
{
}

bool AShotGunEnemy::Init()
{
	AEnemy::Init();

	return true;
}

void AShotGunEnemy::Update(float DeltaTime)
{
	AEnemy::Update(DeltaTime);

	float AimSpriteAngle;
	float AimSpriteLength;

	if (CountDown(FireTime, DeltaTime))
	{
		IsFire = true;
		AimPosition = Player->GetWorldPosition();
	}


	if (!IsReload)
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
		float Angle = GetWorldPosition().GetViewTargetAngle(AimPosition);

		ABullet* Bullet1 = mScene->CreateObj<ABullet>("Bullet");
		Bullet1->SetWorldPos(GetWorldPosition());
		Bullet1->Fire(RandomRange(5.f, Angle));

		ABullet* Bullet2 = mScene->CreateObj<ABullet>("Bullet");
		Bullet2->SetWorldPos(GetWorldPosition());
		Bullet2->Fire(RandomRange(5.f, Angle));

		ABullet* Bullet3 = mScene->CreateObj<ABullet>("Bullet");
		Bullet3->SetWorldPos(GetWorldPosition());
		Bullet3->Fire(RandomRange(5.f, Angle));

		ABullet* Bullet4 = mScene->CreateObj<ABullet>("Bullet");
		Bullet4->SetWorldPos(GetWorldPosition());
		Bullet4->Fire(RandomRange(5.f, Angle));

		ABullet* Bullet5 = mScene->CreateObj<ABullet>("Bullet");
		Bullet5->SetWorldPos(GetWorldPosition());
		Bullet5->Fire(RandomRange(5.f, Angle));

		mAudio->SetSound("ShotGunFire");
		FireTime = RandomRange(2.f, 6);
		IsFire = false;
		IsReload = true;
	}

	if (IsReload)
	{
		if (CountDown(3.f, DeltaTime))
		{
			IsReload = false;
		}
	}
}