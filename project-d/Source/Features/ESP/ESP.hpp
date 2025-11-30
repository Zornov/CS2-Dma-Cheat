#pragma once

class ESP {
public:
    void Render(ImDrawList* drawList);

    void Update();
};

inline std::unique_ptr<ESP> esp = std::make_unique<ESP>();