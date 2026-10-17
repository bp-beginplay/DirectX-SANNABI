#pragma once

#include "Player.h"
#include "Scene.h"

class APlayer;
class CAnimation2D;
class CAudioComponent;

class CPlayerAnimation
{
public:
	void PlayAnimtion();


private:
	void Wall();
	void SetFlip();
	void Falling();
	void Ground();
	void AddSequence();
	void Play_Walk1();
	void Play_Walk2();

	void Play_WallClimbUp1();
	void Play_WallClimbUp2();

	void Restart();

	void Play_Jump();



	class CInput* Input = nullptr;
	APlayer* Player;
	CAnimation2D* PlayerAnimation;
	CPlayerMovement* PlayerMovement;
	CAudioComponent* mAudio;
	float CountTime = 0.f;

public:
	void SetPlayer(APlayer* _Player)
	{
		Player = _Player;
		PlayerAnimation = Player->GetAnimation();
		PlayerMovement = Player->GetPlayerMovement();
		mAudio = Player->GetAudioComponent();
		Input = Player->GetScene()->GetInput();
		AddSequence();
	}
};