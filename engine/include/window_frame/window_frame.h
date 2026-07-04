#pragma once
#include <windows.h>

namespace Engine {
    class WindowFrame {
    public:
        HWND hwnd;

        WindowFrame();
        int initWindow();
        void processWin32Events();
    };
}