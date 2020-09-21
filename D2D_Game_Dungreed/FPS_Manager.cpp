#include "framework.h"
#include "FPS_Manager.h"

IMPLEMENT_SINGLETON(FPS_Manager)

FPS_Manager::FPS_Manager()
	: m_szFPS{TEXT("")}, m_iFPS{0},
	m_fFPS{0.f},m_fDeltaTime{0.f}
{
	ZeroMemory(&m_CpuTick, sizeof(LARGE_INTEGER));
	ZeroMemory(&m_StartTime, sizeof(LARGE_INTEGER));
	ZeroMemory(&m_EndTime, sizeof(LARGE_INTEGER));
}

FPS_Manager::~FPS_Manager()
{
}

void FPS_Manager::Ready_FixFPS(const float & fFPS)
{
	m_fSPF = 1.f / fFPS;
	QueryPerformanceFrequency(&m_CpuTick);
	QueryPerformanceCounter(&m_StartTime);
	QueryPerformanceCounter(&m_EndTime);
}

bool FPS_Manager::Loop_FPS()
{
	QueryPerformanceFrequency(&m_CpuTick);
	QueryPerformanceCounter(&m_EndTime);

	m_fDeltaTime += static_cast<float>(m_EndTime.QuadPart - m_StartTime.QuadPart) / m_CpuTick.QuadPart;
	m_StartTime.QuadPart = m_EndTime.QuadPart;
	if (m_fSPF < m_fDeltaTime)
	{
		m_fDeltaTime = 0.f;
		++m_iFPS;
		return true;
	}
	return false;
}

void FPS_Manager::Render()
{
	m_fFPS += TIME_MGR->Get_DeltaTime();
	if (1.f <= m_fFPS)
	{
		wsprintf(m_szFPS, TEXT("Dungreed FPS : %d"), m_iFPS);
		m_iFPS = 0;
		m_fFPS = 0.f;
	}
	SetWindowText(g_hWND, m_szFPS);

	/*D3DXMATRIX matTrans;
	D3DXMatrixTranslation(&matTrans, 0.f, 0.f, 0.f);

	GD_MGR->Get_Sprite()->SetTransform(&matTrans);
	GD_MGR->Get_Font()->DrawTextW(GD_MGR->Get_Sprite(), m_szFPS, lstrlen(m_szFPS), nullptr, 0, D3DCOLOR_ARGB(255, 255, 255, 255));
*/
	
}
