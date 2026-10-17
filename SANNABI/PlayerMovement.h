#pragma once

#include "MovementComponent.h"

class APlayer;
class CColliderBase;

enum EMovement
{
	Ground,
	Falling,
	Wall,
	Attack,
	Swing,
	FireJump,
	Damage,
	Death
};

class CPlayerMovement : public CMovementComponent
{
	friend class AActor;

public:
	void Move(float _VelocityX, float _VelocityY, float _XSpeed, float _YSpeed);
	void GroundJump();
	void EdgeJump();
	void WallJump(float _VelocityX);
	void OffWall(float _VelocityX, float _DeltaTime);
	bool CountDown(float _Time, float DeltaTime);
private:
	virtual void Update(float DeltaTime) override;
	void Ground();
	void Falling();
	void Attack();
	void PrintLog();
	void Swing();
	void FireJump();

private:
	EMovement Movement = EMovement::Ground;
	bool IsGroundJump = false;
	float JumpSpeed = 0.f;
	float GravityAccel = 0;
	bool IsOverWall = false;
	bool IsWallJump = false;
	float WallJumpVelocityX = 0.f;
	float WallJumpXSpeed = 0.f;
	APlayer* Player = nullptr;
	FVector3D TargetPoint;
	float AttackSpeed = 0.f;
	bool IsAttack = false;
	float CrossZ = 0;
	float SwingAccel = 0.f;
	float EdgeJumpSpeed = 0.f;
	float CountTime = 0.f;
	FVector3D PlayerPosition;
	FVector3D HookPosition;

public:
	void SetTargetPoint(FVector3D _Point) { TargetPoint = _Point; }
	EMovement GetMovement() const { return Movement; }
	void SetMovement(EMovement _Movement) { Movement = _Movement; }
	void SetJumpSpeed(float _Speed) { JumpSpeed = _Speed; }
	float GetJumpSpeed() const { return JumpSpeed; }
	void SetEdgeJumpSpeed(float _Speed) { EdgeJumpSpeed = _Speed; }
	void SetWallJumpXSpeed(float _Speed) { WallJumpXSpeed = _Speed; }
	void SetAttackSpeed(float _Speed) { AttackSpeed = _Speed; }
	bool GetIsGroundJump() const { return IsGroundJump; }
	void SetIsGroundJump(bool _IsJump) { IsGroundJump = _IsJump; }
	bool GetIsOverWall() const { return IsOverWall; }
	void SetIsOverWall(bool _IsOverWall) { IsOverWall = _IsOverWall; }
	void SetSwingAccel(float _Accel) { SwingAccel = _Accel; }
	void SetPlayer(APlayer* _Player) { Player = _Player; }
	void SetGravityAccel(float _Accel) { GravityAccel = _Accel; }
	void SetIsAttack(bool _IsAttack) { IsAttack = _IsAttack; }
};