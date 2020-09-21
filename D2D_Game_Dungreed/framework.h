// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

/*누수 체크 헤더*/
// ===============================
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
// ===============================

#include "d3d9.h"
#pragma comment(lib, "d3d9.lib")
#include "d3dx9.h"
#pragma comment(lib, "d3dx9.lib")

// =============SOUND====================
#include <io.h>
#include "fmod.h"
#pragma comment(lib, "fmodex_vc.lib")
//#include "SoundMgr.h"
// ======================================


#include "Headers.h"



//=================== 콘솔창 띄우기 =======================
// 콘솔창 띄우기
#ifdef _DEBUG
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
#else

#endif
//========================================================



// ================= 메모리 누수 체크 =====================
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

//========================================================