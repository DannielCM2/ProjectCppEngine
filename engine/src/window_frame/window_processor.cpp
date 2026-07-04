#include <windows.h>
#include "window_frame/window_frame.h"
#include <iostream>

LRESULT CALLBACK WindowProc(
    HWND hwnd, 
    UINT msg, 
    WPARAM wParam, 
    LPARAM lParam
)
{
    if (msg == WM_NCCREATE)
    {
        auto* cs = reinterpret_cast<CREATESTRUCT*>(lParam);
        auto* window = static_cast<Engine::WindowFrame*>(cs->lpCreateParams);

        SetWindowLongPtrW(
            hwnd,
            GWLP_USERDATA,
            reinterpret_cast<LONG_PTR>(window)
        );

        return TRUE;
    }

    auto* window = reinterpret_cast<Engine::WindowFrame*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));

    switch (msg)
    {
        case WM_KEYUP:
        {
            if (window && window->getInput()) {
                window->getInput()->onKeyUp(static_cast<std::uint8_t>(wParam));
            }
            return 0;
        }
        case WM_KEYDOWN:
        {
            if (window && window->getInput()) {
                window->getInput()->onKeyDown(static_cast<std::uint8_t>(wParam));
            }
            return 0;
        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
    }
    
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}