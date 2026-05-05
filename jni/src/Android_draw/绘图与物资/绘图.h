if (DrawIo[20] && ((DrawIo[31] && !fanhua.IsBot) || !DrawIo[31]) && ((DrawIo[32] && fanhua.Health > 0) || !DrawIo[32])) {
strcpy(Aim[AimCount].Name, fanhua.PlayerName);
Aim[AimCount].WodDistance = fanhua.Distance;
Aim[AimCount].AimMovement = fanhua.Predict;
if (NumIo[8] == 1.0){
Aim[AimCount].ObjAim = fanhua.Head.Pos;
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - fanhua.Head.ScreenPos.x, 2) + pow(screen_y / 2 - fanhua.Head.ScreenPos.y, 2));
} else if (NumIo[8] == 2.0){
Aim[AimCount].ObjAim = fanhua.Chest.Pos;
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - fanhua.Chest.ScreenPos.x, 2) + pow(screen_y / 2 - fanhua.Chest.ScreenPos.y, 2));
} else if (NumIo[8] == 3.0){
Aim[AimCount].ObjAim = fanhua.Pelvis.Pos; 
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - fanhua.Pelvis.ScreenPos.x, 2) + pow(screen_y / 2 - fanhua.Pelvis.ScreenPos.y, 2));
} else {
Aim[AimCount].ObjAim = fanhua.Head.Pos;
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - fanhua.Head.ScreenPos.x, 2) + pow(screen_y / 2 - fanhua.Head.ScreenPos.y, 2));
}  
AimCount++;
}

if (DrawIo[49] && Gmin != -1)
{   
Draw->AddCircle({vpvp.x, vpvp.y}, 8, ImColor(255, 49, 49), 0, 3.0f);
}
float top, right, left, bottom, top1; 
left  = fanhua.Head.ScreenPos.x - fanhua.w * 0.6;
right = fanhua.Head.ScreenPos.x + fanhua.w * 0.6;
if (!fanhua.Head.Pos.x) {
top1 = fanhua.Pelvis.ScreenPos.y - fanhua.Chest.ScreenPos.y;
} else {
top1 = fanhua.Pelvis.ScreenPos.y - fanhua.Head.ScreenPos.y;
}
top  = fanhua.Pelvis.ScreenPos.y - top1 - fanhua.w / 5;
if (fanhua.Left_Ankle.ScreenPos.y < fanhua.Right_Ankle.ScreenPos.y) {
bottom = fanhua.Right_Ankle.ScreenPos.y + fanhua.w / 10;
} else {
bottom = fanhua.Left_Ankle.ScreenPos.y  + fanhua.w / 10;
}
if(DrawIo[48])
{
    if (fanhua.IsBot == 1)
    {
        continue;
    }
}
if (DrawIo[1]) {
    const float boxWidth = fanhua.w * 1.2f;
    const float boxHeight = (fanhua.Pelvis.ScreenPos.y - fanhua.Head.ScreenPos.y) * 2.5f;
    
    const float left = fanhua.Head.ScreenPos.x - boxWidth / 2;
    const float right = fanhua.Head.ScreenPos.x + boxWidth / 2;
    const float top = fanhua.Head.ScreenPos.y - boxHeight * 0.2f;
    
    const float bottom = fanhua.Pelvis.ScreenPos.y + boxHeight * 0.3f;
    if (left < screen_x && right > 0 && top < screen_y && bottom > 0) {
    
        ImColor 方框;
        if (fanhua.IsBot) {
            方框 = ImColor(0, 255, 0); 
        } else if (fanhua.Health <= 0) {
            方框 = ImColor(100, 100, 100); 
        } else {
            方框 = ImColor(255, 0, 0); 
        }
        const float borderThickness = 1.5f; 
        Draw->AddRect({left, top}, {right, bottom}, 方框, 0.0f, 0, borderThickness);
         ImColor fillColor = ImColor(方框.Value.x, 方框.Value.y, 方框.Value.z, 0.1f);
         Draw->AddRectFilled({left, top}, {right, bottom}, fillColor);
    }
}
if (DrawIo[2]) {
    static const float rayStartY = (draw_style[0] == 0 || draw_style[0] == 1) ? 73 : 
                                 (draw_style[0] == 2) ? screen_y*0.135f : 0;
    const ImVec2 endPos = {fanhua.Head.ScreenPos.x, fanhua.Head.ScreenPos.y - 70};
    const bool isOffScreen = (fanhua.Head.ScreenPos.x < 0 || fanhua.Head.ScreenPos.x > screen_x ||
                             fanhua.Head.ScreenPos.y < 0 || fanhua.Head.ScreenPos.y > screen_y);
    ImColor 射线;
    if (fanhua.IsBot) {
        射线 = ImColor(0, 255, 0);
    } else if (isOffScreen) {
        射线 = ImColor(255, 255, 255);
    } else {
        射线 = ImColor(255, 0, 0);
    }
    const float lineWidth = fanhua.IsBot ? 绘制粗细[4] : 绘制粗细[3];
    Draw->AddLine({screen_x / 2, rayStartY}, endPos,射线,lineWidth);
}
if (DrawIo[6]) {
if (!fanhua.IsBot) {
DrawHealth({fanhua.Head.ScreenPos.x, top }, fanhua.w * 2, fanhua.Health, fanhua.TeamID, fanhua.PlayerName);
} else {
DrawHealth({fanhua.Head.ScreenPos.x, top }, fanhua.w * 2, fanhua.Health, fanhua.TeamID, "人机");
}
}
if (DrawIo[50]) {
    const int 敌人头 = fanhua.敌人头;
    const int 敌人甲 = fanhua.敌人甲;
    const int 敌人包 = fanhua.敌人包;
    
    const float headScreenX = fanhua.Head.ScreenPos.x;
    const float headScreenY = fanhua.Head.ScreenPos.y;
    static char equipInfo[64]; 
    
    snprintf(equipInfo, sizeof(equipInfo), "头:%s 甲:%s 包:%s", 
             tou(敌人头).c_str(), jia(敌人甲).c_str(), bao(敌人包).c_str());
    const float fontSize = 18.0f;
    
    ImVec2 textSize = ImGui::CalcTextSize(equipInfo);
    float textX = headScreenX - (textSize.x * fontSize / 25.0f) / 3.0f;
    float textY = headScreenY - 82.0f;
    const ImColor textColor = ImColor(0, 255, 200);
    Draw->AddText(nullptr, fontSize, {textX, textY}, textColor, equipInfo);
}

int  武器id;
武器id = GetWeapon(fanhua.scwq);
if (DrawIo[10]) {
  const float weaponBoxWidth = 90.0f;
  const float weaponBoxHeight = 40.0f;
  const float textSizeY = 12.0f;
  const float yOffset = 30.0f;

  float nameY = top - textSizeY - 5;
  float weaponY = nameY - 15;
  ImVec2 weaponTextPos = {fanhua.Head.ScreenPos.x - (weaponBoxWidth / 2), weaponY - (textSizeY / 2) - yOffset};
  ImVec2 weaponImageMin = {fanhua.Head.ScreenPos.x - 45, weaponY - 40 - yOffset};
  ImVec2 weaponImageMax = {fanhua.Head.ScreenPos.x + 45, weaponY - yOffset};

  PlayerId = fanhua.scwq;
  Draw->PushClipRect(weaponImageMin, weaponImageMax, true);
  Draw->AddImage(weapon[武器id/10], weaponImageMin, weaponImageMax);
  Draw->PopClipRect();
  Draw->AddText(nullptr, 12.0f, weaponTextPos, ImColor(255, 255, 255, 255), "");
}

if (DrawIo[3]) {
    bool isOnScreen = (fanhua.Head.ScreenPos.x > 0 && fanhua.Head.ScreenPos.x < screen_x &&
                      fanhua.Head.ScreenPos.y > 0 && fanhua.Head.ScreenPos.y < screen_y &&
                      fanhua.Pelvis.ScreenPos.x > 0 && fanhua.Pelvis.ScreenPos.x < screen_x &&
                      fanhua.Pelvis.ScreenPos.y > 0 && fanhua.Pelvis.ScreenPos.y < screen_y);
    if (isOnScreen) {
        ImVec2 bonePositions[59]; 
        bonePositions[4] = ImVec2(fanhua.Chest.ScreenPos.x, fanhua.Chest.ScreenPos.y);   
        bonePositions[3] = ImVec2(fanhua.Chest.ScreenPos.x, fanhua.Chest.ScreenPos.y);   
        bonePositions[0] = ImVec2(fanhua.Pelvis.ScreenPos.x, fanhua.Pelvis.ScreenPos.y);  
        
        bonePositions[11] = ImVec2(fanhua.Left_Shoulder.ScreenPos.x, fanhua.Left_Shoulder.ScreenPos.y);
        bonePositions[12] = ImVec2(fanhua.Left_Elbow.ScreenPos.x, fanhua.Left_Elbow.ScreenPos.y);
        bonePositions[13] = ImVec2(fanhua.Left_Wrist.ScreenPos.x, fanhua.Left_Wrist.ScreenPos.y);
        
        bonePositions[33] = ImVec2(fanhua.Right_Shoulder.ScreenPos.x, fanhua.Right_Shoulder.ScreenPos.y);
        bonePositions[34] = ImVec2(fanhua.Right_Elbow.ScreenPos.x, fanhua.Right_Elbow.ScreenPos.y);
        bonePositions[35] = ImVec2(fanhua.Right_Wrist.ScreenPos.x, fanhua.Right_Wrist.ScreenPos.y);
        
        bonePositions[52] = ImVec2(fanhua.Left_Thigh.ScreenPos.x, fanhua.Left_Thigh.ScreenPos.y);
        bonePositions[53] = ImVec2(fanhua.Left_Knee.ScreenPos.x, fanhua.Left_Knee.ScreenPos.y);
        bonePositions[54] = ImVec2(fanhua.Left_Ankle.ScreenPos.x, fanhua.Left_Ankle.ScreenPos.y);
        
        bonePositions[56] = ImVec2(fanhua.Right_Thigh.ScreenPos.x, fanhua.Right_Thigh.ScreenPos.y);
        bonePositions[57] = ImVec2(fanhua.Right_Knee.ScreenPos.x, fanhua.Right_Knee.ScreenPos.y);
        bonePositions[58] = ImVec2(fanhua.Right_Ankle.ScreenPos.x, fanhua.Right_Ankle.ScreenPos.y);
        static const std::pair<int, int> boneConnections[] = {
            {5, 4}, {4, 3}, {3, 0}, {3, 11}, {11, 12}, {12, 13}, 
            {3, 33}, {33, 34}, {34, 35}, {0, 52}, {52, 53}, {53, 54}, 
            {0, 56}, {56, 57}, {57, 58}
        };
        const size_t connectionCount = sizeof(boneConnections) / sizeof(boneConnections[0]);
        ImColor boneColor = ImColor(0, 255, 0);
        float lineThickness = 绘制粗细[3];
        for (size_t i = 0; i < connectionCount; ++i) {
            const auto& connection = boneConnections[i];
            const ImVec2& start = bonePositions[connection.first];
            const ImVec2& end = bonePositions[connection.second];
            if (start.x > 0 && start.y > 0 && end.x > 0 && end.y > 0 &&
                start.x < screen_x && start.y < screen_y && end.x < screen_x && end.y < screen_y) {
                Draw->AddLine(start, end, boneColor, lineThickness);
            }
        }
    }
}
/*
Vec2 aimAngle = rotateCoord(fanhua.Head.Pos, fanhua.MyPos);
FRotator aimMZ = FRotator(0, ReadFloat(fanhua.Objaddr + 0x1A8), 0); // 敌人视角角度
aimMZ.Clamp();
float AimX = abs(aimAngle.x - aimMZ.Yaw);

bool isDuplicate = false;
for (int j = 0; j < 被瞄索引; j++) {
    if (被瞄[j].Name == fanhua.PlayerName) {
        isDuplicate = true;
        break;
    }
}
if (!isDuplicate && AimX <= 4 && 被瞄索引 < 100 && fanhua.Health > 0) {
    被瞄[被瞄索引].距离 = fanhua.Distance;
    被瞄[被瞄索引].Name = fanhua.PlayerName;
    被瞄[被瞄索引].手持武器 = GetWeapon(fanhua.scwq);
    被瞄索引++;
}
if (DrawIo[89]) {
    for (int i = 0; i < 被瞄索引; ) {
        bool isAlive = false;
        for (int j = 0; j < fanhua.Count; j++) {
            uintptr_t entityAddr = driver->read<uintptr_t>(fanhua.Arrayaddr + 8 * j);
            if (entityAddr == fanhua.Objaddr) {
                float health = (driver->read<float>(entityAddr + 0xdb0) / driver->read<float>(entityAddr + 0xdb4)) * 100;
                if (health > 0 && 被瞄[i].Name == fanhua.PlayerName) {
                    isAlive = true;
                    break;
                }
            }
        }
        
        if (!isAlive) {
            for (int k = i; k < 被瞄索引 - 1; k++) {
                被瞄[k] = 被瞄[k + 1];
            }
            被瞄索引--;
            continue;
        }
        
        std::string name = 被瞄[i].Name;
        std::string weapon = 被瞄[i].手持武器;
        std::string distance = std::to_string((int)被瞄[i].距离);
        float heightOffset = 50.0f;
        float fixedUseX = screen_x / 2 - (screen_x / 16);
        float startY = screen_y - (screen_y/2) - (screen_y/4) - (screen_y/8);
        
        float nameWidth = ImGui::GetFont()->CalcTextSizeA(60, FLT_MAX, -1, name.c_str()).x;
        float nameX = fixedUseX - nameWidth - 10;
        
        Draw->AddText(nullptr, 60.f, ImVec2(nameX, startY + i * heightOffset), ImColor(0, 150, 255, 255), name.c_str());
        Draw->AddText(nullptr, 60.f, ImVec2(fixedUseX, startY + i * heightOffset), ImColor(0, 255, 0, 255), " 使用 ");
        
        float weaponX = fixedUseX + ImGui::GetFont()->CalcTextSizeA(60, FLT_MAX, -1, " 使用 ").x;
        Draw->AddText(nullptr, 60.f, ImVec2(weaponX, startY + i * heightOffset), ImColor(255, 0, 0, 255), weapon.c_str());
        
        float aimX = weaponX + ImGui::GetFont()->CalcTextSizeA(60, FLT_MAX, -1, weapon.c_str()).x;
        Draw->AddText(nullptr, 60.f, ImVec2(aimX, startY + i * heightOffset), ImColor(0, 255, 0, 255), " 瞄准你 ");
        
        float distanceX = aimX + ImGui::GetFont()->CalcTextSizeA(60, FLT_MAX, -1, " 瞄准你 ").x;
        Draw->AddText(nullptr, 60.f, ImVec2(distanceX, startY + i * heightOffset), ImColor(255, 255, 0, 255), distance.c_str());
        
        float mX = distanceX + ImGui::GetFont()->CalcTextSizeA(60, FLT_MAX, -1, distance.c_str()).x;
        Draw->AddText(nullptr, 60.f, ImVec2(mX, startY + i * heightOffset), ImColor(255, 255, 0, 255), "M");
        
        i++;  // 只有当前敌人存活时才递增索引
    }
}
*/