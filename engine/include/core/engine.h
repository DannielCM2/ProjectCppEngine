#pragma once
#include <chrono>
#include <windows.h>
#include <input/input.h>
#include <window_frame/window_frame.h>

namespace Engine {
    class Engine {
    public:
        Input m_input;
        WindowFrame m_windowFrame;

        Engine();
        void init();
        void start();
        bool isRunning() const { return m_running; };
        void stop() { m_running = false; };
        void setFps(double fps);
        std::chrono::duration<double, std::milli> getFrameInterval() const { return m_frameInterval; };

    private:
        bool m_running = true;
        double m_fps;
        std::chrono::duration<double, std::milli> m_frameInterval;

        void processEvents();
    };
}