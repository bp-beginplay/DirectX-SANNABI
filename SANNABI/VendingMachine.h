#pragma once

#include "Actor.h"

class AVendingMachine : public AActor
{
	friend class CScene;
protected:
	AVendingMachine();
	AVendingMachine(const AVendingMachine& Obj);
	AVendingMachine(AVendingMachine&& Obj) noexcept;
	virtual ~AVendingMachine();

private:
	virtual bool Init() override;
	virtual void Update(float DeltaTime) override;
	void EndScene(const FVector3D& HitPoint, CColliderBase* Dest);
};

