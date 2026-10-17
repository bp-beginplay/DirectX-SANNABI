#include "EndScene.h"
#include "Image.h"
#include "SANNABIOST.h"
#include "SceneUIManager.h"
#include "AssetManager.h"
#include "SoundManager.h"
#include "Device.h"

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