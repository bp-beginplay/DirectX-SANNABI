#pragma once

class CObject abstract
{
protected:
	CObject();
	virtual ~CObject();

public:
	virtual void AddRef();
	virtual void Release();
	virtual void Destroy();

	bool IsActive() { return mActive; }
	bool IsEnable() { return mEnable; }
	int GetRefCount() const { return mRefCount; }
	void SetEnable(bool Enable) { mEnable = Enable; }

protected:
	int mRefCount = 0;
	bool mActive = true;
	bool mEnable = true;
};