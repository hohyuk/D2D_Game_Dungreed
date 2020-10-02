#pragma once

#include "GameObjectManager.h"

class Scene abstract
{
public:
	virtual HRESULT Ready() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate();
	virtual void Render() = 0;
	virtual void Release();
public:
	explicit Scene();
	virtual ~Scene();
protected:
	void LoadData(SCENE::TYPE eID);
	wstring LoadFilePath(SCENE::TYPE eID);
	GameObject* ClassType(HANDLE & hFile, CLASS::TYPE eType);
	virtual void Render_BackGround();

protected:
	//vector<pair<OBJ::ID, GameObject*>> m_vecMonster;
};

