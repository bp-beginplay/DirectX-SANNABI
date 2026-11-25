#pragma once

#include "Engine/UI/WindowWidget.h"

class WMainWidget : public CWindowWidget
{
	friend class CSceneUIManager;

protected:
	WMainWidget();
	virtual ~WMainWidget();
};

