#pragma once

#include "SpriteEffect.h"

class EBulletExplodeEffect : public ESpriteEffect
{
	friend class CScene;

protected:
	EBulletExplodeEffect();
	EBulletExplodeEffect(const EBulletExplodeEffect& Obj);
	EBulletExplodeEffect(EBulletExplodeEffect&& Obj);
	virtual ~EBulletExplodeEffect();

public:
	virtual bool Init() override;
	virtual void Update(float DeltaTime) override;

private:
	virtual void AnimationEnd() override;

public:
	virtual void SetAnimation(const std::string& Name, float PlayTime = 1.f, float PlayRate = 1.f, bool Loop = false, bool Reverse = false) override;
};