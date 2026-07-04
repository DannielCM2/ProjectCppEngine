#include <iostream>
#include <windows.h>
#include "core/engine.h"
#include "logger/crash_handler.h"

int main() {
    SetUnhandledExceptionFilter(CrashHandler);
    timeBeginPeriod(1);

    Engine::Engine engine;
    std::cout << "Welcome to ProjectCppEngine!\n";
    engine.init();
    engine.start();
    
    timeEndPeriod(1);

    return 0;
}