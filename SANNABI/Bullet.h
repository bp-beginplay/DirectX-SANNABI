#pragma once

#include "Actor.h"

class ABullet : public AActor
{
	friend class CScene;
protected:
	ABullet();
	ABullet(const ABullet& Obj);
	ABullet(ABullet&& Obj) noexcept;
	virtual ~ABullet();

public:
	void Fire(float Angle);

private:
	virtual bool Init() override;
	virtual void Update(float DeltaTime) override;
	virtual void Destroy() override;
	void Destroy(const FVector3D& HitPoint, CColliderBase* Dest);
};

