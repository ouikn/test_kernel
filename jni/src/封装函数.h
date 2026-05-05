#ifndef __IMGUI_WHITECLOUD_H
#define __IMGUI_WHITECLOUD_H
#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <map>
#include <linux/input.h>
#include "imgui.h"
#include <sstream>
using std::string;
float speed = 1.5f;
bool 开关 = true;
bool window = true, windows = true;
bool 增加;
bool 减少;
int Tab,Tab1;
float window_x, window_y, aevrage_now, aevrage_all, 设置_Tab, 人数显示左, 人数显示右;
float tab0, tab1, tab2, tab3, tab4, tab5, tab6, tab_0, tab_1, tab_2, tab_3, tab_4;
float 人数显示大小 = 1.0f;
float homepage, homepages, setup, setups;
void 开启();
void 关闭();
void 主页_1();
void 绘制_1();
void 自瞄_1();
void 设置_1();
void 其他_1();
void 物资_1();
void 人数显示();
void 主页_2();
void 绘制_2();
void 绘制_3();
void 自瞄_2();
void 自瞄_3();
void 自瞄_11();
void 设置_2();
void 设置_3();
void 设置_4();
void 设置_5();
void 设置_6();
void 设置_7();
void 设置_8();
void 设置_11();
struct wc {
int Tab;
float beg, end;
ImColor color;
};   
map<string, wc> wh;
extern map<string, ImColor> Styles;
wc& 位置x = wh["位置_x"];
wc& 位置y = wh["位置_y"];
wc& 窗口x = wh["window_x"];
wc& 窗口y = wh["window_y"];
wc& 人数显示宽度 = wh["人数显示宽度"];
wc& 人数显示高度s = wh["人数显示高度s"];
wc& 人数显示高度x = wh["人数显示高度x"];
ImVec2 operator+(const ImVec2& a, const ImVec2& b) {
    return ImVec2(a.x + b.x, a.y + b.y);
}
ImVec2 operator-(const ImVec2& a, const ImVec2& b) {
    return ImVec2(a.x - b.x, a.y - b.y);
}
ImVec2 operator*(const ImVec2& a, const float& b) {
    return ImVec2(a.x * b, a.y * b);
}
ImVec2 operator/(const ImVec2& a, const float& b) {
    return ImVec2(a.x / b, a.y / b);
}
ImVec4 operator+(const ImVec4& lhs, const ImVec4& rhs) {
    return ImVec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}
ImVec4 operator-(const ImVec4& lhs, const ImVec4& rhs) {
    return ImVec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}
ImVec4 operator*(const ImVec4& lhs, const ImVec4& rhs) {
    return ImVec4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}
ImVec4 operator/(const ImVec4& lhs, const ImVec4& rhs) {
    return ImVec4(rhs.x != 0? lhs.x / rhs.x : 0, rhs.y != 0? lhs.y / rhs.y : 0, rhs.z != 0? lhs.z / rhs.z : 0, rhs.w != 0? lhs.w / rhs.w : 0);
}
ImVec4 operator+=(ImVec4& lhs, const ImVec4& rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;
    return lhs;
}
ImColor operator+(const ImColor& lhs, const ImColor& rhs) {
    ImVec4 result = lhs.Value + rhs.Value;
    return ImColor(result);
}
ImColor operator-(const ImColor& lhs, const ImColor& rhs) {
    ImVec4 result = lhs.Value - rhs.Value;
    return ImColor(result);
}
ImColor operator*(const ImColor& lhs, const ImColor& rhs) {
    ImVec4 result = lhs.Value * rhs.Value;
    return ImColor(result);
}
ImColor operator/(const ImColor& lhs, const ImColor& rhs) {
    ImVec4 result = lhs.Value / rhs.Value;
    return ImColor(result);
}
void Lerp(float& a, const float& b, float t) {
    a += (b - a) * (t * speed);
}
void window_set() {
    ImGuiStyle & style = ImGui::GetStyle();
    ImGui::StyleColorsLight();
    style.Colors[ImGuiCol_WindowBg] = ImVec4(240.0f/255.0f, 240.0f/255.0f, 240.0f/255.0f, 0.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.92f, 0.92f, 0.92f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.94f, 0.94f, 0.94f, 1.0f);    
    style.Colors[ImGuiCol_FrameBg] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.98f, 0.98f, 0.98f, 1.0f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.96f, 0.96f, 0.96f, 1.0f);  
    style.Colors[ImGuiCol_Button] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(74, 146, 255, 255);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(74, 146, 255, 255);  
    style.Colors[ImGuiCol_Text] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.6f, 0.6f, 0.6f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.WindowBorderSize = 0.0f;
    style.Colors[ImGuiCol_Border] = ImVec4(0, 0, 0, 0);
    style.WindowRounding = 12.0f;
    style.ChildRounding = 20.0f;
    style.FrameRounding = 8.0f;
    style.PopupRounding = 8.0f;
    style.ScrollbarSize = 20.0f;
    style.ScrollbarRounding = 8.0f;
    style.GrabMinSize = 8.0f;
    style.GrabRounding = 8.0f;
    style.ScaleAllSizes(1.0f);
}
void zhu_set() {
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 25.0f);
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.8f, 0.8f, 0.8f, 0.0f));
}
void CenteredText(const char* text, float customScale = 1.0f) {
    ImGui::PushFont(ImGui::GetFont());
    float fontSize = ImGui::GetFontSize() * customScale;
    ImVec2 textSize = ImGui::CalcTextSize(text) * customScale;
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - textSize.x) * 0.5f);
    ImGui::SetWindowFontScale(customScale);
    ImGui::Text("%s", text);
    ImGui::SetWindowFontScale(1.0f);
    ImGui::PopFont();
}
bool button(const string& 名称, ImVec2 尺寸, float 圆角大小 = 15.0f, ImVec4 默认颜色 = ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4 悬停颜色 = ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4 按下颜色 = ImVec4(0.0f, 155.0f/255.0f, 255.0f/255.0f, 0.0f),
         bool 是否激活标签 = false) {
    ImGuiWindow* 窗口 = ImGui::GetCurrentWindow();
    if (窗口->SkipItems) return false;
    ImGuiContext& 上下文 = *GImGui;
    const ImGuiStyle& 样式 = 上下文.Style;
    const ImGuiID ID = 窗口->GetID(名称.c_str()); 
    const ImVec2 标签尺寸 = ImGui::CalcTextSize(名称.c_str(), NULL, true);
    ImVec2 实际尺寸 = ImGui::CalcItemSize(尺寸, 标签尺寸.x + 样式.FramePadding.x * 2.0f, 标签尺寸.y + 样式.FramePadding.y * 2.0f);  
    const ImRect 边界框(窗口->DC.CursorPos, 窗口->DC.CursorPos + 实际尺寸);
    ImGui::ItemSize(边界框, 样式.FramePadding.y);
    if (!ImGui::ItemAdd(边界框, ID)) return false;
    bool 悬停状态, 按住状态;
    bool 按下状态 = ImGui::ButtonBehavior(边界框, ID, &悬停状态, &按住状态, 0);
    struct 按钮动画状态 {
        ImVec4 背景色;
        ImVec4 文本色;
        float Y轴偏移;
        float 背景透明度;
    };
    static std::map<ImGuiID, 按钮动画状态> 动画数据;   
    auto 动画迭代器 = 动画数据.find(ID);
    if (动画迭代器 == 动画数据.end()) {
        动画数据.insert({ID, {默认颜色, ImVec4(1,1,1,1), 0.0f, 1.0f}});
        动画迭代器 = 动画数据.find(ID);
    }
    ImVec4 目标背景色 = 按住状态 ? 按下颜色 : 悬停状态 ? ImVec4(0.9f, 0.9f, 0.9f, 0.0f) : 默认颜色;
    ImVec4 目标文本色 = 按住状态 ? ImVec4(1,1,1,1) : 悬停状态 ? ImVec4(0.1f, 0.1f, 0.1f, 1.0f) : ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
    动画迭代器->second.背景色 = ImLerp(动画迭代器->second.背景色, 目标背景色, 上下文.IO.DeltaTime * 12.f);
    动画迭代器->second.文本色 = ImLerp(动画迭代器->second.文本色, 目标文本色, 上下文.IO.DeltaTime * 12.f);
    动画迭代器->second.Y轴偏移 = ImLerp(动画迭代器->second.Y轴偏移, 按住状态 ? 2.0f : 0.0f, 上下文.IO.DeltaTime * 15.f);
    动画迭代器->second.背景透明度 = ImLerp(动画迭代器->second.背景透明度, 悬停状态 ? 1.1f : 1.0f, 上下文.IO.DeltaTime * 10.f);
    窗口->DrawList->AddRectFilled(边界框.Min + ImVec2(0, 动画迭代器->second.Y轴偏移),边界框.Max + ImVec2(0, 动画迭代器->second.Y轴偏移),ImGui::GetColorU32(动画迭代器->second.背景色),圆角大小);
    const ImVec2 文本位置 = 边界框.Min + (实际尺寸 - 标签尺寸) * 0.5f + ImVec2(0, 动画迭代器->second.Y轴偏移);
    ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetColorU32(动画迭代器->second.文本色));
    ImGui::RenderText(文本位置, 名称.c_str());
    ImGui::PopStyleColor();
    if (按下状态) {
        const float 插值 = ImMin(上下文.IO.DeltaTime * 50, 1.0f);
        窗口->DrawList->AddCircleFilled(边界框.GetCenter() + ImVec2(0, 动画迭代器->second.Y轴偏移),标签尺寸.x * 0.6f * (1.0f - 插值),ImGui::GetColorU32(ImVec4(1,1,1,0.15f * 插值)),16);
    }
    return 按下状态;
}
float 动画总时间 = 0.0f;  
int 当前菜单 = -1;        
struct 动画参数 {
    float 滑动持续时间 = 8.0f;      
    float 底部偏移量 = 730.0f;    
    float 控件延迟 = 1.5f;       
    float 初始延迟 = 1.0f;      
};
inline float 缓出五次方(float 时间因子) {
    return 1.0f - powf(1.0f - 时间因子, 5.0f);
}
void i(int 控件序号) {
    static 动画参数 参数;
    static int lastTab = -1;
    static int 上一个控件 = -1;
    if (当前菜单 != Tab || lastTab != Tab) {
        动画总时间 = 0.0f;
        当前菜单 = Tab;
        lastTab = Tab;
        上一个控件 = -1;
    }
    动画总时间 += ImGui::GetIO().DeltaTime;
    auto 缓入缓出 = [](float 时间因子) {
        时间因子 = std::clamp(时间因子, 0.0f, 1.0f);
        if (时间因子 < 0.5f) {
            return 4.0f * 时间因子 * 时间因子 * 时间因子;
        } else {
            float 因子 = (2.0f * 时间因子 - 2.0f);
            return 0.5f * 因子 * 因子 * 因子 + 1.0f;
        }
    };
    float 实际延迟 = 参数.初始延迟 + (控件序号 * 参数.控件延迟);
    float 进度 = (动画总时间 > 实际延迟) 
        ? std::min((动画总时间 - 实际延迟) / 参数.滑动持续时间, 1.0f)
        : 0.0f;
    float 缓动进度 = 缓入缓出(进度);
    float 当前偏移量 = 参数.底部偏移量 * (1.0f - 缓动进度);
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 当前偏移量);
    float 透明度 = 缓动进度;
    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 透明度);
    上一个控件 = 控件序号;
}
void Y() {
    ImGui::PopStyleVar();
}
void Toggle(const string& 名称, bool& 开关状态, float 宽度 = 300, float 字体大小 = 45, 
            ImVec2 按钮尺寸 = ImVec2(95, 50), float 动画速度 = 0.05f, 
            ImColor 未激活颜色 = ImColor(190, 190, 190), ImColor 已激活颜色 = ImColor(15, 150, 255)) {
    static ImVec2 原始光标位置;
    static float 半径;
    static ImVec2 最小坐标, 最大坐标;
    static ImVec4 目标颜色值;
    wc& 动画数据 = wh[名称.c_str()];
    原始光标位置 = ImGui::GetCursorPos();
    float 窗口宽度 = ImGui::GetWindowWidth();
    float 边界 = 窗口宽度 * 0.10f;
    float 按钮右侧位置 = 窗口宽度 - 边界 - 按钮尺寸.x;
    ImGui::SetCursorPosX(按钮右侧位置);
    if (ImGui::InvisibleButton(名称.c_str(), 按钮尺寸)) {
        开关状态 = !开关状态;
    }
    最小坐标 = ImGui::GetItemRectMin();
    最大坐标 = ImGui::GetItemRectMax();
    半径 = (最大坐标.y - 最小坐标.y) * 0.5f;
    动画数据.end = 开关状态 ? (最大坐标.x - 半径) : (最小坐标.x + 半径);
    目标颜色值 = 开关状态 ? 已激活颜色.Value : 未激活颜色.Value;
    动画数据.color.Value.x += (目标颜色值.x - 动画数据.color.Value.x) * 动画速度;
    动画数据.color.Value.y += (目标颜色值.y - 动画数据.color.Value.y) * 动画速度;
    动画数据.color.Value.z += (目标颜色值.z - 动画数据.color.Value.z) * 动画速度;
    动画数据.color.Value.w += (目标颜色值.w - 动画数据.color.Value.w) * 动画速度;
    动画数据.beg += (动画数据.end - 动画数据.beg) * 动画速度;ImVec2 圆圈中心(ImClamp(动画数据.beg, 最小坐标.x + 半径, 最大坐标.x - 半径), 最小坐标.y + 半径);
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    draw_list->AddRectFilled(最小坐标, 最大坐标, 动画数据.color, 9999.0f, 0);
    draw_list->AddCircleFilled(圆圈中心, 半径 * 0.85f, ImColor(255, 255, 255));
    ImGui::SetCursorPos(原始光标位置);
    const char* text = 名称.c_str();
    ImVec2 文本位置 = ImGui::GetCursorScreenPos();
    float 右移偏移量 = 40.0f; 
    draw_list->AddText(NULL, 字体大小, ImVec2(文本位置.x + 右移偏移量, 文本位置.y), ImColor(0, 0, 0, 255), text);
    ImGui::SetCursorPosY(原始光标位置.y + ImMax(ImGui::GetFont()->CalcTextSizeA(字体大小, FLT_MAX, -1, text).y,按钮尺寸.y) + ImGui::GetStyle().ItemSpacing.y);
}
bool SliderFloat(const char* 标签, float* 值, float 最小值, float 最大值, 
                const char* 格式 = "%.1f", ImGuiSliderFlags 标志 = 0, 
                float 缩进 = 5.0f, float 宽度比例 = 1.3f, float 右偏移量 = 50.0f)  
{
    ImGuiWindow* 窗口 = ImGui::GetCurrentWindow();
    if (窗口->SkipItems)
        return false;
    ImGuiContext& 上下文 = *GImGui;
    const ImGuiStyle& 样式 = 上下文.Style;
    const ImGuiID ID = 窗口->GetID(标签);
    if (!格式) 格式 = "%.1f";
    const float 宽度 = (ImGui::CalcItemWidth() - 缩进 * 2) * 宽度比例;
    const float 标签尺寸 = ImGui::CalcTextSize(标签, NULL, true).x;
    const float 框架高度 = ImGui::GetFrameHeight();
    const float 滑动条高度 = 15.0f; 
    const float 圆半径 = 18.0f;   
    const float 边距 = 4.0f;
    const float 文本滑动条间距 = -8.0f;
    ImVec2 位置 = 窗口->DC.CursorPos;
    位置.x += 缩进 + 右偏移量;  
    ImRect 滑动条框(ImVec2(位置.x, 位置.y + 框架高度 + 文本滑动条间距), 
                     ImVec2(位置.x + 宽度, 位置.y + 框架高度 + 文本滑动条间距 + 滑动条高度));
    ImRect 交互框 = 滑动条框;
    const float 交互扩展 = 10.0f;
    交互框.Expand(ImVec2(0, 交互扩展));
    const float 文本Y = 滑动条框.Min.y - 框架高度 + 样式.FramePadding.y + 5.0f;
    ImRect 总框(ImVec2(位置.x, 文本Y), ImVec2(位置.x + 宽度, 滑动条框.Max.y + 圆半径));
    ImGui::ItemSize(总框, 样式.FramePadding.y);
    if (!ImGui::ItemAdd(交互框, ID, &交互框))
        return false;
    ImGui::SetWindowFontScale(1.15f);
    char 值缓冲[64];
    ImFormatString(值缓冲, IM_ARRAYSIZE(值缓冲), 格式, *值);
    const float 值尺寸 = ImGui::CalcTextSize(值缓冲, NULL).x;
    ImGui::RenderText(ImVec2(滑动条框.Min.x, 文本Y), 标签);
    ImGui::RenderText(ImVec2(滑动条框.Max.x - 值尺寸, 文本Y), 值缓冲);
    ImGui::SetWindowFontScale(1.0f);
    const float t = ImClamp((*值 - 最小值) / (最大值 - 最小值), 0.0f, 1.0f);
    const float 圆X = ImLerp(滑动条框.Min.x + 边距 + 圆半径, 
                            滑动条框.Max.x - 边距 - 圆半径, t);
    const ImVec2 圆心(圆X, 滑动条框.GetCenter().y);
    bool 悬停, 按住;
    bool 按下 = ImGui::ButtonBehavior(交互框, ID, &悬停, &按住, ImGuiButtonFlags_PressedOnClick);
    if (按下 || 按住) {
        if (上下文.ActiveIdSource == ImGuiInputSource_Mouse) {
            const float 可用宽度 = 滑动条框.GetWidth() - 2 * (边距 + 圆半径);
            float 鼠标t = ImClamp((上下文.IO.MousePos.x - 滑动条框.Min.x - 边距 - 圆半径) / 
                                 可用宽度, 0.0f, 1.0f);
            *值 = ImLerp(最小值, 最大值, 鼠标t);
            ImGui::MarkItemEdited(ID);
        }
    }
    const ImU32 轨道颜色 = ImGui::GetColorU32(ImVec4(0.78f, 0.78f, 0.80f, 1.0f)); 
    const ImU32 填充颜色 = ImGui::GetColorU32(ImVec4(0.0f, 0.48f, 1.0f, 1.0f));   
    窗口->DrawList->AddRectFilled(
        ImVec2(滑动条框.Min.x, 滑动条框.GetCenter().y - 滑动条高度/2),
        ImVec2(滑动条框.Max.x, 滑动条框.GetCenter().y + 滑动条高度/2),
        轨道颜色, 
        滑动条高度/2
    );
    const float 填充右边缘 = 圆心.x + 边距;
    窗口->DrawList->AddRectFilled(
        ImVec2(滑动条框.Min.x, 滑动条框.GetCenter().y - 滑动条高度/2),
        ImVec2(填充右边缘, 滑动条框.GetCenter().y + 滑动条高度/2),
        填充颜色, 
        滑动条高度/2
    );
    const ImU32 圆颜色 = ImGui::GetColorU32(ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    const ImU32 圆边框颜色 = ImGui::GetColorU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
    窗口->DrawList->AddCircleFilled(圆心 + ImVec2(0, 1), 圆半径, ImGui::GetColorU32(ImVec4(0,0,0,0.1f)));
    窗口->DrawList->AddCircleFilled(圆心, 圆半径, 圆颜色);
    窗口->DrawList->AddCircle(圆心, 圆半径, 圆边框颜色, 0, 2.0f);
    return 按下 || 按住;
}
void whitecloud(const vector<string>& 名称列表, float& 当前参数, float 是否居中 = 0, float 按钮宽度 = 100, float 按钮高度 = 60, float 矩形圆角 = 15, float 左内边距 = 0.0f, float 右内边距 = 0.0f, float 上内边距 = 0.0f, float 下内边距 = 0.0f, float 左移偏移量 = 40.0f, float 下移偏移量 = 8.0f) 
{
    const ImVec2 按钮尺寸(按钮宽度, 按钮高度);
    const ImVec2 矩形尺寸(按钮尺寸.x * 0.97f, 按钮尺寸.y * 0.95f);
    const ImVec2 尺寸差值(按钮尺寸.x - 矩形尺寸.x, 按钮尺寸.y - 矩形尺寸.y);
    const ImVec2 窗口尺寸(
        按钮尺寸.x * 名称列表.size() + 左内边距 + 右内边距,
        按钮尺寸.y + 上内边距 + 下内边距
    );
    static wc* 当前标签 = nullptr;
    if (!当前标签) {
        当前标签 = &wh[名称列表[0].c_str()];
    }
    if (是否居中) {
        ImGui::SetCursorPosX(ImGui::GetWindowWidth() - 窗口尺寸.x - ImGui::GetStyle().WindowPadding.x - 25.0f - 左移偏移量);
    } else {
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 左内边距 + 左移偏移量);
    }
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 上内边距 + 下移偏移量);
    struct StyleGuard {
        StyleGuard() {
            const ImVec4 背景色(0.86f, 0.86f, 0.86f, 1.0f);
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.86f, 0.86f, 0.86f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ChildBg, 背景色);
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.86f, 0.86f, 0.86f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.86f, 0.86f, 0.86f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.86f, 0.86f, 0.86f, 0.0f));
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, ImGui::GetStyle().ItemSpacing.y));
        }
        ~StyleGuard() {
            ImGui::PopStyleColor(5);
            ImGui::PopStyleVar(2);
        }
    } styleGuard;
    ImGui::BeginChild(名称列表[0].c_str(), 窗口尺寸, true);
    ImGui::SetCursorPos(ImVec2(左内边距, 上内边距));
    ImVec2 最小坐标, 最大坐标;
    {
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 0, 0, 0));
        if (ImGui::Button(名称列表[0].c_str(), 按钮尺寸)) {
            当前标签->Tab = 0;
            当前参数 = 0;
        }
        ImGui::PopStyleColor();
        ImGui::SameLine();
        最小坐标 = ImVec2(ImGui::GetItemRectMin().x + 尺寸差值.x, ImGui::GetItemRectMin().y + 尺寸差值.y); 
        最大坐标 = ImVec2(ImGui::GetItemRectMax().x - 尺寸差值.x, ImGui::GetItemRectMax().y - 尺寸差值.y); 
        Lerp(当前标签->beg, 当前标签->end, 0.06f);
        ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(最小坐标.x + 当前标签->beg, 最小坐标.y),ImVec2(最大坐标.x + 当前标签->beg, 最大坐标.y),ImColor(255, 255, 255, 255),矩形圆角,ImDrawCornerFlags_All);
    }
    for (size_t i = 0; i < 名称列表.size(); ++i) {
        if (i > 0) {
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 0, 0, 0));
            if (ImGui::Button(名称列表[i].c_str(), 按钮尺寸)) {
                当前标签->Tab = i;
                当前参数 = i;
            }
            ImGui::PopStyleColor();
            if (i + 1 < 名称列表.size()) {
                ImGui::SameLine();
            }
        }
        if (当前标签->Tab == i) {
            当前标签->end = 按钮尺寸.x * i;
        }
        const string& 当前名称 = 名称列表[i];
        ImVec2 居中坐标(最小坐标.x + 按钮尺寸.x * i, 最小坐标.y);
        const float 文本X = 居中坐标.x + (最大坐标.x - 最小坐标.x) * 0.5f;
        const float 文本Y = 居中坐标.y + (最大坐标.y - 最小坐标.y) * 0.5f;
        static ImVec2 文本尺寸; 
        if (i == 0 || 文本尺寸.x == 0) { 
            文本尺寸 = ImGui::GetFont()->CalcTextSizeA(35, FLT_MAX, -1, 当前名称.c_str());
        }
        ImGui::GetWindowDrawList()->AddText(NULL, 35, ImVec2(文本X - 文本尺寸.x * 0.5f, 文本Y - 文本尺寸.y * 0.5f), ImColor(0, 0, 0, 255), 当前名称.c_str());
    }
    ImGui::EndChild();
}
class DrawIo {
public:
inline void 绘制加粗文本(float size, float x, float y, ImColor color, ImColor color1, const char* str) {
ImGui::GetBackgroundDrawList()->AddText(NULL, size, {(float)(x-0.1), (float)(y-0.1)}, color1, str);
ImGui::GetBackgroundDrawList()->AddText(NULL, size, {(float)(x+0.1), (float)(y+0.1)}, color1, str);
ImGui::GetBackgroundDrawList()->AddText(NULL, size, {x, y}, color, str);
}
inline void 绘制字体描边(float size,int x, int y, ImVec4 color, const char* str) {
ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x - 0.1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(color), str);
}
inline void CenterText(float X,float Y,const char* content,float fontSize, ImVec4 color) {
auto textSize = ImGui::CalcTextSize(content, 0, fontSize);
textSize.x *= fontSize / 25.0f;
textSize.y *= fontSize / 25.0f;
ImGui::GetBackgroundDrawList()->AddText(NULL, fontSize,ImVec2(X - textSize.x / 2, Y), ImGui::ColorConvertFloat4ToU32(color), content);  
}
inline void DrawRectFilledCorner(int x, int y, int w, int h, ImColor color, int rounding) {
ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), (color), rounding, ImDrawCornerFlags_All);
}
inline void DrawCircleFilled(int x, int y, int radius, ImVec4 color, int segments) {
ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(color), segments);
}
inline void DrawLine(int x1, int y1, int x2, int y2, ImVec4 color, int size) {
ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(color), size);
}
inline void DrawRect(int x, int y, int w, int h, ImVec4 color,int size) {
ImGui::GetBackgroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x+w, y+h), ImGui::ColorConvertFloat4ToU32(color), 10, ImDrawCornerFlags_All, size);
}
inline void DrawRectFilled(int x, int y, int w, int h, ImVec4 color) {
ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x+w, y+h), ImGui::ColorConvertFloat4ToU32(color), 0, 0);
}
inline void DrawCircle(float X, float Y, float radius, float a, float r, float g, float b, float thickness) {
ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(X, Y), radius, ImColor(r, g, b, a), 0, thickness);
}
inline void DrawStrokeText(int x, int y, ImVec4 color, const char* str) {
ImGui::GetBackgroundDrawList()->AddText(NULL, 25, ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
ImGui::GetBackgroundDrawList()->AddText(NULL, 25, ImVec2(x - 0.1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
ImGui::GetBackgroundDrawList()->AddText(NULL, 25, ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
ImGui::GetBackgroundDrawList()->AddText(NULL, 25, ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
ImGui::GetBackgroundDrawList()->AddText(NULL, 25, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(color), str);
}
inline void DrawTriangleFilled(int x1, int y1, int x2, int y2, int x3, int y3, ImVec4 Color, int T) {
ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), ImGui::ColorConvertFloat4ToU32(Color));
}
inline void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, ImVec4 Color, int T) {
ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), ImGui::ColorConvertFloat4ToU32(Color));
}
}DrawTf;
void TouchScroll(const bool& 惯性标志 = false)
{
    ImGuiWindow* 窗口指针 = ImGui::GetCurrentWindow();
    float 最大滚动Y = ImGui::GetScrollMaxY();
    if (窗口指针->SkipItems || 最大滚动Y <= 0.0f)
        return;
    static const float 惯性减速率 = 0.96f;       
    static const float 反弹刚度 = 0.25f;         
    static const float 反弹阻尼 = 0.15f;         
    static const float 最大过冲 = 200.0f;        
    static const float 最小速度阈值 = 2.0f;      
    static const float 触摸灵敏度 = 1.2f;        
    static float 滚动速度 = 0.0f;
    static float 滚动加速度 = 0.0f;
    static ImVec2 起始触摸位置 = ImVec2(0, 0);
    static bool 正在滚动 = false;
    static float 上次滚动Y = 0.0f;
    static double 上次时间 = 0.0;
    static double 上次触摸时间 = 0.0;
    static ImVec2 上次触摸速度 = ImVec2(0, 0);
    ImGuiIO& 输入输出 = ImGui::GetIO();
    bool 悬停状态 = ImGui::IsWindowHovered();
    auto 更新滚动 = [&](float 增量Y, float 时间差) {
        float 当前滚动Y = ImGui::GetScrollY();
        float 新滚动Y = 当前滚动Y + 增量Y * 触摸灵敏度;
        新滚动Y = ImClamp(新滚动Y, -最大过冲, 最大滚动Y + 最大过冲);
        ImGui::SetScrollY(新滚动Y);
        if (时间差 > 0.0f) {
            滚动速度 = 增量Y / 时间差;
            上次触摸速度.y = 滚动速度;
            上次触摸时间 = ImGui::GetTime();
        }
        上次滚动Y = 新滚动Y;
    };
    auto 获取时间差 = [&]() {
        double 当前时间 = ImGui::GetTime();
        float 时间差 = (float)(当前时间 - 上次时间);
        上次时间 = 当前时间;
        return 时间差;
    };
    auto 切换父窗口移动 = [窗口指针](bool 禁止移动) {
        if (ImGuiWindow* 父窗口指针 = 窗口指针->ParentWindow) {
            父窗口指针->Flags = 禁止移动 ? 
                (父窗口指针->Flags | ImGuiWindowFlags_NoMove) : 
                (父窗口指针->Flags & ~ImGuiWindowFlags_NoMove);
        }
    };
    if (悬停状态 && 输入输出.MouseDown[0] && !正在滚动) {
        起始触摸位置 = 输入输出.MousePos;
        正在滚动 = true;
        上次滚动Y = ImGui::GetScrollY();
        上次时间 = ImGui::GetTime();
        滚动速度 = 0.0f;
        滚动加速度 = 0.0f;
        切换父窗口移动(true);
    }
    if (正在滚动) {
        float 时间差 = 获取时间差();
        if (输入输出.MouseDown[0]) {
            float 增量Y = 起始触摸位置.y - 输入输出.MousePos.y;
            更新滚动(增量Y, 时间差);
            起始触摸位置 = 输入输出.MousePos;
        } else {
            正在滚动 = false;
            切换父窗口移动(false);
            if (ImGui::GetTime() - 上次触摸时间 < 0.1f) {
                滚动速度 = 上次触摸速度.y;
            }
        }
    }
    if (!正在滚动 && (fabsf(滚动速度) > 最小速度阈值 || 
                      ImGui::GetScrollY() < 0.0f || 
                      ImGui::GetScrollY() > 最大滚动Y)) {
        float 时间差 = 获取时间差();
        float 当前滚动Y = ImGui::GetScrollY();
        float 反弹力 = 0.0f;
        if (当前滚动Y < 0.0f) {
            float 过冲量 = -当前滚动Y;
            反弹力 = 过冲量 * 反弹刚度 - 滚动速度 * 反弹阻尼;
        } else if (当前滚动Y > 最大滚动Y) {
            float 过冲量 = 当前滚动Y - 最大滚动Y;
            反弹力 = -过冲量 * 反弹刚度 - 滚动速度 * 反弹阻尼;
        }
        滚动速度 += 反弹力 * 时间差;
        滚动速度 *= powf(惯性减速率, 时间差 * 60.0f);
        float 新滚动Y = 当前滚动Y + 滚动速度 * 时间差;
        if (新滚动Y <= -最大过冲) {
            新滚动Y = -最大过冲;
            滚动速度 = 0.0f;
        } else if (新滚动Y >= 最大滚动Y + 最大过冲) {
            新滚动Y = 最大滚动Y + 最大过冲;
            滚动速度 = 0.0f;
        }
        ImGui::SetScrollY(新滚动Y);
        if (fabsf(滚动速度) < 最小速度阈值) {
            if (新滚动Y < 0.0f) {
                float 回弹速度 = -新滚动Y * 0.15f;  
                ImGui::SetScrollY(新滚动Y + 回弹速度);
                if (新滚动Y > -1.0f) ImGui::SetScrollY(0.0f);
            } else if (新滚动Y > 最大滚动Y) {
                float 回弹速度 = (最大滚动Y - 新滚动Y) * 0.15f;
                ImGui::SetScrollY(新滚动Y + 回弹速度);
                if (新滚动Y < 最大滚动Y + 1.0f) ImGui::SetScrollY(最大滚动Y);
            } else {
                滚动速度 = 0.0f;
            }
        }
    } else if (!正在滚动) {
        滚动速度 = 0.0f;
    }
}
void DrawSectionWithItems(const char* 标题, const std::function<void()>& 内容回调函数, int 项目数量) {
    ImDrawList* 绘制列表 = ImGui::GetWindowDrawList();
    float 分区高度 = 20 + (项目数量 * (ImGui::GetTextLineHeight()));
    float 分区宽度 = ImGui::GetContentRegionAvail().x * 0.9f;  
    float 分区位置X = (ImGui::GetContentRegionAvail().x - 分区宽度) * 0.5f;
    ImVec2 光标位置 = ImGui::GetCursorScreenPos();
    ImVec2 分区位置 = ImVec2(光标位置.x + 分区位置X, 光标位置.y + ImGui::GetTextLineHeight() + 10);
    绘制列表->AddRectFilled(分区位置,
        分区位置 + ImVec2(分区宽度, 分区高度 - ImGui::GetTextLineHeight() - 10),
        ImColor(255, 255, 255, 150),
        15.0f);
    ImGui::SetCursorPosX(分区位置X + 10);  
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(20, 20));
    ImGui::Text("%s", 标题);
    ImGui::PopStyleVar();
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);
    if (内容回调函数) {
        内容回调函数();
    }
}
void CustomSeparator(float 宽度百分比 = 0.9f, float 粗细 = 1.0f, ImU32 颜色 = IM_COL32(0, 0, 0, 255)) {
    ImGuiWindow* 窗口 = ImGui::GetCurrentWindow();
    if (窗口->SkipItems)
        return;
       float 可用宽度 = ImGui::GetContentRegionAvail().x;
    float 分隔线宽度 = 可用宽度 * 宽度百分比;
    float 起始X = (可用宽度 - 分隔线宽度) * 0.48f;
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 起始X);
    ImRect 边界框(窗口->DC.CursorPos, 窗口->DC.CursorPos + ImVec2(分隔线宽度, 粗细));
    ImGui::ItemSize(边界框);
    if (!ImGui::ItemAdd(边界框, 0))
        return;
    窗口->DrawList->AddLine(边界框.Min,ImVec2(边界框.Max.x, 边界框.Min.y),颜色,粗细);  
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 粗细 + ImGui::GetStyle().ItemSpacing.y);
}
void ColorPresetSelector() {
    static ImColor themeColors[8] = {
        ImColor(148,144,142),   
        ImColor(77,178,47), 
        ImColor(238,184,47), 
        ImColor(240,129,48),   
        ImColor(223,79,85), 
        ImColor(239,90,159),   
        ImColor(150,51,149), 
        ImColor(11,117,240)   
    };
    static int selectedColorIndex = 3; 
    const float circleRadius = 19.0f;
    const float circleSpacing = 10.0f;
    const ImVec2 circleSize(circleRadius * 2, circleRadius * 2);
    const float hitBoxSize = 50.0f;
    const ImVec2 hitBoxVec2(hitBoxSize, hitBoxSize);
    const float animDuration = 0.2f; 
    const float minScale = 0.8f;     
    static float colorAnimTimes[9] = {0}; 
    static float currentColorAnimTime = 0; 
    ImGui::AlignTextToFramePadding();
    ImVec2 textStartPos = ImGui::GetCursorScreenPos();
    ImGui::Text("  我的色彩");
    ImGui::SameLine();
    float textHeight = ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 2;
    float textCenterY = textStartPos.y + textHeight * 0.5f;
    float buttonStartY = textCenterY - hitBoxSize/2.0f - ImGui::GetWindowPos().y;
    ImGui::SetCursorPosY(buttonStartY);
    float deltaTime = ImGui::GetIO().DeltaTime;
    for (int i = 0; i < 9; i++) { 
        if (colorAnimTimes[i] > 0) {
            colorAnimTimes[i] += deltaTime;
            if (colorAnimTimes[i] > animDuration) {
                colorAnimTimes[i] = 0; 
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        ImGui::SameLine(0, circleSpacing);
        ImGui::InvisibleButton(("##ThemeColorBtn" + std::to_string(i)).c_str(), hitBoxVec2);
        ImVec2 btnScreenPos = ImGui::GetItemRectMin();
        ImVec2 btnCenter = ImVec2(
            btnScreenPos.x + hitBoxSize/2.0f,
            textCenterY
        );
        float scale = 1.0f;
        if (colorAnimTimes[i] > 0) {
            float t = colorAnimTimes[i] / animDuration;
            if (t < 0.5f) {
                scale = 1.0f - (0.2f * (t / 0.5f));
            } else {
                scale = 0.8f + (0.2f * ((t - 0.5f) / 0.5f));
            }
        }
        if (ImGui::IsItemClicked()) {
            selectedColorIndex = i;
            colorAnimTimes[i] = deltaTime; 
        }
        float scaledRadius = circleRadius * scale;
        float scaledFillRadius = (circleRadius - 1.0f) * scale;
        ImGui::GetWindowDrawList()->AddCircle(
            btnCenter,
            scaledRadius,
            ImColor(100, 100, 100),
            0,
            7.0f * scale 
        );
        ImGui::GetWindowDrawList()->AddCircleFilled(
            btnCenter,
            scaledFillRadius,
            themeColors[i]
        );
    }
    ImGui::SameLine(0, circleSpacing);
    ImGui::InvisibleButton("##MulticolorBtn", hitBoxVec2);
    ImVec2 multicolorBtnScreenPos = ImGui::GetItemRectMin();
    ImVec2 multicolorBtnCenter = ImVec2(
        multicolorBtnScreenPos.x + hitBoxSize/2.0f,
        textCenterY
    );
    float multicolorScale = 1.3f;
    if (colorAnimTimes[8] > 0) {
        float t = colorAnimTimes[8] / animDuration;
        if (t < 0.5f) {
            multicolorScale = 1.3f - (0.2f * (t / 0.5f));
        } else {
            multicolorScale = 1.1f + (0.2f * ((t - 0.5f) / 0.5f));
        }
    }
    if (ImGui::IsItemClicked()) {
        selectedColorIndex = 0;
        colorAnimTimes[8] = deltaTime; 
        Tab = 4; 
    }
    float scaledRadius = circleRadius * multicolorScale;
    float scaledFillRadius = (circleRadius - 0.8f) * multicolorScale;
    ImVec2 textPos = ImVec2(multicolorBtnCenter.x, multicolorBtnCenter.y + circleRadius + 10);
    ImGui::GetWindowDrawList()->AddText(
        ImVec2(textPos.x - ImGui::CalcTextSize("多色").x/2, textPos.y),
        ImGui::GetColorU32(ImGuiCol_Text),
        "多色"
    );
    ImGui::SetCursorPosY(buttonStartY + hitBoxSize);
    ImGui::AlignTextToFramePadding();
    textStartPos = ImGui::GetCursorScreenPos();
    ImGui::Text("  当前设置色彩  ");
    ImGui::SameLine();
    textHeight = ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 2;
    textCenterY = textStartPos.y + textHeight * 0.5f;
    buttonStartY = textCenterY - hitBoxSize/2.0f - ImGui::GetWindowPos().y;
    ImGui::SetCursorPosY(buttonStartY);
    if (currentColorAnimTime > 0) {
        currentColorAnimTime += deltaTime;
        if (currentColorAnimTime > animDuration) {
            currentColorAnimTime = 0;
        }
    }
    ImGui::InvisibleButton("##CurrentColorBtn", hitBoxVec2);
    ImVec2 btnScreenPos = ImGui::GetItemRectMin();
    ImVec2 btnCenter = ImVec2(
        btnScreenPos.x + hitBoxSize/2.0f,
        textCenterY
    );
    float currentScale = 1.0f;
    if (currentColorAnimTime > 0) {
        float t = currentColorAnimTime / animDuration;
        if (t < 0.5f) {
            currentScale = 1.0f - (0.2f * (t / 0.5f));
        } else {
            currentScale = 0.8f + (0.2f * ((t - 0.5f) / 0.5f));
        }
    }
    if (ImGui::IsItemClicked()) {
        currentColorAnimTime = deltaTime;
    }
    float scaledRadiusCurrent = circleRadius * currentScale;
    float scaledFillRadiusCurrent = (circleRadius - 1.0f) * currentScale;
    ImGui::GetWindowDrawList()->AddCircle(
        btnCenter,
        scaledRadiusCurrent,
        ImColor(100, 100, 100),
        0,
        7.0f * currentScale
    );
    ImGui::GetWindowDrawList()->AddCircleFilled(
        btnCenter,
        scaledFillRadiusCurrent,
        themeColors[selectedColorIndex]
    );
    ImGui::SetCursorPosY(buttonStartY + hitBoxSize);
}
bool CustomRadioButton(const char* label, bool active, float scale = 0.9f) {
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;
    		  ImGui::SetWindowFontScale(1.15f); 
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0,0,0,0));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0,0,0,0));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0,0,0,0));
    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
    const float w = ImGui::CalcItemWidth() * scale;
    const ImVec2 pos = window->DC.CursorPos;
    const float circle_diameter = style.FramePadding.y * 2.4f * scale;
    const float total_height = ImMax(label_size.y, circle_diameter) + style.FramePadding.y * 2.0f;
    const ImRect total_bb(pos, ImVec2(pos.x + w, pos.y + total_height));
    ImGui::ItemSize(total_bb, style.FramePadding.y);
    if (!ImGui::ItemAdd(total_bb, id))
        return false;
    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(total_bb, id, &hovered, &held);
    const float radius = style.FramePadding.y * 1.2f * scale;
    ImVec2 center = ImVec2(
        pos.x + radius + style.FramePadding.x,
        pos.y + total_height * 0.5f  
    );
    window->DrawList->AddCircleFilled(center, radius, IM_COL32(255, 255, 255, 255), 12);
    if (active) {
        window->DrawList->AddCircle(center, radius, IM_COL32(18,134,252, 255), 128, 10.0f);
        window->DrawList->AddCircleFilled(center, radius * 0.56f, IM_COL32(255, 255, 255, 255), 128);
    } else {
        window->DrawList->AddCircle(center, radius, IM_COL32(255, 255, 255, 255), 128, 10.0f);
    }
    ImVec2 label_pos = ImVec2(
        pos.x + radius * 2.0f + style.FramePadding.x * 3.0f,
        center.y - label_size.y * 0.5f  
    );
    ImGui::RenderText(label_pos, label);
    		  ImGui::SetWindowFontScale(1.0f); 
    ImGui::PopStyleColor(3); 
    return pressed;
}
#endif
