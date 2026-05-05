void DrawHealth(Vec2 box, float w, float i血量, uint32_t 队伍ID, const char* name) {
    if (!DrawIo[6]) return;
    const float x = box.x;
    const float y = box.y - (draw_style[1] == 0 ? 30.0f : draw_style[1] == 1 ? 20.0f : 15.0f);
    const float distance = fanhua.Distance;
    const int style = static_cast<int>(draw_style[1]);
    auto* drawList = ImGui::GetBackgroundDrawList();
    static const ImColor white = ImColor(255, 255, 255, 255);
    static const ImColor black = ImColor(0, 0, 0, 255);
    static const ImColor purple = ImColor(128, 0, 128, 255);
    static const ImColor yellow = ImColor(255, 255, 0, 255);
    static const ImColor lightBlue = ImColor(173, 216, 230, 255);
    static const ImColor semiBlack = ImColor(0, 0, 0, 112);
    static const float outlineThickness = 1.5f;
    static const float baseFontSize = 20.0f;
    static char combinedText[128];
    static char distanceText[32];
    switch (style) {
        case 0: { 
            snprintf(combinedText, sizeof(combinedText), "%d.%s", 队伍ID, name);
            const auto combinedSize = ImGui::GetFont()->CalcTextSizeA(baseFontSize, FLT_MAX, -1, combinedText);
            const float textX = x - (combinedSize.x / 2);
            const float textY = y - combinedSize.y - 5;
            DrawTf.绘制字体描边(baseFontSize, textX, textY, white, combinedText);
            const float healthBarX = x - 37;
            const float healthBarY = y - 2;
            drawList->AddRect(ImVec2(healthBarX, healthBarY), ImVec2(healthBarX + 74, healthBarY + 10), lightBlue, 0.0f, 0, outlineThickness);
            if (i血量 > 0) {
                drawList->AddLine(ImVec2(healthBarX + 2, healthBarY + 5), ImVec2(healthBarX + 2 + i血量 * 0.7, healthBarY + 5),white, 6.f);
            }
            const float segmentStart = healthBarX + 2;
            for (int i = 0; i < 5; ++i) {
                const float segmentX = segmentStart + i * 14;
                drawList->AddRect(ImVec2(segmentX, healthBarY + 2), ImVec2(segmentX + 14, healthBarY + 8), black, 0.0f, 0, outlineThickness);
            }
            break;
        }
        case 1: { 
            static constexpr float healthBarLength = 180.0f;
            static constexpr float healthBarHeight = 5.0f;
            static constexpr float idBoxWidth = 30.0f;
            static constexpr float padding = 5.0f;
            static constexpr float totalWidth = healthBarLength + idBoxWidth + padding;
            const float startX = x - totalWidth/2;  
            drawList->AddRectFilled(ImVec2(startX, y - 42),ImVec2(startX + totalWidth, y - 11),  semiBlack, 4, 0);
            drawList->AddRectFilled(ImVec2(startX, y - 42), ImVec2(startX + idBoxWidth, y - 11), purple, 4, 0);
            snprintf(combinedText, sizeof(combinedText), "%d", 队伍ID);
            const auto idSize = ImGui::GetFont()->CalcTextSizeA(baseFontSize, FLT_MAX, -1, combinedText);
            DrawTf.绘制字体描边(baseFontSize, startX + idBoxWidth/2 - idSize.x/2, y - 42 + (idBoxWidth - idSize.y)/2, white, combinedText);
            drawList->AddRectFilled(ImVec2(startX, y - 16), ImVec2(x + totalWidth/2, y - 11), black, 1, 0);
            if (i血量 > 0) {
                drawList->AddRectFilled(ImVec2(startX, y - 16), ImVec2(startX + totalWidth * (i血量 / 100.0f), y - 11), yellow, 1, 0);
            }
            const float nameFontSize = baseFontSize * 0.8f;
            const auto nameSize = ImGui::GetFont()->CalcTextSizeA(nameFontSize, FLT_MAX, -1, name);
            DrawTf.绘制字体描边(nameFontSize, x - nameSize.x/2, y - 38, white, name);
            snprintf(distanceText, sizeof(distanceText), "[%dM]", static_cast<int>(distance));
            const auto distanceSize = ImGui::GetFont()->CalcTextSizeA(baseFontSize, FLT_MAX, -1, distanceText);
            DrawTf.绘制字体描边(baseFontSize, x + totalWidth/2 - distanceSize.x - 5, y - 38, yellow, distanceText);
            break;
        }
case 2:
{
    ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(x, y - 40), 20.0f, ImColor(0, 0, 0, 200), 0, 2.0f);
    float arcAngle = i血量 * 3.6f;
    ImColor healthColor;
    if (i血量 > 70) {
        healthColor = ImColor(0, 255, 0, 255);
    } else if (i血量 > 30) {
        healthColor = ImColor(255, 255, 0, 255);
    } else {
        healthColor = ImColor(255, 0, 0, 255);
    } 
    ImGui::GetBackgroundDrawList()->PathArcTo(ImVec2(x, y - 40), 20.0f, -IM_PI/2, -IM_PI/2 + arcAngle * IM_PI/180, 32);
    ImGui::GetBackgroundDrawList()->PathStroke(healthColor, false, 5.0f);
    
    char distanceText[16];
    sprintf(distanceText, "%d", static_cast<int>(distance));
    auto distanceTextSize = ImGui::GetFont()->CalcTextSizeA(16, FLT_MAX, -1, distanceText);
    DrawTf.绘制字体描边(16, x - distanceTextSize.x/2, y - 40 - distanceTextSize.y/2, ImVec4{255, 255, 255, 255}, distanceText);
    
    snprintf(combinedText, sizeof(combinedText), "%d.%s", 队伍ID, name);
    auto combinedSize = ImGui::GetFont()->CalcTextSizeA(18, FLT_MAX, -1, combinedText);
    DrawTf.绘制字体描边(18, x - combinedSize.x/2, y - 10, ImVec4{255, 255, 255, 255}, combinedText);
    break;
       }
    }
}
