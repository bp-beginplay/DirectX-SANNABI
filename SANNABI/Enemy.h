#pragma once

#include "Actor.h"

class CColliderSphere2D;
class CSpriteComponent;
class APlayer;

class AEnemy : public AActor
{
	friend class CScene;

protected:
	AEnemy();
	AEnemy(const AEnemy& Obj);
	AEnemy(AEnemy&& Obj) noexcept;
	virtual ~AEnemy();

public:
	virtual bool Init() override;
	virtual void Update(float DeltaTime) override;
	virtual void SetColliderScale() override;
	virtual void Destroy() override;

protected:
	APlayer* Player;
	bool IsFire = false;
	float FireTime;
	float RandomRange(float Range, float AimAngle);
	int BulletCount = 0;
	TSharedPtr<CSpriteComponent> AimSprite;
	FVector3D AimPosition;
	bool IsReload = false;
private:


	TSharedPtr<CColliderSphere2D> AimPlayerColli;


};