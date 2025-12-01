#pragma once

#include <cstdint>
#include <Memory/Memory.h>

class CPlayer_WeaponServices {
public:
    uintptr_t m_Address{};

public:
    CPlayer_WeaponServices() = default;
    explicit CPlayer_WeaponServices(uintptr_t addr) : m_Address(addr) {}

    void Update() {
    }
};
