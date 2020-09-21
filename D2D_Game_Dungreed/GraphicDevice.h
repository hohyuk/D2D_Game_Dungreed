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
	void Render_End(HWND hWnd = nullptr);			// 여러 창을 쓰기위해 매개변수를 넣었다.

	void Release_GraphicDevice();

private:
	// 장치(디바이스)를 다룰 객체
	LPDIRECT3DDEVICE9 m_pDevice;
	// 장치의 지원 수준 조사 및 장치를 제어할 객체를 생성할 COM객체
	LPDIRECT3D9 m_pSDK;
	// LPD3DXSPRITE - DirectX에서 2D이미지를 그리기 위한 Interfaces이다. (3D에서 주로 UI)
	LPD3DXSPRITE m_pSprite;
	LPD3DXFONT m_pFont;
};


/*
C - Component
O - Object
M - Model
마이크로소프트가 개발한 소프트웨어 구성 요소들의 응용 프로그램 이진 인터페이스이다.
COM을 이용해 개발된 프로그램들은 프로세스간 통신과 동적 오브젝트 생성이 가능하다.
강사님 曰 - 그냥 하나 하나 부품처럼 생각한다라 생각
*/