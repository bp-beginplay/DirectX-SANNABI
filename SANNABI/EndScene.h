#pragma once

#include "Scene.h"

class CEndScene : public CScene
{
	friend class CSceneManager;

protected:
	CEndScene();
	virtual ~CEndScene();


public:
	virtual bool Init() override;
};

