#include "Pch.hpp"
#include "DMA.hpp"

bool DMA::Init() {
    if (!mem->Init(GAME_NAME)) {
        LOG_ERROR("Failed to initialize DMA");
        return false;
    }
	int errors = 0;

    Globals::ClientBase = mem->GetBaseDaddy(CLIENT_DLL);
    if (!Globals::ClientBase || Globals::ClientBase == NULL) {
        LOG_ERROR("Failed to get ClientBase");
        return false;
    }

    if (!mem->GetKeyboard()->InitKeyboard()) {
        errors++;
        LOG_ERROR("Failed to initialize DMA keyboard (continuing without keyboard support)");
    }

    if (errors > 0) {
        LOG_WARN("DMA initialized with {} errors", errors);
    } else {
		LOG_INFO("DMA initialized successfully");
    }

    ProcInfo::DmaInitialized = true;
    return true;
}
