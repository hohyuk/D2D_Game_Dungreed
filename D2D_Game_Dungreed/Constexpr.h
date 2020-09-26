#pragma once

// 화면 크기
constexpr int WINCX{ 1024 };
constexpr int WINCY{ 768 };

constexpr int OBJ_NOEVENT{ 0 };
constexpr int OBJ_DEAD{ 1 };

// COLOR
constexpr DWORD BASIC_COLOR{ D3DCOLOR_ARGB(255, 255, 255, 255) };
constexpr DWORD RED_COLOR{ D3DCOLOR_ARGB(255, 255, 0, 0) };
constexpr DWORD GREEN_COLOR{ D3DCOLOR_ARGB(255, 0, 255, 0) };
constexpr DWORD BLUE_COLOR{ D3DCOLOR_ARGB(255, 0, 0, 255) };