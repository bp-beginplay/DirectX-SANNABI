#include "ProfileManager.h"

CProfileManager::CProfileManager() {}

CProfileManager::~CProfileManager()
{
	auto iter = mProfileMap.begin();
	auto iterEnd = mProfileMap.end();

	for (; iter != iterEnd; ++iter)
	{
		SAFE_DELETE(iter->second);
	}
}

bool CProfileManager::Init()
{
	CreateProfile("Default", ECollisionChannel::Default, false, ECollisionInteraction::Ignore);

	// Player
	CreateProfile("Player", ECollisionChannel::Player, true, ECollisionInteraction::Ignore);
	CreateProfile("PlayerU", ECollisionChannel::Player, true, ECollisionInteraction::Ignore);
	CreateProfile("PlayerD", ECollisionChannel::Player, true, ECollisionInteraction::Ignore);
	CreateProfile("PlayerR", ECollisionChannel::Player, true, ECollisionInteraction::Ignore);
	CreateProfile("PlayerL", ECollisionChannel::Player, true, ECollisionInteraction::Ignore);
	CreateProfile("PlayerHand", ECollisionChannel::Player, true, ECollisionInteraction::Ignore);
	CreateProfile("Aim", ECollisionChannel::Player, true, ECollisionInteraction::Ignore);
	CreateProfile("EnemyColli", ECollisionChannel::Player, true, ECollisionInteraction::Ignore);

	// Ground
	CreateProfile("Ground", ECollisionChannel::Ground, true, ECollisionInteraction::Ignore);

	// Grab
	CreateProfile("Grab", ECollisionChannel::Grab, true, ECollisionInteraction::Ignore);

	// Enemy
	CreateProfile("Enemy", ECollisionChannel::Enemy, true, ECollisionInteraction::Ignore);

	
	CreateProfile("Bullet", ECollisionChannel::Bullet, true, ECollisionInteraction::Ignore);

	CreateProfile("VendingMachine", ECollisionChannel::VendingMachine, true, ECollisionInteraction::Ignore);


	SetInteraction("Player", ECollisionChannel::Enemy, ECollisionInteraction::Collision);
	SetInteraction("Player", ECollisionChannel::Bullet, ECollisionInteraction::Collision);
	SetInteraction("Player", ECollisionChannel::VendingMachine, ECollisionInteraction::Collision);

	SetInteraction("PlayerU", ECollisionChannel::Ground, ECollisionInteraction::Collision);
	SetInteraction("PlayerD", ECollisionChannel::Ground, ECollisionInteraction::Collision);
	SetInteraction("PlayerR", ECollisionChannel::Ground, ECollisionInteraction::Collision);
	SetInteraction("PlayerL", ECollisionChannel::Ground, ECollisionInteraction::Collision);
	SetInteraction("PlayerHand", ECollisionChannel::Ground, ECollisionInteraction::Collision);
	SetInteraction("Aim", ECollisionChannel::Ground, ECollisionInteraction::Collision);
	SetInteraction("EnemyColli", ECollisionChannel::Enemy, ECollisionInteraction::Collision);
	SetInteraction("EnemyColli", ECollisionChannel::Ground, ECollisionInteraction::Ignore);


	SetInteraction("Ground", ECollisionChannel::Player, ECollisionInteraction::Collision);
	SetInteraction("Ground", ECollisionChannel::Grab, ECollisionInteraction::Collision);
	SetInteraction("Ground", ECollisionChannel::Bullet, ECollisionInteraction::Collision);

	SetInteraction("Grab", ECollisionChannel::Ground, ECollisionInteraction::Collision);
	SetInteraction("Grab", ECollisionChannel::Enemy, ECollisionInteraction::Collision);
	SetInteraction("Grab", ECollisionChannel::VendingMachine, ECollisionInteraction::Ignore);

	SetInteraction("Enemy", ECollisionChannel::Player, ECollisionInteraction::Collision);
	SetInteraction("Enemy", ECollisionChannel::Grab, ECollisionInteraction::Collision);

	SetInteraction("Bullet", ECollisionChannel::Player, ECollisionInteraction::Collision);
	SetInteraction("Bullet", ECollisionChannel::Ground, ECollisionInteraction::Collision);
	SetInteraction("Bullet", ECollisionChannel::Enemy, ECollisionInteraction::Ignore);
	SetInteraction("Bullet", ECollisionChannel::Grab, ECollisionInteraction::Ignore);

	SetInteraction("VendingMachine", ECollisionChannel::Player, ECollisionInteraction::Collision);
	SetInteraction("VendingMachine", ECollisionChannel::Enemy, ECollisionInteraction::Ignore);
	SetInteraction("VendingMachine", ECollisionChannel::Grab, ECollisionInteraction::Ignore);
	SetInteraction("VendingMachine", ECollisionChannel::Ground, ECollisionInteraction::Ignore);
	SetInteraction("VendingMachine", ECollisionChannel::Bullet, ECollisionInteraction::Ignore);

	return true;
}

bool CProfileManager::CreateProfile(const std::string& Name, ECollisionChannel::Type Channel, bool Enable, ECollisionInteraction::Type Interaction)
{
	FCollisionProfile* Profile = FindProfile(Name);
	if (Profile != nullptr) { return false; }
	Profile = new FCollisionProfile;
	Profile->Name = Name;
	Profile->Channel = Channel;
	Profile->Enable = Enable;
	for (int i = 0; i < ECollisionChannel::End; ++i)
	{
		Profile->Interaction[i] = Interaction;
	}
	mProfileMap.insert(std::make_pair(Name, Profile));
	return true;
}

bool CProfileManager::SetInteraction(const std::string& Name, ECollisionChannel::Type Channel, ECollisionInteraction::Type Interaction)
{
	FCollisionProfile* Profile = FindProfile(Name);
	if (Profile == nullptr) return false;
	Profile->Interaction[Channel] = Interaction;
	return true;
}

bool CProfileManager::SetEnable(const std::string& Name, bool Enable)
{
	FCollisionProfile* Profile = FindProfile(Name);
	if (Profile == nullptr)return false;
	Profile->Enable = Enable;
	return true;
}

FCollisionProfile* CProfileManager::FindProfile(const std::string& Name)
{
	std::unordered_map<std::string, FCollisionProfile*>::iterator iter = mProfileMap.find(Name);
	if (iter == mProfileMap.end())return nullptr;
	return iter->second;
}