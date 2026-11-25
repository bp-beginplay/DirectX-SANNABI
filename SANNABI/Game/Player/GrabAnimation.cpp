#include "Game/Player/GrabAnimation.h"
#include "Engine/Animation/Animation2D.h"
#include "Game/Player/Grab.h"
#include "Engine/Component/AudioComponent.h"

void CGrabAnimation::AddSequence()
{
	GrabAnimation->AddSequence("SNBGrab_Grabbing", 1.f, 1.f, false, false);
	//GrabAnimation->AddNotify("SNBGrab_Grabbing", 1, this, &CGrabAnimation::Play_Shoot);

	GrabAnimation->AddSequence("SNBGrab_Idle", 1.f, 1.f, true, false);
}

void CGrabAnimation::PlayAnimation()
{
	if (Grab->GetIsFire())
	{
		GrabAnimation->ChangeAnimation("SNBGrab_Grabbing");

	}
	else
	{
		GrabAnimation->ChangeAnimation("SNBGrab_Idle");
	}
}