#include <windows.h>
#include "window_frame/window_frame.h"

LRESULT CALLBACK WindowProc(
    HWND hwnd, 
    UINT msg, 
    WPARAM wParam, 
    LPARAM lParam
)
{
    switch (msg)
    {
        case WM_NCCREATE:
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
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
    }
    
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}