#include <Pch.hpp>
#include <SDK.hpp>
#include "Aimbot.hpp"

void Aimbot::Render(ImDrawList* drawList) {
	if (!config.Aim.Aimbot) return;


	if (config.Aim.DrawFov) {
		Renderer::DrawCircle(drawList, ScreenCenter.x, ScreenCenter.y, config.Aim.AimbotFov, config.Aim.AimbotFovColor, 0.2f);
	}
}