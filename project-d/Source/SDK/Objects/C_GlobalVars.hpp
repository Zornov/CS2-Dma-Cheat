#pragma once

#include <Memory/Memory.h>
#include <cstdint>
#include <Globals.hpp>
#include <cs2/offsets.hpp>

class C_GlobalVars {
private:
    uintptr_t m_Address{};

public:
    float realtime{};

public:

    C_GlobalVars() = default;

    C_GlobalVars(uintptr_t addr) : m_Address(addr) {}

    void Update() {
        realtime = mem->Read<float>(m_Address + 0x00);
    }
};
