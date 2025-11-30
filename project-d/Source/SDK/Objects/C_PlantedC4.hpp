#pragma once

#include <Memory/Memory.h>
#include <cs2/client_dll.hpp>
#include <cs2/offsets.hpp>
#include <cstdint>
#include <Globals.hpp>
#include "C_BaseEntity.hpp"

class C_PlantedC4 : public C_BaseEntity {
public:

    bool m_bBombPlanted{};
    int m_iBombSite{};

public:
    C_PlantedC4() = default;

    C_PlantedC4(std::uintptr_t addr) : C_BaseEntity(addr) {}

    void Update() {
        C_BaseEntity::Update();

        m_bBombPlanted = mem->Read<bool>(
            Globals::ClientBase + cs2_dumper::offsets::client_dll::dwPlantedC4 - 0x8
        );

        if (m_bBombPlanted) {
            m_iBombSite = mem->Read<int>(
                m_Address + cs2_dumper::schemas::client_dll::C_PlantedC4::m_nBombSite
            );
        }
        else {
            m_iBombSite = -1;
        }
    }
};