#pragma once

#include "Extern.h"
#include "Constexpr.h"
#include "Enums.h"
#include "Structs.h"
#include "Define.h"
#include "Template.h"
#include "BaseMath.h"
#include "D3DX_Func.h"

#include "SingletonMacro.h"
#include "TimeManager.h"
#include "FPS_Manager.h"
#include "GraphicDevice.h"
#include "TextureManager.h"
#include "KeyManager.h"

#include "SceneManager.h"

// =============SOUND====================
#include <io.h>
#include "fmod.h"
#pragma comment(lib, "fmodex_vc.lib")
#include "SoundManager.h"
// ======================================


inline void LeakCheck()
{
	// ���� üũ
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//_CrtSetBreakAlloc(��)260); // ���� ������ ����� ()�ȿ� �극��ũ ������ ��ȣ�� ����
	//_CrtSetBreakAlloc(1484);
}

// ErrorMessage
#ifdef _AFX
#define ERR_MSG(Message) AfxMessageBox(Message)
#else
#define ERR_MSG(Message) MessageBox(nullptr,Message,TEXT("System Error"),MB_OK)
#endif