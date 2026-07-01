#include "utils/time_util.h"
#include <iostream>
#include <windows.h>
#include <thread>

void sleepUntilNextFrame(
    std::chrono::steady_clock::time_point frameStart,
    std::chrono::duration<double, std::milli> frameInterval
)
{
    auto targetTime = frameStart + frameInterval;

    auto now = std::chrono::steady_clock::now();

    if (now < targetTime - std::chrono::milliseconds(1))
    {
        auto remaining = targetTime - now - std::chrono::milliseconds(1);

        Sleep(static_cast<DWORD>(std::chrono::duration_cast<std::chrono::milliseconds>(remaining).count()));
    }

    while (std::chrono::steady_clock::now() < targetTime)
    {
        std::this_thread::yield();
    }
}