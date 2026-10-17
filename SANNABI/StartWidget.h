#pragma once
#include "UserWidget.h"
class CStartWidget :
	public CUserWidget
{
	friend class CSceneUIManager;

protected:
	CStartWidget();
	virtual ~CStartWidget();

protected:
	TSharedPtr<class CButton> mButton;
	//TSharedPtr<class CButton> mEditorButton;

public:
	virtual bool Init();

private:
	void StartButtonClick();
};
