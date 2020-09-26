#pragma once

typedef struct tagTexture
{
	// 이미지 한장을 제어하기 위한 COM Object
	LPDIRECT3DTEXTURE9	pTexture;
	// 이미지의 정보를 담아둘 구조체
	D3DXIMAGE_INFO		tImageInfo;
}TEXINFO;

typedef struct tagInfo
{
	D3DXVECTOR3 vPos{ 0.f,0.f,0.f };		// 위치벡터 
	D3DXVECTOR3 vDir{ 0.f,0.f,0.f };		// 방향벡터 
	D3DXVECTOR3 vSize{ 3.f,3.f,1.f };		// 던그리드 게임의 기본 크기가 3배이다. 
	D3DXVECTOR3 vLook{ 1.f,1.f,1.f };
	D3DXVECTOR3 vCenter{};
	D3DXMATRIX mat;
}INFO;


typedef struct tagFrame
{
	int iFrameStart{};			// 시작 프레임
	int iFrameCurrent{};		// 현재 프레임 장면
	int iFrameEnd{};			// 마지막 프레임
	float fFrameSpeed{};		// 프레임 속도
	float fFixTime{ 0.5f };			// 프레임 넘기는 속도
	wstring StateKey{ TEXT("") };
}FRAME;