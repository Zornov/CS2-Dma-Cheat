#pragma once
#include <Memory/Memory.h>

class DMA {
public:

	bool Init();

};

inline std::unique_ptr<DMA> dma = std::make_unique<DMA>();