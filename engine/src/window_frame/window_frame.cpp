#include <windows.h>
#include "window_frame/window_frame.h"
#include "window_frame/window_processor.h"

namespace Engine {
    WindowFrame::WindowFrame() = default;

    // Initialize window function to create a window for the engine
    int WindowFrame::initWindow()
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
            return -1;
        }

        this->hwnd = CreateWindowW(
            CLASS_NAME,
            WINDOW_TITLE,
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            100, 100, 1280, 720,
            nullptr, nullptr, wc.hInstance, this
        );

        if (!this->hwnd) {
            return -1;
        }

        return 0;
    }

    void WindowFrame::processWin32Events() {
        MSG msg{};
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}