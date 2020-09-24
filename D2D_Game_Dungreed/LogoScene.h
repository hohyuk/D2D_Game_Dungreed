#pragma once
#include "Scene.h"
class LogoScene final :
	public Scene
{
public:
	// Scene을(를) 통해 상속됨
	virtual HRESULT Ready() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	explicit LogoScene();
	virtual ~LogoScene();
};