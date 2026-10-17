#pragma once

#include "Engine.h"

class CComponent abstract : public CObject
{
	friend class CScene;
	friend class AActor;

protected:
	CComponent();
	CComponent(const CComponent& Obj);
	CComponent(CComponent&& Obj);
	virtual ~CComponent();

public:
	virtual bool Init();
	virtual bool Init(const char* FileName);
	virtual void PreUpdate(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void PreRender();
	virtual void Render();
	virtual void PostRender();
	virtual void EndFrame();
	virtual CComponent* Clone();
	virtual void EraseOwner();

	class CScene* GetScene() const { return mScene; }
	class AActor* GetOwner() const { return mOwnerObject; }
	void SetOwner(AActor* _Actor) { mOwnerObject = _Actor; }
	const char* GetName() const { return mName.c_str(); }
	void SetName(const std::string& Name) { mName = Name; }

protected:
	class CScene* mScene = nullptr;
	class AActor* mOwnerObject = nullptr;
	std::string mName;
};