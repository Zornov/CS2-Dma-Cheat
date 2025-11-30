#include "Pch.hpp"
#include "DMA.hpp"

bool DMA::Init() {
    if (!mem.Init(GAME_NAME)) {
        LOG_ERROR("Failed to initialize DMA");
        return false;
    }

    Globals::ClientBase = mem.GetBaseDaddy(CLIENT_DLL);
    if (!Globals::ClientBase || Globals::ClientBase == NULL) {
        LOG_ERROR("Failed to get ClientBase");
        return false;
    }

    if (!mem.GetKeyboard()->InitKeyboard()) {
        LOG_ERROR("Failed to initialize DMA keyboard (continuing without keyboard support)");
    }

    if (!mem.FixCr3()) {
        LOG_ERROR("Failed to fix CR3");
        return false;
    }

    LOG_INFO("DMA successfully initialized");

    ProcInfo::DmaInitialized = true;
    return true;
}
