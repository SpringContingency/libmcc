#pragma once

#include <Windows.h>

#include <winnt.h>
#include <winternl.h>

namespace libmcc {
    inline HMODULE get_module_base_address() {
        return *reinterpret_cast<HMODULE*>(__readgsqword(0x60) + 0x10);
    }

    inline int get_tls_index(HMODULE hModule) {
        auto module = reinterpret_cast<uintptr_t>(hModule);
        auto pnth = reinterpret_cast<PIMAGE_NT_HEADERS>(module + reinterpret_cast<PIMAGE_DOS_HEADER>(hModule)->e_lfanew);
        auto addr = pnth->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress;
        return *reinterpret_cast<int*>(reinterpret_cast<PIMAGE_TLS_DIRECTORY>(module + addr)->AddressOfIndex);
    }

    inline void* get_tls(int tls_index) {
        return reinterpret_cast<void**>(__readgsqword(0x58))[tls_index];
    }
}