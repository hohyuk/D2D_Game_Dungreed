#pragma once
#include "UI.h"
class ButtonUI :
	public UI
{
public:
	virtual HRESULT Ready() override;
	virtual void	LateUpdate();
public:
	static GameObject* Create(CLASS::BUTTON_UI eButtonUI);

public:
	explicit ButtonUI();
	virtual ~ButtonUI();

private:
	CLASS::BUTTON_UI m_eButtonUI;
};

