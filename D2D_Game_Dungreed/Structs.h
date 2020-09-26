#pragma once

typedef struct tagTexture
{
	// �̹��� ������ �����ϱ� ���� COM Object
	LPDIRECT3DTEXTURE9	pTexture;
	// �̹����� ������ ��Ƶ� ����ü
	D3DXIMAGE_INFO		tImageInfo;
}TEXINFO;

typedef struct tagInfo
{
	D3DXVECTOR3 vPos{ 0.f,0.f,0.f };		// ��ġ���� 
	D3DXVECTOR3 vDir{ 0.f,0.f,0.f };		// ���⺤�� 
	D3DXVECTOR3 vSize{ 3.f,3.f,1.f };		// ���׸��� ������ �⺻ ũ�Ⱑ 3���̴�. 
	D3DXVECTOR3 vLook{ 1.f,1.f,1.f };
	D3DXVECTOR3 vCenter{};
	D3DXMATRIX mat;
}INFO;


typedef struct tagFrame
{
	int iFrameStart{};			// ���� ������
	int iFrameCurrent{};		// ���� ������ ���
	int iFrameEnd{};			// ������ ������
	float fFrameSpeed{};		// ������ �ӵ�
	float fFixTime{ 0.5f };			// ������ �ѱ�� �ӵ�
	wstring StateKey{ TEXT("") };
}FRAME;