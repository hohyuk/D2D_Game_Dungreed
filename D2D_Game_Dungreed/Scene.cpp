#include "framework.h"
#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::LoadData(SCENE::TYPE eID)
{
}

wstring Scene::LoadFilePath(SCENE::TYPE eID)
{
	return wstring();
}

GameObject * Scene::ClassType(HANDLE & hFile, CLASS::TYPE eType)
{
	GameObject* pObj = nullptr;

	switch (eType)
	{
	case CLASS::TILE_CLASS:
		break;
	case CLASS::ARCH_CLASS:
		break;
	case CLASS::MONSTER_CLASS:
		break;
	case CLASS::LINE_CLASS:
		break;
	case CLASS::END_CLASS:
	default:
		return nullptr;
	}
	return pObj;
}

void Scene::Render_BackGround()
{
}
