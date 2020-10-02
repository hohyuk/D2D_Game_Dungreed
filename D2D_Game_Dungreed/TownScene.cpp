#include "framework.h"
#include "TownScene.h"
#include "MouseUI.h"
#include "Player.h"
HRESULT TownScene::Ready()
{
	SOUND_MGR->StopAll();
	//SOUND_MGR->PlayBGM((TCHAR*)TEXT("Town.wav"));

	OBJ_MGR->Add_GameObject(OBJECT::TYPE::MOUSE_OBJ, MouseUI::Create(SCENE::TYPE::TOWN_SCENE));

	OBJ_MGR->Add_GameObject(OBJECT::TYPE::PLAYER_OBJ, Player::Create(113.f, 732.f));
	return S_OK;
}

void TownScene::Update()
{
	OBJ_MGR->Update();
}

void TownScene::Render()
{
	D3DXMATRIX matScale, matTrans, matSky, matBG, matLayer;
	float size = 4.0f;

	D3DXMatrixScaling(&matScale, size, size, 0.f);
	D3DXMatrixTranslation(&matTrans, 0.f, 0.f, 0.f);
	matSky = matScale * matTrans;
	RenderBackGround(TEXT("Sky_Day"), matSky);

	D3DXMatrixTranslation(&matTrans, 0.f, 50.f, 0.f);
	matBG = matTrans * matSky;
	RenderBackGround(TEXT("TownBG_Day"), matBG);

	D3DXMatrixTranslation(&matTrans, 0.f, 70.f, 0.f);
	matLayer = matTrans * matBG;
	RenderBackGround(TEXT("TownLayer_Day"), matLayer);

	OBJ_MGR->Render();
}

TownScene::TownScene()
{
}

TownScene::~TownScene()
{
	Release();
}

void TownScene::RenderBackGround(const wstring & wsrObject, const D3DXMATRIX & mat)
{
	const TEXINFO* pTexInfo = TextureManager::Get_Instance()->Get_TexInfo(wsrObject);
	if (pTexInfo == nullptr)
		return;
	GD_MGR->Get_Sprite()->SetTransform(&mat);
	GD_MGR->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}
