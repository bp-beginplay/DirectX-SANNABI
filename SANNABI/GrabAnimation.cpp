#include "GrabAnimation.h"
#include "Animation2D.h"
#include "Grab.h"
#include "AudioComponent.h"

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