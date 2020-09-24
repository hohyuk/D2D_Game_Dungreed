#include "framework.h"
#include "LogoScene.h"

HRESULT LogoScene::Ready()
{
	return E_NOTIMPL;
}

void LogoScene::Update()
{
}

void LogoScene::LateUpdate()
{
}

void LogoScene::Render()
{
}

void LogoScene::Release()
{
}

LogoScene::LogoScene()
{
}

LogoScene::~LogoScene()
{
	Release();
}
