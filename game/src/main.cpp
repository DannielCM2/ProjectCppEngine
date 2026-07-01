#include <iostream>
#include <windows.h>
#include "core/engine.h"

int main() {
    timeBeginPeriod(1);

    core::Engine engine;
    std::cout << "Welcome to ProjectCppEngine!\n";
    engine.init();
    engine.start();
    
    timeEndPeriod(1);

    return 0;
}