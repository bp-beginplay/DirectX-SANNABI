#include "PlayerMovement.h"
#include "Player.h"
#include "SpriteComponent.h"
#include "Enemy.h"
#include "Grab.h"
#include "Scene.h"
#include "Input.h"
#define _USE_MATH_DEFINES

#include <math.h>

void CPlayerMovement::Update(float DeltaTime)
{
	switch (Movement)
	{
	case EMovement::Ground:
		//CLog::PrintLog("Ground");
		Ground();
		break;
	case EMovement::Falling:
		//CLog::PrintLog("Falling");
		Falling();
		break;
	case EMovement::Wall:
		//CLog::PrintLog("Wall");
		break;
	case EMovement::Attack:
		//CLog::PrintLog("Attack");
		Attack();
		break;
	case EMovement::Swing:
		//CLog::PrintLog("Swing");
		Swing();
		break;
	case EMovement::FireJump:
		//CLog::PrintLog("FireJump");
		FireJump();
		break;
	case EMovement::Damage:
		XSpeed = 0;
		YSpeed = 0;
		break;
	default:
		break;
	}

	CMovementComponent::Update(DeltaTime);
}

void CPlayerMovement::Ground()
{
	if (!IsGroundJump)
		YSpeed = 0;
}

void CPlayerMovement::GroundJump()
{
	YSpeed = JumpSpeed;
	IsGroundJump = true;
}

void CPlayerMovement::Falling()
{
	Velocity.y = 1;
	YSpeed -= GravityAccel;
	if (YSpeed < 0)
	{
		IsOverWall = false;
	}
	if (IsWallJump)
	{
		Velocity.x = WallJumpVelocityX;
		XSpeed = WallJumpXSpeed;
		if (YSpeed < JumpSpeed / 2)
		{
			IsWallJump = false;
		}
	}
	if (Player->GetIsBlockUp() && Velocity.y * YSpeed > 0)
	{
		YSpeed = 0;
	}
}

void CPlayerMovement::Attack()
{
	float Angle = Player->GetWorldPosition().GetViewTargetAngle(TargetPoint);
	Player->GetSprite()->SetWorldRotationZ(Angle);
	Velocity = TargetPoint - Player->GetWorldPosition();
	if (Player->GetHook()->GetIsFire())
	{
		XSpeed = AttackSpeed;
		YSpeed = AttackSpeed;
	}
	else
	{
		Player->GetSprite()->SetWorldRotationZ(0);
		XSpeed = 0;
		YSpeed = 0;
	}
	IsAttack = true;
}

void CPlayerMovement::Swing()
{	
	float Angle = Player->GetWorldPosition().GetViewTargetAngle(Player->GetHook()->GetWorldPosition());
	Player->GetSprite()->SetWorldRotationZ(Angle);
	FVector3D TensionVelocity = Player->GetHook()->GetWorldPosition() - Player->GetWorldPosition();
	Velocity = TensionVelocity.Cross(FVector3D(0, 0, CrossZ));

	if (Player->GetIsBlockLeft()
		|| Player->GetIsBlockRight()
		|| Player->GetIsOnGround())
	{
		XSpeed = 0;
		YSpeed = 0;
	}
	else
	{
		if (mScene->GetInput()->FindBindKey("MoveLeft")->KeyHold)
		{
			XSpeed += SwingAccel;
			YSpeed += SwingAccel;
		}
		else if (mScene->GetInput()->FindBindKey("MoveRight")->KeyHold)
		{
			XSpeed -= SwingAccel;
			YSpeed -= SwingAccel;
		}
		
		XSpeed += GravityAccel * float(sin(Angle * M_PI / 180));
		YSpeed += GravityAccel * float(sin(Angle * M_PI / 180));
	}
	if (!Player->GetHook()->GetIsOnHook())
	{
		Player->GetSprite()->SetWorldRotationZ(0);
		if (YSpeed < 0)
		{
			YSpeed *= -1;
			XSpeed *= -1;
		}
	}
	if (Player->GetIsBlockUp() && Velocity.y * YSpeed > 0)
	{
		XSpeed = 0;
		YSpeed = 0;
	}
}

void CPlayerMovement::EdgeJump()
{
	YSpeed = EdgeJumpSpeed;
}

void CPlayerMovement::WallJump(float _VelocityX)
{
	YSpeed = JumpSpeed;
	Player->AddWorldPos(10 * _VelocityX, 0);
	WallJumpVelocityX = _VelocityX;
	IsWallJump = true;
}

void CPlayerMovement::OffWall(float _VelocityX, float _DeltaTime)
{
	if (CountDown(2.f, _DeltaTime))
	{
		Player->AddWorldPos(10.f * _VelocityX, 0.f);
		YSpeed = 0;
	}
}

bool CPlayerMovement::CountDown(float _Time, float DeltaTime)
{
	CountTime += DeltaTime;
	if (CountTime >= _Time)
	{
		CountTime = 0;
		return true;
	}
	return false;
}

void CPlayerMovement::FireJump()
{
	float Angle = Player->GetWorldPosition().GetViewTargetAngle(TargetPoint);
	Player->GetSprite()->SetWorldRotationZ(Angle);
	Velocity = TargetPoint - Player->GetWorldPosition();

	if (Player->GetHook()->GetIsOnHook())
	{
		XSpeed = 0;
		YSpeed = 0;
		if (PlayerPosition.x < HookPosition.x)
		{
			CrossZ = 1.f;
		}
		else
		{
			CrossZ = -1.f;
		}
	}
	else
	{
		XSpeed = Player->GetFireJumpSpeed();
		YSpeed = Player->GetFireJumpSpeed();
	}
}

void CPlayerMovement::Move(float _VelocityX, float _VelocityY, float _XSpeed, float _YSpeed)
{
	if(_VelocityX != 0)
		Velocity.x = _VelocityX;
	if(_VelocityY != 0)
		Velocity.y = _VelocityY;
	if (_XSpeed != 0)
		XSpeed = _XSpeed;
	if(_YSpeed != 0)
		YSpeed = _YSpeed;
}