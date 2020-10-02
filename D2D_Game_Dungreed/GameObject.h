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
	void RepeatAnim();
protected:
	const TEXINFO* m_pTexInfo{ nullptr };
	wstring m_wstrObjectKey;
	INFO m_tInfo;
	FRAME m_tFrame;
	D3DXVECTOR2 m_tTexOffSet{ 0.f,0.f };

protected:
	D3DXVECTOR3 m_ObjSize;
	D3DXVECTOR3 m_ObjHalfSize;
	RECT m_ColliderRect;

protected:
	COLOR m_tColor;
};

