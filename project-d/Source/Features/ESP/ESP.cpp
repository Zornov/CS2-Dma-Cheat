#include <Pch.hpp>
#include <SDK.hpp>
#include "ESP.hpp"
#include <string>
#include <sstream>
#include <iostream>

void ESP::Update() {}

void ESP::Render(ImDrawList* drawList) {
    if (!drawList) return;

    uintptr_t entityList = mem->Read<uintptr_t>(
        Globals::ClientBase + cs2_dumper::offsets::client_dll::dwEntityList
    );
    if (!entityList)
        return;

    uintptr_t listEntryBase = mem->Read<uintptr_t>(entityList + 0x10);
    if (!listEntryBase)
        return;

    const int maxPlayers = 64;

    for (int i = 0; i < maxPlayers; ++i) {

        uintptr_t controller = mem->Read<uintptr_t>(listEntryBase + (i + 1) * 0x70);
        if (!controller)
            continue;

        uint32_t pawnHandle = 0;
        if (!mem->Read(controller + cs2_dumper::schemas::client_dll::CBasePlayerController::m_hPawn,
            &pawnHandle, sizeof(pawnHandle)))
            continue;
        if (!pawnHandle)
            continue;

        int seg = (pawnHandle & 0x7FFF) >> 9;
        int ent = (pawnHandle & 0x1FF);

        uintptr_t pawnSegment = mem->Read<uintptr_t>(entityList + 0x10 + seg * 8);
        if (!pawnSegment)
            continue;

        uintptr_t pawn = mem->Read<uintptr_t>(pawnSegment + ent * 0x70);
        if (!pawn)
            continue;

        uintptr_t gameSceneNode = mem->Read<uintptr_t>(
            pawn + cs2_dumper::schemas::client_dll::C_BaseEntity::m_pGameSceneNode
        );
        if (!gameSceneNode)
            continue;

        Vector3 pos{};
        if (!mem->Read(gameSceneNode + cs2_dumper::schemas::client_dll::CGameSceneNode::m_vecAbsOrigin,
            &pos, sizeof(pos)))
            continue;

        if (!std::isfinite(pos.x) || !std::isfinite(pos.y) || !std::isfinite(pos.z))
            continue;

        Vector2 screen;
        if (!sdk->WorldToScreen(pos, screen))
            continue;

        char nameBuf[64] = { 0 };
        auto nameOffset = cs2_dumper::schemas::client_dll::CBasePlayerController::m_iszPlayerName;
        if (nameOffset && !mem->Read(controller + nameOffset, nameBuf, sizeof(nameBuf)))
            nameBuf[0] = '\0';

        uint64_t steamID = 0;
        mem->Read(controller + cs2_dumper::schemas::client_dll::CBasePlayerController::m_steamID,
            &steamID, sizeof(steamID));

        std::string text = std::format("[{}] {}", i, nameBuf[0] ? nameBuf : "unknown");

        drawList->AddText(
            ImVec2(screen.x, screen.y),
            IM_COL32(255, 255, 255, 255),
            text.c_str()
        );
    }
}