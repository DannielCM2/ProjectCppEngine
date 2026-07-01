#pragma once
#include <chrono>
#include <windows.h>

namespace core {
    class Engine {
    public:
        std::chrono::duration<double, std::milli> frameInterval;
        HWND hwnd;
        double fps;

        Engine();
        void init();
        void start();
    };
}