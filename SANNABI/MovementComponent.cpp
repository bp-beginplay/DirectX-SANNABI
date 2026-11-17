#include "MovementComponent.h"
#include "SceneComponent.h"

CMovementComponent::CMovementComponent() {}
CMovementComponent::CMovementComponent(const CMovementComponent& Com) : CComponent(Com) {}
CMovementComponent::CMovementComponent(CMovementComponent&& Com) noexcept : CComponent(Com) {}
CMovementComponent::~CMovementComponent() {}

bool CMovementComponent::Init()
{
	if (!CComponent::Init()) return false;
	return true;
}

bool CMovementComponent::Init(const char* FileName)
{
	if (!CComponent::Init(FileName)) return false;
	return true;
}

void CMovementComponent::PreUpdate(float DeltaTime)
{
	CComponent::PreUpdate(DeltaTime);
	if (UpdateComponent)
	{
		if (!UpdateComponent->IsActive()) UpdateComponent = nullptr;
		else if (UpdateComponent->IsEnable()) {}
	}
}

void CMovementComponent::Update(float DeltaTime)
{
	CComponent::Update(DeltaTime);

	if (UpdateComponent)
	{
		if (!UpdateComponent->IsActive())
		{
			UpdateComponent = nullptr;
		}
		else if (UpdateComponent->IsEnable())
		{
			if (IsCanMove)
			{
				if (MoveAxis != EAxis::None)
				{
					Velocity = UpdateComponent->GetAxis(MoveAxis);
				}
				Velocity.Normalize();

				if (Velocity.Length() > 0.f)
				{
					MoveStep.x = Velocity.x * XSpeed * DeltaTime;
					MoveStep.y = Velocity.y * YSpeed * DeltaTime;

					UpdateComponent->AddWorldPos(MoveStep);
				}
			}
		}
	}
}

void CMovementComponent::PostUpdate(float DeltaTime)
{
	CComponent::PostUpdate(DeltaTime);

	if (UpdateComponent)
	{
		if (!UpdateComponent->IsActive())
		{
			UpdateComponent = nullptr;
		}
		else if (UpdateComponent->IsEnable())
		{
			// 여기서 작업 
		}
	}
}

void CMovementComponent::PostRender()
{
	CComponent::PostRender();

	if (UpdateComponent)
	{
		if (!UpdateComponent->IsActive())
		{
			UpdateComponent = nullptr;
		}
		else if (UpdateComponent->IsEnable())
		{
			// 여기서 작업 
		}
	}
}

CMovementComponent* CMovementComponent::Clone()
{
	return new CMovementComponent(*this);
}

void CMovementComponent::SetUpdateComponent(CSceneComponent* Target)
{
	UpdateComponent = Target;
}

void CMovementComponent::EndFrame()
{
	if (VelocityInit)
		Velocity = FVector3D::Zero;

	MoveStep = FVector3D::Zero;
}