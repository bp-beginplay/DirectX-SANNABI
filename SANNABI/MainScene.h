#pragma once
#include "Scene.h"

class CMainScene :
	public CScene
{
	friend class CSceneManager;

protected:
	CMainScene();
	virtual ~CMainScene();


public:
	virtual bool Init();
	void SetEnemyInScene();
	virtual void Update(float DeltaTime) override;
};

