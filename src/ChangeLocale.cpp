// ChangeLocale.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    SetThreadLocale(
        MAKELCID(
            MAKELANGID(
                LANG_RUSSIAN,
                SUBLANG_DEFAULT
            ),
            SORT_DEFAULT
        )
    );

    return TRUE;
}