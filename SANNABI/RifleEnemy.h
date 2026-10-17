#pragma once

#include "Enemy.h"

class ARifleEnemy : public AEnemy
{
	friend class CScene;

protected:
	ARifleEnemy();
	ARifleEnemy(const ARifleEnemy& Obj);
	ARifleEnemy(ARifleEnemy&& Obj) noexcept;
	virtual ~ARifleEnemy();

public:
	virtual bool Init() override;
	virtual void Update(float DeltaTime) override;
};

