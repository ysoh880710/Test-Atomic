#include <iostream>
#include <Windows.h>
#include <atomic>

using namespace std;

atomic<unsigned long long> g_ullValue = 0ull;
atomic<bool> g_bExit0 = false;
atomic<bool> g_bExit1 = false;
atomic<bool> g_bExit2 = false;
atomic<bool> g_bExit3 = false;

unsigned long __stdcall Func0(void* const _pParameter)
{
    for (unsigned long long i = 0ull; i < 10000ull; ++i)
    {
        ++g_ullValue;
    }

    return 0ul;
}

unsigned long __stdcall Func1(void* const _pParameter)
{
    while (true)
    {
        if (g_bExit0)
        {
            break;
        }
    }

    return 0ul;
}

unsigned long __stdcall Func2(void* const _pParameter)
{
    while (true)
    {
        if (g_bExit0)
        {
            break;
        }
    }

    return 0ul;
}

unsigned long __stdcall Func3(void* const _pParameter)
{
    while (true)
    {
        if (g_bExit0)
        {
            break;
        }
    }

    return 0ul;
}

unsigned long __stdcall Func4(void* const _pParameter)
{
    while (true)
    {
        if (g_bExit0)
        {
            break;
        }
    }

    return 0ul;
}

int main()
{
    // Example 1
    unsigned long ulThreadID0 = 0ul;
    unsigned long ulThreadID1 = 0ul;
    unsigned long ulThreadID2 = 0ul;
    unsigned long ulThreadID3 = 0ul;

    void* pThread0 = CreateThread(nullptr,
                                  0ull,
                                  Func1,
                                  nullptr,
                                  0ul,
                                  &ulThreadID0);

    void* pThread1 = CreateThread(nullptr,
                                  0ull,
                                  Func2,
                                  nullptr,
                                  0ul,
                                  &ulThreadID1);

    void* pThread2 = CreateThread(nullptr,
                                  0ull,
                                  Func3,
                                  nullptr,
                                  0ul,
                                  &ulThreadID2);

    void* pThread3 = CreateThread(nullptr,
                                  0ull,
                                  Func4,
                                  nullptr,
                                  0ul,
                                  &ulThreadID3);

    Sleep(1000);
    g_bExit0 = true;

    unsigned long ulExitCode = 10ul;
    while (true)
    {
        GetExitCodeThread(pThread0, &ulExitCode);
        if (ulExitCode == 0ul)
        {
            break;
        }
    }

    while (true)
    {
        GetExitCodeThread(pThread1, &ulExitCode);
        if (ulExitCode == 0ul)
        {
            break;
        }
    }

    while (true)
    {
        GetExitCodeThread(pThread2, &ulExitCode);
        if (ulExitCode == 0ul)
        {
            break;
        }
    }

    while (true)
    {
        GetExitCodeThread(pThread3, &ulExitCode);
        if (ulExitCode == 0ul)
        {
            break;
        }
    }

    wcout << L"[Atomic]" << endl;
    wcout << L"g_bExit0\t:\t" << g_bExit0 << endl;
    
    return 0;
}