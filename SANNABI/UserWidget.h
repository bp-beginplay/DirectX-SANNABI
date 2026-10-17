#pragma once
#include "Widget.h"

class CUserWidget :
	public CWidget
{
	friend class CSceneUIManager;

protected:
	CUserWidget();
	virtual ~CUserWidget();

protected:
	//위젯들 목록
	std::vector<TSharedPtr<CWidget>> mWidgetList;

public:
	void AddWidget(CWidget* Widget)
	{
		Widget->SetParent(this);
		mWidgetList.emplace_back(Widget);
	}

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void Render();
	virtual void Render(const FVector3D& Pos);
	virtual bool CollisionMouse(CWidget** Result, const FVector2D& MousePos);

	static bool SortCollision(const TSharedPtr<CWidget>& Src, const TSharedPtr<CWidget>& Dest);
	static bool SortRender(const TSharedPtr<CWidget>& Src, const TSharedPtr<CWidget>& Dest);


};

