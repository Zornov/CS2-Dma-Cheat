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
        bool Trigger;
        int TriggerKey;
        int TriggerKeyMode;
        int TriggerDelay;

        bool Aimbot;

        bool DrawFov;
        ImVec4 AimbotFovColor;

        bool AimFriendly;
        bool AimVisible;

        int AimbotKey;
        int AimbotKeyMode;
        float AimbotFov;
        float AimbotSmooth;
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
