#include "framework.h"
#include "SingleTexture.h"

HRESULT SingleTexture::Insert_Texture(const wstring & wstrFilePath, const wstring & wstrStateKey, const DWORD & rCount)
{
	m_pTexInfo = new TEXINFO;
	ZeroMemory(m_pTexInfo, sizeof(TEXINFO));

	// D3DXGetImageInfoFromFile - 주어진 이미지 파일에 대한 정보를 검색한다.
	// 첫번째 매개 변수 - 정보를 검색 할 이미지의 파일 이름
	// 두번째 매개 변수 - 소스 파일의 데이터 설명으로 채워질 D3DXIMAGE_INFO 구조 에 대한 포인터 .
	if (FAILED(D3DXGetImageInfoFromFile(wstrFilePath.c_str(), &m_pTexInfo->tImageInfo)))
	{
		ERR_MSG(TEXT("Failed SingleTexture ImageInfo"));
		return E_FAIL;
	}

	// D3DXCreateTextureFromFileEx - 파일에서 텍스처를 만든다. 이것은 D3DXCreateTextureFromFile 보다 고급 기능이다.
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
