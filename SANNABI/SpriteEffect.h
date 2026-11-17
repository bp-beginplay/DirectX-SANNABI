#pragma once

#include "Actor.h"

class ESpriteEffect :
	public AActor
{
	friend class CScene;

protected:
	TSharedPtr<class CSpriteComponent> mRoot;

	class CAnimation2D* mAnimation = nullptr;

	bool mLoop = false;

protected:
	ESpriteEffect();
	ESpriteEffect(const ESpriteEffect& Obj);
	ESpriteEffect(ESpriteEffect&& Obj);
	virtual ~ESpriteEffect();
	virtual void AnimationEnd();

public:
	virtual bool Init() override;
	virtual void Update(float DeltaTime) override;


public:
	virtual void SetAnimation(const std::string& Name, float PlayTime = 1.f, float PlayRate = 1.f, bool Loop = false, bool Reverse = false);
};
