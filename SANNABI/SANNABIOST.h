#pragma once

#include "Actor.h"
#include "SpriteComponent.h"

class CSANNABIOST : public AActor
{
	friend class CScene;

protected:
	CSANNABIOST();
	CSANNABIOST(const CSANNABIOST& Obj);
	CSANNABIOST(CSANNABIOST&& Obj);
	virtual ~CSANNABIOST();

public:
	virtual bool Init() override;
	virtual void Update(float DeltaTime) override;

private:
	void BackStartScene();

public:
	void setFlip(bool Flip)
	{
		Sprite->SetFlip(Flip);
	}

};

