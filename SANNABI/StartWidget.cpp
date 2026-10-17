#include "StartWidget.h"

#include "Device.h"
#include "Scene.h"
#include "MainScene.h"
#include "SceneManager.h"
#include "SceneUIManager.h"
#include "Button.h"
#include "Image.h"
#include "AssetManager.h"
#include "SoundManager.h"

CStartWidget::CStartWidget()
{
}

CStartWidget::~CStartWidget()
{
}

bool CStartWidget::Init()
{
	CUserWidget::Init();

	CAssetManager::GetInst()->GetSoundManager()->Play("StartSceneBGM");

	FResolution RS = CDevice::GetInst()->GetResolution();

	//배경
	TSharedPtr<CImage> Title = mScene->GetUIManager()->CreateWidget<CImage>("Title");
	TSharedPtr<CImage> BackGround = mScene->GetUIManager()->CreateWidget<CImage>("BackGround");
	
	//버튼을 추가하기 
	mButton = mScene->GetUIManager()->CreateWidget<CButton>("TestButton");

	Title->SetTexture("Title", TEXT("Texture/SANNABI.png"));
	Title->SetSize(1500.f, 1500.f);
	Title->SetPos(700.f, 100.f);
	BackGround->SetTexture("StartBackGround", TEXT("Texture/MainTitle.png"));
	BackGround->SetSize((float)RS.Width, (float)RS.Height);

	Title->SetZOrder(8);
	BackGround->SetZOrder(7);
	mButton->SetZOrder(10);

	AddWidget(Title);
	AddWidget(BackGround);
	AddWidget(mButton);

	mButton->SetPos(1600.f, 300.f);
	mButton->SetSize(400.f, 100.f);
	mButton->SetPivot(FVector2D(0.5f, 0.5f));

	mButton->SetTexture(EButtonState::Normal, "StartButton", TEXT("Texture/StartButton.png"));
	mButton->SetTexture(EButtonState::Hovered, "StartButton");
	mButton->SetTexture(EButtonState::Click, "StartButton", TEXT("Texture/StartButton.png"));
	mButton->SetTexture(EButtonState::Disable, "StartButton", TEXT("Texture/StartButton.png"));

	mButton->SetTint(EButtonState::Normal, 0.8f, 0.8f, 0.8f);
	mButton->SetTint(EButtonState::Hovered, 1.f, 1.f, 1.f);
	mButton->SetTint(EButtonState::Click, 0.5f, 0.5f, 0.5f);
	mButton->SetTint(EButtonState::Disable, 0.1f, 0.1f, 0.1f);

	mButton->SetEventCallBack(EButtonEventState::Click, this, &CStartWidget::StartButtonClick);

	return true;
}


void CStartWidget::StartButtonClick()
{
	CLog::PrintLog("Start Button Click");

	CSceneManager::GetInst()->CreateLoadScene<CMainScene>();
}