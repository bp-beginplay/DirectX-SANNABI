#pragma once

#include "Actor.h"

class CColliderLine2D;
class CCameraComponent;
class CSpriteComponent;
class CPlayerMovement;
class AGrab;
class CColliderBase;
class CPlayerAnimation;
class CColliderSphere2D;
class AEnemy;
class ACameraActor;

class APlayer : public AActor
{
	friend class CScene;

private:
	APlayer();
	APlayer(const APlayer& Obj);
	APlayer(APlayer&& Obj) noexcept;
	virtual ~APlayer();
	void FindNearestEnemy(float MouseAngle);
	void SetAimColli(float MouseAngle);
	virtual bool Init() override;
	void SetSprite();
	void SetPlayerState();
	void SetColli();
	void SetBindInput();
	virtual void Update(float DeltaTime) override;
	void SetHUD_HP(float DeltaTime);
	void SetCameraPosition();
	void SetAimObject();
	void UpdateMovement();
	void SetAimSprite();
	void SetChain();
	void AttachHook();
	void MoveRight(float DeltaTime);
	void MoveLeft(float DeltaTime);
	void MoveUp();
	void MoveDown();
	void Jump();
	void Click();
	void HoldClick();
	void StopClick();
	void Restore();
	void OnBlockRight(const FVector3D& HitPoint, CColliderBase* Dest);
	void OffBlockRight(CColliderBase* Dest);
	void OnBlockLeft(const FVector3D& HitPoint, CColliderBase* Dest);
	void OffBlockLeft(CColliderBase* Dest);
	void OnGround(const FVector3D& HitPoint, CColliderBase* Dest);
	void OffGround(CColliderBase* Dest);
	void OnBlockUp(const FVector3D& HitPoint, CColliderBase* Dest);
	void OffBlockUp(CColliderBase* Dest);
	void OnHand(const FVector3D& HitPoint, CColliderBase* Dest);
	void OffHand(CColliderBase* Dest);
	void OnAimGround(const FVector3D& HitPoint, CColliderBase* Dest);
	void OffAimGround(CColliderBase* Dest);
	void OnAimEnemy(const FVector3D& HitPoint, CColliderBase* Dest);
	void OffAimEnemy(CColliderBase* Dest);
	void OnBody(const FVector3D& HitPoint, CColliderBase* Dest);
	virtual void SetColliderScale() override;

public:
	int Health = 4;

private:
	TSharedPtr<CSpriteComponent> AimSprite;
	unordered_map<CColliderBase*, bool> umEnemy;
	unordered_map<CColliderBase*, bool> umInAngleEnemy;

	CColliderBase* GroundObject = nullptr;
	CColliderBase* EnemyObject = nullptr;

	CColliderBase* AimObject = nullptr;
	CColliderBase* TargetObject = nullptr;


	float GroundSpeed = 0.f;
	float ClimbSpeed = 0.f;
	float FireSpeed = 0.f;
	bool IsHoldWall = false;
	bool IsHoldClick = false;
	bool IsFireJump = false;
	bool IsDamage = false;

	ACameraActor* CameraActor;
	TSharedPtr<CColliderLine2D> UColli;
	TSharedPtr<CColliderLine2D> DColli;
	TSharedPtr<CColliderLine2D> RColli;
	TSharedPtr<CColliderLine2D> LColli;
	TSharedPtr<CColliderLine2D> HandColli;
	TSharedPtr<CColliderLine2D> AimColli;
	TSharedPtr<CColliderSphere2D> OnAimEnemyColli;
	TSharedPtr<CSpriteComponent> ChainSprite;
	TSharedPtr<CSpriteComponent> HUD_HPSprite;
	class CAnimation2D* HUD_HP_Animation = nullptr;
	CPlayerMovement* PlayerMovement;
	AGrab* Hook = nullptr;
	CPlayerAnimation* PlayerAnimation;
	float FireJumpSpeed = 0.f;
	bool IsBlockLeft = false;
	bool IsBlockRight = false;
	bool IsOnGround = true;
	bool IsBlockUp = false;
	bool IsOnHand = false;
	bool IsDeath = false;
	float FireDistance = 400.f;
	FVector3D GroundPoint;

public:
	void SetIsDeath(bool _IsDeath) { IsDeath = _IsDeath; }

	float GetFireSpeed() const { return FireSpeed; }
	bool GetIsHoldClick() const { return IsHoldClick; }
	void SetIsFireJump(bool _IsJump) { IsFireJump = _IsJump; }
	CPlayerMovement* GetPlayerMovement() const { return PlayerMovement; }
	CSpriteComponent* GetSprite() const { return Sprite; }
	AGrab* GetHook() const { return Hook; }
	int GetHealth() const { return Health; }
	float GetFireDistance() const { return FireDistance; }
	float GetFireJumpSpeed() const { return FireJumpSpeed; }
	bool GetIsOnGround() const { return IsOnGround; }
	bool GetIsBlockRight() const { return IsBlockRight; }
	bool GetIsBlockLeft() const { return IsBlockLeft; }
	bool GetIsBlockUp() const { return IsBlockUp; }
	bool GetIsDeath() const { return IsDeath; }
};