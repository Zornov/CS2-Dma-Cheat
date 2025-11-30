#include <Pch.hpp>
#include <SDK.hpp>
#include "ESP.hpp"
#include <string>

void ESP::Render(ImDrawList* drawList) {

    // 0x3ECC

    auto localPlayerController = mem.Read<uintptr_t>(Globals::ClientBase + cs2_dumper::offsets::client_dll::dwLocalPlayerController);
    localPlayerController = mem.Read<uintptr_t>(localPlayerController);

	int health = mem.Read<bool>(localPlayerController + 0x904);

    Renderer::Text(
        drawList,
        ScreenCenter.x,
        ScreenCenter.y,
        0.f, 0.f,
        std::to_string(health),
        ImVec4(255, 255, 255, 255)
    );
}