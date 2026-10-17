#include "PlayerAnimation.h"
#include "Animation2D.h"
#include "SpriteComponent.h"
#include "PlayerMovement.h"
#include "AudioComponent.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainScene.h"

void CPlayerAnimation::AddSequence()
{
	PlayerAnimation->AddSequence("SNB_Idle", 1.f, 1.f, true, false);
	
	PlayerAnimation->AddSequence("SNB_Running", 1.f, 1.f, true, false);
	PlayerAnimation->AddNotify("SNB_Running", 1, this, &CPlayerAnimation::Play_Walk1);
	PlayerAnimation->AddNotify("SNB_Running", 5, this, &CPlayerAnimation::Play_Walk2);
	PlayerAnimation->AddNotify("SNB_Running", 10, this, &CPlayerAnimation::Play_Walk1);
	PlayerAnimation->AddNotify("SNB_Running", 15, this, &CPlayerAnimation::Play_Walk2);

	PlayerAnimation->AddSequence("SNB_Jumping", 1.f, 1.f, false, false);
	PlayerAnimation->AddNotify("SNB_Jumping", 1, this, &CPlayerAnimation::Play_Jump);

	PlayerAnimation->AddSequence("SNB_FallingStart", 0.2f, 1.f, false, false);
	PlayerAnimation->AddSequence("SNB_Falling", 1.f, 1.f, false, false);

	PlayerAnimation->AddSequence("SNB_ClimbUp", 0.5f, 1.f, true, false);
	PlayerAnimation->AddNotify("SNB_ClimbUp", 1, this, &CPlayerAnimation::Play_WallClimbUp1);
	PlayerAnimation->AddNotify("SNB_ClimbUp", 6, this, &CPlayerAnimation::Play_WallClimbUp2);

	PlayerAnimation->AddSequence("SNB_ClimbDown", 0.5f, 1.f, true, false);

	PlayerAnimation->AddSequence("SNB_Swing", 1.f, 1.f, false, false);
	PlayerAnimation->AddSequence("SNB_Rolling", 1.f, 1.f, false, false);

	PlayerAnimation->AddSequence("SNB_Damage", 5.f, 1.f, false, false);

	PlayerAnimation->AddSequence("SNB_Death", 3.f, 1.f, false, false);
	PlayerAnimation->AddNotify("SNB_Death", 24, this, &CPlayerAnimation::Restart);
}

void CPlayerAnimation::PlayAnimtion()
{
	switch (PlayerMovement->GetMovement())
	{
	case EMovement::Ground:
		SetFlip();
		Ground();
		break;
	case EMovement::Falling:
		SetFlip();
		Falling();
		break;
	case EMovement::Swing:
		PlayerAnimation->ChangeAnimation("SNB_Swing");
		break;
	case EMovement::Wall:
		Wall();
		break;
	case EMovement::Damage:
		PlayerAnimation->ChangeAnimation("SNB_Damage");
		break;
	case EMovement::Death:
		break;
	default:
		break;
	}
}

void CPlayerAnimation::Wall()
{
	if (Input->FindBindKey("MoveUp")->KeyHold)
	{
		PlayerAnimation->ChangeAnimation("SNB_ClimbUp");
	}
	else if (Input->FindBindKey("MoveDown")->KeyHold)
	{
		PlayerAnimation->ChangeAnimation("SNB_ClimbDown");
	}
	else
	{
		PlayerAnimation->ChangeAnimation("SNB_ClimbDown");
	}
}

void CPlayerAnimation::SetFlip()
{
	if (Input->FindBindKey("MoveRight")->KeyHold)
	{
		Player->GetSprite()->SetFlip(false);
	}

	if (Input->FindBindKey("MoveLeft")->KeyHold)
	{
		Player->GetSprite()->SetFlip(true);
	}
}

void CPlayerAnimation::Falling()
{
	if (PlayerMovement->GetVelocity().y > 0)
	{
		if (PlayerMovement->GetYSpeed() > PlayerMovement->GetJumpSpeed())
		{
			PlayerAnimation->ChangeAnimation("SNB_Rolling");
		}
		else
		{
			PlayerAnimation->ChangeAnimation("SNB_Jumping");
		}

	}
	else
	{
		PlayerAnimation->ChangeAnimation("SNB_FallingStart");
	}
}

void CPlayerAnimation::Ground()
{
	if ((Input->FindBindKey("MoveLeft")->KeyHold)
		|| (Input->FindBindKey("MoveRight")->KeyHold))
	{
		PlayerAnimation->ChangeAnimation("SNB_Running");
	}
	else
	{
		PlayerAnimation->ChangeAnimation("SNB_Idle");
	}
}


void CPlayerAnimation::Play_Walk1()
{
	mAudio->SetSound("Walk1");
}

void CPlayerAnimation::Play_Walk2()
{
	mAudio->SetSound("Walk2");
}

void CPlayerAnimation::Play_WallClimbUp1()
{
	mAudio->SetSound("ClimbUp1");
}

void CPlayerAnimation::Play_WallClimbUp2()
{
	mAudio->SetSound("ClimbUp2");
}

void CPlayerAnimation::Restart()
{
	CLog::PrintLog("Active");
	CSceneManager::GetInst()->CreateLoadScene<CMainScene>();
}

void CPlayerAnimation::Play_Jump()
{
	mAudio->SetSound("Jump");
}