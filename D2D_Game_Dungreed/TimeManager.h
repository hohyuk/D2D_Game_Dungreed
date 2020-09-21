#pragma once
class TimeManager
{
	DECLARE_SINGLETON(TimeManager)
private:
	explicit TimeManager();
	~TimeManager();

public:
	float Get_DeltaTime() { return m_fDeltaTime; }

public:
	void Ready();
	void Update();
private:
	float m_fDeltaTime;

	LARGE_INTEGER m_CpuTick;
	LARGE_INTEGER m_StartTime;
	LARGE_INTEGER m_EndTime;
};

