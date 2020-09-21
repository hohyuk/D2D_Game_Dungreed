#include "framework.h"
#include "TimeManager.h"

IMPLEMENT_SINGLETON(TimeManager)

TimeManager::TimeManager()
{

}

TimeManager::~TimeManager()
{
}

void TimeManager::Ready()
{
	QueryPerformanceFrequency(&m_CpuTick);
	QueryPerformanceCounter(&m_EndTime);
	QueryPerformanceCounter(&m_StartTime);
}

void TimeManager::Update()
{
	QueryPerformanceFrequency(&m_CpuTick);
	QueryPerformanceCounter(&m_EndTime);

	m_fDeltaTime = float(m_EndTime.QuadPart - m_StartTime.QuadPart) / m_CpuTick.QuadPart;
	m_StartTime.QuadPart = m_EndTime.QuadPart;
}
