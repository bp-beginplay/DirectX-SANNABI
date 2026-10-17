#pragma once

#include "Engine.h"

class CProfileManager
{
	DECLARE_SINGLETON(CProfileManager)

public:
	bool Init();
	bool CreateProfile(const std::string& Name, ECollisionChannel::Type Channel, bool Enable, ECollisionInteraction::Type Interaction);
	bool SetInteraction(const std::string& Name, ECollisionChannel::Type Channel, ECollisionInteraction::Type Interaction);
	bool SetEnable(const std::string& Name, bool Enable);
	FCollisionProfile* FindProfile(const std::string& Name);

private:
	std::unordered_map<std::string, FCollisionProfile*> mProfileMap;
};