#include <Pch.hpp>
#include <SDK.hpp>
#include <cs2/offsets.hpp>

bool SDK::Init() {
    Globals::Running = true;

	// Planted C4
    auto cPlantedC4 = mem.Read<uintptr_t>(
        Globals::ClientBase + cs2_dumper::offsets::client_dll::dwPlantedC4
    );
    cPlantedC4 = mem.Read<uintptr_t>(cPlantedC4);

    planted_C4 = std::make_unique<C_PlantedC4>(cPlantedC4);

    // Weapon C4
    auto cC4 = mem.Read<uintptr_t>(
        Globals::ClientBase + cs2_dumper::offsets::client_dll::dwWeaponC4
    );
    cC4 = mem.Read<uintptr_t>(cC4);
    
    c4 = std::make_unique<C_C4>(cC4);

    return true;
}


bool SDK::WorldToScreen(const Vector3& WorldPos, Vector2& ScreenPos, const Matrix& Matrix) {
    float w = Matrix[3][0] * WorldPos.x + Matrix[3][1] * WorldPos.y + Matrix[3][2] * WorldPos.z + Matrix[3][3];

    if (w < 0.001f) {
        return false;
    }

    float inv_w = 1.0f / w;

    float ndc_x = (Matrix[0][0] * WorldPos.x + Matrix[0][1] * WorldPos.y + Matrix[0][2] * WorldPos.z + Matrix[0][3]) * inv_w;
    float ndc_y = (Matrix[1][0] * WorldPos.x + Matrix[1][1] * WorldPos.y + Matrix[1][2] * WorldPos.z + Matrix[1][3]) * inv_w;

    float screen_x = ScreenCenter.x + (ndc_x * ScreenCenter.x);
    float screen_y = ScreenCenter.y - (ndc_y * ScreenCenter.y);

    ScreenPos.x = screen_x;
    ScreenPos.y = screen_y;

    return true;
}