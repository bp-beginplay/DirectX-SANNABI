#pragma once

#include "Engine.h"

class CRenderState
{
	friend class CRenderStateManager;

protected:
	CRenderState();
	virtual ~CRenderState();

public:
	virtual void SetState() = 0;
	virtual void ResetState() = 0;

protected:
	ID3D11DeviceChild* mState = nullptr;
	ID3D11DeviceChild* mPrevState = nullptr;
	ERenderStateType::Type mStateType;
};