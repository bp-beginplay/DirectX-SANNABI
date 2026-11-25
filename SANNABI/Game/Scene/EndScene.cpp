#include "Game/Scene/EndScene.h"
#include "Engine/UI/Image.h"
#include "Game/Object/SANNABIOST.h"
#include "Engine/Scene/SceneUIManager.h"
#include "Engine/Asset/AssetManager.h"
#include "Engine/Asset/SoundManager.h"
#include "Engine/Device/Device.h"

CEndScene::CEndScene()
{
}

CEndScene::~CEndScene()
{
}

bool CEndScene::Init()
{
	if (!CScene::Init())
	{
		return false;
	}

	//CAssetManager::GetInst()->GetSoundManager()->Stop("SceneMainBGM");
	CSANNABIOST* BackGorund = CreateObj<CSANNABIOST>("BackGround");
	BackGorund->setFlip(false);
	BackGorund->SetWorldScale(2.f, 2.f);

	return true;
}