#include <iostream>
#include <thread>
#include <chrono>
#include "core/engine.h"
#include "core/frame.h"
#include <windows.h>

// Engine constructor initializes the frame rate and calculates the frame delay based on the desired frames per second (fps).
core::Engine::Engine() {
    fps = 60;
    frameDelay = std::chrono::duration<double, std::milli>(1000.0 / fps);
}

void core::Engine::init() {
    hwnd = initWindow();
}

// The start method runs the main loop of the engine, printing messages to indicate the engine's state and managing frame timing to maintain a consistent frame rate.
void core::Engine::start() {
    bool running = true;

    while (running) {
        processMessages();

        auto frameStart = std::chrono::steady_clock::now();

        auto frameEnd = std::chrono::steady_clock::now();

        std::chrono::duration<double, std::milli> elapsed = frameEnd - frameStart;
        double sleepTime = frameDelay.count() - elapsed.count();

        if (sleepTime > 0) {
            std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(sleepTime));
        }
    }
}