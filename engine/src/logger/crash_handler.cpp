#include <windows.h>
#include <dbghelp.h>

LONG WINAPI CrashHandler(EXCEPTION_POINTERS* exceptionInfo)
{
    HANDLE file = CreateFileW(
        L"crash.dmp",
        GENERIC_WRITE,
        0,
        nullptr,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    if (file != INVALID_HANDLE_VALUE)
    {
        MINIDUMP_EXCEPTION_INFORMATION dumpInfo{};
        dumpInfo.ThreadId = GetCurrentThreadId();
        dumpInfo.ExceptionPointers = exceptionInfo;
        dumpInfo.ClientPointers = FALSE;

        MiniDumpWriteDump(
            GetCurrentProcess(),
            GetCurrentProcessId(),
            file,
            MiniDumpNormal,
            &dumpInfo,
            nullptr,
            nullptr
        );

        CloseHandle(file);
    }

    return EXCEPTION_EXECUTE_HANDLER;
}