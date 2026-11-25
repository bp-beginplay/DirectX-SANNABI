#include "Engine/Render/RenderState.h"

CRenderState::CRenderState() {}

CRenderState::~CRenderState()
{
	SAFE_RELEASE(mState);
	SAFE_RELEASE(mPrevState);
}