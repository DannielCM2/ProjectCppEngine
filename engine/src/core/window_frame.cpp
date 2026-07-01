#include <windows.h>
#include "core/window_frame.h"

// Initialize window function to create a window for the engine
HWND initWindow()
{
    const wchar_t CLASS_NAME[] = L"WindowClass";
    const wchar_t WINDOW_TITLE[] = L"Project C++ Engine";

    WNDCLASSW wc{};

    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = CLASS_NAME;
    wc.lpfnWndProc = WindowProc;

    if(!RegisterClassW(&wc)) {
        return nullptr;
    }

    HWND hwnd = CreateWindowW(
        CLASS_NAME,
        WINDOW_TITLE,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100, 100, 1280, 720,
        NULL, NULL, wc.hInstance, NULL
    );

    return hwnd;
}

// Window procedure function to handle window messages
LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam) 
{
    switch(msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void processWin32Events() {
    MSG msg{};
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}