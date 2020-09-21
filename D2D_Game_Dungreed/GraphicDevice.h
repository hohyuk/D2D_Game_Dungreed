#pragma once
class GraphicDevice final
{
	DECLARE_SINGLETON(GraphicDevice)
private:
	explicit GraphicDevice();
	~GraphicDevice();
public:
	LPDIRECT3DDEVICE9 Get_Device() { return m_pDevice; }
	LPD3DXSPRITE Get_Sprite() { return m_pSprite; }
	LPD3DXFONT Get_Font() { return m_pFont; }

public:
	HRESULT Ready_GraphicDevice();

	void Render_Begin();
	void Render_End(HWND hWnd = nullptr);			// ���� â�� �������� �Ű������� �־���.

	void Release_GraphicDevice();

private:
	// ��ġ(����̽�)�� �ٷ� ��ü
	LPDIRECT3DDEVICE9 m_pDevice;
	// ��ġ�� ���� ���� ���� �� ��ġ�� ������ ��ü�� ������ COM��ü
	LPDIRECT3D9 m_pSDK;
	// LPD3DXSPRITE - DirectX���� 2D�̹����� �׸��� ���� Interfaces�̴�. (3D���� �ַ� UI)
	LPD3DXSPRITE m_pSprite;
	LPD3DXFONT m_pFont;
};


/*
C - Component
O - Object
M - Model
����ũ�μ���Ʈ�� ������ ����Ʈ���� ���� ��ҵ��� ���� ���α׷� ���� �������̽��̴�.
COM�� �̿��� ���ߵ� ���α׷����� ���μ����� ��Ű� ���� ������Ʈ ������ �����ϴ�.
����� �� - �׳� �ϳ� �ϳ� ��ǰó�� �����Ѵٶ� ����
*/