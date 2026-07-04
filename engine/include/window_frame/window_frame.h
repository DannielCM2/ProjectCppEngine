#pragma once
#include <windows.h>
#include "input/input.h"

namespace Engine {
    class WindowFrame {
    public:
        HWND hwnd;

        WindowFrame();
        int initWindow();
        void processWin32Events();
        Input* getInput() const { return m_input; };
        void setInput(Input* input){ m_input = input; };

    private:
        Input* m_input;
    };
}