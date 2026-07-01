#pragma once

#include <chrono>

void sleepUntilNextFrame(
    std::chrono::steady_clock::time_point frameStart,
    std::chrono::duration<double, std::milli> frameInterval
);