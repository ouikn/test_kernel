void DrawLogo(ImTextureID ID,ImVec2 center, float size) {
ImGui::SetCursorPos({size*2, size*2});
ImGui::GetWindowDrawList()->AddImageRounded(ID,ImVec2(center.x - size, center.y - size), ImVec2(center.x + size, center.y + size), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255), 9999.0f);
}
FTransform getBone(uintptr_t addr) {
FTransform transform;
driver->read(addr, reinterpret_cast<void*>(&transform), 4 * 11);
return transform;
}
void GetClassName(char *Name, long int address, int id) {
long int ClassNameadd = driver->read<uintptr_t>(address + (id / 0x4000) * 0x8);
long int ClassNameaddr = driver->read<uintptr_t>(ClassNameadd + (id % 0x4000) * 0x8);
driver->read(ClassNameaddr + 0xC, Name, 64);
}
char* 获取类名(long addr) {
int id = driver->read<int>(addr + 0x18);
long ye = driver->read<uintptr_t>(fanhua.Gname + (id / 0x4000) * 8);
long xu = driver->read<uintptr_t>(ye + (id % 0x4000) * 8);
static char Item[256];
driver->read(xu + 0xc, Item, sizeof(Item));
return Item;
}

void GetDistance(Vec3 Object, Vec3 Self, float *Distance) {
float DistanceX = pow(Object.x - Self.x, 2);
float DistanceY = pow(Object.y - Self.y, 2);
float DistanceZ = pow(Object.z - Self.z, 2);
*Distance = sqrt(DistanceX + DistanceY + DistanceZ) * 0.01f;
}
Vec2 rotateCoord(float angle, float objRadar_x, float objRadar_y) {
Vec2 radarCoordinate;
float s = sin(angle * PI / 180);
float c = cos(angle * PI / 180);
radarCoordinate.x = objRadar_x * c + objRadar_y * s;
radarCoordinate.y = -objRadar_x * s + objRadar_y * c;
return radarCoordinate;
}
void getUTF8(UTF8 * buf, long namepy) {
UTF16 buf16[16] = { 0 };
driver->read(namepy, buf16, 28);
UTF16 *pTempUTF16 = buf16;
UTF8 *pTempUTF8 = buf;
UTF8 *pUTF8End = pTempUTF8 + 32;
while (pTempUTF16 < pTempUTF16 + 28) {
if (*pTempUTF16 <= 0x007F && pTempUTF8 + 1 < pUTF8End) {
*pTempUTF8++ = (UTF8) * pTempUTF16;
} else if (*pTempUTF16 >= 0x0080 && *pTempUTF16 <= 0x07FF && pTempUTF8 + 2 < pUTF8End) {
*pTempUTF8++ = (*pTempUTF16 >> 6) | 0xC0;
*pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
} else if (*pTempUTF16 >= 0x0800 && *pTempUTF16 <= 0xFFFF && pTempUTF8 + 3 < pUTF8End) {
*pTempUTF8++ = (*pTempUTF16 >> 12) | 0xE0;
*pTempUTF8++ = ((*pTempUTF16 >> 6) & 0x3F) | 0x80;
*pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
} else {
break;
}
pTempUTF16++;
}
}
Vec2 WorldIsScreen(Vec3 obj, float ViewW) {
float x = screen_x/2 + (fanhua.matrix[0] * obj.x + fanhua.matrix[4] * obj.y + fanhua.matrix[8] * obj.z + fanhua.matrix[12]) / ViewW * screen_x/2;
float y = screen_y/2 - (fanhua.matrix[1] * obj.x + fanhua.matrix[5] * obj.y + fanhua.matrix[9] * obj.z + fanhua.matrix[13]) / ViewW * screen_y/2;
return Vec2(x, y);
}
Vec2 WorldToScreen(Vec3 obj, float a[16], float b) {
Vec2 bscreen;
float camear = fanhua.matrix[3] * obj.x + fanhua.matrix[7] * obj.y + fanhua.matrix[11] * obj.z + fanhua.matrix[15];
bscreen.x = screen_x/2 + (fanhua.matrix[0] * obj.x + fanhua.matrix[4] * obj.y + fanhua.matrix[8] * obj.z + fanhua.matrix[12]) / camear * screen_x/2;
bscreen.y = screen_y/2 - (fanhua.matrix[1] * obj.x + fanhua.matrix[5] * obj.y + fanhua.matrix[9] * obj.z + fanhua.matrix[13]) / camear * screen_y/2;
return bscreen;
}
void WorldToScreen(Vec2 *bscreen, float *camea, float *w, Vec3 obj) { 
float camear = fanhua.matrix[3] * obj.x + fanhua.matrix[7] * obj.y + fanhua.matrix[11] * obj.z + fanhua.matrix[15];
*camea = camear;
bscreen->x = screen_x/2 + (fanhua.matrix[0] * obj.x + fanhua.matrix[4] * obj.y + fanhua.matrix[8] * obj.z + fanhua.matrix[12]) / camear * screen_x/2;
bscreen->y = screen_y/2 - (fanhua.matrix[1] * obj.x + fanhua.matrix[5] * obj.y + fanhua.matrix[9] * obj.z + fanhua.matrix[13]) / camear * screen_y/2;
float bscreenZ = screen_y/2 - (fanhua.matrix[1] * obj.x + fanhua.matrix[5] * obj.y + fanhua.matrix[9] * (obj.z + 165) + fanhua.matrix[13]) / camear * screen_y/2;
float bscreenz = bscreen->y - bscreenZ;
*w = (bscreen->y - bscreenZ) / 2;
}
float ReadFloat(long addr) {
	float he=0;
	driver->read(addr, &he, 4);
	return he;
}

// 绘制骨骼函数
void DrawBone(ImVec2 start, ImVec2 end) {
if (!isnan(start.x) && !isnan(start.y) && !isnan(end.x) && !isnan(end.x)) {
double dx = start.x - end.x;
double dy = start.y - end.y;
if (sqrt(dx * dx + dy * dy) > 100)
return;
if (fanhua.IsBot) {
ImGui::GetForegroundDrawList()->AddLine(start, end, 绘制颜色[8], 绘制粗细[5]);
} else {
ImGui::GetForegroundDrawList()->AddLine(start, end, 绘制颜色[7], 绘制粗细[6]);
}
}
}
int GetBase() {
if (draw_style[10] == 1) {

fanhua.pid = driver->GetPid("com.tencent.tmgp.pubgmhd");
if (fanhua.pid > 0 && fanhua.pid < 100000)
driver->initialize(fanhua.pid);
else {
printf("\n和平精英未启动\n");
return 0;
}
fanhua.libUE4 = driver->getModuleBase("libUE4.so");
memset(fanhua.matrix, 0, 16);
fanhua.Matrixs = driver->read<uintptr_t>(driver->read<uintptr_t>(fanhua.libUE4 + 0x12132d60) + 0x20) + 0x270;
}

return 1;
}
#include "绘图与物资/血量绘图.h"

Vec2 rotateCoord(Vec3 Enemy, Vec3 RealPerson)
{
    float x = RealPerson.x - Enemy.x;
    float y = RealPerson.y - Enemy.y;
    float z = RealPerson.z - Enemy.z;
	Vec2 radarCoordinate;
	radarCoordinate.x = atan2(y,x)*180/3.141592653589793238;
	radarCoordinate.y = atan2(z,sqrt(x*x+y*y)) * 180 / 3.141592653589793238;
	return radarCoordinate;
}



class FRotator
{
public:
    FRotator() :Pitch(0.f), Yaw(0.f), Roll(0.f) {

    }
    FRotator(float _Pitch, float _Yaw, float _Roll) : Pitch(_Pitch), Yaw(_Yaw), Roll(_Roll)
    {

    }
    ~FRotator()
    {

    }
    float Pitch;
    float Yaw;
    float Roll;
    inline FRotator Clamp()
    {

        if (Pitch > 180)
        {
            Pitch -= 360;
        }
        else
        {
            if (Pitch < -180)
            {
                Pitch += 360;
            }
        }
        if (Yaw > 180)
        {
            Yaw -= 360;
        }
        else {
            if (Yaw < -180)
            {
                Yaw += 360;
            }
        }
        if (Pitch > 89)
        {
            Pitch = 89;
        }
        if (Pitch < -89)
        {
            Pitch = -89;
        }
        while (Yaw < 180)
        {
            Yaw += 360;
        }
        while (Yaw > 180)
        {
            Yaw -= 360;
        }
        Roll = 0;
        return FRotator(Pitch, Yaw, Roll);
    }
    inline float Length()
    {
        return sqrtf(Pitch * Pitch + Yaw * Yaw + Roll * Roll);
    }
    FRotator operator+(FRotator v) {
        return FRotator(Pitch + v.Pitch, Yaw + v.Yaw, Roll + v.Roll);
    }
    FRotator operator-(FRotator v) {
        return FRotator(Pitch - v.Pitch, Yaw - v.Yaw, Roll - v.Roll);
    }
};