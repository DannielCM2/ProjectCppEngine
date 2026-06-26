#pragma once
#include <chrono>
#include <windows.h>

namespace core {
    class Engine {
    public:
        std::chrono::duration<double, std::milli> frameDelay;
        HWND hwnd;
        int fps;

        Engine();
        void init();
        void start();
    };
}