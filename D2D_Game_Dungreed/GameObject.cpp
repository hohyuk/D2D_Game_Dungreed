#include "framework.h"
#include "GameObject.h"

void GameObject::LateUpdate()
{
	D3DX_ST(m_tInfo);
}

void GameObject::Render()
{
	m_pTexInfo = TEXTURE_MGR->Get_TexInfo(m_wstrObjectKey, m_tFrame.StateKey, DWORD(m_tFrame.iFrameCurrent));
	if (m_pTexInfo == nullptr)
		return;
	m_tInfo.vCenter = { float(m_pTexInfo->tImageInfo.Width >> 1), float(m_pTexInfo->tImageInfo.Height >> 1) , 0.f };
	GD_MGR->Get_Sprite()->SetTransform(&m_tInfo.mat);
	GD_MGR->Get_Sprite()->Draw(m_pTexInfo->pTexture, nullptr, &m_tInfo.vCenter, nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void GameObject::Release()
{
}

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Set_ObjSize(const wstring & wsrKey, const wstring & wsrStateKey, const int & index)
{
	const TEXINFO* pTexInfo = TEXTURE_MGR->Get_TexInfo(wsrKey, wsrStateKey, index);
	if (pTexInfo == nullptr)
		return;
	m_ObjSize = { float(pTexInfo->tImageInfo.Width) * m_tInfo.vSize.x, float(pTexInfo->tImageInfo.Height) * m_tInfo.vSize.y, 0.f };
	m_ObjHalfSize = m_ObjSize / 2.f;

	MakeRect(m_ColliderRect, m_tInfo.vPos, m_ObjHalfSize);
}
