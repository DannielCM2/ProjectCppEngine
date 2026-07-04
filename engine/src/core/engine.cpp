#include <iostream>
#include <thread>
#include <chrono>
#include "core/engine.h"
#include "utils/time_util.h"
#include "input/input.h"
#include <windows.h>

namespace Engine {
    Engine::Engine() {
        setFps(60.0);
    }

    // Initializes engine components
    void Engine::init(){
        m_windowFrame.initWindow();
    };
    
    // This function serves as entry point for the engine's main loop.
    void Engine::start() {
        auto lastFrameStart = std::chrono::steady_clock::now();;

        while (isRunning()) {
            auto frameStart = std::chrono::steady_clock::now();

            processEvents();

            std::chrono::duration<double, std::milli> deltaTime = frameStart - lastFrameStart;
            lastFrameStart = frameStart;
                        
            sleepUntilNextFrame(frameStart, getFrameInterval());
        }
    }

    void Engine::processEvents() {
        m_input.update();
        m_windowFrame.processWin32Events();
    }

    void Engine::setFps(double fps) {
        m_fps = fps;
        m_frameInterval = std::chrono::duration<double, std::milli>(1000.0 / m_fps);
    }
}
