#pragma once
#include "GameObject.h"
class Actor :
	public GameObject
{
public:
	// GameObject을(를) 통해 상속됨
	virtual HRESULT Ready() override;
	virtual int Update() override;
public:
	explicit Actor();
	virtual ~Actor();

protected:
	virtual void ChangeAnim();
};

