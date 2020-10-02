#pragma once
#include "Scene.h"
class TownScene final:
	public Scene
{
public:
	// Scene��(��) ���� ��ӵ�
	virtual HRESULT Ready() override;
	virtual void Update() override;
	virtual void Render() override;
	
public:
	explicit TownScene();
	virtual ~TownScene();

private:
	void RenderBackGround(const wstring& wsrObject, const D3DXMATRIX& mat);
};

