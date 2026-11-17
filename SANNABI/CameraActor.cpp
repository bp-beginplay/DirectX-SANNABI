#include "CameraActor.h"
#include "CameraComponent.h"

ACameraActor::ACameraActor()
{
}

ACameraActor::ACameraActor(const ACameraActor& Obj)
{
}

ACameraActor::ACameraActor(ACameraActor&& Obj) noexcept
{
}

ACameraActor::~ACameraActor()
{
}

bool ACameraActor::Init()
{
	AActor::Init();

	Camera = CreateComponent<CCameraComponent>();
	Camera->SetProjectionType(ECameraProjectionType::Ortho);
	Root->AddChild(Camera);

	return true;
}

