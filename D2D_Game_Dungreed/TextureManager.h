#pragma once
class Texture;

class TextureManager final
{
	DECLARE_SINGLETON(TextureManager)

private:
	explicit TextureManager();
	~TextureManager();
public:
	enum TEX_ID { TEX_SINGLE, TEX_MULTI, TEXEND };
public:
	const TEXINFO* Get_TexInfo(const wstring& wstrObjectKey, const wstring& wstrStateKey = TEXT(""), const DWORD& dwImgIndex = 0);
	HRESULT Insert_Texture(const TEX_ID& eTexID, const wstring& wstrFilePath, const wstring& wstrObjectKey, const wstring& wstrStateKey = TEXT(""), const  DWORD& dwImgIndex = 0);
	void Release_TextureManager();
private:
	map<wstring, Texture*> m_mapTexture;		// ObjectKey를 담을 것
};

