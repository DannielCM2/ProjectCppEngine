#include <chrono>
#pragma once

namespace core {
    class Engine {
    public:
        std::chrono::duration<double, std::milli> frameDelay;
        int fps;

        Engine();
        void start();
    };
}