#pragma once
#include <imgui/imgui.h>
#include <Timer/Timer.hpp>

class Aimbot {
public:
    void Render(ImDrawList* drawList);

    void Update();
};

inline std::unique_ptr<Aimbot> aimbot = std::make_unique<Aimbot>();