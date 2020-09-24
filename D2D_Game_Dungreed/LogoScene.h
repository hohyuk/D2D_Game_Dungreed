#pragma once
#include "Scene.h"
class LogoScene final :
	public Scene
{
public:
	// Scene��(��) ���� ��ӵ�
	virtual HRESULT Ready() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	explicit LogoScene();
	virtual ~LogoScene();
};