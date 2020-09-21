#include "framework.h"
#include "MultiTexture.h"

HRESULT MultiTexture::Insert_Texture(const wstring & wstrFilePath, const wstring & wstrStateKey, const DWORD & rCount)
{
	// wstrStateKey �ǹ� - �� ) Player ���� �ȿ� Attack Dash Walk ��  ���� ������ �����ϸ� �� �� �ϳ��� ���� �ȿ� �������� �̹���
	// rCount �ǹ� - ��) ���� �̹����� ���� ������ �ǹ�
	// ��) Attack1,Attack2,Attack3...Attackn -> Attack�� StateKey�̸�  %d�� Count �� �ǹ��� �� �ִ�.
	auto iter_find = m_mapMultiTexture.find(wstrStateKey);
	TCHAR szFilePath[MAX_PATH] = TEXT("");

	// ã�� ������ ��� - ���ο� StateKey��� �Ǵ�
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

			// StateKey�� ��´�.
			m_mapMultiTexture[wstrStateKey].emplace_back(pTexInfo);
		}
	}
	return S_OK;
}

const TEXINFO * MultiTexture::Get_Texture(const wstring & wstrStateKey, const DWORD & rIndex)
{
	auto iter_find = m_mapMultiTexture.find(wstrStateKey);

	// ã�� ������ ��� 
	if (iter_find == m_mapMultiTexture.end())
		return nullptr;

	return iter_find->second[rIndex];		// == m_mapMultiTexture[wstrStateKey][rIndex];
}

void MultiTexture::Release_Texture()
{
	// Map�� �ִ� Value�� Vector�� �����ֱ� ����.
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
