#pragma once
#include "Extern.h"
#include "Constexpr.h"
#include "Structs.h"


inline void LeakCheck()
{
	// ���� üũ
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//_CrtSetBreakAlloc(��)260); // ���� ������ ����� ()�ȿ� �극��ũ ������ ��ȣ�� ����
	//_CrtSetBreakAlloc(1484);
}