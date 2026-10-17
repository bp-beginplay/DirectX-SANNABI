#pragma once

#include "Engine.h"
#include "SceneComponent.h"
#include "ColliderAABB2D.h"

class CColliderLine2D;

class AActor : public CObject
{
	friend class CScene;

protected:
	AActor();
	AActor(const AActor& Obj);
	AActor(AActor&& Obj) noexcept;
	virtual ~AActor();
	bool CountDown(float _Time, float DeltaTime);
public:
	virtual bool Init();
	virtual void SetColliderScale();

	virtual void PreUpdate(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void PreRender();
	virtual void Render();
	virtual void PostRender();
	virtual void EndFrame();
	virtual AActor* Clone();
	virtual void Destroy() override;

protected:
	float CountTime = 0.f;
	TSharedPtr<class CSceneComponent> Root;
	TSharedPtr<class CSpriteComponent> Sprite;
	TSharedPtr<class CColliderAABB2D> Colli;
	TSharedPtr<class CAudioComponent> mAudio;
	TSharedPtr<class CMovementComponent> MovementComponent;
	class CAnimation2D* mAnimation = nullptr;

	class CScene* mScene = nullptr;
	std::string mName = "None";
	std::vector<TSharedPtr<class CComponent>> mNonComponentList;
	std::vector<TSharedPtr<class CComponent>> mSceneComponentList;
	float mLifeTime = 0.f;

public:
	CMovementComponent* GetMovementComponent() const { return MovementComponent; }
	CAudioComponent* GetAudioComponent() const { return mAudio; }
	CAnimation2D* GetAnimation() const { return mAnimation; }
	void SetLifeTime(float Time) { mLifeTime = Time; }
	class CSceneComponent* GetRootComponent() const { return Root; }
	class CColliderAABB2D* GetColliderComponent() const { return Colli; }
	class CScene* GetScene() const { return mScene; }
	const char* GetName() const { return  mName.c_str(); }
	void SetName(const std::string& Name) { mName = Name; }
	void SetRootComponent(class CSceneComponent* _Root) { Root = _Root; }

	template<typename T>
	T* CreateComponent(const std::string LayerName = "")
	{
		T* Component = new T;

		Component->mScene = mScene;
		Component->mOwnerObject = this;

		class CSceneComponent* Com = dynamic_cast<CSceneComponent*>(Component);

		if (!LayerName.empty() && Com)
		{
			Com->mRenderLayerName = LayerName;
		}

		if (!Component->Init())
		{
			SAFE_DELETE(Component);
			return nullptr;
		}

		if (!Com)
		{
			mNonComponentList.emplace_back(Component);
		}
		else
		{
			mSceneComponentList.emplace_back(Component);
		}

		return Component;
	}

public:
#pragma region Transform
	const FMatrix& GetScaleMatrix() const;
	const FMatrix& GetRotationMatrix() const;
	const FMatrix& GetTranslateMatrix() const;
	const FMatrix& GetWorldMatrix() const;

	const FVector3D& GetAxis(EAxis::Type Axis) const;
	const FVector3D& GetRelativeScale() const;
	const FVector3D& GetRelativeRotation() const;
	const FVector3D& GetRelativePosition() const;
	const FVector3D& GetWorldScale() const;
	const FVector3D& GetWorldRotation() const;
	const FVector3D& GetWorldPosition() const;

	void SetRelativeScale(const FVector3D& Scale);
	void SetRelativeScale(float x, float y, float z);
	void SetRelativeScale(const FVector2D& Scale);
	void SetRelativeScale(float x, float y);

	void SetRelativeRotation(const FVector3D& Rot);
	void SetRelativeRotation(float x, float y, float z);
	void SetRelativeRotation(const FVector2D& Rot);
	void SetRelativeRotation(float x, float y);
	void SetRelativeRotationX(float x);
	void SetRelativeRotationY(float y);
	void SetRelativeRotationZ(float z);
	void SetRelativeRotationAxis(float Angle, const FVector3D& Axis);

	void SetRelativePos(const FVector3D& Pos);
	void SetRelativePos(float x, float y, float z);
	void SetRelativePos(const FVector2D& Pos);
	void SetRelativePos(float x, float y);

	void SetWorldScale(const FVector3D& Scale);
	void SetWorldScale(float x, float y, float z);
	void SetWorldScale(const FVector2D& Scale);
	void SetWorldScale(float x, float y);

	void SetWorldRotation(const FVector3D& Rot);
	void SetWorldRotation(float x, float y, float z);
	void SetWorldRotation(const FVector2D& Rot);
	void SetWorldRotation(float x, float y);
	void SetWorldRotationX(float x);
	void SetWorldRotationY(float y);
	void SetWorldRotationZ(float z);
	void SetWorldRotationAxis(float Angle, const FVector3D& Axis);

	void SetWorldPos(const FVector3D& Pos);
	void SetWorldPos(float x, float y, float z);
	void SetWorldPos(const FVector2D& Pos);
	void SetWorldPos(float x, float y);

	void AddRelativeScale(const FVector3D& Scale);
	void AddRelativeScale(float x, float y, float z);
	void AddRelativeScale(const FVector2D& Scale);
	void AddRelativeScale(float x, float y);

	void AddRelativeRotation(const FVector3D& Rot);
	void AddRelativeRotation(float x, float y, float z);
	void AddRelativeRotation(const FVector2D& Rot);
	void AddRelativeRotation(float x, float y);
	void AddRelativeRotationX(float x);
	void AddRelativeRotationY(float y);
	void AddRelativeRotationZ(float z);

	void AddRelativePos(const FVector3D& Pos);
	void AddRelativePos(float x, float y, float z);
	void AddRelativePos(const FVector2D& Pos);
	void AddRelativePos(float x, float y);

	void AddWorldScale(const FVector3D& Scale);
	void AddWorldScale(float x, float y, float z);
	void AddWorldScale(const FVector2D& Scale);
	void AddWorldScale(float x, float y);

	void AddWorldRotation(const FVector3D& Rot);
	void AddWorldRotation(float x, float y, float z);
	void AddWorldRotation(const FVector2D& Rot);
	void AddWorldRotation(float x, float y);
	void AddWorldRotationX(float x);
	void AddWorldRotationY(float y);
	void AddWorldRotationZ(float z);

	void AddWorldPos(const FVector3D& Pos);
	void AddWorldPos(float x, float y, float z);
	void AddWorldPos(const FVector2D& Pos);
	void AddWorldPos(float x, float y);
#pragma endregion
};
