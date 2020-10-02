#pragma once
#include "UI.h"
class MouseUI :
	public UI
{
public:
	D3DXVECTOR3 Get_MousePoint()const { return m_tInfo.vPos; }
	
public:
	virtual HRESULT Ready() override;
	virtual int Update() override;
public:
	static GameObject* Create(SCENE::TYPE eScene);

public:
	explicit MouseUI();
	virtual ~MouseUI();

private:
	SCENE::TYPE m_eSceneType;
};

