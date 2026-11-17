#pragma once

#include "SpriteEffect.h"

class EExplodeEffect : public ESpriteEffect
{
	friend class CScene;

protected:
	EExplodeEffect();
	EExplodeEffect(const EExplodeEffect& Obj);
	EExplodeEffect(EExplodeEffect&& Obj);
	virtual ~EExplodeEffect();

public:
	virtual bool Init() override;
	virtual void Update(float DeltaTime) override;

private:
	virtual void AnimationEnd() override;

public:
	virtual void SetAnimation(const std::string& Name, float PlayTime = 1.f, float PlayRate = 1.f, bool Loop = false, bool Reverse = false) override;
};

