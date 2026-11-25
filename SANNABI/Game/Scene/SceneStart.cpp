#include "Game/Scene/SceneStart.h"

#include "Game/UI/StartWidget.h"
#include "Engine/Scene/SceneUIManager.h"

CSceneStart::CSceneStart()
{

}

CSceneStart::~CSceneStart()
{

}

bool CSceneStart::Init()
{
	if (!CScene::Init())
	{
		return false;
	}


	//UI 생성
	CStartWidget* Widget = mUIManager->CreateWidget<CStartWidget>("Start");

	mUIManager->AddToViewport(Widget);



	return true;
}
