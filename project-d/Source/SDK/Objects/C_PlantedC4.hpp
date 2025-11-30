#pragma once
#include <Memory/Memory.h>
#include <cstdint>

class C_PlantedC4 {
public:
    std::uintptr_t m_Address = 0;

    bool m_bBombTicking{};
    int32_t m_nBombSite{};
    int32_t m_nSourceSoundscapeHash{};
    float m_flNextGlow{};
    float m_flNextBeep{};
    float m_flC4Blow{};
    bool m_bCannotBeDefused{};
    bool m_bHasExploded{};
    float m_flTimerLength{};
    bool m_bBeingDefused{};
    float m_bTriggerWarning{};
    float m_bExplodeWarning{};
    bool m_bC4Activated{};
    bool m_bTenSecWarning{};
    float m_flDefuseLength{};
    float m_flDefuseCountDown{};
    bool m_bBombDefused{};
    float m_flNextRadarFlashTime{};
    bool m_bRadarFlash{};
    float m_fLastDefuseTime{};
    float m_flC4ExplodeSpectateDuration{};

public:
    C_PlantedC4() = default;
    explicit C_PlantedC4(std::uintptr_t addr) : m_Address(addr) {}

    bool IsValid() const {
        return m_Address != 0;
    }

    void Update() {
        if (!IsValid()) {
            LOG_WARN("Error: not valid");
            return;
        }
		namespace Offsets = cs2_dumper::schemas::client_dll::C_PlantedC4;

        m_bBombTicking = mem.Read<bool>(m_Address + Offsets::m_bBombTicking);
        m_nBombSite = mem.Read<int32_t>(m_Address + Offsets::m_nBombSite);
        m_nSourceSoundscapeHash = mem.Read<int32_t>(m_Address + Offsets::m_nSourceSoundscapeHash);
        m_flNextGlow = mem.Read<float>(m_Address + Offsets::m_flNextGlow);
        m_flNextBeep = mem.Read<float>(m_Address + Offsets::m_flNextBeep);
        m_flC4Blow = mem.Read<float>(m_Address + Offsets::m_flC4Blow);
        m_bCannotBeDefused = mem.Read<bool>(m_Address + Offsets::m_bCannotBeDefused);
        m_bHasExploded = mem.Read<bool>(m_Address + Offsets::m_bHasExploded);
        m_flTimerLength = mem.Read<float>(m_Address + Offsets::m_flTimerLength);
        m_bBeingDefused = mem.Read<bool>(m_Address + Offsets::m_bBeingDefused);
        m_bTriggerWarning = mem.Read<float>(m_Address + Offsets::m_bTriggerWarning);
        m_bExplodeWarning = mem.Read<float>(m_Address + Offsets::m_bExplodeWarning);
        m_bC4Activated = mem.Read<bool>(m_Address + Offsets::m_bC4Activated);
        m_bTenSecWarning = mem.Read<bool>(m_Address + Offsets::m_bTenSecWarning);
        m_flDefuseLength = mem.Read<float>(m_Address + Offsets::m_flDefuseLength);
        m_flDefuseCountDown = mem.Read<float>(m_Address + Offsets::m_flDefuseCountDown);
        m_bBombDefused = mem.Read<bool>(m_Address + Offsets::m_bBombDefused);
        m_flNextRadarFlashTime = mem.Read<float>(m_Address + Offsets::m_flNextRadarFlashTime);
        m_bRadarFlash = mem.Read<bool>(m_Address + Offsets::m_bRadarFlash);
        m_fLastDefuseTime = mem.Read<float>(m_Address + Offsets::m_fLastDefuseTime);
        m_flC4ExplodeSpectateDuration = mem.Read<float>(m_Address + Offsets::m_flC4ExplodeSpectateDuration);
    }
};