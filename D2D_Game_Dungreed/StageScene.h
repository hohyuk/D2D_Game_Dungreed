#pragma once
#include "Scene.h"
class StageScene :
	public Scene
{
public:
	// Scene을(를) 통해 상속됨
	virtual HRESULT Ready() override;
	virtual void Update() override;
	virtual void Render() override;

public:
	explicit StageScene();
	virtual ~StageScene();
};

