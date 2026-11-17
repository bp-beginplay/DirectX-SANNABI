#pragma once

#include "Engine.h"

class CAsset abstract : public CObject
{
public:
	CAsset();
	virtual ~CAsset();

public:
	const std::string& GetName() const { return mName; }
	EAssetType GetAssetType() const { return mAssetType; }
	void SetName(const std::string& Name) { mName = Name; }

protected:
	class CScene* mScene = nullptr;
	std::string mName;
	EAssetType mAssetType;
};

