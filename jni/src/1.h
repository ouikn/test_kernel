                    const char* buttons[] = {"主页声明", "绘制图画", "触摸瞄准", "我的物资", "程序设置"};
                    ImTextureID buttons_icons[] = {主页_png, 绘图_png, 瞄准_png, 物资_png, 设置_png};
                    
                    if (标签动画进度 < 1.0f) {
                        标签动画进度 += 标签动画速度;
                        float easedProgress = 标签动画进度 < 0.5f ? 2.0f * 标签动画进度 * 标签动画进度 : 1.0f - pow(-2.0f * 标签动画进度 + 2.0f, 2.0f) * 0.5f;
                        if (标签动画进度 > 1.0f) {
                            标签动画进度 = 1.0f;
                            当前标签 = 目标标签;
                        }
                    }
                    
                    for (int i = 0; i < 5; i++) {
                        ImVec2 cursorPos = ImGui::GetCursorPos();
                        float iconSize = buttonHeight * 0.6f;
                        float iconPadding = buttonHeight * 0.2f;
                        float availableWidth = ImGui::GetContentRegionAvail().x;
                        ImVec2 buttonSize(availableWidth * 0.95f, buttonHeight);
                        ImVec2 buttonPos = ImGui::GetCursorScreenPos();
                        
                        if (i == 当前标签) {
                            当前标签位置 = buttonPos;
                            当前标签尺寸 = buttonSize;
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
                        }
                        if (i == 目标标签) {
                            目标标签位置 = buttonPos;
                            目标标签尺寸 = buttonSize;
                        }
                        
                        ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.5f + (iconSize + iconPadding) / (2 * buttonSize.x), 0.5f));
                        std::string buttonText = "    " + std::string(buttons[i]);
                        if (button(buttonText.c_str(), buttonSize)) {
                            if (i != 当前标签) {
                                目标标签 = i;
                                标签动画进度 = 0.0f;
                                Tab = i;
                            }
                        }
                        ImGui::PopStyleVar();
                        
                        if (i == 当前标签) {
                            ImGui::PopStyleColor();
                        }
                        
                        drawList->AddImage(buttons_icons[i], ImVec2(buttonPos.x + iconPadding, buttonPos.y + (buttonHeight - iconSize) * 0.5f), ImVec2(buttonPos.x + iconPadding + iconSize, buttonPos.y + (buttonHeight - iconSize) * 0.5f + iconSize), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255));
                    }
                    
                    if (标签动画进度 < 1.0f) {
                        float easedProgress = 标签动画进度 < 0.5f ? 2.0f * 标签动画进度 * 标签动画进度 : 1.0f - pow(-2.0f * 标签动画进度 + 2.0f, 2.0f) * 0.5f;
                        ImVec2 animPos = ImLerp(当前标签位置, 目标标签位置, easedProgress);
                        ImVec2 animSize = ImLerp(当前标签尺寸, 目标标签尺寸, easedProgress);
                        drawList->AddRectFilled(animPos, ImVec2(animPos.x + animSize.x, animPos.y + animSize.y), ImColor(0, 0, 0, static_cast<int>(std::clamp(80 * (0.7f + 0.3f * cosf(标签动画进度 * IM_PI)), 0.0f, 255.0f))), 15.0f);
                    } else if (当前标签 >= 0 && 当前标签 < 5) {
                        drawList->AddRectFilled(当前标签位置, ImVec2(当前标签位置.x + 当前标签尺寸.x, 当前标签位置.y + 当前标签尺寸.y), ImColor(0, 0, 0, 50), 12.0f);
                    }
                    
                    ImGui::PopStyleVar(2);
                }
                ImGui::EndChild();
                
                float rightWidth = aevrage * 4.53f;
                ImGui::SetCursorPos(ImVec2(aevrage*1.5 + 42.0f, 20));
                ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 20.0f);
                ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 0.0f);
                ImGui::BeginChild("右侧内容", ImVec2(rightWidth, 752), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoBackground);
                {
                    ImDrawList* drawList = ImGui::GetWindowDrawList();
                    ImVec2 windowPos = ImGui::GetWindowPos();
                    ImVec2 windowSize = ImGui::GetWindowSize();
                    
                    drawList->AddRectFilled(windowPos, windowPos + windowSize, ImColor(255, 255, 255, 255), 12.0f, ImDrawFlags_RoundCornersTopRight | ImDrawFlags_RoundCornersBottomRight);
                    drawList->AddImageRounded(背景_png, windowPos, windowPos + windowSize, ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 220), 12.0f, ImDrawFlags_RoundCornersTopRight | ImDrawFlags_RoundCornersBottomRight);
                    
                    ImGui::BeginChild("内容区域", ImVec2(rightWidth, 752), true);
                    {
                        switch (Tab) {
                            case 0: 主页_1(); break;
                            case 1: 绘制_1(); break;
                            case 2: 自瞄_1(); break;
                            case 3: 物资_1(); break;
                            case 4: 设置_1(); break;
                        }
                    }
                    ImGui::EndChild();
                }