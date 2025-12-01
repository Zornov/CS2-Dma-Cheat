#pragma once
#include <cstdint>
#include <memory>
#include <Memory/Memory.h>
#include <cs2/client_dll.hpp>
#include "CGameSceneNode.hpp"

class C_BaseEntity {
protected:
    std::uintptr_t m_Address = 0;

public:
    int m_iTeamNum{};
    std::unique_ptr<CGameSceneNode> m_GameSceneNode;

public:
    C_BaseEntity() = default;

    explicit C_BaseEntity(std::uintptr_t addr)
        : m_Address(addr)
        , m_GameSceneNode(std::make_unique<CGameSceneNode>())
    {
    }

    // Prevent copying to avoid double-delete
    C_BaseEntity(const C_BaseEntity&) = delete;
    C_BaseEntity& operator=(const C_BaseEntity&) = delete;

    // Allow moving
    C_BaseEntity(C_BaseEntity&&) = default;
    C_BaseEntity& operator=(C_BaseEntity&&) = default;

    ~C_BaseEntity() = default;

    inline std::uintptr_t GetAddress() const { return m_Address; }

    virtual void Update() {
        if (!m_GameSceneNode) return;
        
        m_GameSceneNode->m_Address = mem->Read<uintptr_t>(
            m_Address + cs2_dumper::schemas::client_dll::C_BaseEntity::m_pGameSceneNode
        );
        m_GameSceneNode->Update();
    }
};