#pragma once

#include <imgui/imgui.h>
#include <Timer/Timer.hpp>
#include <memory>

class TrigerBot {
public:
    void Render(ImDrawList* drawList);

    void Update();
};

inline std::unique_ptr<TrigerBot> triger = std::make_unique<TrigerBot>();