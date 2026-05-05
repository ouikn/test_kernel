static constexpr float 文字偏移 = 55.0f;
static constexpr float 圆点大小 = 13.0f;
static constexpr float 圆点Y坐标 = 30.0f;
static constexpr float 水平间距 = 32.0f;
static constexpr int 圆点总数 = 3;

static constexpr float 文字内边距 = 20.0f;
static constexpr float 错误背景高度 = 40.0f;
static constexpr float 文字大小 = 50.0f;
static constexpr float 阴影偏移 = 2.0f;

static constexpr float 阴影角度步长 = 3.1415926f / 4.0f;
static constexpr ImVec2 子窗口尺寸(650, 250);
static constexpr ImVec2 按钮尺寸(200, 80);
static constexpr ImVec2 按钮偏移(100, 33);
static constexpr float 目标宽度 = 990.0f;
static constexpr float 目标高度 = 930.0f;
static constexpr float 动画圆角 = 15.0f;

static const ImColor 圆点颜色[圆点总数] = {
    ImColor(255, 50, 0, 255),
    ImColor(255, 240, 30, 255),
    ImColor(50, 255, 50, 255)
};
static const float 圆点半径 = 13.2f;
static const float 圆点间距 = 9.0f;
static ImVec2 圆点位置[圆点总数];
static const char* 错误信息 = "矩阵获取失败，请重启辅助或获取数据试试";

static float errorBgWidth = 0.0f;
static float errorBgHeight = 0.0f;
static float targetBgWidth = 0.0f;
static float targetBgHeight = 0.0f;
static float bgAnimationSpeed = 0.1f;
static ImVec2 窗口拖拽偏移 = ImVec2(0, 0);
static bool 正在拖拽 = false;

static int 当前标签 = 0;
static int 目标标签 = 0;
static float 标签动画进度 = 0.0f;
static constexpr float 标签动画速度 = 1.5f/15.0f;
static ImVec2 当前标签位置 = ImVec2(0, 0);
static ImVec2 当前标签尺寸 = ImVec2(0, 0);
static ImVec2 目标标签位置 = ImVec2(0, 0);
static ImVec2 目标标签尺寸 = ImVec2(0, 0);
void Draw_Meun() {
    Lerp(wh["win_y_1"].beg, wh["win_y_1"].end, 0.04f);
    Lerp(wh["win_y_2"].beg, wh["win_y_2"].end, 0.04f);

    wh["win_y_1"].end = (Tab == 0) ? 780 : (Tab == 1) ? 0 : 0;
    wh["win_y_2"].end = (Tab == 0) ? 780 : (Tab == 1) ? 780 : 0;
    wh["1win_y_1"].end = (Tab1 == 0) ? 780 : (Tab1 == 1) ? 0 : 0;
    wh["1win_y_2"].end = (Tab1 == 0) ? 780 : (Tab1 == 1) ? 780 : 0;

    if (开关) {
        float 窗口居中X = (screen_x - 目标宽度) / 2.0f;
        float 窗口居中Y = (screen_y - 目标高度) / 2.0f;
        float 最终X = 窗口居中X + 窗口拖拽偏移.x;
        float 最终Y = 窗口居中Y + 窗口拖拽偏移.y;
        
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 动画圆角);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::SetNextWindowPos(ImVec2(最终X, 最终Y), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(目标宽度, 目标高度), ImGuiCond_Always);
    
        if (window) {
            zhu_set();
            if (ImGui::Begin("繁华奚落", &window, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar)) {
                ImGui::PopStyleVar();
                ImGui::PopStyleColor();
                float aevrage = ImGui::GetWindowSize().x / 6.302521f;
                ImGui::SetCursorPos(ImVec2(0, 20 - 0.2f));
                ImGui::BeginChild("左侧标题", ImVec2(aevrage*1.78, 754), true);
                {
                    if (ImGui::IsWindowHovered() && ImGui::IsMouseDragging(ImGuiMouseButton_Left)) {
                        正在拖拽 = true;
                        窗口拖拽偏移.x += ImGui::GetIO().MouseDelta.x;
                        窗口拖拽偏移.y += ImGui::GetIO().MouseDelta.y;
                    } else {
                        正在拖拽 = false;
                    }
                    
                    ImDrawList* drawList = ImGui::GetWindowDrawList();
                    drawList->AddRectFilled(ImGui::GetWindowPos(), ImGui::GetWindowPos() + ImGui::GetWindowSize(), ImColor(175, 175, 175, 230), 15.0f, ImDrawFlags_RoundCornersLeft);
                    
                    ImVec2 窗口位置 = ImGui::GetWindowPos();
                    for (int i = 0; i < 圆点总数; ++i) {
                        圆点位置[i] = ImVec2(窗口位置.x + 18 + i * (圆点半径*2 + 圆点间距), 窗口位置.y + 25);
                        drawList->AddCircleFilled(圆点位置[i], 圆点半径, 圆点颜色[i]);
                        drawList->AddCircle(圆点位置[i], 圆点半径, IM_COL32(150, 150, 150, 255), 0, 1.5f);
                    }
                    
                    float line_x = 窗口位置.x + 275;
                    drawList->AddLine(ImVec2(line_x, 窗口位置.y), ImVec2(line_x, 窗口位置.y + ImGui::GetWindowSize().y), IM_COL32(80, 80, 80, 255), 4.0f);
                    
                    DrawLogo(logo_png, ImGui::GetWindowPos() + ImVec2(aevrage/1.944444f + 20, 100), 135);
                    
                    ImVec2 rect_min = ImGui::GetWindowPos() + ImVec2(15, 215);
                    ImVec2 rect_size(ImGui::GetWindowSize().x - 30, 50);
                    drawList->AddRectFilled(rect_min, ImVec2(rect_min.x + rect_size.x, rect_min.y + rect_size.y), ImGui::GetColorU32(ImVec4(1.0f, 1.0f, 1.0f, 1.0f)), 50.0f);
                    drawList->AddImage(驱动_png, ImVec2(rect_min.x + 5, rect_min.y + 5), ImVec2(rect_min.x + 45, rect_min.y + 45));
                    drawList->AddText(ImGui::GetFont(), 0.9f * ImGui::GetFontSize(), ImVec2(rect_min.x + 49, rect_min.y + 7), ImGui::GetColorU32(ImVec4(0, 0, 0, 1)), "驱动加载失败");
                    drawList->AddCircleFilled(ImVec2(rect_min.x + 49 + ImGui::CalcTextSize("驱动加载成功").x, rect_min.y + 27.5), 7.5f, ImGui::GetColorU32(ImVec4(0, 1, 0, 1)));
                    
                    ImVec2 rect_min2(rect_min.x, rect_min.y + rect_size.y + 10);
                    drawList->AddRectFilled(rect_min2, ImVec2(rect_min2.x + rect_size.x, rect_min2.y + rect_size.y), ImGui::GetColorU32(ImVec4(1.0f, 1.0f, 1.0f, 1.0f)), 50.0f);
                    drawList->AddImage(安卓_png, ImVec2(rect_min2.x + 6, rect_min2.y + 6), ImVec2(rect_min2.x + 46, rect_min2.y + 46));
                    
                    char version_text[256];
                    snprintf(version_text, sizeof(version_text), "版本: %s", android_version.c_str());
                    drawList->AddText(ImGui::GetFont(), 0.91f * ImGui::GetFontSize(), ImVec2(rect_min2.x + 50, rect_min2.y + 6), ImGui::GetColorU32(ImVec4(0, 0, 0, 1)), version_text);

                    ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(0,0,0,0));
                    ImGui::Separator();
                    ImGui::PopStyleColor();
                    
                    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);
                    float buttonHeight = (ImGui::GetContentRegionAvail().y - 20) / 6.0f;
                    
                    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 15.0f);
                    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, buttonHeight*0.6f));
                    ImGui::Text("");
                    ImGui::Text("");
                    
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
                ImGui::EndChild();
                ImGui::PopStyleVar(2);  
                ImGui::End();
            }
        }
        ImGui::PopStyleVar(2); 
    } else {
        windows = 0;
    }
    人数显示();
}

void 主页_1() {
    TouchScroll(true);
    CenteredText("声明与须知", 1.5f);
    float windowHeight = ImGui::GetContentRegionAvail().y;
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + windowHeight * 0.18f);
    float windowWidth = ImGui::GetContentRegionAvail().x;
    ImGui::PushTextWrapPos(windowWidth);
    float 偏移量 = windowWidth * 0.4f;    
    i(0); ImGui::SetCursorPosX(偏移量); Y();
    i(1); ImGui::Text("   关于利益问题：\n"); Y();
    i(2); ImGui::SetCursorPosX(偏移量); Y();
    i(3); ImGui::Text("本产品无任何收费以及内部等\n切勿被骗，开发者不会主动联\n系你，更不会同你索要财务\n"); Y();
    
    i(4); ImGui::SetCursorPosX(偏移量); Y();
    i(5); ImGui::Text("   关于使用问题：\n"); Y();
    i(6); ImGui::SetCursorPosX(偏移量); Y();
    i(7); ImGui::Text("本作品仅限于交流学习，使用\n者的任何行为与应用开发者无\n关，请在二十四小时内副除本\n应用[下载代表同意本协议]\n"); Y();
    
    i(8); ImGui::SetCursorPosX(偏移量); Y();
    i(9); ImGui::Text("   关于隐私问题：\n"); Y();
    i(10); ImGui::SetCursorPosX(偏移量); Y();
    i(11); ImGui::Text("本作品不会收集用户约任何隐\n私，包括但不限于账号、IMEI\n更不会存在上传行"); Y();
    
    ImGui::PopTextWrapPos();
}

void 绘制_1() {
CenteredText("绘图", 1.5f);
ImGui::Separator();
    if (ImGui::BeginChild("绘制页面1", ImVec2(0, ImGui::GetContentRegionAvail().y - 10), false, ImGuiWindowFlags_NoBackground)) {
        TouchScroll(true);
        DrawSectionWithItems("  人物类型绘制", []() {
            Toggle("  方框", DrawIo[1]);
            CustomSeparator();
            Toggle("  骨骼", DrawIo[3]);
            CustomSeparator();
            Toggle("  射线", DrawIo[2]);
            CustomSeparator();
            Toggle("  血量", DrawIo[6]);
            CustomSeparator();
            Toggle("  头甲", DrawIo[50]);
            CustomSeparator();
            Toggle("  人机", DrawIo[17]);
            CustomSeparator();
            Toggle("  手持", DrawIo[10]);

        }, 14);
        ImGui::Text("");
        ImGui::Text("");
        DrawSectionWithItems("  非人物类型绘制", []() {
            Toggle("  背敌", DrawIo[8]);
            CustomSeparator();
            Toggle("  手雷", DrawIo[14]);
            CustomSeparator();
            Toggle("  忽地", DrawIo[32]);
        }, 6);
        
        ImGui::Text("");
        DrawSectionWithItems("", []() {
            vector<string> triggerOptions = {"分格", "矩形", "传统"};
            whitecloud(triggerOptions, draw_style[1], 1, 120.0f);
        }, 3);
        ImGui::Text("");
        ImGui::EndChild();
    }
}

void 自瞄_1() {
    CenteredText("自 瞄", 1.5f);
    ImGui::Separator();
    ImGui::BeginChild("ScrollRegion", ImVec2(0, ImGui::GetContentRegionAvail().y - 10), false);
    {
        TouchScroll(true);
        DrawSectionWithItems("  自瞄功能", []() {
            Toggle("  自瞄总开关", DrawIo[20]);
            CustomSeparator();
            Toggle("  显示自瞄圈", DrawIo[45]);
            CustomSeparator();
            Toggle("  触摸位置", DrawIo[21]);
            CustomSeparator();
            Toggle("  动态范围", DrawIo[25]);
            CustomSeparator();
            Toggle("  预瞄位置", DrawIo[49]);
            CustomSeparator();
            Toggle("  锁定目标", DrawIo[30]);
            CustomSeparator();
            Toggle("  狙击自瞄", DrawIo[31]);
            CustomSeparator();
            Toggle("  喷子自瞄", DrawIo[41]);
             }, 16);
             ImGui::Text("");
             ImGui::Text("");
            DrawSectionWithItems("  多种参数", []() {
            Toggle("  指哪打哪", DrawIo[39]);
            CustomSeparator();
            Toggle("  被瞄预警", DrawIo[89]);
        }, 4);
        ImGui::Text("");
        DrawSectionWithItems("", []() {
            vector<string> 自瞄部位 = {"头部", "胸部"}; 
            whitecloud(自瞄部位, NumIo[8], 2, 120.0f);
            }, 3);
            ImGui::Text("");
            DrawSectionWithItems("  瞄准设置", []() {
            SliderFloat("预判", &NumIo[22], 0.1f, 5.0f, "%.1f", 5);
            SliderFloat("范围", &NumIo[3], 10.0f, 350.0f, "%1.f");
            SliderFloat("平滑", &NumIo[9], 1.0f, 50.0f, "%0.1f");
            SliderFloat("速度", &NumIo[4], 1.0f, 30.0f, "%0.1f");
            SliderFloat("触摸", &NumIo[7], 50.01f, 400.0f, "%0.2f");
            SliderFloat("压枪", &NumIo[14], 0.1f, 5.0f, "%.1f", 5);
            }, 13);
            ImGui::Text("");
            DrawSectionWithItems("特殊设置", []() {
            SliderFloat("喷子距离限制", &NumIo[33], 0.0f, 50.0f, "%.1f", 5);
            vector<string> 喷子梓喵 = {"腰射", "开镜"}; 
            whitecloud(喷子梓喵, NumIo[34], 1, 120.0f);
            ImGui::Text("");
            ImGui::Text("");
        }, 6);
    }
 ImGui::EndChild();
}
void 设置_1() {
    CenteredText("设置", 1.5f);
    ImGui::Separator();
    ImGui::BeginChild("ScrollRegion", ImVec2(0, ImGui::GetContentRegionAvail().y - 10), false);
    {
        TouchScroll(true);
        DrawSectionWithItems("  主要的设置", []() {
            bool 当前无后台状态 = (access("/sdcard/无后台", F_OK) == 0);
            bool 当前防录屏状态 = (access("/sdcard/防录屏", F_OK) == 0);
            bool 无后台新状态 = 当前无后台状态;
            bool 防录屏新状态 = 当前防录屏状态;
            Toggle("  脱离后台运行", 无后台新状态);
            CustomSeparator();
            Toggle("  防止录屏[14-15]", 防录屏新状态);
            if (无后台新状态) {
                int fd = open("/sdcard/无后台", O_CREAT | O_RDWR, 0644);
                close(fd);
            } else {
                unlink("/sdcard/无后台");
            }
            if (防录屏新状态) {
                int fd = open("/sdcard/防录屏", O_CREAT | O_RDWR, 0644);
                close(fd);
            } else {
                unlink("/sdcard/防录屏");
            }
        }, 4);
        
        DrawSectionWithItems("", []() {
            float buttonWidth = ImGui::GetContentRegionAvail().x * 0.9f;
            float buttonPosX = (ImGui::GetContentRegionAvail().x - buttonWidth) / 2.0f;
            ImGui::SetCursorPosX(buttonPosX);
            if (button("链接数据", ImVec2(buttonWidth, 63), 12.0)) {
                GetBase();
            }
            CustomSeparator();
            ImGui::SetCursorPosX(buttonPosX);
            if (button("退出 & 保存配置", ImVec2(buttonWidth, 63), 12.0f)) {
                NumIoSave("繁华配置");
                exit(0);
            }
        }, 5);
    }
    ImGui::EndChild();
}

void 物资_1() {
    CenteredText("物 资", 1.5f);
    ImGui::Separator();
    ImGui::BeginChild("ScrollRegion", ImVec2(0, ImGui::GetContentRegionAvail().y - 10), false);
    {
    TouchScroll(true);
        DrawSectionWithItems("", []() {
            Toggle("  载具", 物资[1]);
            CustomSeparator();
            Toggle("  盒子", 物资[45]);
            CustomSeparator();
            Toggle("  宝箱状态", DrawIo[910]);
             }, 6);
             ImGui::Text("");
             DrawSectionWithItems("", []() {
            Toggle("  宝箱", 物资[18]);
            CustomSeparator();
            Toggle("  信号枪", 物资[3]);
            CustomSeparator();
            Toggle("  空投", 物资[9]);
                }, 6);
                ImGui::Text("");
              DrawSectionWithItems("", []() {  
            Toggle("  金插", 物资[4]);
            CustomSeparator();
            Toggle("  BOOS", 物资[69]);
            CustomSeparator();
            Toggle("  超级物资", 物资[60]);
            CustomSeparator();
            Toggle("  内鬼显示", 物资[21]);
            ImGui::Text("");
        }, 8);
    }
  ImGui::EndChild();
}
void 人数显示() {
    const float 中心X = screen_x * 0.5f;
    const float 半间距 = (水平间距 * (圆点总数 - 1)) * 0.5f;
    const float 起始X = 中心X - 半间距;    
    ImDrawList* 绘图列表 = ImGui::GetForegroundDrawList();
    UpdateAnimation(errorBgWidth, targetBgWidth, bgAnimationSpeed);
    UpdateAnimation(errorBgHeight, targetBgHeight, bgAnimationSpeed);
    if (!fanhua.libUE4) {
        const ImVec2 文字尺寸 = ImGui::CalcTextSize(错误信息);
        if (targetBgWidth != 文字尺寸.x + 文字内边距 * 2 || 
            targetBgHeight != 错误背景高度) {
            targetBgWidth = 文字尺寸.x + 文字内边距 * 2;
            targetBgHeight = 错误背景高度;
        }
        const ImVec2 背景最小(中心X - errorBgWidth * 0.5f, 150 - errorBgHeight * 0.5f);
        const ImVec2 背景最大(中心X + errorBgWidth * 0.5f, 150 + errorBgHeight * 0.5f);
        绘图列表->AddRectFilled(背景最小, 背景最大, ImColor(0, 255, 0, 230), errorBgHeight * 0.5f);
        绘图列表->AddText(ImVec2(中心X - 文字尺寸.x * 0.5f, 150 - 文字尺寸.y * 0.5f), ImColor(255, 255, 255), 错误信息);
    }
    if (!开关) {
        for (int i = 0; i < 圆点总数; ++i) {
            绘图列表->AddCircleFilled(ImVec2(起始X + i * 水平间距, 圆点Y坐标),圆点大小,圆点颜色[i]);
        }
    }
    auto 渲染带阴影文字 = [&](int 数量, float X偏移, const ImColor& 颜色) {
        char 文字缓冲[16];
        snprintf(文字缓冲, sizeof(文字缓冲), "%d", 数量);
        const ImVec2 文字尺寸 = ImGui::GetFont()->CalcTextSizeA(文字大小, FLT_MAX, -1, 文字缓冲);
        const float 文字Y = 73.5f - 文字尺寸.y * 0.5f;
        const ImVec2 基础位置(中心X - 文字尺寸.x * 0.5f + X偏移, 文字Y);
        for (int i = 0; i < 8; ++i) {
            const float 角度 = i * 阴影角度步长;
            const ImVec2 阴影偏移量(cosf(角度) * 阴影偏移, sinf(角度) * 阴影偏移);
            绘图列表->AddText(nullptr, 文字大小, 基础位置 + 阴影偏移量, ImColor(0, 0, 0, 255), 文字缓冲);
        }
        绘图列表->AddText(nullptr, 文字大小, 基础位置, 颜色, 文字缓冲);
    };
    if (fanhua.PlayerCount >= 0) {
        渲染带阴影文字(fanhua.PlayerCount, -文字偏移, ImColor(255, 0, 0, 255));
    }
    if (fanhua.BotCount >= 0) {
        渲染带阴影文字(fanhua.BotCount, 文字偏移, ImColor(0, 255, 0, 240));
    }
    static const ImVec4 透明(0.0f, 0.0f, 0.0f, 0.0f);
    static const ImGuiCol 样式颜色[] = {
        ImGuiCol_WindowBg, ImGuiCol_Border, ImGuiCol_BorderShadow,
        ImGuiCol_Button, ImGuiCol_ButtonHovered, ImGuiCol_ButtonActive
    };
    for (auto 颜色 : 样式颜色) {
        ImGui::PushStyleColor(颜色, 透明);
    }
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 100);
    ImGui::SetNextWindowPos(ImVec2(中心X - 子窗口尺寸.x * 0.5f, 0));
    ImGui::SetNextWindowSize(子窗口尺寸);
    if (ImGui::Begin("人数显示控制", nullptr, 
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | 
        ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse)) {
        ImGui::SetCursorPos(ImVec2(子窗口尺寸.x * 0.5f - 按钮偏移.x, 按钮偏移.y));
        if (ImGui::Button("", 按钮尺寸)) {
            开关 = !开关;
        }
    }
    ImGui::End();
    ImGui::PopStyleVar();
    ImGui::PopStyleColor(sizeof(样式颜色)/sizeof(样式颜色[0]));
}
