#pragma once
class FPS_Manager final
{
	DECLARE_SINGLETON(FPS_Manager)
private:
	FPS_Manager();
	~FPS_Manager();

public:
	void Ready_FixFPS(const float& fFPS);
	bool Loop_FPS();
	void Render();

private:
	TCHAR m_szFPS[32];
	int m_iFPS;

	float m_fSPF;
	float m_fFPS;
	float m_fDeltaTime;

	LARGE_INTEGER m_CpuTick;
	LARGE_INTEGER m_StartTime;
	LARGE_INTEGER m_EndTime;
};

