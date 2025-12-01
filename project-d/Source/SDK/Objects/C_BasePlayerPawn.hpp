#pragma once

#include <cstdint>
#include <Memory/Memory.h>
#include <cs2/client_dll.hpp>
#include "CGameSceneNode.hpp"
#include "CPlayer_WeaponServices.hpp"
#include <Pch.hpp>

class C_BasePlayerPawn {
protected:
    std::uintptr_t m_Address = 0;

public:
    Vector3 m_vOldOrigin{};
    CPlayer_WeaponServices* m_pWeaponServices = nullptr;

public:
    C_BasePlayerPawn() = default;

    explicit C_BasePlayerPawn(std::uintptr_t addr) : m_Address(addr) {
        m_pWeaponServices = new CPlayer_WeaponServices();
    }

    inline std::uintptr_t GetAddress() const { return m_Address; }

    virtual void Update() {
        m_vOldOrigin = mem->Read<Vector3>(m_Address + cs2_dumper::schemas::client_dll::C_BasePlayerPawn::m_vOldOrigin);

        m_pWeaponServices->m_Address = mem->Read<uintptr_t>(
            m_Address + cs2_dumper::schemas::client_dll::C_BasePlayerPawn::m_pWeaponServices
		);
		m_pWeaponServices->Update();
    }
};