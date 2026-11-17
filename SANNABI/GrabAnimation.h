#pragma once

#include "Grab.h"

class AGrab;
class CAnimation2D;
class CAudioComponent;

class CGrabAnimation
{
private:
	void AddSequence();

public:
	void PlayAnimation();

private:

private:
	CAnimation2D* GrabAnimation;
	CAudioComponent* mAudio;
	AGrab* Grab;

public:
	void SetGrab(AGrab* _Grab)
	{
		Grab = _Grab;
		GrabAnimation = Grab->GetAnimation();
		mAudio = Grab->GetAudioComponent();
		AddSequence();
	}
};

