#pragma once

#include "Actor.h"

class CCameraComponent;

class ACameraActor : public AActor
{
	friend class CScene;

protected:
	ACameraActor();
	ACameraActor(const ACameraActor& Obj);
	ACameraActor(ACameraActor&& Obj) noexcept;
	virtual ~ACameraActor();

public:
	virtual bool Init() override;

private:
	TSharedPtr<CCameraComponent> Camera;
};

