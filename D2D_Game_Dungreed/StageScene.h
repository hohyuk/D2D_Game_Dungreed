#pragma once
#include "Scene.h"
class StageScene :
	public Scene
{
public:
	// Scene��(��) ���� ��ӵ�
	virtual HRESULT Ready() override;
	virtual void Update() override;
	virtual void Render() override;

public:
	explicit StageScene();
	virtual ~StageScene();
};

