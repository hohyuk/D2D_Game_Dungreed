#pragma once
class GameObject;

class GameObjectManager final
{
	DECLARE_SINGLETON(GameObjectManager)
private:
	explicit GameObjectManager();
	~GameObjectManager();

public:		// Get
	GameObject* Get_Player()const { return m_listObject[OBJECT::TYPE::PLAYER_OBJ].front(); }
	D3DXVECTOR3 Get_MousePoint()const;

public:
	void ChangeScene() { isSceneChange = true; }
	D3DXVECTOR2 Get_MapSize()const { return m_vMapSize; }

public:
	HRESULT Add_GameObject(OBJECT::TYPE eType, GameObject* pObject);
	void	DeleteGameObject(OBJECT::TYPE eType);
	int		Update();
	void	LateUpdate();
	void	Render();
	void	Release();

private:
	list<GameObject*> m_listObject[OBJECT::TYPE::END_OBJ];

private:
	bool isSceneChange{ false };
	D3DXVECTOR2 m_vMapSize{};
};

