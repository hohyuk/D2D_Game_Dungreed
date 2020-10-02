#pragma once
#include "GameObject.h"
class Actor :
	public GameObject
{
public:
	// GameObject��(��) ���� ��ӵ�
	virtual HRESULT Ready() override;
	virtual int Update() override;
public:
	explicit Actor();
	virtual ~Actor();

protected:
	virtual void ChangeAnim();
};

