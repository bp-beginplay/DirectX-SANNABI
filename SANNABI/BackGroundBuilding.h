#pragma once

#include "Actor.h"

class CBackGroundBuilding : public AActor
{
protected:
	CBackGroundBuilding();
	CBackGroundBuilding(const CBackGroundBuilding& Obj);
	CBackGroundBuilding(CBackGroundBuilding&& Obj);
	virtual ~CBackGroundBuilding();

protected:
	//TSharedPtr<class CSpriteComponent> BackGroundSprite;
public:
	virtual bool Init() override;

public:
	void setFlip(bool Flip);
};