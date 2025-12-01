#include <Pch.hpp>
#include <SDK.hpp>
#include "ESP.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>

void ESP::Update() {

}

void ESP::Render(ImDrawList* drawList) {
    if (!sdk->c4Planted || !sdk->c4Planted->m_bBombPlanted)
        return;

    if (!sdk->c4Planted->m_GameSceneNode)
        return;

    Vector3 bombPos = sdk->c4Planted->m_GameSceneNode->m_vecAbsOrigin;

    Vector2 screenPos;
    if (!sdk->WorldToScreen(bombPos, screenPos))
        return;

    char buffer[256];

    const char* siteName = "Unknown";
    if (sdk->c4Planted->m_iBombSite == 0)
        siteName = "A";
    else if (sdk->c4Planted->m_iBombSite == 1)
        siteName = "B";

    snprintf(buffer, sizeof(buffer),
        "Bomb Planted\nSite: %s\nPos: %.1f %.1f %.1f",
        siteName,
        bombPos.x, bombPos.y, bombPos.z
    );

    Renderer::Text(
        drawList,
        screenPos.x,
        screenPos.y,
        0.0f, 0.0f,
        buffer,
        ImVec4(1.0f, 0.2f, 0.2f, 1.0f)
    );
}