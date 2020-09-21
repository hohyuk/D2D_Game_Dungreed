#pragma once
#include "Extern.h"
#include "Constexpr.h"
#include "Structs.h"


inline void LeakCheck()
{
	// 누수 체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//_CrtSetBreakAlloc(예)260); // 만약 누수가 생기면 ()안에 브레이크 포인터 번호를 넣자
	//_CrtSetBreakAlloc(1484);
}