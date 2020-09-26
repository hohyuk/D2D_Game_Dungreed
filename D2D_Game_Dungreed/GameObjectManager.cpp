#include "framework.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "MouseUI.h"

IMPLEMENT_SINGLETON(GameObjectManager)

GameObjectManager::GameObjectManager()
{

}

GameObjectManager::~GameObjectManager()
{
}

D3DXVECTOR3 GameObjectManager::Get_MousePoint() const
{
	if (nullptr == dynamic_cast<MouseUI*>(m_listObject[OBJECT::TYPE::MOUSE_OBJ].front()))
		return D3DXVECTOR3();

	return dynamic_cast<MouseUI*>(m_listObject[OBJECT::TYPE::MOUSE_OBJ].front())->MousePoint();
}

HRESULT GameObjectManager::Add_GameObject(OBJECT::TYPE eType, GameObject * pObject)
{
	if (nullptr == pObject || OBJECT::TYPE::END_OBJ <= eType)
		return E_FAIL;

	m_listObject[eType].emplace_back(pObject);
	return S_OK;
}

void GameObjectManager::DeleteGameObject(OBJECT::TYPE eType)
{
	for (auto& pObj : m_listObject[eType])
		Safe_Delete(pObj);
	m_listObject[eType].clear();
}

int GameObjectManager::Update()
{
	for (int i = OBJECT::TYPE::ARCHITECTURE_OBJ; i < OBJECT::TYPE::END_OBJ; ++i)
	{
		list<GameObject*>::iterator iter;
		for (iter = m_listObject[i].begin(); iter != m_listObject[i].end();)
		{
			int iEvent = (*iter)->Update();
			if (OBJ_DEAD == iEvent)
			{
				Safe_Delete(*iter);
				iter = m_listObject[i].erase(iter);
			}
			else
				++iter;
		}
	}
	return OBJ_NOEVENT;
}

void GameObjectManager::LateUpdate()
{
	for (int i = OBJECT::TYPE::ARCHITECTURE_OBJ; i < OBJECT::TYPE::END_OBJ; ++i)
	{
		for (const auto& pObj : m_listObject[i])
		{
			pObj->LateUpdate();
			if (isSceneChange)
			{
				isSceneChange = false;
				return;
			}
		}

	}
}

void GameObjectManager::Render()
{
	for (int i = 0; i < OBJECT::TYPE::END_OBJ; ++i)
		for (const auto& pObj : m_listObject[i])
			pObj->Render();
}

void GameObjectManager::Release()
{
	for (int i = 0; i < OBJECT::TYPE::END_OBJ; ++i)
	{
		for (auto& pObj : m_listObject[i])
			Safe_Delete(pObj);
		m_listObject[i].clear();
	}
}
