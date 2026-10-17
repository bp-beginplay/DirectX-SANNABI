#pragma once

#include "Actor.h"

class CColliderLine2D;

class AGround : public AActor
{
	friend class CScene;

protected:
	AGround();
	AGround(const AGround& Obj);
	AGround(AGround&& Obj) noexcept;
	virtual ~AGround();

public:
	virtual bool Init();

	virtual void SetColliderScale() override;
};