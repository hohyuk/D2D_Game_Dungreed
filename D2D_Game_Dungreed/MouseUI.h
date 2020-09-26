#pragma once
#include "UI.h"
class MouseUI :
	public UI
{
public:
	D3DXVECTOR3 MousePoint();
	
public:
	virtual HRESULT Ready() override;
public:
	static GameObject* Create(SCENE::TYPE eScene);

public:
	explicit MouseUI();
	virtual ~MouseUI();

private:
	SCENE::TYPE m_eSceneType;
};

