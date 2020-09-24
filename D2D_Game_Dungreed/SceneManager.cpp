#include "framework.h"
#include "SceneManager.h"

IMPLEMENT_SINGLETON(SceneManager)

SceneManager::SceneManager()
	: m_eCurScene{ SCENE::TYPE::END_SCENE },
	m_eNextScene{ SCENE::TYPE::END_SCENE },
	m_pScene{ nullptr }
{

}

SceneManager::~SceneManager()
{
	Release();
}

HRESULT SceneManager::Change_Scene(SCENE::TYPE eNextScene)
{
	return S_OK;
}

void SceneManager::Update()
{
	
}

void SceneManager::LateUpdate()
{
}

void SceneManager::Render()
{
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
