#pragma once
#include <imgui/imgui.h>
#include <Timer/Timer.hpp>

class Aimbot {
    void Render(ImDrawList* drawList);

public:
    void Update(ImDrawList* drawList) {
        TIMER("Aimbot update");

        TIMER("Aimbot render");
        Render(drawList);
    }

    static Aimbot& Get() {
        static Aimbot instance;
        return instance;
    }
};

inline Aimbot& aimbot = Aimbot::Get();