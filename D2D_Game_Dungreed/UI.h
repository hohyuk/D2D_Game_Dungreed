#pragma once
#include "GameObject.h"
class UI :
	public GameObject
{
	// GameObject��(��) ���� ��ӵ�
	virtual HRESULT Ready() override;
	virtual int Update() override;
};

