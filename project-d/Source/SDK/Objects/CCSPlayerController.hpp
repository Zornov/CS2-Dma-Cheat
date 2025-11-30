#pragma once

#include <Memory/Memory.h>
#include <cs2/client_dll.hpp>
#include <cstdint>

class CCSPlayerController {
private:
    std::uintptr_t m_Address = 0;

public:
    // ======= FIELDS =======
    std::uint32_t m_iPing{};
    bool m_bHasCommunicationAbuseMute{};
    std::uint32_t m_uiCommunicationMuteFlags{};
    std::uint8_t  m_iPendingTeamNum{};
    bool m_bEverPlayedOnTeam{};
    bool m_bPawnIsAlive{};
    std::uint32_t m_iPawnHealth{};
    std::int32_t m_iPawnArmor{};
    bool m_bPawnHasDefuser{};
    bool m_bPawnHasHelmet{};
    std::int32_t m_iScore{};
    std::uint8_t m_recentKillQueue[8]{};
    std::uint8_t m_nFirstKill{};
    std::uint8_t m_nKillCount{};
    bool m_bMvpNoMusic{};

public:
    CCSPlayerController() = default;

    explicit CCSPlayerController(std::uintptr_t addr) : m_Address(addr) {}

    bool IsValid() const {
        return m_Address != 0;
    }

    void Update() {
        if (!IsValid())
            return;

        namespace Offsets = cs2_dumper::schemas::client_dll::CCSPlayerController;

        m_iPing = mem.Read<std::uint32_t>(m_Address + Offsets::m_iPing);
        m_bHasCommunicationAbuseMute = mem.Read<bool>(m_Address + Offsets::m_bHasCommunicationAbuseMute);
        m_uiCommunicationMuteFlags = mem.Read<std::uint32_t>(m_Address + Offsets::m_uiCommunicationMuteFlags);
        m_iPendingTeamNum = mem.Read<std::uint8_t>(m_Address + Offsets::m_iPendingTeamNum);
        m_bEverPlayedOnTeam = mem.Read<bool>(m_Address + Offsets::m_bEverPlayedOnTeam);

        m_bPawnIsAlive = mem.Read<bool>(m_Address + Offsets::m_bPawnIsAlive);
        m_iPawnHealth = mem.Read<std::uint32_t>(m_Address + Offsets::m_iPawnHealth);
        m_iPawnArmor = mem.Read<std::int32_t>(m_Address + Offsets::m_iPawnArmor);
        m_bPawnHasDefuser = mem.Read<bool>(m_Address + Offsets::m_bPawnHasDefuser);
        m_bPawnHasHelmet = mem.Read<bool>(m_Address + Offsets::m_bPawnHasHelmet);

        m_iScore = mem.Read<std::int32_t>(m_Address + Offsets::m_iScore);

        // recentKillQueue[8]
        for (int i = 0; i < 8; i++)
            m_recentKillQueue[i] = mem.Read<std::uint8_t>(m_Address + Offsets::m_recentKillQueue + i);

        m_nFirstKill = mem.Read<std::uint8_t>(m_Address + Offsets::m_nFirstKill);
        m_nKillCount = mem.Read<std::uint8_t>(m_Address + Offsets::m_nKillCount);
        m_bMvpNoMusic = mem.Read<bool>(m_Address + Offsets::m_bMvpNoMusic);
    }
};