#pragma once
#include <cstdint>
#include <Memory/Memory.h>
#include <cs2/client_dll.hpp>
#include "CGameSceneNode.hpp"

class C_BaseEntity {
protected:
    std::uintptr_t m_Address = 0;

public:
    int m_iTeamNum{};
    CGameSceneNode* m_GameSceneNode = nullptr;

public:
    C_BaseEntity() = default;

    explicit C_BaseEntity(std::uintptr_t addr)
        : m_Address(addr)
    {
        m_GameSceneNode = new CGameSceneNode();
    }

    ~C_BaseEntity() {
        delete m_GameSceneNode;
    }

    inline std::uintptr_t GetAddress() const { return m_Address; }

    virtual void Update() {
        m_GameSceneNode->m_Address = mem->Read<uintptr_t>(
            m_Address + cs2_dumper::schemas::client_dll::C_BaseEntity::m_pGameSceneNode
        );
        m_GameSceneNode->Update();
    }
};