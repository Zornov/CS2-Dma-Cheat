#pragma once

#include <Memory/Memory.h>
#include <cs2/client_dll.hpp>
#include <cstdint>

class C_C4 {
private:
    std::uintptr_t m_Address = 0;

public:

    bool m_bStartedArming{};
    bool m_bBombPlacedAnimation{};
    bool m_bIsPlantingViaUse{};
    int  m_nSpotRules{};
    bool m_bPlayedArmingBeeps[7]{};
    bool m_bBombPlanted{};

public:
    C_C4() = default;

    explicit C_C4(std::uintptr_t addr) : m_Address(addr) {}

    bool IsValid() const {
        return m_Address != 0;
    }

    void Update() {
        if (!IsValid())
            return;

        namespace Offsets = cs2_dumper::schemas::client_dll::C_C4;

        m_bIsPlantingViaUse = mem.Read<bool>(m_Address + Offsets::m_bIsPlantingViaUse);
        m_bBombPlanted = mem.Read<bool>(m_Address + Offsets::m_bBombPlanted);
        m_bStartedArming = mem.Read<bool>(m_Address + Offsets::m_bStartedArming);
        m_bBombPlacedAnimation = mem.Read<bool>(m_Address + Offsets::m_bBombPlacedAnimation);
        m_nSpotRules = mem.Read<int>(m_Address + Offsets::m_nSpotRules);

        for (int i = 0; i < 7; i++)
            m_bPlayedArmingBeeps[i] = mem.Read<bool>(m_Address + Offsets::m_bPlayedArmingBeeps + i);
    }
};