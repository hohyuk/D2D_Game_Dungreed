#include "framework.h"
#include "GraphicDevice.h"

IMPLEMENT_SINGLETON(GraphicDevice)

GraphicDevice::GraphicDevice()
{
}

GraphicDevice::~GraphicDevice()
{
	Release_GraphicDevice();
}

HRESULT GraphicDevice::Ready_GraphicDevice()
{
	// 렌더링 과정.
	// 1. 후면 버퍼를 비운다.
	// 2. 그린다.
	// 3. 후면버퍼와 전면 버퍼를 교체한다.
	// 4. 1~3 반복

	// 장치 초기화 과정
	// 1. SDK를 먼저 만든다.
	// 2. 장치의 SDK지원 수준을 조사한다.
	// 3. 지원 수준에 맞는 COM Object (실질적으로 장치를 제어할 객체)를 생성.

	D3DCAPS9 DeviceCaps;
	ZeroMemory(&DeviceCaps, sizeof(D3DCAPS9));		// 반드시 구조체를 지운다.
	// 장치의수준을 조사할 COM객체를 생성
	m_pSDK = Direct3DCreate9(D3D_SDK_VERSION);

	if (FAILED(m_pSDK->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &DeviceCaps)))
	{
		ERR_MSG(TEXT("Get DeviceCaps Failed"));
		return E_FAIL;
	}

	DWORD VertexProcessing{};
	// 셰이더를 지원할때 하드웨어로 지원 할것인가 소프트웨어로 지원할 것인가.
	// 보통 D3DCREATE_HARDWARE_VERTEXPROCESSING을 사용한다. 
	// 만약 SOFTWARE가 된다면 컴퓨터가 안좋은것이다...
	if (DeviceCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		VertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		VertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;


	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	// Back Buffer의 가로 세로 크기
	d3dpp.BackBufferWidth = WINCX;
	d3dpp.BackBufferHeight = WINCY;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;

	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = g_hWND;

	d3dpp.Windowed = TRUE;		// TRUE - 창모드 FALSE - 전체모드 (주의 - MFC는 창모드만 가능하다 전체 모드는 에러난다.)
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;

	// 조사하고 세팅한 데이터를 가지고 이제 장치를 제어할 COM객체를 생성
	if (FAILED(m_pSDK->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWND, VertexProcessing, &d3dpp, &m_pDevice)))
	{
		ERR_MSG(TEXT("Failed Creating Device"));
		return E_FAIL;
	}

	if (FAILED(D3DXCreateSprite(m_pDevice, &m_pSprite)))
	{
		ERR_MSG(TEXT("Failed Creating Sprite"));
		return E_FAIL;
	}

	// Font Create
	D3DXFONT_DESC tFontInfo;
	ZeroMemory(&tFontInfo, sizeof(D3DXFONT_DESC));
	tFontInfo.Height = 15;
	tFontInfo.Width = 10;
	tFontInfo.Weight = FW_EXTRABOLD;
	tFontInfo.CharSet = HANGUL_CHARSET;
	lstrcpy(tFontInfo.FaceName, TEXT("맑은 고딕"));
	if (FAILED(D3DXCreateFontIndirect(m_pDevice, &tFontInfo, &m_pFont)))
	{
		ERR_MSG(TEXT("Failed Creating Font"));
		return E_FAIL;
	}
	return S_OK;
}

void GraphicDevice::Render_Begin()
{
	m_pDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, D3DCOLOR_ARGB(255, 0, 0, 255), 0.f, 0);
	m_pDevice->BeginScene();
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void GraphicDevice::Render_End(HWND hWnd /*= nullptr*/)
{
	m_pSprite->End();
	m_pDevice->EndScene();
	m_pDevice->Present(nullptr, nullptr, hWnd, nullptr);		// 페이지 전환을 수행하는 함수
}

void GraphicDevice::Release_GraphicDevice()
{
	Safe_Release(m_pFont);
	Safe_Release(m_pSprite);
	Safe_Release(m_pDevice);
	Safe_Release(m_pSDK);
}
