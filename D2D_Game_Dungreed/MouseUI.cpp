#include "framework.h"
#include "MouseUI.h"

D3DXVECTOR3 MouseUI::MousePoint()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);

	// ȭ���� ����Ǿ����� �����ش�. ���콺 ��ġ��
	RECT rcView;
	GetClientRect(g_hWND, &rcView);
	float fsizeX = WINCX / static_cast<float>(rcView.right - rcView.left);
	float fsizeY = WINCY / static_cast<float>(rcView.bottom - rcView.top);

	m_tInfo.vPos = { static_cast<float>(pt.x) * fsizeX, static_cast<float>(pt.y) * fsizeY, 0.f };

	return m_tInfo.vPos;
}

HRESULT MouseUI::Ready()
{
	ShowCursor(false);
	if (SCENE::TYPE::LOGO_SCENE == m_eSceneType)
		m_wstrObjectKey = TEXT("BasicCursor");
	else
		m_wstrObjectKey = TEXT("ShootingCursor");

	return S_OK;
}

GameObject * MouseUI::Create(SCENE::TYPE eScene)
{
	GameObject* pInstance = new MouseUI;
	dynamic_cast<MouseUI*>(pInstance)->m_eSceneType = eScene;

	if (FAILED(pInstance->Ready()))
		return nullptr;

	return pInstance;
}

MouseUI::MouseUI()
{
}

MouseUI::~MouseUI()
{
}
