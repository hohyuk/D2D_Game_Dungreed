#include "framework.h"
#include "Scene.h"

void Scene::LateUpdate()
{
	OBJ_MGR->LateUpdate();
}

void Scene::Release()
{
	OBJ_MGR->Release();
}

Scene::Scene()
{
}

Scene::~Scene()
{
	Release();
}

void Scene::LoadData(SCENE::TYPE eID)
{
	wstring wstrFile = LoadFilePath(eID);
	HANDLE hFile = CreateFile(wstrFile.c_str(), GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (INVALID_HANDLE_VALUE == hFile)
		return;

	DWORD dwByte = 0;
	CLASS::TYPE eType = CLASS::TYPE::END_CLASS;
	while (true)
	{
		ReadFile(hFile, &eType, sizeof(CLASS::TYPE), &dwByte, nullptr);
		if (dwByte == 0)
			break;

		GameObject* pObj = ClassType(hFile, eType);

		if (nullptr == pObj) break;

		switch (eType)
		{
		case CLASS::TYPE::TILE_CLASS:
			OBJ_MGR->Add_GameObject(OBJECT::TYPE::TILE_OBJ, pObj);
			break;
		case CLASS::TYPE::ARCH_CLASS:
			OBJ_MGR->Add_GameObject(OBJECT::TYPE::ARCHITECTURE_OBJ, pObj);
			break;
		case CLASS::TYPE::MONSTER_CLASS:
			//if (eID == SCENE::TYPE::STAGE4_SCENE || eID == SCENE::TYPE::BOSS_SCENE)
				OBJ_MGR->Add_GameObject(OBJECT::TYPE::MOUSE_OBJ, pObj);
			//else   // 몬스터만 따로 담기
			//	m_vecMonster.emplace_back(OBJ::OBJ_EFFECT, pObj);
			break;
		case CLASS::TYPE::LINE_CLASS:
			OBJ_MGR->Add_GameObject(OBJECT::TYPE::TILE_OBJ, pObj);
			break;
		case CLASS::TYPE::END_CLASS:
			break;
		default:
			break;
		}
	}
	CloseHandle(hFile);
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
