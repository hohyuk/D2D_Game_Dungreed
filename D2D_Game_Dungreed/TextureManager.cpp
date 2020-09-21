#include "framework.h"
#include "TextureManager.h"

#include "SingleTexture.h"
#include "MultiTexture.h"

IMPLEMENT_SINGLETON(TextureManager)

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	Release_TextureManager();
}

const TEXINFO * TextureManager::Get_TexInfo(const wstring & wstrObjectKey, const wstring & wstrStateKey, const DWORD & dwImgIndex)
{
	map<wstring, Texture*>::iterator iter_find = m_mapTexture.find(wstrObjectKey);

	// ObjectKey를 찾지 못했을 때
	if (m_mapTexture.end() == iter_find)
		return nullptr;
	return iter_find->second->Get_Texture(wstrStateKey, dwImgIndex);		// 만약 SingleTexture이면 디폴트 매개변수값으로 들어간다.
}

HRESULT TextureManager::Insert_Texture(const TEX_ID & eTexID, const wstring & wstrFilePath, const wstring & wstrObjectKey, const wstring & wstrStateKey, const DWORD & dwImgIndex)
{
	auto iter_find = m_mapTexture.find(wstrObjectKey);		// == map<wstring, Texture*>::iterator iter_find = m_mapTexture.find(wstrObjectKey);

	if (iter_find == m_mapTexture.end())
	{
		Texture* pTexture = nullptr;

		switch (eTexID)
		{
		case TextureManager::TEX_SINGLE:
			pTexture = new SingleTexture;
			break;
		case TextureManager::TEX_MULTI:
			pTexture = new MultiTexture;
			break;
		default:
			break;
		}

		if (FAILED(pTexture->Insert_Texture(wstrFilePath, wstrStateKey, dwImgIndex)))
		{
			ERR_MSG(TEXT("Texture Creating Failed"));
			return E_FAIL;
		}
		m_mapTexture.emplace(wstrObjectKey, pTexture);
	}
	else if (TextureManager::TEX_MULTI == eTexID)
	{
		// 이 조건은 MultiTexture에만 적용되며 ObjectKey가 존재하여 StateKey를 저장할때 넘어 온다.
		if (FAILED(m_mapTexture[wstrObjectKey]->Insert_Texture(wstrFilePath, wstrStateKey, dwImgIndex)))
		{
			ERR_MSG(TEXT("MultiTexture Creating Failed"));
			return E_FAIL;
		}
	}
	return S_OK;
}

void TextureManager::Release_TextureManager()
{
	for (auto& rPair : m_mapTexture)
		Safe_Delete(rPair.second);

	m_mapTexture.clear();
}
