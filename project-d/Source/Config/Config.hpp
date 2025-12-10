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

            Kmbox.Enabled = true;
            Kmbox.Ip = "192.168.2.188";
            Kmbox.Port = 61697;
            Kmbox.Uuid = "FF313CAB";

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