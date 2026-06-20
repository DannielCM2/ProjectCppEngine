#include <iostream>
#include <thread>
#include <chrono>
#include "core/engine.h"

core::Engine::Engine() {
    fps = 60;
    frameDelay = std::chrono::duration<double, std::milli>(1000.0 / fps);
}

void core::Engine::start() {
    std::cout << "Engine starting..." << std::endl;

    bool running = true;

    while (running) {
        auto frameStart = std::chrono::steady_clock::now();

        std::cout << "Engine running..." << std::endl;

        auto frameEnd = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = frameEnd - frameStart;
        double sleepTime = frameDelay.count() - elapsed.count();

        if (sleepTime > 0) {
            std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(sleepTime));
        }
    }
}
