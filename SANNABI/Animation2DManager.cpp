#include "Animation2DManager.h"
#include "Animation2DData.h"
#include "Animation2D.h"

CAnimation2DManager::CAnimation2DManager() {}

CAnimation2DManager::~CAnimation2DManager() { CAnimation2D::DestroyCBuffer(); }

bool CAnimation2DManager::Init()
{
	CAnimation2D::CreateCBuffer();

	std::vector<const TCHAR*> FileName;
#pragma region BackGroundAnim
	CreateAnimation("BackGroundAnim");
	SetAnimationTextureType("BackGroundAnim", EAnimationTextureType::Frame);
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (1).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (2).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (3).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (4).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (5).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (6).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (7).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (8).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (9).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (10).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (11).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (12).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (13).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (14).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (15).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (16).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (17).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (18).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (19).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (20).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (21).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (22).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (23).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (24).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (25).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (26).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (27).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (28).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (29).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (30).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (31).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (32).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (33).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (34).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (35).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (36).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (37).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (38).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (39).png"));
	FileName.emplace_back(TEXT("Map\\BackGround\\BackGroundAnim (40).png"));
	SetTexture("BackGroundAnim", "BackGroundAnim", FileName);
	AddFrameCount("BackGroundAnim", 40, 0.f, 0.f, 3000.f, 2000.f);
#pragma endregion BackGroundAnim

#pragma region SNB_Idle
	CreateAnimation("SNB_Idle");
	SetAnimationTextureType("SNB_Idle", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (1).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (2).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (3).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (4).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (5).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (6).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (7).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (8).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (9).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (10).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (11).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (12).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (13).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (14).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (15).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (16).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (17).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (18).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (19).png"));
	FileName.emplace_back(TEXT("SNB\\Idle\\SNB_Idle (20).png"));
	SetTexture("SNB_Idle", "SNB_Idle", FileName);
	AddFrameCount("SNB_Idle", 20, 0.f, 0.f, 40.f, 40.f);
#pragma endregion SNB_Idle

#pragma region SNB_Running
	CreateAnimation("SNB_Running");
	SetAnimationTextureType("SNB_Running", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (1).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (2).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (3).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (4).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (5).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (6).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (7).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (8).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (9).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (10).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (11).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (12).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (13).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (14).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (15).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (16).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (17).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (18).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (19).png"));
	FileName.emplace_back(TEXT("SNB\\Running\\SNB_Running (20).png"));
	SetTexture("SNB_Running", "SNB_Running", FileName);
	AddFrameCount("SNB_Running", 20, 0.f, 0.f, 40.f, 40.f);
#pragma endregion SNB_Running

#pragma region SNB_Jumping
	CreateAnimation("SNB_Jumping");
	SetAnimationTextureType("SNB_Jumping", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Jumping\\SNB_Jumping (1).png"));
	FileName.emplace_back(TEXT("SNB\\Jumping\\SNB_Jumping (2).png"));
	FileName.emplace_back(TEXT("SNB\\Jumping\\SNB_Jumping (3).png"));
	FileName.emplace_back(TEXT("SNB\\Jumping\\SNB_Jumping (4).png"));
	FileName.emplace_back(TEXT("SNB\\Jumping\\SNB_Jumping (5).png"));
	FileName.emplace_back(TEXT("SNB\\Jumping\\SNB_Jumping (6).png"));
	SetTexture("SNB_Jumping", "SNB_Jumping", FileName);
	AddFrameCount("SNB_Jumping", 6, 0.f, 0.f, 40.f, 40.f);
#pragma endregion SNB_Jumping

#pragma region SNB_FallingStart
	CreateAnimation("SNB_FallingStart");
	SetAnimationTextureType("SNB_FallingStart", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\FallingStart\\SNB_FallingStart (1).png"));
	FileName.emplace_back(TEXT("SNB\\FallingStart\\SNB_FallingStart (2).png"));
	FileName.emplace_back(TEXT("SNB\\FallingStart\\SNB_FallingStart (3).png"));
	SetTexture("SNB_FallingStart", "SNB_FallingStart", FileName);
	AddFrameCount("SNB_FallingStart", 3, 0.f, 0.f, 40.f, 40.f);
#pragma endregion SNB_FallingStart

#pragma region SNB_Falling
	CreateAnimation("SNB_Falling");
	SetAnimationTextureType("SNB_Falling", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Falling\\SNB_Falling (1).png"));
	FileName.emplace_back(TEXT("SNB\\Falling\\SNB_Falling (2).png"));
	FileName.emplace_back(TEXT("SNB\\Falling\\SNB_Falling (3).png"));
	SetTexture("SNB_Falling", "SNB_Falling", FileName);
	AddFrameCount("SNB_Falling", 3, 0.f, 0.f, 40.f, 40.f);
#pragma endregion SNB_Falling

#pragma region SNB_ClimbUp
	CreateAnimation("SNB_ClimbUp");
	SetAnimationTextureType("SNB_ClimbUp", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Climb\\Up\\SNB_ClimbUp (1).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Up\\SNB_ClimbUp (2).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Up\\SNB_ClimbUp (3).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Up\\SNB_ClimbUp (4).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Up\\SNB_ClimbUp (5).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Up\\SNB_ClimbUp (6).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Up\\SNB_ClimbUp (7).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Up\\SNB_ClimbUp (8).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Up\\SNB_ClimbUp (9).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Up\\SNB_ClimbUp (10).png"));
	SetTexture("SNB_ClimbUp", "SNB_ClimbUp", FileName);
	AddFrameCount("SNB_ClimbUp", 10, 0.f, 0.f, 40.f, 40.f);
#pragma endregion SNB_ClimbUp

#pragma region SNB_ClimbDown
	CreateAnimation("SNB_ClimbDown");
	SetAnimationTextureType("SNB_ClimbDown", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (1).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (2).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (3).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (4).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (5).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (6).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (7).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (8).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (9).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (10).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (11).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (12).png"));
	FileName.emplace_back(TEXT("SNB\\Climb\\Down\\SNB_ClimbDown (13).png"));
	SetTexture("SNB_ClimbDown", "SNB_ClimbDown", FileName);
	AddFrameCount("SNB_ClimbDown", 13, 0.f, 0.f, 40.f, 40.f);
#pragma endregion SNB_ClimbDown

#pragma region SNB_Swing
	CreateAnimation("SNB_Swing");
	SetAnimationTextureType("SNB_Swing", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (1).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (2).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (3).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (4).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (5).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (6).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (7).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (8).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (9).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (10).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (11).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (12).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (13).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (14).png"));
	FileName.emplace_back(TEXT("SNB\\Swing\\SNB_Swing (15).png"));
	SetTexture("SNB_Swing", "SNB_Swing", FileName);
	AddFrameCount("SNB_Swing", 15, 0.f, 0.f, 40.f, 40.f);
#pragma endregion SNB_Swing

#pragma region SNB_Rolling
	CreateAnimation("SNB_Rolling");
	SetAnimationTextureType("SNB_Rolling", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (1).png"));
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (2).png"));
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (3).png"));
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (4).png"));
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (5).png"));
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (6).png"));
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (7).png"));
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (8).png"));
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (9).png"));
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (10).png"));
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (11).png"));
	FileName.emplace_back(TEXT("SNB\\Rolling\\SNB_Rolling (12).png"));
	SetTexture("SNB_Rolling", "SNB_Rolling", FileName);
	AddFrameCount("SNB_Rolling", 12, 0.f, 0.f, 40.f, 40.f);
#pragma endregion SNB_Rolling

#pragma region SNB_Damage
	CreateAnimation("SNB_Damage");
	SetAnimationTextureType("SNB_Damage", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Damage\\SNB_Damaged (1).png"));
	FileName.emplace_back(TEXT("SNB\\Damage\\SNB_Damaged (2).png"));
	FileName.emplace_back(TEXT("SNB\\Damage\\SNB_Damaged (3).png"));
	FileName.emplace_back(TEXT("SNB\\Damage\\SNB_Damaged (4).png"));
	FileName.emplace_back(TEXT("SNB\\Damage\\SNB_Damaged (5).png"));
	SetTexture("SNB_Damage", "SNB_Damage", FileName);
	AddFrameCount("SNB_Damage", 5, 0.f, 0.f, 40.f, 40.f);
#pragma endregion SNB_Damage

#pragma region SNB_Death
	CreateAnimation("SNB_Death");
	SetAnimationTextureType("SNB_Death", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (1).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (2).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (3).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (4).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (5).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (6).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (7).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (8).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (9).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (10).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (11).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (12).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (13).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (14).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (15).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (16).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (17).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (18).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (19).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (20).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (21).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (22).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (23).png"));
	FileName.emplace_back(TEXT("SNB\\Death\\SNB_Death (24).png"));
	SetTexture("SNB_Death", "SNB_Death", FileName);
	AddFrameCount("SNB_Death", 24, 0.f, 0.f, 40.f, 40.f);
#pragma endregion SNB_Death

#pragma region SNBGrab_Idle
	CreateAnimation("SNBGrab_Idle");
	SetAnimationTextureType("SNBGrab_Idle", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Grab\\SNBGrab_Idle.png"));
	SetTexture("SNBGrab_Idle", "SNBGrab_Idle", FileName);
	AddFrameCount("SNBGrab_Idle", 1, 0.f, 0.f, 20.f, 20.f);
#pragma endregion SNBGrab_Idle

#pragma region SNBGrab_Grabbing
	CreateAnimation("SNBGrab_Grabbing");
	SetAnimationTextureType("SNBGrab_Grabbing", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (1).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (2).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (3).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (4).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (5).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (6).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (7).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (8).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (9).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (10).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (11).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (12).png"));
	FileName.emplace_back(TEXT("SNB\\Grab\\Grabbing\\SNBGrab_Grabbing (13).png"));
	SetTexture("SNBGrab_Grabbing", "SNBGrab_Grabbing", FileName);
	AddFrameCount("SNBGrab_Grabbing", 13, 0.f, 0.f, 20.f, 20.f);
#pragma endregion SNBGrab_Grabbing

#pragma region Enemy_Explode
	CreateAnimation("Enemy_Explode");
	SetAnimationTextureType("Enemy_Explode", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (1).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (2).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (3).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (4).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (5).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (6).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (7).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (8).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (9).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (10).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (11).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (12).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (13).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (14).png"));
	FileName.emplace_back(TEXT("Enemy\\Explode\\Enemy_Explode (15).png"));
	SetTexture("Enemy_Explode", "Enemy_Explode", FileName);
	AddFrameCount("Enemy_Explode", 15, 0.f, 0.f, 100.f, 100.f);
#pragma endregion Enemy_Explode

#pragma region Bullet_Boom
	CreateAnimation("Bullet_Boom");
	SetAnimationTextureType("Bullet_Boom", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (1).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (2).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (3).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (4).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (5).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (6).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (7).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (8).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (9).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (10).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (11).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (12).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (13).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (14).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (15).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (16).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (17).png"));
	FileName.emplace_back(TEXT("Bullet\\Bullet_Boom (18).png"));
	SetTexture("Bullet_Boom", "Bullet_Boom", FileName);
	AddFrameCount("Bullet_Boom", 18, 0.f, 0.f, 45.f, 45.f);
#pragma endregion Bullet_Boom

#pragma region HUD_HP4_Idle
	CreateAnimation("HUD_HP4_Idle");
	SetAnimationTextureType("HUD_HP4_Idle", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Idle (1).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Idle (2).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Idle (3).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Idle (4).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Idle (5).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Idle (6).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Idle (7).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Idle (8).png"));
	SetTexture("HUD_HP4_Idle", "HUD_HP4_Idle", FileName);
	AddFrameCount("HUD_HP4_Idle", 8, 0.f, 0.f, 70.f, 60.f);
#pragma endregion HUD_HP4_Idle

#pragma region HUD_HP4_Damage
	CreateAnimation("HUD_HP4_Damage");
	SetAnimationTextureType("HUD_HP4_Damage", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Damage (1).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Damage (2).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Damage (3).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Damage (4).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Damage (5).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Damage (6).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\4\\HUD_HP4_Damage (7).png"));
	SetTexture("HUD_HP4_Damage", "HUD_HP4_Damage", FileName);
	AddFrameCount("HUD_HP4_Damage", 7, 0.f, 0.f, 70.f, 60.f);
#pragma endregion HUD_HP4_Damage

#pragma region HUD_HP3_Idle
	CreateAnimation("HUD_HP3_Idle");
	SetAnimationTextureType("HUD_HP3_Idle", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Idle (1).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Idle (2).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Idle (3).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Idle (4).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Idle (5).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Idle (6).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Idle (7).png"));
	SetTexture("HUD_HP3_Idle", "HUD_HP3_Idle", FileName);
	AddFrameCount("HUD_HP3_Idle", 7, 0.f, 0.f, 70.f, 60.f);
#pragma endregion HUD_HP3_Idle

#pragma region HUD_HP3_Damage
	CreateAnimation("HUD_HP3_Damage");
	SetAnimationTextureType("HUD_HP3_Damage", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Damage (1).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Damage (2).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Damage (3).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Damage (4).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Damage (5).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Damage (6).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Damage (7).png"));
	SetTexture("HUD_HP3_Damage", "HUD_HP3_Damage", FileName);
	AddFrameCount("HUD_HP3_Damage", 7, 0.f, 0.f, 70.f, 60.f);
#pragma endregion HUD_HP3_Damage

#pragma region HUD_HP3_Restore
	CreateAnimation("HUD_HP3_Restore");
	SetAnimationTextureType("HUD_HP3_Restore", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Restore (1).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Restore (2).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Restore (3).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Restore (4).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Restore (5).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Restore (6).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Restore (7).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Restore (8).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Restore (9).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Restore (10).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\3\\HUD_HP3_Restore (11).png"));
	SetTexture("HUD_HP3_Restore", "HUD_HP3_Restore", FileName);
	AddFrameCount("HUD_HP3_Restore", 11, 0.f, 0.f, 70.f, 60.f);
#pragma endregion HUD_HP3_Restore

#pragma region HUD_HP2_Idle
	CreateAnimation("HUD_HP2_Idle");
	SetAnimationTextureType("HUD_HP2_Idle", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Idle (1).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Idle (2).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Idle (3).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Idle (4).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Idle (5).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Idle (6).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Idle (7).png"));
	SetTexture("HUD_HP2_Idle", "HUD_HP2_Idle", FileName);
	AddFrameCount("HUD_HP2_Idle", 7, 0.f, 0.f, 70.f, 60.f);
#pragma endregion HUD_HP2_Idle

#pragma region HUD_HP2_Damage
	CreateAnimation("HUD_HP2_Damage");
	SetAnimationTextureType("HUD_HP2_Damage", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Damage (1).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Damage (2).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Damage (3).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Damage (4).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Damage (5).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Damage (6).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\2\\HUD_HP2_Damage (7).png"));
	SetTexture("HUD_HP2_Damage", "HUD_HP2_Damage", FileName);
	AddFrameCount("HUD_HP2_Damage", 7, 0.f, 0.f, 70.f, 60.f);
#pragma endregion HUD_HP2_Damage

#pragma region HUD_HP1_Idle
	CreateAnimation("HUD_HP1_Idle");
	SetAnimationTextureType("HUD_HP1_Idle", EAnimationTextureType::Frame);
	FileName.clear();
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (1).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (2).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (3).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (4).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (5).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (6).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (7).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (8).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (9).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (10).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (11).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (12).png"));
	FileName.emplace_back(TEXT("HUD\\HP\\1\\HUD_HP1_Idle (13).png"));
	SetTexture("HUD_HP1_Idle", "HUD_HP1_Idle", FileName);
	AddFrameCount("HUD_HP1_Idle", 13, 0.f, 0.f, 70.f, 60.f);
#pragma endregion HUD_HP1_Idle

	CreateAnimation("VendingMachine_Idle");
	SetAnimationTextureType("VendingMachine_Idle", EAnimationTextureType::Frame);
	FileName.clear();
	TCHAR Path1[52][MAX_PATH] = {};
	for (int i = 1; i <= 52; ++i)
	{
		wsprintf(Path1[i - 1], TEXT("VendingMachine\\VendingMachine_Idle (%d).png"), i);
		FileName.emplace_back(Path1[i - 1]);
	}
	SetTexture("VendingMachine_Idle", "VendingMachine_Idle", FileName);
	AddFrameCount("VendingMachine_Idle", 52, 0.f, 0.f, 54, 82);

	CreateAnimation("ostVideo");
	SetAnimationTextureType("ostVideo", EAnimationTextureType::Frame);
	FileName.clear();
	TCHAR Path[250][MAX_PATH] = {};
	for (int i = 1; i <= 250; ++i)
	{
		wsprintf(Path[i - 1], TEXT("SANNABIOST\\1080\\Frame (%d).jpg"), i);
		FileName.emplace_back(Path[i - 1]);
	}
	SetTexture("ostVideo", "ostVideo", FileName);
	AddFrameCount("ostVideo", 250, 0.f, 0.f, 1920.f, 1080.f);

	return true;
}

bool CAnimation2DManager::CreateAnimation(const std::string& Name)
{
	if (FindAnimation(Name)) return false;
	CAnimation2DData* Animation = new CAnimation2DData;
	Animation->SetName(Name);
	mAnimationMap.insert(std::make_pair(Name, Animation));
	return true;
}

class CAnimation2DData* CAnimation2DManager::FindAnimation(const std::string& Name)
{
	auto iter = mAnimationMap.find(Name);
	if (iter == mAnimationMap.end()) return nullptr;
	return iter->second;
}

void CAnimation2DManager::ReleaseAnimation(class CAsset* Animation)
{
	auto iter = mAnimationMap.find(Animation->GetName());
	if (iter != mAnimationMap.end()) mAnimationMap.erase(iter);
}

bool CAnimation2DManager::SetAnimationTextureType(const std::string& Name, EAnimationTextureType Type)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->SetAnimationTextureType(Type);
	return true;
}

bool CAnimation2DManager::SetTexture(const std::string& Name, class CTexture* Texture)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->SetTexture(Texture);
	return true;
}

bool CAnimation2DManager::SetTexture(const std::string& Name, const std::string& TextureName)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->SetTexture(TextureName);
	return true;
}

bool CAnimation2DManager::SetTexture(const std::string& Name, const std::string& TextureName, const TCHAR* FileName)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->SetTexture(TextureName, FileName);
	return true;
}

bool CAnimation2DManager::SetTexture(const std::string& Name, const std::string& TextureName, std::vector<const TCHAR*> FileName)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->SetTexture(TextureName, FileName);
	return true;
}

bool CAnimation2DManager::SetTexture(const std::string& Name, const std::string& TextureName, const TCHAR* FileName, const TCHAR* Ext, int Count)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->SetTexture(TextureName, FileName, Ext, Count);
	return true;
}

bool CAnimation2DManager::SetTextureFullPath(const std::string& Name, const std::string& TextureName,
	const TCHAR* FullPath)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->SetTextureFullPath(TextureName, FullPath);
	return true;
}

bool CAnimation2DManager::SetTextureFullPath(const std::string& Name, const std::string& TextureName,
	const std::vector<const TCHAR*>& FullPath)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->SetTextureFullPath(TextureName, FullPath);
	return true;
}

bool CAnimation2DManager::AddFrame(const std::string& Name, const FVector2D& Start, const FVector2D& Size)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->AddFrame(Start, Size);
	return true;
}

bool CAnimation2DManager::AddFrame(const std::string& Name, float StartX, float StartY, float SizeX, float SizeY)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->AddFrame(StartX, StartY, SizeX, SizeY);
	return true;
}

bool CAnimation2DManager::AddFrameCount(const std::string& Name, int Count, const FVector2D& Start,
	const FVector2D& Size)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->AddFrameCount(Count, Start, Size);
	return true;
}

bool CAnimation2DManager::AddFrameCount(const std::string& Name, int Count, float StartX, float StartY,
	float SizeX, float SizeY)
{
	CAnimation2DData* Animation = FindAnimation(Name);
	if (!Animation) return false;
	Animation->AddFrameCount(Count, StartX, StartY, SizeX, SizeY);
	return true;
}