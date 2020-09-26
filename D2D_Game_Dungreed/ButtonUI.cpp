#include "framework.h"
#include "ButtonUI.h"

HRESULT ButtonUI::Ready()
{
	m_wstrObjectKey = TEXT("UI");
	m_tFrame.iFrameCurrent = 0;
	float OffSet = WINCY / 2.f + 25.f;
	switch (m_eButtonUI)
	{
	case CLASS::PLAY_BUTTON:
		m_tFrame.StateKey = TEXT("Play");
		m_tInfo.vPos = { WINCX / 2.f, OffSet, 0.f };
		break;
	case CLASS::OPTION_BUTTON:
		m_tFrame.StateKey = TEXT("Option");
		m_tInfo.vPos = { WINCX / 2.f, OffSet + 50.f,0.f };
		break;
	case CLASS::EXIT_BUTTON:
		m_tFrame.StateKey = TEXT("Exit");
		m_tInfo.vPos = { WINCX / 2.f, OffSet + 100.f,0.f };
		break;
	case CLASS::BUTTON_END:
		break;
	default:
		break;
	}

	GameObject::Set_ObjSize(m_wstrObjectKey, m_tFrame.StateKey);
	D3DX_ST(m_tInfo);

	return S_OK;
}

void ButtonUI::LateUpdate()
{
	bool isButton = IsPointInRect(MOUSE_POINT, m_ColliderRect);
	m_tFrame.iFrameCurrent = isButton ? 1 : 0;

	if (isButton && KEY_MGR->DOWN(VK_LBUTTON))
	{
		switch (m_eButtonUI)
		{
		case CLASS::PLAY_BUTTON:
			SCENE_MGR->Change_Scene(SCENE::TYPE::TOWN_SCENE);
			break;
		case CLASS::OPTION_BUTTON:
			break;
		case CLASS::EXIT_BUTTON:
			g_msg.message = WM_QUIT;
			break;
		case CLASS::BUTTON_END:
			break;
		default:
			break;
		}
	}
}

GameObject * ButtonUI::Create(CLASS::BUTTON_UI eButtonUI)
{
	GameObject* pInstance = new ButtonUI;
	dynamic_cast<ButtonUI*>(pInstance)->m_eButtonUI = eButtonUI;

	if (FAILED(pInstance->Ready()))
		return nullptr;

	return pInstance;
}

ButtonUI::ButtonUI()
{
}

ButtonUI::~ButtonUI()
{
}
