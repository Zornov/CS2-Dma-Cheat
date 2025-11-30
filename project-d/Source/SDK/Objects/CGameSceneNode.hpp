#pragma once

#include <cstdint>
#include <Memory/Memory.h>
#include <cs2/client_dll.hpp>

class CGameSceneNode {
public:
    uintptr_t m_Address{};
    Vector3 m_vecAbsOrigin{};

public:
    CGameSceneNode() = default;
    explicit CGameSceneNode(uintptr_t addr) : m_Address(addr) {}

    void Update() {
        m_vecAbsOrigin = mem->Read<Vector3>(m_Address + cs2_dumper::schemas::client_dll::CGameSceneNode::m_vecAbsOrigin);
    }
};
