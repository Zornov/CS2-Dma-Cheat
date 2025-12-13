#pragma once

#include "Structs.hpp"

namespace Config {

    struct AppConfig {
        Structs::AimConfig Aim;
        Structs::KmboxConfig Kmbox;
        Structs::VisualsConfig Visuals;
        Structs::MiscConfig Misc;

        bool Init() {
            Kmbox.Enabled = true;
            Visuals.Enabled = true;
            Visuals.Background = false;
            Misc.VSync = false;
            return true;
        }
    };

}

inline std::unique_ptr<Config::AppConfig> config = std::make_unique<Config::AppConfig>();