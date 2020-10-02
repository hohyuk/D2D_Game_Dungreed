#pragma once

inline void LoadTexture();
inline void Single_Texture(const wstring& wstrFilePath, const wstring& objectKey);
inline void Multi_Texture(const wstring& wstrFilePath, const wstring& objectKey, const wstring& stateKey, const int& count);

inline void LogoTex();
inline void BackGroundTex();
inline void UITex();
inline void PlayerTex();

inline void LoadTexture()
{
	LogoTex();
	BackGroundTex();
	UITex();
	PlayerTex();
}

void Single_Texture(const wstring& wstrFilePath, const wstring& objectKey)
{
	const wstring& RelativePath = TEXT("../Resource/Texture/") + wstrFilePath;
	if (FAILED(TEXTURE_MGR->Insert_Texture(TextureManager::TEX_SINGLE, RelativePath, objectKey)))
		return;
}

void Multi_Texture(const wstring& wstrFilePath, const wstring& objectKey, const wstring& stateKey, const int& count)
{
	const wstring& RelativePath = TEXT("../Resource/Texture/") + wstrFilePath;
	if (FAILED(TEXTURE_MGR->Insert_Texture(TextureManager::TEX_MULTI, RelativePath, objectKey, stateKey, count)))
		return;
}

void LogoTex()
{
	Single_Texture(TEXT("Logo/BackGround.png"), TEXT("BackGround"));
	Single_Texture(TEXT("Logo/BackCloud.png"), TEXT("BackCloud"));
	Single_Texture(TEXT("Logo/FrontCloud.png"), TEXT("FrontCloud"));
	Single_Texture(TEXT("Logo/MainLogo.png"), TEXT("MainLogo"));

	Multi_Texture(TEXT("Logo/Play%d.png"), TEXT("UI"), TEXT("Play"), 2);
	Multi_Texture(TEXT("Logo/Option%d.png"), TEXT("UI"), TEXT("Option"), 2);
	Multi_Texture(TEXT("Logo/Exit%d.png"), TEXT("UI"), TEXT("Exit"), 2);
}

void BackGroundTex()
{
	Single_Texture(TEXT("BackGround/Black.png"), TEXT("Black"));
	Single_Texture(TEXT("BackGround/Sky_Day.png"), TEXT("Sky_Day"));
	Single_Texture(TEXT("BackGround/TownBG_Day.png"), TEXT("TownBG_Day"));
	Single_Texture(TEXT("BackGround/TownLayer_Day.png"), TEXT("TownLayer_Day"));
	Single_Texture(TEXT("BackGround/SubBG.png"), TEXT("SubBG"));
	Single_Texture(TEXT("BackGround/BGLayer.png"), TEXT("BGLayer"));
	Single_Texture(TEXT("BackGround/Snow.png"), TEXT("Snow"));
}

void UITex()
{
	Single_Texture(TEXT("UI/Mouse/BasicCursor.png"), TEXT("BasicCursor"));
	Single_Texture(TEXT("UI/Mouse/ShootingCursor2.png"), TEXT("ShootingCursor"));
}

void PlayerTex()
{
	Multi_Texture(TEXT("Player/Idle/CharIdle%d.png"), TEXT("Player"), TEXT("Idle"), 5);
	Multi_Texture(TEXT("Player/Run/CharRun%d.png"), TEXT("Player"), TEXT("Run"), 8);
	Multi_Texture(TEXT("Player/Jump/CharJump%d.png"), TEXT("Player"), TEXT("Jump"), 1);

	if (FAILED(TEXTURE_MGR->Insert_Texture(TextureManager::TEX_MULTI, TEXT("../Resource/Texture/Player/Idle/CharIdle%d.png"), TEXT("Player"), TEXT("Idle"), 5)))
		return;
	if (FAILED(TEXTURE_MGR->Insert_Texture(TextureManager::TEX_MULTI, TEXT("../Resource/Texture/Player/Run/CharRun%d.png"), TEXT("Player"), TEXT("Run"), 8)))
		return;
	if (FAILED(TEXTURE_MGR->Insert_Texture(TextureManager::TEX_MULTI, TEXT("../Resource/Texture/Player/Jump/CharJump%d.png"), TEXT("Player"), TEXT("Jump"), 1)))
		return;
}