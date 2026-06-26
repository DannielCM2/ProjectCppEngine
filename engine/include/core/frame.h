#pragma once
#include <windows.h>

HWND initWindow();
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

void processMessages();