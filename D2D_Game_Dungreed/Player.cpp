#include "framework.h"
#include "Player.h"

HRESULT Player::Ready()
{
	m_wstrObjectKey = TEXT("Player");
	m_tFrame.StateKey = TEXT("Idle");
	m_tFrame.iFrameStart = m_tFrame.iFrameCurrent = 0;
	m_tFrame.iFrameEnd = 5;
	m_tFrame.fFixTime = 0.1f;
	return S_OK;
}

int Player::Update()
{
	GameObject::RepeatAnim();
	return OBJ_NOEVENT;
}

GameObject * Player::Create(float posX, float posY)
{
	GameObject* pInstance = new Player;
	dynamic_cast<Player*>(pInstance)->m_tInfo.vPos = D3DXVECTOR3(posX, posY, 0.f);
	if (FAILED(pInstance->Ready()))
		return nullptr;

	return pInstance;
}

Player::Player()
{
}

Player::~Player()
{
}
