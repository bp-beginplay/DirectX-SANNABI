#include "MainScene.h"
#include "Player.h"
#include "Ground.h"
#include "SceneComponent.h"
#include "ColliderAABB2D.h"
#include "SpriteComponent.h"
#include "BackGround.h"
#include "SceneAssetManager.h"
#include "Enemy.h"
#include "RifleEnemy.h"
#include "ShotGunEnemy.h"
#include "AudioComponent.h"
#include "SoundManager.h"
#include "VendingMachine.h"
#include "AssetManager.h"

CMainScene::CMainScene() {}
CMainScene::~CMainScene() {}

bool CMainScene::Init()
{
	if (!CScene::Init())
		return false;
	CAssetManager::GetInst()->GetSoundManager()->Stop("StartSceneBGM");
	CAssetManager::GetInst()->GetSoundManager()->Play("SceneMainBGM");

	AActor* Player = CreateObj<APlayer>("Player");
	Player->GetRootComponent()->SetWorldPos(-1400.f, -900.f, 0.f);
	Player->GetRootComponent()->SetWorldScale(40.f, 40.f, 1.f);
	Player->SetColliderScale();

	AGround* GroundDown = CreateObj<AGround>("Ground");
	GroundDown->GetRootComponent()->SetWorldPos(0.f, -950.f);
	GroundDown->GetRootComponent()->SetWorldScale(3000.f, 50.f, 1.f);
	GroundDown->SetColliderScale();


	AGround* WallLeft = CreateObj<AGround>("Ground");
	WallLeft->GetRootComponent()->SetWorldPos(-1450.f, 0.f);
	WallLeft->GetRootComponent()->SetWorldScale(50.f, 2000.f, 1.f);
	WallLeft->SetColliderScale();

	AGround* GroundUp = CreateObj<AGround>("Ground");
	GroundUp->GetRootComponent()->SetWorldPos(0.f, 950.f);
	GroundUp->GetRootComponent()->SetWorldScale(3000.f, 50.f, 1.f);
	GroundUp->SetColliderScale();

	AGround* WallRight = CreateObj<AGround>("Ground");
	WallRight->GetRootComponent()->SetWorldPos(1450.f, 0.f);
	WallRight->GetRootComponent()->SetWorldScale(50.f, 2000.f, 1.f);
	WallRight->SetColliderScale();

	AGround* Block1 = CreateObj<AGround>("Ground");
	Block1->GetRootComponent()->SetWorldPos(150.f, -225.f);
	Block1->GetRootComponent()->SetWorldScale(100.f, 100.f, 1.f);
	Block1->SetColliderScale();
 
	AGround* Block2 = CreateObj<AGround>("Ground");
	Block2->GetRootComponent()->SetWorldPos(-700.f, -500.f);
	Block2->GetRootComponent()->SetWorldScale(500.f, 100.f, 1.f);
	Block2->SetColliderScale();


	AGround* Block3 = CreateObj<AGround>("Ground");
	Block3->GetRootComponent()->SetWorldPos(-700.f, -500.f);
	Block3->GetRootComponent()->SetWorldScale(500.f, 100.f, 1.f);
	Block3->SetColliderScale();

	AGround* Block4 = CreateObj<AGround>("Ground");
	Block4->GetRootComponent()->SetWorldPos(-700.f, -200.f);
	Block4->GetRootComponent()->SetWorldScale(50.f, 300.f, 1.f);
	Block4->SetColliderScale();

	AGround* Block5 = CreateObj<AGround>("Ground");
	Block5->GetRootComponent()->SetWorldPos(-400.f, 0.f);
	Block5->GetRootComponent()->SetWorldScale(300.f, 300.f, 1.f);
	Block5->SetColliderScale();


	AGround* Block6 = CreateObj<AGround>("Ground");
	Block6->GetRootComponent()->SetWorldPos(-1000.f, -875.f);
	Block6->GetRootComponent()->SetWorldScale(100.f, 100.f, 1.f);
	Block6->SetColliderScale();

	AGround* Block7 = CreateObj<AGround>("Ground");
	Block7->GetRootComponent()->SetWorldPos( 1200.f, -675.f);
	Block7->GetRootComponent()->SetWorldScale(500.f, 500.f, 1.f);
	Block7->SetColliderScale();

	AGround* Block8 = CreateObj<AGround>("Ground");
	Block8->GetRootComponent()->SetWorldPos(1200.f, 0.f);
	Block8->GetRootComponent()->SetWorldScale(100.f, 100.f, 1.f);
	Block8->SetColliderScale();

	AGround* Block9 = CreateObj<AGround>("Ground");
	Block9->GetRootComponent()->SetWorldPos(-1200.f, -200.f);
	Block9->GetRootComponent()->SetWorldScale(300.f, 100.f, 1.f);
	Block9->SetColliderScale();


	AGround* Block10 = CreateObj<AGround>("Ground");
	Block10->GetRootComponent()->SetWorldPos(-1400.f, -400.f);
	Block10->GetRootComponent()->SetWorldScale(100.f, 500.f, 1.f);
	Block10->SetColliderScale();

	AGround* Block11 = CreateObj<AGround>("Ground");
	Block11->GetRootComponent()->SetWorldPos(1200.f, 600.f);
	Block11->GetRootComponent()->SetWorldScale(600.f, 100.f, 1.f);
	Block11->SetColliderScale();


	CBackGround* BackGorund = CreateObj<CBackGround>("BackGround");
	BackGorund->SetWorldScale(3000.f, 2000.f);
	BackGorund->setFlip(false);
	
	SetEnemyInScene();

	//AVendingMachine* VendingMachine = CreateObj<AVendingMachine>("VendingMachine");
	//VendingMachine->GetRootComponent()->SetWorldPos(-1200.f, -900.f, 0.f);
	//VendingMachine->GetRootComponent()->SetWorldScale(54.f, 82.f, 1.f);
	//VendingMachine->SetColliderScale();

	return true;
}

void CMainScene::SetEnemyInScene()
{
	//ARifleEnemy* Enemy1 = CreateObj<ARifleEnemy>("Enemy");
	//Enemy1->GetRootComponent()->SetWorldPos(-475.f, -425.f);
	//Enemy1->GetRootComponent()->SetWorldScale(50.f, 50.f, 1.f);
	//Enemy1->SetColliderScale();
	ARifleEnemy* Enemy2 = CreateObj<ARifleEnemy>("Enemy");
	Enemy2->GetRootComponent()->SetWorldPos(-500.f, -575.f);
	Enemy2->GetRootComponent()->SetWorldScale(50.f, 50.f, 1.f);
	Enemy2->SetRelativeRotationZ(180.f);
	Enemy2->SetColliderScale();
	//ARifleEnemy* Enemy3 = CreateObj<ARifleEnemy>("Enemy");
	//Enemy3->GetRootComponent()->SetWorldPos(-400.f, 175.f);
	//Enemy3->GetRootComponent()->SetWorldScale(50.f, 50.f, 1.f);
	//Enemy3->SetColliderScale();
	//ARifleEnemy* Enemy6 = CreateObj<ARifleEnemy>("Enemy");
	//Enemy6->GetRootComponent()->SetWorldPos(700.f, 0.f);
	//Enemy6->GetRootComponent()->SetWorldScale(50.f, 50.f, 1.f);
	//Enemy6->SetColliderScale();

	//AShotGunEnemy* Enemy4 = CreateObj<AShotGunEnemy>("Enemy");
	//Enemy4->GetRootComponent()->SetWorldPos(0.f, -900.f);
	//Enemy4->GetRootComponent()->SetWorldScale(50.f, 50.f, 1.f);
	//Enemy4->SetColliderScale();
	//AShotGunEnemy* Enemy5 = CreateObj<AShotGunEnemy>("Enemy");
	//Enemy5->GetRootComponent()->SetWorldPos(-1025.f, -200.f);
	//Enemy5->SetWorldRotationZ(270.f);
	//Enemy5->GetRootComponent()->SetWorldScale(50.f, 50.f, 1.f);
	//Enemy5->SetColliderScale();
	//AShotGunEnemy* Enemy7 = CreateObj<AShotGunEnemy>("Enemy");
	//Enemy7->GetRootComponent()->SetWorldPos(1000.f, 300.f);
	//Enemy7->GetRootComponent()->SetWorldScale(50.f, 50.f, 1.f);
	//Enemy7->SetColliderScale();
	//AShotGunEnemy* Enemy8 = CreateObj<AShotGunEnemy>("Enemy");
	//Enemy8->GetRootComponent()->SetWorldPos(1100.f, 675.f);
	//Enemy8->GetRootComponent()->SetWorldScale(50.f, 50.f, 1.f);
	//Enemy8->SetColliderScale();
}

void CMainScene::Update(float DeltaTime)
{
	CScene::Update(DeltaTime);

	if (Point == 8)
	{
		AVendingMachine* VendingMachine = CreateObj<AVendingMachine>("VendingMachine");
		VendingMachine->GetRootComponent()->SetWorldPos(1400.f, 700.f);
		VendingMachine->GetRootComponent()->SetWorldScale(54.f, 82.f, 1.f);
		VendingMachine->SetColliderScale();
		Point = 0;
	}
}
