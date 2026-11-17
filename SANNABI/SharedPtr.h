#pragma once

template <typename T>
class TSharedPtr
{
private:
	T* mObj = nullptr;

public:
	TSharedPtr() {}
	TSharedPtr(T* Obj) { mObj = Obj; if (mObj) mObj->AddRef(); }
	TSharedPtr(const TSharedPtr<T>& Ptr) { mObj = Ptr.mObj; if (mObj) mObj->AddRef(); }
	TSharedPtr(TSharedPtr<T>&& Ptr) noexcept { mObj = Ptr.mObj; if (mObj) mObj->AddRef(); }
	~TSharedPtr() { if (mObj) mObj->Release(); }

	void operator = (T* Obj)
	{
		if (mObj) mObj->Release();
		mObj = Obj;
		if (mObj) mObj->AddRef();
	}
	void operator = (const TSharedPtr<T>& Ptr)
	{
		if (mObj) mObj->Release();
		mObj = Ptr.mObj;
		if (mObj) mObj->AddRef();
	}
	void operator = (TSharedPtr<T>&& Ptr) noexcept
	{
		if (mObj) mObj->Release();
		mObj = Ptr.mObj;
		if (mObj) mObj->AddRef();
	}

	bool operator == (T* Obj) const { return mObj == Obj; }
	bool operator == (const TSharedPtr<T>& Ptr) const { return mObj == Ptr.mObj; }
	bool operator == (TSharedPtr<T>&& Ptr) const { return mObj == Ptr.mObj; }

	bool operator != (T* Obj) const { return mObj != Obj; }
	bool operator != (const TSharedPtr<T>& Ptr) const { return mObj != Ptr.mObj; }
	bool operator != (TSharedPtr<T>&& Ptr) const { return mObj != Ptr.mObj; }

	T* operator -> () const { return mObj; }

	operator T* () const { return mObj; }

	T* Get() const { return mObj; }
};

