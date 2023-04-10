#pragma once


#ifdef RUNNING_PLATFORM_WINDOWS
    #ifdef BUILD_DLL
        #define TTE_API __declspec(dllexport)
    #else
        #define TTE_API __declspec(dllimport)
    #endif
#else
    #define TTE_API
    // #error TTEngine only supports Windows!
#endif