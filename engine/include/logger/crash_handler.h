#pragma once
#include <windows.h>
#include <dbghelp.h>

LONG WINAPI CrashHandler(EXCEPTION_POINTERS* exceptionInfo);