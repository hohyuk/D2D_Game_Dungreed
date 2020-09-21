#include "framework.h"
#include "SingleTexture.h"

HRESULT SingleTexture::Insert_Texture(const wstring & wstrFilePath, const wstring & wstrStateKey, const DWORD & rCount)
{
	m_pTexInfo = new TEXINFO;
	ZeroMemory(m_pTexInfo, sizeof(TEXINFO));

	// D3DXGetImageInfoFromFile - �־��� �̹��� ���Ͽ� ���� ������ �˻��Ѵ�.
	// ù��° �Ű� ���� - ������ �˻� �� �̹����� ���� �̸�
	// �ι�° �Ű� ���� - �ҽ� ������ ������ �������� ä���� D3DXIMAGE_INFO ���� �� ���� ������ .
	if (FAILED(D3DXGetImageInfoFromFile(wstrFilePath.c_str(), &m_pTexInfo->tImageInfo)))
	{
		ERR_MSG(TEXT("Failed SingleTexture ImageInfo"));
		return E_FAIL;
	}

	// D3DXCreateTextureFromFileEx - ���Ͽ��� �ؽ�ó�� �����. �̰��� D3DXCreateTextureFromFile ���� ��� ����̴�.
	if (FAILED(D3DXCreateTextureFromFileEx(
		GD_MGR->Get_Device(),
		wstrFilePath.c_str(),
		m_pTexInfo->tImageInfo.Width,
		m_pTexInfo->tImageInfo.Height,
		m_pTexInfo->tImageInfo.MipLevels,
		0,
		m_pTexInfo->tImageInfo.Format,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0, nullptr, nullptr,
		&m_pTexInfo->pTexture)))
	{
		wstring wstrErrMessage = wstrFilePath + TEXT("Create Texture Failed.");
		ERR_MSG(wstrErrMessage.c_str());
		return E_FAIL;
	}
	return S_OK;
}

const TEXINFO * SingleTexture::Get_Texture(const wstring & wstrStateKey, const DWORD & rIndex)
{
	return m_pTexInfo;
}

void SingleTexture::Release_Texture()
{
	Safe_Delete(m_pTexInfo);
}

SingleTexture::SingleTexture()
{
}

SingleTexture::~SingleTexture()
{
	Release_Texture();
}
