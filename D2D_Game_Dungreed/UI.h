#pragma once
#include "GameObject.h"
class UI :
	public GameObject
{
	// GameObject을(를) 통해 상속됨
	virtual HRESULT Ready() override;
	virtual int Update() override;
};

