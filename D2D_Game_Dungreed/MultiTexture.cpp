#include "framework.h"
#include "MultiTexture.h"

HRESULT MultiTexture::Insert_Texture(const wstring & wstrFilePath, const wstring & wstrStateKey, const DWORD & rCount)
{
	// wstrStateKey 의미 - 예 ) Player 폴더 안에 Attack Dash Walk 등  여러 파일이 존재하며 그 중 하나의 파일 안에 여러장의 이미지
	// rCount 의미 - 예) 여러 이미지들 중의 순서를 의미
	// 예) Attack1,Attack2,Attack3...Attackn -> Attack은 StateKey이며  %d은 Count 를 의미할 수 있다.
	auto iter_find = m_mapMultiTexture.find(wstrStateKey);
	TCHAR szFilePath[MAX_PATH] = TEXT("");

	// 찾지 못했을 경우 - 새로운 StateKey라고 판단
	if (m_mapMultiTexture.end() == iter_find)
	{
		for (DWORD i = 0; i < rCount; ++i)
		{
			wsprintf(szFilePath, wstrFilePath.c_str(), i);
			TEXINFO* pTexInfo = new TEXINFO;
			ZeroMemory(pTexInfo, sizeof(TEXINFO));
			if (FAILED(D3DXGetImageInfoFromFile(szFilePath, &pTexInfo->tImageInfo)))
			{
				Safe_Delete(pTexInfo);
				ERR_MSG(TEXT("Failed MultiTexture ImageInfo"));
				return E_FAIL;
			}

			if (FAILED(D3DXCreateTextureFromFileEx(
				GD_MGR->Get_Device(),
				szFilePath,
				pTexInfo->tImageInfo.Width,
				pTexInfo->tImageInfo.Height,
				pTexInfo->tImageInfo.MipLevels,
				0,
				pTexInfo->tImageInfo.Format,
				D3DPOOL_MANAGED,
				D3DX_DEFAULT,
				D3DX_DEFAULT,
				0, nullptr, nullptr,
				&pTexInfo->pTexture)))
			{
				wstring wstrErrMessage = wstrFilePath + TEXT("Create Texture Failed");
				ERR_MSG(wstrErrMessage.c_str());
				Safe_Delete(pTexInfo);
				return E_FAIL;
			}

			// StateKey에 담는다.
			m_mapMultiTexture[wstrStateKey].emplace_back(pTexInfo);
		}
	}
	return S_OK;
}

const TEXINFO * MultiTexture::Get_Texture(const wstring & wstrStateKey, const DWORD & rIndex)
{
	auto iter_find = m_mapMultiTexture.find(wstrStateKey);

	// 찾지 못했을 경우 
	if (iter_find == m_mapMultiTexture.end())
		return nullptr;

	return iter_find->second[rIndex];		// == m_mapMultiTexture[wstrStateKey][rIndex];
}

void MultiTexture::Release_Texture()
{
	// Map에 있는 Value인 Vector를 지워주기 위함.
	for (auto& rPair : m_mapMultiTexture)
	{
		for (auto& pTexInfo : rPair.second)
			Safe_Delete(pTexInfo);

		rPair.second.clear();
		rPair.second.shrink_to_fit();
	}
}

MultiTexture::MultiTexture()
{
}

MultiTexture::~MultiTexture()
{
	Release_Texture();
}
