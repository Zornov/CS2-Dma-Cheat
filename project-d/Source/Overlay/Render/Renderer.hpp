#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"

class Renderer {
public:
    static void Text(ImDrawList* drawList, float x, float y, const std::string& text, const ImVec4& color) {
        ImVec2 pos(x, y);

        drawList->AddText(pos, ImGui::GetColorU32(color), text.c_str());
    }

    static void Text(ImDrawList* drawList, float x, float y, float w, float h, const std::string& text, ImFont* font, const ImVec4& color, float font_size) {
        ImVec2 pos(x, y);
        ImVec2 size(w, h);

        drawList->AddText(font, font_size, pos, ImGui::GetColorU32(color), text.c_str());
    }

    static void DrawRect(ImDrawList* drawList, float x, float y, float w, float h, const ImVec4& color, float thickness) {
        ImVec2 pos(x, y);
        ImVec2 size(w, h);

        drawList->AddRect(pos, ImVec2(pos.x + size.x, pos.y + size.y), ImGui::GetColorU32(color), 0.0f, -1, thickness);
    }

    static void DrawFilledRect(ImDrawList* drawList, float x, float y, float w, float h, const ImVec4& color) {
        ImVec2 pos(x, y);
        ImVec2 size(w, h);

        drawList->AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + size.y), ImGui::GetColorU32(color));
    }

    static void DrawCircle(ImDrawList* drawList, float x, float y, float radius, const ImVec4& color, float thickness) {
        ImVec2 pos(x, y);

        drawList->AddCircle(pos, radius, ImGui::GetColorU32(color), 0, thickness);
    }

    static void DrawFilledCircle(ImDrawList* drawList, float x, float y, float radius, const ImVec4& color) {
        ImVec2 pos(x, y);

        drawList->AddCircleFilled(pos, radius, ImGui::GetColorU32(color));
    }

    static void DrawLine(ImDrawList* drawList, float x1, float y1, float x2, float y2, const ImVec4& color, float thickness) {
        ImVec2 pos1(x1, y1);
        ImVec2 pos2(x2, y2);

        drawList->AddLine(pos1, pos2, ImGui::GetColorU32(color), thickness);
    }

    static void DrawRotatedRect(
        ImDrawList* dl,
        float cx, float cy,
        float w, float h,
        float yawDeg,
        const ImVec4& color,
        float thickness = 1.0f
    ) {
        float yaw = (yawDeg * 3.14159265f) / 180.0f;

        float cs = cosf(yaw);
        float sn = sinf(yaw);

        float hw = w * 0.5f;
        float hh = h * 0.5f;

        ImVec2 pts[4] = {
            ImVec2(-hw, -hh),
            ImVec2(hw, -hh),
            ImVec2(hw,  hh),
            ImVec2(-hw,  hh)
        };

        for (int i = 0; i < 4; i++)
        {
            float x = pts[i].x;
            float y = pts[i].y;

            pts[i].x = cx + (x * cs - y * sn);
            pts[i].y = cy + (x * sn + y * cs);
        }

        dl->AddPolyline(pts, 4, ImGui::GetColorU32(color), true, thickness);
    }

    static inline ImVec4 RGBA(int r, int g, int b, int a = 255) {
        return ImVec4(
            r / 255.f,
            g / 255.f,
            b / 255.f,
            a / 255.f
        );
    }

    static void DrawHitmarker(ImDrawList* drawList, const ImVec4& color, float length = 10.0f, float thickness = 1.0f) {
        ImVec2 center = ImGui::GetIO().DisplaySize * 0.5f;

        // From top left to bottom right
        DrawLine(drawList, center.x - length, center.y - length, center.x - 5.0f, center.y - 5.0f, color, thickness);
        // From top right to bottom left
        DrawLine(drawList, center.x + length, center.y - length, center.x + 5.0f, center.y - 5.0f, color, thickness);
        // From bottom left to top right
        DrawLine(drawList, center.x - length, center.y + length, center.x - 5.0f, center.y + 5.0f, color, thickness);
        // From bottom right to top left
        DrawLine(drawList, center.x + length, center.y + length, center.x + 5.0f, center.y + 5.0f, color, thickness);
    }

    static ImVec4 GetHealthBarColor(int health) {
        const float healthFrac = static_cast<float>(health) / 100.0f;

        float r = 255 * (1.0f - healthFrac);
        float g = 255 * healthFrac;
        float b = 0.0f;
        float a = 255.0f;

        return ImVec4(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
    }

    /**
     * @brief Calculates the alpha value based on the start time and duration.
     * @param start The start time ( GetTickCount64() ).
     * @param duration The duration in milliseconds.
     * @return The calculated alpha value.
     */
    static float CalculateAlpha(unsigned long startTime, unsigned long duration) {
        unsigned long currentTime = GetTickCount64();
        unsigned long elapsedTime = currentTime - startTime;

        if (elapsedTime > duration)
        {
            return 0.0f;
        }

        return 1.0f - (float)elapsedTime / duration;
    }
};