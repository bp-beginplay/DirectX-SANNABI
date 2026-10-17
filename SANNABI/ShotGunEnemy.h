#pragma once

#include "Enemy.h"

class AShotGunEnemy : public AEnemy
{
	friend class CScene;

protected:
	AShotGunEnemy();
	AShotGunEnemy(const AShotGunEnemy& Obj);
	AShotGunEnemy(AShotGunEnemy&& Obj) noexcept;
	virtual ~AShotGunEnemy();

public:
	virtual bool Init() override;
	virtual void Update(float DeltaTime) override;
};

