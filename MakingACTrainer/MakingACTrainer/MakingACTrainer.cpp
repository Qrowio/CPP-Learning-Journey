#include <iostream>
#include <windows.h>
#include <string>

void nop(unsigned char* dst, unsigned int size) {
    unsigned long old_protect;

    VirtualProtect(dst, size, 0x40, &old_protect);
    memset(dst, 0x90, size);
    VirtualProtect(dst, size, old_protect, &old_protect);
}

DWORD __stdcall Init(HMODULE hModule) // WHEN INIT IS CALLED
{
    uintptr_t BaseAddress = (uintptr_t)GetModuleHandle(0);
    uintptr_t localPlayer = *(uintptr_t*)(BaseAddress + 0x10F4F4);
    int* playerHealth = (int*)(localPlayer + 0xF8);
    int* playerArmor = (int*)(localPlayer + 0xFC);
    int* rifleDelay = (int*)(localPlayer + 0x178);
    int* rifleAmmo = (int*)(localPlayer + 0x150);
    int* pistolAmmo = (int*)(localPlayer + 0x13C);
    int* pistolDelay = (int*)(localPlayer + 0x164);
    int* grenades = (int*)(localPlayer + 0x158);
    int* grenadeDelay = (int*)(localPlayer + 0x180);
    int* knifeDelay = (int*)(localPlayer + 0x160);
    int* recoil = (int*)(0x4EE444);
    nop((unsigned char*)recoil, 10);
    while (!GetAsyncKeyState(VK_END))
    {
        *playerHealth = 1000;
        *rifleDelay = 0;
        *rifleAmmo = 100;
        *pistolAmmo = 100;
        *pistolDelay = 0;
        *playerArmor = 1000;
        *grenades = 100;
        *grenadeDelay = 0;
        *knifeDelay = 0;
    }
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

int __stdcall DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved) // CODE STARTS HERE
{
    if (reason == DLL_PROCESS_ATTACH) // IF THE DLL ATTACHES TO A PROCESS
        CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, hModule, 0, 0)); // CREATE A NEW THREAD AND RUN THE INIT FUNCTION

    return 1;
}