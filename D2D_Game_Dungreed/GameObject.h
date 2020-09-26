#pragma once
#include "GameObjectManager.h"

class GameObject abstract
{
public:
	virtual HRESULT Ready() = 0;
	virtual int		Update() = 0;
	virtual void	LateUpdate();
	virtual void	Render();
	virtual void	Release();
public:
	explicit GameObject();
	virtual ~GameObject();

protected:
	void Set_ObjSize(const wstring& wsrKey, const wstring& wsrStateKey = TEXT(""), const int& index = 0);
protected:
	const TEXINFO* m_pTexInfo{ nullptr };
	wstring m_wstrObjectKey;
	INFO m_tInfo;
	FRAME m_tFrame;

protected:
	D3DXVECTOR3 m_ObjSize;
	D3DXVECTOR3 m_ObjHalfSize;
	RECT m_ColliderRect;
};

