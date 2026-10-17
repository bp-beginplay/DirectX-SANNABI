#include "CameraComponent.h"
#include "Scene.h"
#include "CameraManager.h"

CCameraComponent::CCameraComponent() {}
CCameraComponent::CCameraComponent(const CCameraComponent& Com) : CSceneComponent(Com) {}
CCameraComponent::CCameraComponent(CCameraComponent&& Com) noexcept : CSceneComponent(Com) {}
CCameraComponent::~CCameraComponent() {}

void CCameraComponent::SetProjectionType(ECameraProjectionType Type)
{
    mProjType = Type;
    switch (mProjType)
    {
    case ECameraProjectionType::Perspective:
        mmatProj = DirectX::XMMatrixPerspectiveFovLH(DirectX::XMConvertToRadians(mViewAngle), mWidth / mHeight, 0.5, mViewDistance);
        break;
    case ECameraProjectionType::Ortho:
        mmatProj = DirectX::XMMatrixOrthographicOffCenterLH(mWidth / -2.f, mWidth / 2.f, mHeight / -2.f, mHeight / 2.f, 0, mViewDistance);
        break;
    default:
        break;
    }
}

bool CCameraComponent::Init()
{
    if (!CSceneComponent::Init())
        return false;
    SetProjectionType(ECameraProjectionType::Perspective);
    if (!mScene->GetCameraManager()->GetViewTarget())
        mScene->GetCameraManager()->SetViewTarget(this);
    return true;
}

bool CCameraComponent::Init(const char* FileName)
{
    if (!CSceneComponent::Init(FileName))
        return false;
    SetProjectionType(ECameraProjectionType::Perspective);
    if (!mScene->GetCameraManager()->GetViewTarget()) 
        mScene->GetCameraManager()->SetViewTarget(this);
    return true;
}

void CCameraComponent::PreUpdate(float DeltaTime)
{
    CSceneComponent::PreUpdate(DeltaTime); 
}

void CCameraComponent::Update(float DeltaTime)
{
    CSceneComponent::Update(DeltaTime); 
}

void CCameraComponent::PostUpdate(float DeltaTime)
{
    CSceneComponent::PostUpdate(DeltaTime);
    mmatView.Identity();
    for (int i = 0; i < EAxis::End; ++i)
    {
        FVector3D   Axis = mAxis[i];
        memcpy(&mmatView[i][0], &Axis, sizeof(FVector3D));
    }
    mmatView.Transpose();
    for (int i = 0; i < EAxis::End; ++i)
    {
        mmatView[3][i] = -mAxis[i].Dot(mWorldPos);
    }
}

void CCameraComponent::Collision(float DeltaTime) { CSceneComponent::Collision(DeltaTime); }
void CCameraComponent::PreRender() { CSceneComponent::PreRender(); }
void CCameraComponent::Render() { CSceneComponent::Render(); }
void CCameraComponent::PostRender() { CSceneComponent::PostRender(); }
CCameraComponent* CCameraComponent::Clone() { return new CCameraComponent(*this); }
