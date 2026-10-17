#pragma once

#include "Actor.h"
#include "SpriteComponent.h"
#include "BackGroundBuilding.h"

class CBackGround : public AActor
{
	friend class CScene;

protected:
	CBackGround();
	CBackGround(const CBackGround& Obj);
	CBackGround(CBackGround&& Obj);
	virtual ~CBackGround();

protected:
	TSharedPtr<class CSpriteComponent> BackGroundSprite;
public:
	virtual bool Init() override;

public:
	void setFlip(bool Flip)
	{
		Sprite->SetFlip(Flip);
	}
};

