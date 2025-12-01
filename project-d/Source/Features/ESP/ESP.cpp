#include <Pch.hpp>
#include <SDK.hpp>
#include "ESP.hpp"
#include <string>
#include <sstream>
#include <iostream>

#include <Objects/C_GlobalVars.hpp>
#include <Objects/C_BasePlayerPawn.hpp>
#include <Objects/C_PlantedC4.hpp>

void ESP::Update() {}

void ESP::Render(ImDrawList* drawList) {
    std::stringstream ss;

    if (sdk->globalVars) {
        const C_GlobalVars* gv = sdk->globalVars;
        ss << "GlobalVars:\n"
            << "  realtime: " << gv->realtime << "\n";
    }

    if (sdk->localPlayerPawn) {
        const C_BasePlayerPawn* lp = sdk->localPlayerPawn;
        const auto& pos = lp->m_vOldOrigin;

        ss << "\nLocalPlayerPawn:\n"
            << "  Address: 0x" << std::hex << lp->GetAddress() << std::dec << "\n"
            << "  Origin:  " << pos.x << "  " << pos.y << "  " << pos.z << "\n";
    }

    if (sdk->c4Planted) {
        const C_PlantedC4* c4 = sdk->c4Planted;

        ss << "\nPlantedC4:\n"
            << "  Planted: " << (c4->m_bBombPlanted ? "YES" : "NO") << "\n";

        if (c4->m_bBombPlanted) {
            const Vector3& pos = c4->m_GameSceneNode->m_vecAbsOrigin;

            const char* siteLetter = (c4->m_iBombSite == 0) ? "A" : "B";

            ss << "  BombSite: " << c4->m_iBombSite << " (" << siteLetter << ")\n"
                << "  Origin:   " << pos.x << "  " << pos.y << "  " << pos.z << "\n"
                << "  C4Blow:   " << c4->m_flC4Blow << "\n";

            if (sdk->globalVars) {
                float timeLeft = c4->m_flC4Blow - sdk->globalVars->realtime;
                if (timeLeft < 0.f) timeLeft = 0.f;
                ss << "  Time left: " << timeLeft << "\n";
            }
        }
    }

    std::string debugText = ss.str();

    Renderer::Text(
        drawList,
        ScreenCenter.x * 0.75,
        ScreenCenter.y,
        0.f, 0.f,
        debugText,
        ImVec4(1.f, 1.f, 1.f, 1.f)
    );
}