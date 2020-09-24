#pragma once

inline void LoadTexture();
inline void Single_Texture(const wstring& wstrFilePath, const wstring& objectKey);
inline void Multi_Texture(const wstring& wstrFilePath, const wstring& objectKey, const wstring& stateKey, const int& count);


inline void BackGroundTex();

inline void LoadTexture()
{
	BackGroundTex();
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


inline void BackGroundTex()
{
	Single_Texture(TEXT("../Resource/Texture/BackGround/Black.png"), TEXT("Black"));
}