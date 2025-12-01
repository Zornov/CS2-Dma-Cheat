#pragma once
#include <imgui/imgui.h>
#include <string>

namespace Structs{
    struct KmboxConfig {
        bool Enabled = false;
        std::string Ip = "127.0.0.1";
        unsigned short Port = 6969;
        std::string Uuid = "00000000-0000-0000-0000-000000000000";
    };

    struct AimConfig {
        bool Trigger = false;
        int TriggerKey = 0;
        int TriggerKeyMode = 0;
        int TriggerDelay = 0;

        bool Aimbot = false;

        bool DrawFov = false;
        ImVec4 AimbotFovColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

        bool AimFriendly = false;
        bool AimVisible = false;

        int AimbotKey = 0;
        int AimbotKeyMode = 0;
        float AimbotFov = 0.0f;
        float AimbotSmooth = 0.0f;
    };

    struct VisualsConfig {
        bool Enabled = true;
        bool TeamCheck = false;
        bool VisibleCheck = false;

        bool Background = false;
    };

    struct MiscConfig {
        bool VSync = false;
    };
}
