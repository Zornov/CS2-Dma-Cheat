#pragma once
#include <imgui/imgui.h>
#include <string>

namespace Structs{
    struct KmboxConfig {
        bool Enabled;
        std::string Ip;
        unsigned short Port;
        std::string Uuid;
    };

    struct AimConfig {
        bool Aimbot = false;

        bool DrawFov = false;
        ImVec4 AimbotFovColor = ImVec4(255, 255, 255, 255);

        float AimbotFov = 20.0f;
    };

    struct VisualsConfig {
        bool Enabled;
        bool TeamCheck;
        bool VisibleCheck;

        bool Background;
    };

    struct MiscConfig {
        bool VSync;
    };
}
