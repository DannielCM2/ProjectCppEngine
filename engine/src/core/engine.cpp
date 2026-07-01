#include <iostream>
#include <thread>
#include <chrono>
#include "core/engine.h"
#include "core/window_frame.h"
#include "utils/time_util.h"
#include <windows.h>

core::Engine::Engine() {
    fps = 120.0;
    frameInterval = std::chrono::duration<double, std::milli>(1000.0 / fps);
}

// Initializes engine components
void core::Engine::init() {
    hwnd = initWindow();
}

// This function serves as entry point for the engine's main loop.
void core::Engine::start() {
    bool running = true;
    auto lastFrameStart = std::chrono::steady_clock::now();;
    
    while (running) {
        auto frameStart = std::chrono::steady_clock::now();

        processWin32Events();

        std::chrono::duration<double, std::milli> deltaTime = frameStart - lastFrameStart;
        lastFrameStart = frameStart;
        
        std::cout << " Delta Time: " << deltaTime.count() << "ms\n";
        
        sleepUntilNextFrame(frameStart, frameInterval);
    }
}