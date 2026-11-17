#include "Actor.h"
#include "SceneComponent.h"
#include "SpriteComponent.h"
#include "ColliderAABB2D.h"
#include "ColliderLine2D.h"
#include "MovementComponent.h"
#include "AudioComponent.h"

AActor::AActor()
{
}

AActor::AActor(const AActor& Obj)
{
}

AActor::AActor(AActor&& Obj) noexcept
{
}

AActor::~AActor()
{
	Root->EraseOwner();

	size_t Size = mNonComponentList.size();

	for (size_t i = 0; i < Size; ++i)
	{
		mNonComponentList[i]->EraseOwner();
	}

}

bool AActor::Init()
{
	Root = CreateComponent<CSceneComponent>();
	SetRootComponent(Root);

	Sprite = CreateComponent<CSpriteComponent>("Object");
	Root->AddChild(Sprite);

	Colli = CreateComponent<CColliderAABB2D>();
	Root->AddChild(Colli);

	mAudio = CreateComponent<CAudioComponent>();
	Root->AddChild(mAudio);

	return true;
}

bool AActor::CountDown(float _Time, float DeltaTime)
{
	CountTime += DeltaTime;
	if (CountTime >= _Time)
	{
		CountTime = 0;
		return true;
	}
	return false;
}


void AActor::SetColliderScale()
{
	Colli->SetBoxSize(Root->GetWorldScale().x, Root->GetWorldScale().y);
}

void AActor::PreUpdate(float DeltaTime)
{
	auto    iter = mNonComponentList.begin();
	auto    iterEnd = mNonComponentList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = mNonComponentList.erase(iter);
			iterEnd = mNonComponentList.end();
			continue;
		}

		else if (!(*iter)->IsEnable())
		{
			++iter;
			continue;
		}

		(*iter)->PreUpdate(DeltaTime);
		++iter;
	}


	Root->PreUpdate(DeltaTime);
}

void AActor::Update(float DeltaTime)
{
	auto    iter = mNonComponentList.begin();
	auto    iterEnd = mNonComponentList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = mNonComponentList.erase(iter);
			iterEnd = mNonComponentList.end();
			continue;
		}

		else if (!(*iter)->IsEnable())
		{
			++iter;
			continue;
		}

		(*iter)->Update(DeltaTime);
		++iter;
	}


	Root->Update(DeltaTime);

	//라이프타임 검사 
	if (mLifeTime > 0.f)
	{
		mLifeTime -= DeltaTime;

		if (mLifeTime <= 0.f)
			Destroy();
	}
}

void AActor::PostUpdate(float DeltaTime)
{
	auto    iter = mNonComponentList.begin();
	auto    iterEnd = mNonComponentList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = mNonComponentList.erase(iter);
			iterEnd = mNonComponentList.end();
			continue;
		}

		else if (!(*iter)->IsEnable())
		{
			++iter;
			continue;
		}

		(*iter)->PostUpdate(DeltaTime);
		++iter;
	}

	Root->PostUpdate(DeltaTime);
}

void AActor::Collision(float DeltaTime)
{
	auto    iter = mNonComponentList.begin();
	auto    iterEnd = mNonComponentList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = mNonComponentList.erase(iter);
			iterEnd = mNonComponentList.end();
			continue;
		}

		else if (!(*iter)->IsEnable())
		{
			++iter;
			continue;
		}

		(*iter)->Collision(DeltaTime);
		++iter;
	}

	Root->Collision(DeltaTime);
}

void AActor::PreRender()
{
	auto    iter = mNonComponentList.begin();
	auto    iterEnd = mNonComponentList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = mNonComponentList.erase(iter);
			iterEnd = mNonComponentList.end();
			continue;
		}

		else if (!(*iter)->IsEnable())
		{
			++iter;
			continue;
		}

		(*iter)->PreRender();
		++iter;
	}

	//
	//mRootComponent->PreRender();
}

void AActor::Render()
{
	auto    iter = mNonComponentList.begin();
	auto    iterEnd = mNonComponentList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = mNonComponentList.erase(iter);
			iterEnd = mNonComponentList.end();
			continue;
		}

		else if (!(*iter)->IsEnable())
		{
			++iter;
			continue;
		}

		(*iter)->Render();
		++iter;
	}

	//mRootComponent->Render();
}

void AActor::PostRender()
{
	auto    iter = mNonComponentList.begin();
	auto    iterEnd = mNonComponentList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = mNonComponentList.erase(iter);
			iterEnd = mNonComponentList.end();
			continue;
		}

		else if (!(*iter)->IsEnable())
		{
			++iter;
			continue;
		}

		(*iter)->PostRender();
		++iter;
	}

	//mRootComponent->PostRender();
}

void AActor::EndFrame()
{
	auto    iter = mNonComponentList.begin();
	auto    iterEnd = mNonComponentList.end();

	//for (; iter != iterEnd;)
	//{
	//	if (!(*iter)->IsActive())
	//	{
	//		iter = mNonComponentList.erase(iter);
	//		iterEnd = mNonComponentList.end();
	//		continue;
	//	}

	//	else if (!(*iter)->IsEnable())
	//	{
	//		++iter;
	//		continue;
	//	}

	//	(*iter)->EndFrame();
	//	++iter;
	//}
	for (; iter != iterEnd; ++iter)
	{
		(*iter)->EndFrame();

	}
	Root->EndFrame();
}

AActor* AActor::Clone()
{
	return nullptr;
}

void AActor::Destroy()
{
	CObject::Destroy();

	//삭제될때 컴포넌트들 레퍼런스 카운트 삭제

	{
		auto iter = mNonComponentList.begin();
		auto iterEnd = mNonComponentList.end();

		for (; iter != iterEnd; ++iter)
		{
			(*iter)->Destroy();
		}

		mNonComponentList.clear();
	}

	{
		auto iter = mSceneComponentList.begin();
		auto iterEnd = mSceneComponentList.end();

		for (; iter != iterEnd; ++iter)
		{
			(*iter)->Destroy();
		}

		mSceneComponentList.clear();
	}
}

#pragma region Trasnfrom
// Transform 함수들 

const FMatrix& AActor::GetScaleMatrix() const
{
	return Root->GetScaleMatrix();
}

const FMatrix& AActor::GetRotationMatrix() const
{
	return Root->GetRotationMatrix();
}

const FMatrix& AActor::GetTranslateMatrix() const
{
	return Root->GetTranslateMatrix();
}

const FMatrix& AActor::GetWorldMatrix() const
{
	return Root->GetWorldMatrix();
}

const FVector3D& AActor::GetAxis(EAxis::Type Axis) const
{
	return Root->GetAxis(Axis);
}

const FVector3D& AActor::GetRelativeScale() const
{
	return Root->GetRelativeScale();
}

const FVector3D& AActor::GetRelativeRotation() const
{
	return Root->GetRelativeRotation();
}

const FVector3D& AActor::GetRelativePosition() const
{
	return Root->GetRelativePosition();
}

const FVector3D& AActor::GetWorldScale() const
{
	return Root->GetWorldScale();
}

const FVector3D& AActor::GetWorldRotation() const
{
	return Root->GetWorldRotation();
}

const FVector3D& AActor::GetWorldPosition() const
{
	return Root->GetWorldPosition();
}

void AActor::SetRelativeScale(const FVector3D& Scale)
{
	Root->SetRelativeScale(Scale);
}

void AActor::SetRelativeScale(float x, float y, float z)
{
	Root->SetRelativeScale(x, y, z);
}

void AActor::SetRelativeScale(const FVector2D& Scale)
{
	Root->SetRelativeScale(Scale);
}

void AActor::SetRelativeScale(float x, float y)
{
	Root->SetRelativeScale(x, y);
}

void AActor::SetRelativeRotation(const FVector3D& Rot)
{
	Root->SetRelativeRotation(Rot);
}

void AActor::SetRelativeRotation(float x, float y, float z)
{
	Root->SetRelativeRotation(x, y, z);
}

void AActor::SetRelativeRotation(const FVector2D& Rot)
{
	Root->SetRelativeRotation(Rot);
}

void AActor::SetRelativeRotation(float x, float y)
{
	Root->SetRelativeRotation(x, y);
}

void AActor::SetRelativeRotationX(float x)
{
	Root->SetRelativeRotationX(x);
}

void AActor::SetRelativeRotationY(float y)
{
	Root->SetRelativeRotationY(y);
}

void AActor::SetRelativeRotationZ(float z)
{
	Root->SetRelativeRotationZ(z);
}

void AActor::SetRelativeRotationAxis(float Angle,
	const FVector3D& Axis)
{
	Root->SetRelativeRotationAxis(Angle, Axis);
}

void AActor::SetRelativePos(const FVector3D& Pos)
{
	Root->SetRelativePos(Pos);
}

void AActor::SetRelativePos(float x, float y, float z)
{
	Root->SetRelativePos(x, y, z);
}

void AActor::SetRelativePos(const FVector2D& Pos)
{
	Root->SetRelativePos(Pos);
}

void AActor::SetRelativePos(float x, float y)
{
	Root->SetRelativePos(x, y);
}

void AActor::SetWorldScale(const FVector3D& Scale)
{
	Root->SetWorldScale(Scale);
}

void AActor::SetWorldScale(float x, float y, float z)
{
	Root->SetWorldScale(x, y, z);
}

void AActor::SetWorldScale(const FVector2D& Scale)
{
	Root->SetWorldScale(Scale);
}

void AActor::SetWorldScale(float x, float y)
{
	Root->SetWorldScale(x, y);
}

void AActor::SetWorldRotation(const FVector3D& Rot)
{
	Root->SetWorldRotation(Rot);
}

void AActor::SetWorldRotation(float x, float y, float z)
{
	Root->SetWorldRotation(x, y, z);
}

void AActor::SetWorldRotation(const FVector2D& Rot)
{
	Root->SetWorldRotation(Rot);
}

void AActor::SetWorldRotation(float x, float y)
{
	Root->SetWorldRotation(x, y);
}

void AActor::SetWorldRotationX(float x)
{
	Root->SetWorldRotationX(x);
}

void AActor::SetWorldRotationY(float y)
{
	Root->SetWorldRotationY(y);
}

void AActor::SetWorldRotationZ(float z)
{
	Root->SetWorldRotationZ(z);
}

void AActor::SetWorldRotationAxis(float Angle,
	const FVector3D& Axis)
{
	Root->SetWorldRotationAxis(Angle, Axis);
}

void AActor::SetWorldPos(const FVector3D& Pos)
{
	Root->SetWorldPos(Pos);
}

void AActor::SetWorldPos(float x, float y, float z)
{
	Root->SetWorldPos(x, y, z);
}

void AActor::SetWorldPos(const FVector2D& Pos)
{
	Root->SetWorldPos(Pos);
}

void AActor::SetWorldPos(float x, float y)
{
	Root->SetWorldPos(x, y);
}

void AActor::AddRelativeScale(const FVector3D& Scale)
{
	Root->AddRelativeScale(Scale);
}

void AActor::AddRelativeScale(float x, float y, float z)
{
	Root->AddRelativeScale(x, y, z);
}

void AActor::AddRelativeScale(const FVector2D& Scale)
{
	Root->AddRelativeScale(Scale);
}

void AActor::AddRelativeScale(float x, float y)
{
	Root->AddRelativeScale(x, y);
}

void AActor::AddRelativeRotation(const FVector3D& Rot)
{
	Root->AddRelativeRotation(Rot);
}

void AActor::AddRelativeRotation(float x, float y, float z)
{
	Root->AddRelativeRotation(x, y, z);
}

void AActor::AddRelativeRotation(const FVector2D& Rot)
{
	Root->AddRelativeRotation(Rot);
}

void AActor::AddRelativeRotation(float x, float y)
{
	Root->AddRelativeRotation(x, y);
}

void AActor::AddRelativeRotationX(float x)
{
	Root->AddRelativeRotationX(x);
}

void AActor::AddRelativeRotationY(float y)
{
	Root->AddRelativeRotationY(y);
}

void AActor::AddRelativeRotationZ(float z)
{
	Root->AddRelativeRotationZ(z);
}

void AActor::AddRelativePos(const FVector3D& Pos)
{
	Root->AddRelativePos(Pos);
}

void AActor::AddRelativePos(float x, float y, float z)
{
	Root->AddRelativePos(x, y, z);
}

void AActor::AddRelativePos(const FVector2D& Pos)
{
	Root->AddRelativePos(Pos);
}

void AActor::AddRelativePos(float x, float y)
{
	Root->AddRelativePos(x, y);
}

void AActor::AddWorldScale(const FVector3D& Scale)
{
	Root->AddWorldScale(Scale);
}

void AActor::AddWorldScale(float x, float y, float z)
{
	Root->AddWorldScale(x, y, z);
}

void AActor::AddWorldScale(const FVector2D& Scale)
{
	Root->AddWorldScale(Scale);
}

void AActor::AddWorldScale(float x, float y)
{
	Root->AddWorldScale(x, y);
}

void AActor::AddWorldRotation(const FVector3D& Rot)
{
	Root->AddWorldRotation(Rot);
}

void AActor::AddWorldRotation(float x, float y, float z)
{
	Root->AddWorldRotation(x, y, z);
}

void AActor::AddWorldRotation(const FVector2D& Rot)
{
	Root->AddWorldRotation(Rot);
}

void AActor::AddWorldRotation(float x, float y)
{
	Root->AddWorldRotation(x, y);
}

void AActor::AddWorldRotationX(float x)
{
	Root->AddWorldRotationX(x);
}

void AActor::AddWorldRotationY(float y)
{
	Root->AddWorldRotationY(y);
}

void AActor::AddWorldRotationZ(float z)
{
	Root->AddWorldRotationZ(z);
}

void AActor::AddWorldPos(const FVector3D& Pos)
{
	Root->AddWorldPos(Pos);
}

void AActor::AddWorldPos(float x, float y, float z)
{
	Root->AddWorldPos(x, y, z);
}

void AActor::AddWorldPos(const FVector2D& Pos)
{
	Root->AddWorldPos(Pos);
}

void AActor::AddWorldPos(float x, float y)
{
	Root->AddWorldPos(x, y);
}

#pragma endregion Transform