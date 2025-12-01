#pragma once
#include <memory>
#include <Overlay/Overlay.hpp>
#include <cs2/offsets.hpp>
#include <cs2/client_dll.hpp>
#include <Objects/C_PlantedC4.hpp>
#include <Objects/C_BasePlayerPawn.hpp>
#include <Objects/C_GlobalVars.hpp>

class SDK {
private:
    VMMDLL_SCATTER_HANDLE objectScatter = 0;

public:
    C_GlobalVars* globalVars = nullptr;
    C_BasePlayerPawn* localPlayerPawn = nullptr;
    C_PlantedC4* c4Planted = nullptr;

public:
    bool Init();

    void Update();
    void UpdateObjects();

    bool WorldToScreen(const Vector3& WorldPos, Vector2& ScreenPos, const Matrix& Matrix = Globals::ViewMatrix);
};

inline std::unique_ptr<SDK> sdk = std::make_unique<SDK>();