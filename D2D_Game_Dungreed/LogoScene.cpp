#include "framework.h"
#include "LogoScene.h"
#include "ButtonUI.h"
#include "MouseUI.h"
HRESULT LogoScene::Ready()
{
	SOUND_MGR->StopAll();
	SOUND_MGR->PlayBGM((TCHAR*)TEXT("Title.wav"));

	m_Size = 4.27f;

	OBJ_MGR->Add_GameObject(OBJECT::TYPE::MOUSE_OBJ, MouseUI::Create(SCENE::TYPE::LOGO_SCENE));

	OBJ_MGR->Add_GameObject(OBJECT::TYPE::UI_OBJ, ButtonUI::Create(CLASS::BUTTON_UI::PLAY_BUTTON));
	OBJ_MGR->Add_GameObject(OBJECT::TYPE::UI_OBJ, ButtonUI::Create(CLASS::BUTTON_UI::OPTION_BUTTON));
	OBJ_MGR->Add_GameObject(OBJECT::TYPE::UI_OBJ, ButtonUI::Create(CLASS::BUTTON_UI::EXIT_BUTTON));
	return S_OK;
}

void LogoScene::Update()
{
	OBJ_MGR->LateUpdate();
	m_fBackMove = WrapFloat(0.f, m_fBackMove + (DELTA_TIME * 50.f), m_BackGroundSize);
	m_fFrontMove = WrapFloat(0.f, m_fFrontMove + (DELTA_TIME * 100.f), m_BackGroundSize);
}

void LogoScene::LateUpdate()
{
	OBJ_MGR->LateUpdate();
}

void LogoScene::Render()
{
	Render_BackGround();
	Render_Cloud();
	Render_MainLogo();

	OBJ_MGR->Render();
}

void LogoScene::Release()
{
	OBJ_MGR->Release();
}

LogoScene::LogoScene()
{
}

LogoScene::~LogoScene()
{
	Release();
}

void LogoScene::Render_BackGround()
{
	const TEXINFO* pTexInfo = TextureManager::Get_Instance()->Get_TexInfo(TEXT("BackGround"));
	if (pTexInfo == nullptr)
		return;

	D3DXMATRIX  matTrans;
	D3DXMatrixIdentity(&matTrans);
	GD_MGR->Get_Sprite()->SetTransform(&matTrans);
	GD_MGR->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void LogoScene::Render_Cloud()
{
	Render_MoveCloud(TEXT("BackCloud"), m_fBackMove);
	
	Render_MoveCloud(TEXT("FrontCloud"), m_fFrontMove);
}


void LogoScene::Render_MainLogo()
{
	const TEXINFO* pTexInfo = TextureManager::Get_Instance()->Get_TexInfo(TEXT("MainLogo"));
	if (pTexInfo == nullptr)
		return;
	D3DXVECTOR3 vCenter = { float(pTexInfo->tImageInfo.Width >> 1), float(pTexInfo->tImageInfo.Height >> 1), 0.f };
	D3DXMATRIX matScale, matTrans, matWorld;

	D3DXMatrixScaling(&matScale, 3.f, 3.f, 0.f);
	D3DXMatrixTranslation(&matTrans, WINCX >> 1, (WINCY >> 1) - 150.f, 0.f);
	matWorld = matScale * matTrans;
	GD_MGR->Get_Sprite()->SetTransform(&matWorld);
	GD_MGR->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &vCenter, nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void LogoScene::Render_MoveCloud(const wstring & objectKey, float & move)
{
	D3DXMATRIX matScale, matTrans, matWorld;
	const TEXINFO* pTexInfo = TextureManager::Get_Instance()->Get_TexInfo(objectKey);
	if (pTexInfo == nullptr)
		return;

	D3DXMatrixScaling(&matScale, m_Size, m_Size, 0.f);
	D3DXMatrixTranslation(&matTrans, -move, 0.f, 0.f);
	matWorld = matScale * matTrans;
	GD_MGR->Get_Sprite()->SetTransform(&matWorld);
	GD_MGR->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	if (move >= m_BackGroundSize - WINCX)
	{
		D3DXMatrixScaling(&matScale, m_Size, m_Size, 0.f);
		D3DXMatrixTranslation(&matTrans, -(move - m_BackGroundSize), 0.f, 0.f);
		matWorld = matScale * matTrans;
		GD_MGR->Get_Sprite()->SetTransform(&matWorld);
		GD_MGR->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
}