#pragma once

inline void LoadTexture();
inline void Single_Texture(const wstring& wstrFilePath, const wstring& objectKey);
inline void Multi_Texture(const wstring& wstrFilePath, const wstring& objectKey, const wstring& stateKey, const int& count);

inline void LogoTex();
inline void BackGroundTex();
inline void UITex();


inline void LoadTexture()
{
	LogoTex();
	BackGroundTex();
	UITex();
}

inline void Single_Texture(const wstring& wstrFilePath, const wstring& objectKey)
{
	const wstring& RelativePath = TEXT("../Resource/Texture/") + wstrFilePath;
	if (FAILED(TEXTURE_MGR->Insert_Texture(TextureManager::TEX_SINGLE, RelativePath, objectKey)))
		return;
}

inline void Multi_Texture(const wstring& wstrFilePath, const wstring& objectKey, const wstring& stateKey, const int& count)
{
	const wstring& RelativePath = TEXT("../Resource/Texture/") + wstrFilePath;
	if (FAILED(TEXTURE_MGR->Insert_Texture(TextureManager::TEX_MULTI, RelativePath, objectKey, stateKey, count)))
		return;
}

inline void LogoTex()
{
	Single_Texture(TEXT("Logo/BackGround.png"), TEXT("BackGround"));
	Single_Texture(TEXT("Logo/BackCloud.png"), TEXT("BackCloud"));
	Single_Texture(TEXT("Logo/FrontCloud.png"), TEXT("FrontCloud"));
	Single_Texture(TEXT("Logo/MainLogo.png"), TEXT("MainLogo"));

	Multi_Texture(TEXT("Logo/Play%d.png"), TEXT("UI"), TEXT("Play"), 2);
	Multi_Texture(TEXT("Logo/Option%d.png"), TEXT("UI"), TEXT("Option"), 2);
	Multi_Texture(TEXT("Logo/Exit%d.png"), TEXT("UI"), TEXT("Exit"), 2);
}

inline void BackGroundTex()
{
	Single_Texture(TEXT("BackGround/Black.png"), TEXT("Black"));
}

inline void UITex()
{
	Single_Texture(TEXT("UI/Mouse/BasicCursor.png"), TEXT("BasicCursor"));
	Single_Texture(TEXT("UI/Mouse/ShootingCursor2.png"), TEXT("ShootingCursor"));
}