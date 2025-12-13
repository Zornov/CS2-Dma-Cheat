#pragma once

#include <imgui/imgui.h>
#include <string>
#include <memory>

namespace Structs {

    struct KmboxConfig {
        bool Enabled = false;
        std::string Ip = "192.168.2.188";
        unsigned short Port = 61697;
        std::string Uuid = "FF313CAB";
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
        bool AimVisible = true;

        int AimbotKey = 0;
        int AimbotKeyMode = 0;
        float AimbotFov = 90.0f;
        float AimbotSmooth = 0.5f;
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
