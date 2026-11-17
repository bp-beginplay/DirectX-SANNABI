#pragma once
#include "Component.h"

class CMovementComponent : public CComponent
{
	friend class AActor;

protected:
	CMovementComponent();
	CMovementComponent(const CMovementComponent& Com);
	CMovementComponent(CMovementComponent&& Com) noexcept;
	virtual ~CMovementComponent();

public:
	virtual bool Init();
	virtual bool Init(const char* FileName);
	virtual void PreUpdate(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void PostRender();
	virtual CMovementComponent* Clone();
	void SetUpdateComponent(class CSceneComponent* Target);
	virtual void EndFrame();

protected:
	TSharedPtr<class CSceneComponent> UpdateComponent;
	EAxis::Type MoveAxis = EAxis::None;
	FVector3D Velocity;
	float XSpeed = 0.f;
	float YSpeed = 0.f;
	FVector3D MoveStep;

private:
	bool IsCanMove = true;
	bool VelocityInit = true;


public:
	void SetVelocityInit(bool _VelocityInit) { VelocityInit = _VelocityInit; }
	const FVector3D& GetMoveStep() const { return MoveStep; }
	float GetVelocityLength() const { return Velocity.Length(); }
	FVector3D GetVelocity() const { return Velocity; }
	float GetMoveDistance() const { return MoveStep.Length(); }
	void AddMove(const FVector3D& Dir) { Velocity += Dir; }
	void SetMove(const FVector3D& Dir) { Velocity = Dir; }
	void SetMoveAxis(EAxis::Type Axis) { MoveAxis = Axis; }
	void SetXSpeed(float _Speed) { XSpeed = _Speed; }
	float GetXSpeed() const { return XSpeed; }
	void SetYSpeed(float _Speed) { YSpeed = _Speed; }
	float GetYSpeed() const { return YSpeed; }
	bool GetIsCanMove() const { return IsCanMove; }
	void SetIsCanMove(bool _IsCanMove) { IsCanMove = _IsCanMove; }
};