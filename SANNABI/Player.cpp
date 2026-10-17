#include "Player.h"
#include "CameraComponent.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"
#include "Scene.h"
#include "Input.h"
#include "ColliderAABB2D.h"
#include "ColliderLine2D.h"
#include "Grab.h"
#include "PlayerAnimation.h"
#include "Enemy.h"
#include "ColliderSphere2D.h"
#include "PlayerMovement.h"
#include "SpriteEffect.h"
#include "AudioComponent.h"
#include "CameraActor.h"
#include "Animation2D.h"
#include "SceneManager.h"
#include "MainScene.h"

APlayer::APlayer() : AActor() {}
APlayer::APlayer(const APlayer& Obj) : AActor(Obj) {}
APlayer::APlayer(APlayer&& Obj) noexcept : AActor(Obj) {}
APlayer::~APlayer() {}

bool APlayer::Init()
{
	AActor::Init();

	MovementComponent = CreateComponent<CPlayerMovement>();
	PlayerMovement = dynamic_cast<CPlayerMovement*>(MovementComponent.Get());
	PlayerMovement->SetUpdateComponent(Root);
	PlayerMovement->SetPlayer(this);

	Hook = mScene->CreateObj<AGrab>("Hook");
	Hook->SetPlayer(this);

	mAnimation = Sprite->CreateAnimation2D<CAnimation2D>();
	PlayerAnimation = new CPlayerAnimation;
	PlayerAnimation->SetPlayer(this);

	CameraActor = mScene->CreateObj<ACameraActor>("CameraActor");
	CameraActor->SetWorldPos(-800.f, -600.f, 0.f);

	SetPlayerState();
	SetSprite();
	SetColli();
	SetBindInput();

	HUD_HP_Animation = HUD_HPSprite->CreateAnimation2D<CAnimation2D>();

	HUD_HP_Animation->AddSequence("HUD_HP4_Idle", 1.f, 1.f, true, false);
	HUD_HP_Animation->AddSequence("HUD_HP4_Damage", 2.f, 1.f, false, false);

	HUD_HP_Animation->AddSequence("HUD_HP3_Idle", 1.f, 1.f, true, false);
	HUD_HP_Animation->AddSequence("HUD_HP3_Damage", 2.f, 1.f, false, false);
	HUD_HP_Animation->AddSequence("HUD_HP3_Restore", 3.f, 1.f, false, false);
	HUD_HP_Animation->AddNotify("HUD_HP3_Restore", 11, this, &APlayer::Restore);

	HUD_HP_Animation->AddSequence("HUD_HP2_Idle", 1.f, 1.f, true, false);
	HUD_HP_Animation->AddSequence("HUD_HP2_Damage", 2.f, 1.f, false, false);

	HUD_HP_Animation->AddSequence("HUD_HP1_Idle", 1.f, 1.f, true, false);

	return true;
}

void APlayer::SetSprite()
{
	Sprite->SetTexture("SNB", TEXT("SNB/Idle/SNB_Idle1 (1).png"), 0);
	Sprite->SetTint(1.f, 1.f, 1.f);
	Sprite->SetPivot(0.5f, 0.5f);
	Sprite->SetOpacity(1.f);

	AimSprite = CreateComponent<CSpriteComponent>();
	AimSprite->SetTexture("Aim", TEXT("Texture/Solid_white.png"));
	AimSprite->SetPivot(0.5f, 0.f);
	AimSprite->SetOpacity(0.1f);
	Root->AddChild(AimSprite);

	ChainSprite = CreateComponent<CSpriteComponent>();
	ChainSprite->SetTexture("Chain", TEXT("Texture/Solid_gray.png"), 0);
	ChainSprite->SetTint(1.f, 1.f, 1.f);
	ChainSprite->SetPivot(0.5f, 0.f);
	ChainSprite->SetWorldScale(0.f, 10.f);
	Root->AddChild(ChainSprite);

	HUD_HPSprite = CreateComponent<CSpriteComponent>();
	HUD_HPSprite->SetTexture("HUD_HP", TEXT("HUD/HP/HUD_HP4_Idle (1).png"), 0);
	HUD_HPSprite->SetTint(1.f, 1.f, 1.f);
	HUD_HPSprite->SetPivot(1.f, -0.5f);
	HUD_HPSprite->SetWorldScale(2.f, 2.f);
	HUD_HPSprite->SetRelativePos(0, 0);
	Root->AddChild(HUD_HPSprite);
}

void APlayer::SetColli()
{
	Colli->SetCollisionProfile("Player");
	//Colli->SetCollisionProfile("Default");
	Colli->SetCollisionBeginFunc<APlayer>(this, &APlayer::OnBody);

	RColli = CreateComponent<CColliderLine2D>();
	RColli->SetCollisionProfile("PlayerR");
	Root->AddChild(RColli);
	RColli->SetOverlapFunc<APlayer>(this, &APlayer::OnBlockRight);
	RColli->SetCollisionEndFunc<APlayer>(this, &APlayer::OffBlockRight);

	LColli = CreateComponent<CColliderLine2D>();
	LColli->SetCollisionProfile("PlayerL");
	Root->AddChild(LColli);
	LColli->SetOverlapFunc<APlayer>(this, &APlayer::OnBlockLeft);
	LColli->SetCollisionEndFunc<APlayer>(this, &APlayer::OffBlockLeft);

	UColli = CreateComponent<CColliderLine2D>();
	UColli->SetCollisionProfile("PlayerU");
	Root->AddChild(UColli);
	UColli->SetCollisionBeginFunc<APlayer>(this, &APlayer::OnBlockUp);
	UColli->SetCollisionEndFunc<APlayer>(this, &APlayer::OffBlockUp);

	DColli = CreateComponent<CColliderLine2D>();
	DColli->SetCollisionProfile("PlayerD");
	Root->AddChild(DColli);
	DColli->SetCollisionBeginFunc<APlayer>(this, &APlayer::OnGround);
	DColli->SetCollisionEndFunc<APlayer>(this, &APlayer::OffGround);

	HandColli = CreateComponent<CColliderLine2D>();
	HandColli->SetCollisionProfile("PlayerHand");
	Root->AddChild(HandColli);
	HandColli->SetCollisionBeginFunc<APlayer>(this, &APlayer::OnHand);
	HandColli->SetCollisionEndFunc<APlayer>(this, &APlayer::OffHand);

	AimColli = CreateComponent<CColliderLine2D>();
	AimColli->SetCollisionProfile("Aim");
	Root->AddChild(AimColli);
	AimColli->SetOverlapFunc<APlayer>(this, &APlayer::OnAimGround);
	AimColli->SetCollisionEndFunc<APlayer>(this, &APlayer::OffAimGround);
	AimColli->SetLineDistance(FireDistance);

	OnAimEnemyColli = CreateComponent<CColliderSphere2D>();
	OnAimEnemyColli->SetCollisionProfile("EnemyColli");
	Root->AddChild(OnAimEnemyColli);
	OnAimEnemyColli->SetCollisionBeginFunc<APlayer>(this, &APlayer::OnAimEnemy);
	OnAimEnemyColli->SetCollisionEndFunc<APlayer>(this, &APlayer::OffAimEnemy);
	OnAimEnemyColli->SetRadius(FireDistance);
}

void APlayer::SetBindInput()
{
	mScene->GetInput()->AddBindKey("MoveRight", 'D');
	mScene->GetInput()->AddBindFunction("MoveRight", EInputType::Hold, this, &APlayer::MoveRight);

	mScene->GetInput()->AddBindKey("MoveLeft", 'A');
	mScene->GetInput()->AddBindFunction("MoveLeft", EInputType::Hold, this, &APlayer::MoveLeft);

	mScene->GetInput()->AddBindKey("MoveUp", 'W');
	mScene->GetInput()->AddBindFunction("MoveUp", EInputType::Hold, this, &APlayer::MoveUp);

	mScene->GetInput()->AddBindKey("MoveDown", 'S');
	mScene->GetInput()->AddBindFunction("MoveDown", EInputType::Hold, this, &APlayer::MoveDown);

	mScene->GetInput()->AddBindKey("Jump", VK_SPACE);
	mScene->GetInput()->AddBindFunction("Jump", EInputType::Down, this, &APlayer::Jump);

	mScene->GetInput()->AddBindKey("Click", VK_LBUTTON);
	mScene->GetInput()->AddBindFunction("Click", EInputType::Down, this, &APlayer::Click);
	mScene->GetInput()->AddBindFunction("Click", EInputType::Hold, this, &APlayer::HoldClick);
	mScene->GetInput()->AddBindFunction("Click", EInputType::Up, this, &APlayer::StopClick);
}

void APlayer::SetPlayerState()
{
	PlayerMovement->SetJumpSpeed(400.f);
	PlayerMovement->SetEdgeJumpSpeed(250.f);
	PlayerMovement->SetGravityAccel(0.6f);
	PlayerMovement->SetWallJumpXSpeed(100.f);
	PlayerMovement->SetAttackSpeed(1400.f);
	GroundSpeed = 300.f;
	ClimbSpeed = 300.f;
	FireSpeed = 1500.f;
	FireJumpSpeed = 300.f;
	FireDistance = 500.f;
	PlayerMovement->SetSwingAccel(0.15f);
}

void APlayer::Update(float DeltaTime)
{
	AActor::Update(DeltaTime);





	FVector2D MousePos = mScene->GetInput()->GetMouseWorldPos();
	float MouseAngle = GetWorldPosition().GetViewTargetAngle(FVector3D(MousePos.x, MousePos.y, 0));
	FindNearestEnemy(MouseAngle);
	SetAimObject();
	SetAimColli(MouseAngle);

	SetAimSprite();

	AttachHook();
	SetChain();
	UpdateMovement();
	PlayerAnimation->PlayAnimtion();
	SetCameraPosition();

	if (IsDamage)
	{
		if (CountDown(3.f, DeltaTime))
		{
			Colli->SetCollisionProfile("Player");
			IsDamage = false;
		}
	}

	SetHUD_HP(DeltaTime);

	if (Health <= 0)
	{
		mAnimation->ChangeAnimation("SNB_Death");
		mAudio->SetSound("Death");
		if (CountDown(5.f, DeltaTime))
		{
			CSceneManager::GetInst()->CreateLoadScene<CMainScene>();
		}
	}
}

void APlayer::SetHUD_HP(float DeltaTime)
{
	switch (Health)
	{
	case 0:
		HUD_HPSprite->SetOpacity(0);
		break;
	case 1:
		if (IsDamage)
		{
			HUD_HP_Animation->ChangeAnimation("HUD_HP2_Damage");
		}
		else
		{
			HUD_HP_Animation->ChangeAnimation("HUD_HP1_Idle");
		}
		break;
	case 2:
		if (IsDamage)
		{
			HUD_HP_Animation->ChangeAnimation("HUD_HP3_Damage");
		}
		else
		{
			HUD_HP_Animation->ChangeAnimation("HUD_HP2_Idle");
		}
		break;
	case 3:
		if (IsDamage)
		{
			HUD_HP_Animation->ChangeAnimation("HUD_HP4_Damage");
		}
		else
		{
			HUD_HP_Animation->ChangeAnimation("HUD_HP3_Idle");
		}
		break;
	case 4:
		HUD_HP_Animation->ChangeAnimation("HUD_HP4_Idle");
		break;
	default:
		break;
	}

	if (Health != 4)
	{
		if (CountDown(10.f, DeltaTime))
		{
			Health = 4;
		}
	}
}

void APlayer::SetCameraPosition()
{
	float PlayerPositionX = GetWorldPosition().x;
	float PlayerPositionY = GetWorldPosition().y;

	if (PlayerPositionX < -800.f)
	{
		if (PlayerPositionY < -600.f)
		{
			CameraActor->SetWorldPos(-800.f, -600.f);
		}
		else if (PlayerPositionY > 600.f)
		{
			CameraActor->SetWorldPos(-800.f, 600.f);
		}
		else
		{
			CameraActor->SetWorldPos(-800.f, PlayerPositionY);
		}
	}
	else if (PlayerPositionX > 800.f)
	{
		if (PlayerPositionY < -600.f)
		{
			CameraActor->SetWorldPos(800.f, -600.f);
		}
		else if (PlayerPositionY > 600.f)
		{
			CameraActor->SetWorldPos(800.f, 600.f);
		}
		else
		{
			CameraActor->SetWorldPos(800.f, PlayerPositionY);
		}
	}
	else
	{
		if (PlayerPositionY < -600.f)
		{
			CameraActor->SetWorldPos(PlayerPositionX, -600.f);
		}
		else if (PlayerPositionY > 600.f)
		{
			CameraActor->SetWorldPos(PlayerPositionX, 600.f);
		}
		else
		{
			CameraActor->SetWorldPos(PlayerPositionX, PlayerPositionY);
		}
	}
}

void APlayer::SetAimObject()
{
	if (EnemyObject != nullptr && GroundObject != nullptr)
	{
		if (GetWorldPosition().Distance(GroundPoint) > GetWorldPosition().Distance(EnemyObject->GetWorldPosition()))
		{
			AimObject = EnemyObject;
		}
		else
		{
			AimObject = GroundObject;
		}
	}
	else
	{
		if (GroundObject != nullptr)
		{
			AimObject = GroundObject;
		}
		else if (EnemyObject != nullptr)
		{
			AimObject = EnemyObject;
		}
		else
		{
			AimObject = nullptr;
		}
	}
}

void APlayer::MoveRight(float DeltaTime)
{
	switch (PlayerMovement->GetMovement())
	{
	case Ground:
		if (IsBlockRight)
			return;
		PlayerMovement->Move(1.f, 0.f, GroundSpeed, 0);
		break;
	case Falling:
		if (IsBlockRight)
		{
			if (IsOnHand)
			{
				IsHoldWall = true;
			}
			return;
		}
		PlayerMovement->Move(1.f, 0.f, GroundSpeed, 0);
		break;
	case Wall:
		PlayerMovement->OffWall(1, DeltaTime);
		break;
	default:
		break;
	}
}

void APlayer::MoveLeft(float DeltaTime)
{
	switch (PlayerMovement->GetMovement())
	{
	case Ground:
		if (IsBlockLeft)
			return;
		PlayerMovement->Move(-1.f, 0.f, GroundSpeed, 0);
		break;
	case Falling:
		if (IsBlockLeft)
		{
			if (IsOnHand)
			{
				IsHoldWall = true;
			}
			return;
		}
		PlayerMovement->Move(-1.f, 0.f, GroundSpeed, 0);
		break;
	case Wall:
		PlayerMovement->OffWall(-1, DeltaTime);
		break;
	default:
		break;
	}
}

void APlayer::MoveUp()
{
	switch (PlayerMovement->GetMovement())
	{
	case Wall:
		if (IsBlockUp)
			return;
		if (IsHoldWall)
		{
			PlayerMovement->Move(0.f, 1.f, 0, ClimbSpeed);
		}
		else
		{
			PlayerMovement->EdgeJump();
		}
		break;
	default:
		break;
	}
}

void APlayer::MoveDown()
{
	switch (PlayerMovement->GetMovement())
	{
	case Wall:
		if (IsHoldWall)
		{
			PlayerMovement->Move(0.f, -1.f, 0, ClimbSpeed);
		}
		else
		{
			PlayerMovement->SetYSpeed(0.f);
		}
		break;
	default:
		break;
	}
}

void APlayer::Jump()
{
	switch (PlayerMovement->GetMovement())
	{
	case Ground:
		PlayerMovement->GroundJump();
		if (IsOnHand && 
			(mScene->GetInput()->FindBindKey("MoveRight")->KeyHold || mScene->GetInput()->FindBindKey("MoveLeft")->KeyHold))
			PlayerMovement->SetIsOverWall(true);
		break;
	case Falling:
		break;
	case Wall:
		if (IsOnHand)
		{
			if (IsBlockRight)
			{
				PlayerMovement->WallJump(-1);
			}
			if (IsBlockLeft)
			{
				PlayerMovement->WallJump(1);
			}
		}
		break;
	default:
		break;
	}
}

void APlayer::Click()
{
	if (AimObject != nullptr)
	{
		TargetObject = AimObject;
		if (string(TargetObject->GetOwner()->GetName()) == "Enemy")
		{
			Hook->Fire(TargetObject->GetWorldPosition());
			PlayerMovement->SetTargetPoint(TargetObject->GetWorldPosition());
		}
		else
		{
			Hook->Fire(GroundPoint);
			IsFireJump = true;
			PlayerMovement->SetTargetPoint(GroundPoint);
		}
		Hook->GetMovementComponent()->SetXSpeed(FireSpeed);
		Hook->GetMovementComponent()->SetYSpeed(FireSpeed);
	}
	else
	{
		FVector2D MousePos = mScene->GetInput()->GetMouseWorldPos();
		Hook->Fire(FVector3D(MousePos.x, MousePos.y, 0));
		Hook->GetMovementComponent()->SetXSpeed(FireSpeed);
		Hook->GetMovementComponent()->SetYSpeed(FireSpeed);
	}
}

void APlayer::HoldClick()
{
	IsHoldClick = true;
}

void APlayer::StopClick()
{
	IsHoldClick = false;
	Sprite->SetWorldRotationZ(0.f);
}

void APlayer::Restore()
{
	Health = 4;
}

void APlayer::OnBlockRight(const FVector3D& HitPoint, CColliderBase* Dest)
{
	IsBlockRight = true;
}

void APlayer::OffBlockRight(CColliderBase* Dest)
{
	IsBlockRight = false;
}

void APlayer::OnBlockLeft(const FVector3D& HitPoint, CColliderBase* Dest)
{
	IsBlockLeft = true;
}

void APlayer::OffBlockLeft(CColliderBase* Dest)
{
	IsBlockLeft = false;
}

void APlayer::OnGround(const FVector3D& HitPoint, CColliderBase* Dest)
{
	IsOnGround = true;
	PlayerMovement->SetIsGroundJump(false);
}

void APlayer::OffGround(CColliderBase* Dest)
{
	IsOnGround = false;
}

void APlayer::OnHand(const FVector3D& HitPoint, CColliderBase* Dest)
{
	IsOnHand = true;
}

void APlayer::OffHand(CColliderBase* Dest)
{
	IsOnHand = false;
	PlayerMovement->SetIsOverWall(false);
	IsHoldWall = false;
}

void APlayer::OnAimEnemy(const FVector3D& HitPoint, CColliderBase* Dest)
{
	CColliderBase* Enemy = Dest;
	umEnemy.insert(make_pair(Enemy, true)); 
}

void APlayer::OffAimEnemy(CColliderBase* Dest)
{
	CColliderBase* Enemy = Dest;
	umEnemy.erase(Enemy);
}

void APlayer::OnAimGround(const FVector3D& HitPoint, CColliderBase* Dest)
{
	if (!GroundObject)
		GroundObject = Dest;

	if (GroundObject == Dest)
	{
		GroundPoint = HitPoint;
	}
	else if (HitPoint.Distance(GetWorldPosition()) < GroundPoint.Distance(GetWorldPosition()))
	{
		GroundPoint = HitPoint;
		GroundObject = Dest;
	}
}

void APlayer::OffAimGround(CColliderBase* Dest)
{
	GroundObject = nullptr;
}

void APlayer::OnBody(const FVector3D& HitPoint, CColliderBase* Dest)
{
	if (string(Dest->GetOwner()->GetName()) == "Bullet")
	{
		Colli->SetCollisionProfile("Default");
		Health -= 1;
		IsDamage = true;
		mAudio->SetSound("Damage");
	}

	if (TargetObject != nullptr && string(TargetObject->GetOwner()->GetName()) == "Enemy")
	{
		umEnemy.erase(TargetObject);
		umInAngleEnemy.erase(TargetObject);
		TargetObject->GetOwner()->Destroy();
		TargetObject = nullptr;
		mAudio->SetSound("EnemyExplode");
		Hook->SetIsFire(false);
		Hook->SetWorldPos(GetWorldPosition());
	}
}

void APlayer::FindNearestEnemy(float MouseAngle)
{
	CColliderBase* NearestEnemy = nullptr;
	float NearestAngle = 0.f;
	float iterAngle = 0.f;
	float iterDistance = 0.f;
	float NearestEnemyDistance = 0.f;
	auto iter = umEnemy.begin();
	auto iterend = umEnemy.end();

	for (iter; iter != iterend; iter++)
	{
		iterAngle = GetWorldPosition().GetViewTargetAngle(iter->first->GetWorldPosition());
		if (abs(MouseAngle - iterAngle) < 30.f)
		{
			umInAngleEnemy.insert(make_pair(iter->first, true));
		}
		else
		{
			umInAngleEnemy.erase(iter->first);
		}
	}

	iter = umInAngleEnemy.begin();
	iterend = umInAngleEnemy.end();

	for (iter; iter != iterend; iter++)
	{
		if (NearestEnemy == nullptr)
		{
			NearestEnemy = iter->first;
		}
		else
		{
			iterDistance = GetWorldPosition().Distance(iter->first->GetWorldPosition());
			NearestEnemyDistance = GetWorldPosition().Distance(NearestEnemy->GetWorldPosition());
			if (iterDistance < NearestEnemyDistance)
			{
				NearestEnemy = iter->first;
			}
		}
	}

	EnemyObject = NearestEnemy;
}

void APlayer::SetAimColli(float MouseAngle)
{
	AimColli->SetWorldRotationZ(MouseAngle);
}

void APlayer::SetAimSprite()
{
	AActor* AimActor = nullptr;
	string ActorName = "None";
	float AimSpriteAngle = 0.f;
	float AimSpriteLength = 0.f;

	if (AimObject != nullptr)
	{
		if (GetWorldPosition().Distance(AimObject->GetWorldPosition()) < FireDistance)
		{
			AimActor = AimObject->GetOwner();
		}
	}

	if (AimActor != nullptr)
	{
		AimSprite->SetOpacity(0.8f);
		ActorName = string(AimActor->GetName());

		if (ActorName == "Enemy")
		{
			AimSprite->SetTint(1.f, 0.f, 0.f);
			AimSpriteAngle = GetWorldPosition().GetViewTargetAngle(AimActor->GetWorldPosition());
			AimSprite->SetWorldRotationZ(AimSpriteAngle);
	
			AimSpriteLength = GetWorldPosition().Distance(AimActor->GetWorldPosition());
			AimSprite->SetWorldScale(5.f, AimSpriteLength);
		}
		else if (ActorName == "Ground")
		{
			AimSprite->SetTint(0.f, 1.f, 1.f);
			AimSpriteAngle = GetWorldPosition().GetViewTargetAngle(FVector3D(GroundPoint.x, GroundPoint.y, 0));
			AimSprite->SetWorldRotationZ(AimSpriteAngle);

			AimSpriteLength = GetWorldPosition().Distance(FVector3D(GroundPoint.x, GroundPoint.y, 0));
			AimSprite->SetWorldScale(5.f, AimSpriteLength);
		}
	}
	else
	{
		AimSprite->SetOpacity(0.f);
	}

	if (Hook->GetIsOnHook())
	{
		AimSprite->SetOpacity(0.f);
	}
}

void APlayer::AttachHook()
{
	if (!Hook->GetIsFire())
	{
		Hook->SetWorldPos(GetWorldPosition());
	}
}

void APlayer::UpdateMovement()
{
	if (Hook->GetIsOnHook())
	{
		if (TargetObject)
		{
			if (string(TargetObject->GetOwner()->GetName()) == "Enemy")
			{
				PlayerMovement->SetMovement(EMovement::Attack);
			}
			else
			{
				PlayerMovement->SetMovement(EMovement::Swing);
			}
		}
	}
	else
	{
		if (IsFireJump)
		{
			if (TargetObject)
			{
				if (string(TargetObject->GetOwner()->GetName()) == "Ground")
				{
					PlayerMovement->SetMovement(EMovement::FireJump);
				}
			}
		}
		else
		{
			if (IsOnGround)
			{
				if (PlayerMovement->GetIsGroundJump())
				{
					PlayerMovement->SetMovement(Falling);
				}
				else
				{
					PlayerMovement->SetMovement(Ground);
				}
			}
			else
			{
				if (PlayerMovement->GetIsOverWall())
				{
					if (PlayerMovement->GetYSpeed() < 0)
					{
						PlayerMovement->SetMovement(Wall);
					}
					else
					{
						PlayerMovement->SetMovement(Falling);
					}
				}
				else
				{
					if (IsHoldWall)
					{
						PlayerMovement->SetMovement(Wall);
					}
					else
					{
						PlayerMovement->SetMovement(Falling);
					}
				}
			}
		}
	}

	if (IsDamage)
	{
		PlayerMovement->SetMovement(Damage);
	}

	if (Health <= 0)
	{
		PlayerMovement->SetMovement(Death);
	}
}

void APlayer::SetChain()
{
	FVector3D HookWorldPosition = Hook->GetWorldPosition();
	float ChainLength = GetWorldPosition().Distance(HookWorldPosition);
	ChainSprite->SetWorldScale(2.f, ChainLength);
	float ChainAngle = ChainSprite->GetWorldPosition().GetViewTargetAngle(FVector3D(HookWorldPosition.x, HookWorldPosition.y, 0));
	ChainSprite->SetWorldRotationZ(ChainAngle);
}

void APlayer::OnBlockUp(const FVector3D& HitPoint, CColliderBase* Dest)
{
	IsBlockUp = true;
}

void APlayer::OffBlockUp(CColliderBase* Dest)
{
	IsBlockUp = false;
}

void APlayer::SetColliderScale()
{
	AActor::SetColliderScale();
	Colli->SetBoxSize(Root->GetWorldScale().x * 0.8f, Root->GetWorldScale().y * 0.8f);
	float LineX = Root->GetWorldScale().x;
	float LineY = Root->GetWorldScale().y;

	UColli->SetLineAxis(EAxis::X);
	UColli->SetLineDistance(LineX * 0.5f);
	UColli->SetRelativePos(LineX * 0.5f / -2.f, LineY / 1.5f);

	DColli->SetLineAxis(EAxis::X);
	DColli->SetLineDistance(LineX * 0.5f);
	DColli->SetRelativePos(LineX * 0.5f / -2.f, LineY / -1.5f);

	RColli->SetLineAxis(EAxis::Y);
	RColli->SetLineDistance(LineY * 0.7f);
	RColli->SetRelativePos(LineX / 2.f, LineY * 0.7f / -2.f);

	LColli->SetLineAxis(EAxis::Y);
	LColli->SetLineDistance(LineY * 0.7f);
	LColli->SetRelativePos(LineX / -2.f, LineY * 0.7f / -2.f);

	HandColli->SetLineAxis(EAxis::X);
	HandColli->SetLineDistance(LineX);
	HandColli->SetRelativePos(LineX / -2.f, LineY * 0.2f);
}