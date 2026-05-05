if (wz.w > 0){
if (物资[21]) { 
    if ((strstr(wz.Name, "_PlayerPawn_Impostors_C") != 0) || 
        (strstr(wz.Name, "BP_PlayerPawn_Impo") != 0)) 
    {
        std::string name = "内鬼[";
        name += std::to_string((int)wz.Distance);
        name += "米]";
        auto textSize = ImGui::CalcTextSize(name.c_str(), 0, 30);
        float r_x = wz.ScreenPos.x;
        float r_y = wz.ScreenPos.y - 15; 
        Draw->AddText(
            NULL, 
            30,  
            {r_x - (textSize.x / 2), r_y}, 
            ImColor(255, 0, 0, 255), 
            name.c_str()
        );
    }
}
if (物资[4]) {
if (wz.Distance < 1000) {
string name;
name += "金插[" + to_string((int)wz.Distance) + "米]\n";
if (strstr(wz.Name, "perPeopleSkill")) {
    Draw->AddText(NULL,25,{wz.ScreenPos.x-25,wz.ScreenPos.y-10},ImColor(255,255,255), name.c_str());
}
}
}
if (物资[3] && wz.Distance < 350) {
    std::string str;
    if (strstr(wz.Name, "Flaregun") != nullptr) {
        str = "信号枪";
    } else if (strstr(wz.Name, "Flare") != nullptr) {
        str = "信号弹";
    } else if (strstr(wz.Name, "BP_Pistol_Flaregun_Wrapper_C") != nullptr) {
        str = "信号枪";
    } else if (strstr(wz.Name, "RevivalCard_PickUp_C") != nullptr) {
        str = "通用召回信标";
    } else if (strstr(wz.Name, "BP_Ammo_Flare_Pickup_C") != nullptr) {
        str = "信号弹";
    } else if (strstr(wz.Name, "_revivalAED_Pickup_C") != nullptr) {
        str = "自救器";
    } else if (strstr(wz.Name, "BP_Pickup_Finger_C") != nullptr) {
        str = "飞索";
    }
    if (!str.empty()) {
        str += " [";
        str += std::to_string((int)wz.Distance);
        str += "M]";
        Draw->AddText(NULL, 25, {wz.ScreenPos.x-25, wz.ScreenPos.y-10}, ImColor(255,255,255), str.c_str());
    }
}
if (物资[18] && wz.Distance < 150) {
    std::string str;
    if (strstr(wz.Name, "BP_InnerSupplyBoxBase_C") != nullptr ||
        strstr(wz.Name, "BP_EscapeInnerWrapperList_C") != nullptr) {
    } else if (strstr(wz.Name, "EscapeBoxHight_SupplyBox_Lv1_C") != nullptr ||
               strstr(wz.Name, "EscapeBoxHight_SupplyBox_Lv2_C") != nullptr ||
               strstr(wz.Name, "EscapeBoxHight_SupplyBox_Lv3_C") != nullptr ||
               strstr(wz.Name, "EscapeBoxHight_SupplyBox_Lv4_C") != nullptr ||
               strstr(wz.Name, "EscapeBoxHight_SupplyBox_Lv5_C") != nullptr) {
        str = "物资箱";
        str += " [";
        str += std::to_string((int)wz.Distance);
        str += "M]";
        ImVec2 textPos = ImVec2(wz.ScreenPos.x, wz.ScreenPos.y);
        Draw->AddText(nullptr, 20.0f, textPos, ImColor(255, 0, 0, 222), str.c_str());
    }
}
if (物资[45]) {
    if (wz.Distance < 100) {
        string name;
        name += "盒子[" + to_string((int)wz.Distance) + "米]\n";
        if (strstr(wz.Name, "BP_PlayerDeadListWrapper_C") || strstr(wz.Name, "CharacterDeadInventoryBox_")) {
            ImVec2 textSize = ImGui::CalcTextSize(name.c_str());
            Draw->AddText(NULL, 25, {wz.ScreenPos.x - 25, wz.ScreenPos.y - 10}, ImColor(0, 225, 0, 225), name.c_str());
        }
    }
}
if (物资[9]) {
string name;
name += "空投[" + to_string((int)wz.Distance) + "米]\n";
if (strstr(wz.Name, "_AirDropBox_C") || strstr(wz.Name, "_AirDropBox_SuperPeople_C")) {
    Draw->AddText(NULL,25,{wz.ScreenPos.x-25,wz.ScreenPos.y-10},ImColor(255, 0,0, 255), name.c_str());
}
}
if (DrawIo[31]) {
    if (strstr(wz.Name, "BP_Projectile_SmokeBomb_C") != nullptr) {
        float distanceToSmoke = sqrt(pow(screen_x / 2 - fanhua.Head.ScreenPos.x, 2) + 
                                    pow(screen_y / 2 - fanhua.Head.ScreenPos.y, 2)) / 100.0f;
        if (distanceToSmoke <= 4.0) {
            continue;
        }
    }
}
if (DrawIo[14]) {
    ImColor 投掷物颜色;
    bool hasGrenade = strstr(wz.Name, "BP_Projectile_BurnGrenade_C") != nullptr ||
                     strstr(wz.Name, "BP_Projectile_StunGrenade_C") != nullptr ||
                     strstr(wz.Name, "BP_Projectile_SmokeBomb_C") != nullptr ||
                     strstr(wz.Name, "BP_Projectile_FragGrenade_C") != nullptr;
                                     
    if (hasGrenade && wz.Distance <= 200.0f) {
        std::string ss;
        ss.reserve(256);
        if (strstr(wz.Name, "BP_Projectile_BurnGrenade_C")) ss += "烧死你";
        if (strstr(wz.Name, "BP_Projectile_StunGrenade_C")) ss += "蒸鸡蛋";
        if (strstr(wz.Name, "BP_Projectile_SmokeBomb_C")) ss += "烟黑蛋";
        if (strstr(wz.Name, "BP_Projectile_FragGrenade_C")) ss += "炸死你";
        ss += std::to_string((int)wz.Distance) + "m";
        
        float time = ImGui::GetTime();
        if (fmodf(time, 0.3f) < 0.1f) {
            投掷物颜色 = ImColor(147, 189, 64, 255);
        } else if (fmodf(time, 0.3f) < 0.2f) {
            投掷物颜色 = ImColor(255, 255, 255, 255);
        } else {
            投掷物颜色 = ImColor(255, 0, 0, 255);
        }
        ImVec2 textSize = ImGui::CalcTextSize(ss.c_str());
        float halfTextWidth = textSize.x / 2.0f;
        float circleRadius = 20.0f;
        float circleLineWidth = 3.0f;
        Draw->AddCircle({wz.ScreenPos.x, wz.ScreenPos.y}, circleRadius, 投掷物颜色, 0, circleLineWidth);
       
        ImVec2 textPos = {
            wz.ScreenPos.x - halfTextWidth, 
            wz.ScreenPos.y + circleRadius + 5.0f
        };
        Draw->AddText(NULL, 20.0f, textPos, ImColor(255, 0, 0, 255), ss.c_str());
    }
}

if (物资[1] && wz.Distance < 350) {
    std::string vehicleName;
    if (strstr(wz.Name, "VH_LostMobile_C")) {
        vehicleName = "主题车";
    } else if (strstr(wz.Name, "_StationWagon_C")) {
        vehicleName = "旅行车";
    } else if (strstr(wz.Name, "TrackVehicle_BP_C")) {
        vehicleName = "矿车";
    } else if (strstr(wz.Name, "Buggy")) {
        vehicleName = "蹦蹦";
    } else if (strstr(wz.Name, "CoupeRB")) {
        vehicleName = "跑车";
    } else if (strstr(wz.Name, "PlaneCharacter")) {
        vehicleName = "飞机";
    } else if (strstr(wz.Name, "UAZ")) {
        vehicleName = "吉普";
    } else if (strstr(wz.Name, "LadaNiva")) {
        vehicleName = "吉普";
    } else if (strstr(wz.Name, "Motorglider")) {
        vehicleName = "滑翔机";
    } else if (strstr(wz.Name, "MotorcycleCart")) {
        vehicleName = "摩托车";
    } else if (strstr(wz.Name, "Motorcycle")) {
        vehicleName = "摩托车";
    } else if (strstr(wz.Name, "Dacia")) {
        vehicleName = "轿车";
    } else if (strstr(wz.Name, "AquaRail")) {
        vehicleName = "冲锋艇";
    } else if (strstr(wz.Name, "PG117")) {
        vehicleName = "轮船";
    } else if (strstr(wz.Name, "MiniBus")) {
        vehicleName = "大巴车";
    } else if (strstr(wz.Name, "Mirado")) {
        vehicleName = "跑车";
    } else if (strstr(wz.Name, "Scooter")) {
        vehicleName = "小绵羊";
    } else if (strstr(wz.Name, "Rony")) {
        vehicleName = "皮卡车";
    } else if (strstr(wz.Name, "Snowbike")) {
        vehicleName = "雪地车";
    } else if (strstr(wz.Name, "Snowmobile")) {
        vehicleName = "雪地车";
    } else if (strstr(wz.Name, "Tuk")) {
        vehicleName = "三轮";
    } else if (strstr(wz.Name, "StationWagon")) {
        vehicleName = "行李车";
    } else if (strstr(wz.Name, "BRDM")) {
        vehicleName = "装甲车";
    } else if (strstr(wz.Name, "Bigfoot")) {
        vehicleName = "大脚车";
    } else if (strstr(wz.Name, "UTV")) {
        vehicleName = "拉力车";
    } else if (strstr(wz.Name, "ATV")) {
        vehicleName = "沙滩车";
    } else if (strstr(wz.Name, "Horse")) {
        vehicleName = "马";
    } else if (strstr(wz.Name, "4SportCar")) {
        vehicleName = "跑车";
    }
    if (!vehicleName.empty()) {
        char displayText[128];
        snprintf(displayText, sizeof(displayText), "%s[%d米]", vehicleName.c_str(), (int)wz.Distance);
        const float scale = 0.8f;
        ImVec2 textSize = ImGui::CalcTextSize(displayText);
        textSize.x *= scale;
        textSize.y *= scale;
        const float textX = wz.ScreenPos.x - textSize.x * 0.5f;
        const float textY = wz.ScreenPos.y - textSize.y * 0.5f;
        const float outlineWidth = 1.0f * scale;
        ImVec2 outlinePositions[] = {
            {textX - outlineWidth, textY - outlineWidth},{textX + outlineWidth, textY - outlineWidth},
            {textX - outlineWidth, textY + outlineWidth},{textX + outlineWidth, textY + outlineWidth}
        };
        for (const auto& pos : outlinePositions) {
            Draw->AddText(NULL, 25.0f * scale, pos, ImColor(0, 0, 0), displayText);
        }
        Draw->AddText(NULL, 25.0f * scale, {textX, textY}, ImColor(255, 255, 0), displayText);
    }
}
if (DrawIo[910]) 
{
if (wz.Distance < 100) {
const bool isSupplyBox = strstr(wz.Name, "EscapeBoxHight_SupplyBox_") || strstr(wz.Name, "EscapeBox_SupplyBox_");
if (isSupplyBox && wz.Distance >= 0.5f)
{
const int boxState = driver->read<int>(fanhua.Objaddr + 0x270);
if (boxState == 0) {
static char boxText[128];
snprintf(boxText, sizeof(boxText), "[未开启]宝箱[%d米]", static_cast<int>(wz.Distance));
const ImVec2 textSize = ImGui::CalcTextSize(boxText);
const float padding = 3.0f;
const float halfTextWidth = textSize.x * 0.5f;
const ImVec2 rectMin = {wz.ScreenPos.x - halfTextWidth - padding, wz.ScreenPos.y - padding};
const ImVec2 rectMax = {wz.ScreenPos.x + halfTextWidth + padding, wz.ScreenPos.y + textSize.y + padding};          
Draw->AddRectFilled(rectMin, rectMax, ImColor(0, 0, 0, 0),cornerRadius,ImDrawFlags_RoundCornersAll);
Draw->AddText(nullptr, 25.0f, {wz.ScreenPos.x - halfTextWidth, wz.ScreenPos.y}, ImColor(255, 215, 0), boxText);
}
}
}
}
}
