#pragma once

#include "Structs.hpp"

namespace Config {
    struct AppConfig {
        Structs::AimConfig Aim;
        Structs::KmboxConfig Kmbox;
        Structs::VisualsConfig Visuals;
        Structs::MiscConfig Misc;

        bool Init() {
            Aim.AimbotFovColor = ImVec4(255, 255, 255, 255);

            Kmbox.Enabled = false;
            Kmbox.Ip = "127.0.0.1";
            Kmbox.Port = 6969;
            Kmbox.Uuid = "00000000-0000-0000-0000-000000000000";

            Visuals.Enabled = true;
            Visuals.TeamCheck = false;
            Visuals.VisibleCheck = false;

            Visuals.Background = false;

            Misc.VSync = false;

            return true;
        }
    };
}

inline std::unique_ptr<Config::AppConfig> config = std::make_unique<Config::AppConfig>();