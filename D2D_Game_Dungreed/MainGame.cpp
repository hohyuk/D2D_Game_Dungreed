#include "framework.h"
#include "MainGame.h"
#include "TextureLoad.h"

void MainGame::Ready()
{
	FPS_MGR->Ready_FixFPS(60.f);
	TIME_MGR->Ready();

	if (FAILED(GD_MGR->Ready_GraphicDevice())) return;

	LoadTexture();
}

void MainGame::Update()
{
	TIME_MGR->Update();
}

void MainGame::LateUpdate()
{
}

void MainGame::Render()
{
	GD_MGR->Render_Begin();

	FPS_MGR->Render();
	GD_MGR->Render_End();
}

void MainGame::Release()
{
	TextureManager::Destroy_Instance();
	TimeManager::Destroy_Instance();
	GraphicDevice::Destroy_Instance();
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}
