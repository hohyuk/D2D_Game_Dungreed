#include "framework.h"
#include "SceneManager.h"
#include "GameObjectManager.h"
#include "LogoScene.h"

IMPLEMENT_SINGLETON(SceneManager)

SceneManager::SceneManager()
	: m_eCurScene{ SCENE::TYPE::END_SCENE },
	m_pScene{ nullptr }
{

}

SceneManager::~SceneManager()
{
	Release();
}

HRESULT SceneManager::Change_Scene(SCENE::TYPE eNextScene)
{
	if (m_eCurScene != eNextScene)
	{
		Safe_Delete(m_pScene);
		switch (eNextScene)
		{
		case SCENE::TYPE::LOGO_SCENE:
			m_pScene = new LogoScene;
			break;
		case SCENE::TYPE::TOWN_SCENE:
			m_pScene = new LogoScene;
			break;
		}

		OBJ_MGR->ChangeScene();
		if (FAILED(m_pScene->Ready()))	return E_FAIL;
		m_eCurScene = eNextScene;
		m_iAlpha = 255;
		isFadeIn_Activation = true;
	}
	return S_OK;
}

void SceneManager::Update()
{
	if (isFadeIn_Activation && m_iAlpha < 250) return;			// FadeIn할때 한번 정도만 그려준다.
	m_pScene->Update();
}

void SceneManager::LateUpdate()
{
	if (isFadeIn_Activation) return;
	m_pScene->LateUpdate();
}

void SceneManager::Render()
{
	m_pScene->Render();

	if (!IsActivateScene())
		Render_FadeIn();
}

void SceneManager::Release()
{
	m_pScene->Release();
	Safe_Delete(m_pScene);
}

bool SceneManager::IsActivateScene(const int & speed)
{
	if (!isFadeIn_Activation) return true;
	if (5 >= (m_iAlpha -= speed))
	{
		isFadeIn_Activation = false;
		m_iAlpha = 0;
	}
	return false;
}

void SceneManager::Render_FadeIn()
{
	const TEXINFO* pTexInfo = TextureManager::Get_Instance()->Get_TexInfo(TEXT("Black"));
	if (pTexInfo == nullptr)
		return;
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	GD_MGR->Get_Sprite()->SetTransform(&matWorld);
	GD_MGR->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_ARGB(m_iAlpha, 255, 255, 255));
}
