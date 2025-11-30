#pragma once
#include <memory>
#include <Overlay/Overlay.hpp>
#include <cs2/offsets.hpp>
#include <cs2/client_dll.hpp>
#include <Objects/C_PlantedC4.hpp>

class SDK {
public:
    std::unique_ptr<C_PlantedC4> c4Planted;

public:
    bool Init();

    void Update();
    void UpdateObjects();

    bool WorldToScreen(const Vector3& WorldPos, Vector2& ScreenPos, const Matrix& Matrix = Globals::ViewMatrix);
};

inline std::unique_ptr<SDK> sdk = std::make_unique<SDK>();