#pragma once
#include "Actor.h"
class Player :
	public Actor
{
	virtual HRESULT Ready() override;
	virtual int Update() override;
public:
	static GameObject* Create(float posX, float posY);
public:
	explicit Player();
	virtual ~Player();
};

