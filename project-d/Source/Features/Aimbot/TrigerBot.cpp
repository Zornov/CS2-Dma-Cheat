#include <Pch.hpp>
#include <SDK.hpp>
#include "TrigerBot.hpp"
#include <Windows.h>

void TriggerBot::Render(ImDrawList* drawList) {
    // No rendering needed for TriggerBot
}

void TriggerBot::Update() {
    if (!config->Aim.Trigger)
        return;

    if (!(GetAsyncKeyState(config->Aim.TriggerKey) & 0x8000))
        return;

    //int m_iIDEntIndex = sdk->localPlayerPawn->m_iIDEntIndex;

    //if (m_iIDEntIndex != -1) {
    //    INPUT input = { 0 };
    //    input.type = INPUT_MOUSE;
    //    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    //    SendInput(1, &input, sizeof(INPUT));

    //    ZeroMemory(&input, sizeof(INPUT));
    //    input.type = INPUT_MOUSE;
    //    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    //    SendInput(1, &input, sizeof(INPUT));
    //}
}
