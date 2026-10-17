#pragma once

#include "Actor.h"

class APlayer;
class CGrabAnimation;

class AGrab : public AActor
{
public:
	AGrab();
	AGrab(const AGrab& Obj);
	AGrab(AGrab&& Obj) noexcept;
	virtual ~AGrab();
	virtual bool Init() override;

private:
	virtual void Update(float DeltaTime) override;

public:
	void Fire(FVector3D FirePoint);

private:
	void OnHook(const FVector3D& HitPoint, CColliderBase* Dest);
	void OffHook(CColliderBase* Dest);

private:
	APlayer* Player = nullptr;
	CGrabAnimation* GrabAnimation;
	bool IsOnHook = false;
	bool IsFire = false;
	bool IsReturn = false;



public:
	bool GetIsOnHook() const { return IsOnHook; }
	void SetPlayer(APlayer* _Player) { Player = _Player; }
	bool GetIsFire() const { return IsFire; }
	void SetIsFire(bool _IsFire) { IsFire = _IsFire; }
};
