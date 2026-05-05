
#include "结构体.h"
#include <cstdio>
#include <cstdlib>
#include <random>
struct AimStruct {
Vec3 ObjAim;  
Vec3 AimMovement;  
float ScreenDistance = 0;
float WodDistance = 0; 
char Name[32];//预判数值
};

#ifdef AIMBOT_SEPARATED

using namespace std;

extern AimStruct Aim[100]; // 自瞄结构
extern int AimCount;
extern float zm_x, zm_y;
extern int MaxPlayerCount;
extern int Gmin;
extern bool IsAimLongAim;
extern char AimName[32];
extern Vec2 vpvp;
extern float fwjl;
extern bool DrawIo[50];
extern float NumIo[50];

// 初始化随机数生成器
std::mt19937 generator(static_cast<unsigned int>(time(0)));
std::uniform_int_distribution<int> distribution_offset(-80, 80); // 定义偏移范围，例如±50像素



float GetPitch(float Fov) 
{
if (Fov > 75 && Fov <= 130)  // 不开镜
{
return 0.6f * NumIo[14];
}
else if (Fov == 70 || Fov == 75)// 机瞄 ，侧瞄
{ 
return 2.5f * NumIo[14];   
}
else if (Fov == 55 || Fov == 60)// 红点 ，全息
{
return 2.5f * NumIo[14];
}   
else if ((int)Fov == 44)// 2倍
{
return 5.1f * NumIo[14];
}
else if ((int)Fov == 26)// 3倍
{
return 7.1f * NumIo[14];
}
else if ((int)Fov == 20)// 4倍
{
return 8.4f * NumIo[14];
}
else if ((int)Fov == 13)// 6倍
{   
return 13.9f * NumIo[14];
}
return 2.5f * NumIo[14];   // 8倍
}

float GetWeaponId(int WeaponId) {
    switch (WeaponId) {
        // 自动武器 - 突击步枪
        case 101008: return 1.1;  // M762
        case 101001: return 1.2;  // AKM
        case 101004: return 0.85; // M416
        case 101003: return 0.8;  // SCAR-L
        case 101002: return 0.8;  // M16A4
        case 101009: return 1.05; // Mk47
        case 101006: return 0.75; // AUG
        case 101005: return 1.05; // Groza
        case 101010: return 1.0;  // G36C
        case 101007: return 0.95; // QBZ
        case 101011: return 0.9;  // AC-VAL
        case 101012: return 1.0;  // 蜜獾突击步枪
        
        // 自动武器 - 机关枪
        case 105001: return 1.25; // M249
        case 105002: return 1.23; // DP-28
        case 105010: return 1.0;  // MG3
        
        // 自动武器 - 冲锋枪
        case 102001: return 0.6;  // UZI
        case 102003: return 0.6;  // Vector
        case 100103: return 0.65; // PP-19
        case 102007: return 0.6;  // MP5K
        case 102002: return 0.6;  // UMP 5
        case 102004: return 0.6;  // 汤姆逊
        case 102105: return 0.5;  // P90
        case 102005: return 0.6;  // 野牛
        
        case 103001: return 0;    // 98k
        case 103004: return 0;    // sks
        case 103005: return 0.35; // vss
        case 103012: return 0;    // amr
        case 103015: return 0;    // m200


        default: return 0.95;     // 未收录
    }
}


float getScopeAcc(int Scope){
switch (Scope) {
case 0:
return 1.0f;
break;
case 1:
return .98f;
break;
case 2:
return .95f;
break;
case 3:
return .94f;
break;
case 4:
return .92f;
break;
case 5:
return .9f;
break;
case 6:
return .88f;
break;
case 7:
return .86f;
break;
case 8:
return .85f;
break;
default:
return .9f;
break;
}
}
int findminat()
{
    float min = NumIo[3];
	float DistanceMin = NumIo[17];
    int minAt = 999;
    for (int i = 0; i < MaxPlayerCount; i++)
    {
		switch ((int)NumIo[21])
        {
            case 0:
                if (IsAimLongAim) {
					if (strcmp(Aim[i].Name, AimName) == 0)
    				{           	
        				minAt = i;
    				}
				} else {
    				if (Aim[i].ScreenDistance < min)
    				{
						if (DrawIo[30]) {
							strcpy(AimName, Aim[i].Name);
						}
        				min = Aim[i].ScreenDistance;
        				minAt = i;
    				}
				}
			break;
			case 1:
                if (IsAimLongAim) {
					if (strcmp(Aim[i].Name, AimName) == 0)
    				{           	
        				minAt = i;
    				}
				} else {
    				if (Aim[i].WodDistance < DistanceMin)
    				{
						if (DrawIo[30]) {
							strcpy(AimName, Aim[i].Name);
						}
        				DistanceMin = Aim[i].WodDistance;
        				minAt = i;
					}
    			}
        	break;
		}
    }
    if (minAt == 999)
    {
        Gmin = -1;
		IsAimLongAim = false;
        return -1;
    }
    Gmin = minAt;   
    Aim[minAt].WodDistance;
	if (DrawIo[30]) {
		IsAimLongAim = true;
	}
    return minAt;
}

void AimBotAuto() {
    bool isDown = false;
    int random_offset_x = distribution_offset(generator);
    int random_offset_y = distribution_offset(generator);

    // 应用随机偏移量
    int final_x = NumIo[5] + random_offset_x;
    int final_y = NumIo[6] + random_offset_y;

    double tx = final_x, ty = final_y;
    double ScreenX, ScreenY;
    
    if (screen_x < screen_y) {
        ScreenX = screen_x;
        ScreenY = screen_y;
    } else {
        ScreenX = screen_y;
        ScreenY = screen_x;
    }

    double ScrXH = ScreenX / 2.0f;
    double ScrYH = ScreenY / 2.0f;
    static float TargetX = 0;
    static float TargetY = 0;
    Vec3 obj;
    float NowCoor[3];

    while (1) {
        usleep(1000000 / 120);

        ImGuiIO& iooi = ImGui::GetIO();

        if (DrawIo[21] && iooi.MouseDown[0] && iooi.MousePos.x <= NumIo[6] + NumIo[7] && iooi.MousePos.y <= screen_y - NumIo[5] + NumIo[7] && iooi.MousePos.x >= NumIo[6] - NumIo[7] && iooi.MousePos.y >= screen_y - NumIo[5] - NumIo[7]) {  
            usleep(30000);  
            if (DrawIo[21] && iooi.MouseDown[0] && iooi.MousePos.x <= NumIo[6] + NumIo[7] && iooi.MousePos.y <= screen_y - NumIo[5] + NumIo[7] && iooi.MousePos.x >= NumIo[6] - NumIo[7] && iooi.MousePos.y >= screen_y - NumIo[5] - NumIo[7]) {
                while (DrawIo[21] && iooi.MouseDown[0] && iooi.MousePos.x <= NumIo[6] + NumIo[7] && iooi.MousePos.y <= screen_y - NumIo[5] + NumIo[7] && iooi.MousePos.x >= NumIo[6] - NumIo[7] && iooi.MousePos.y >= screen_y - NumIo[5] - NumIo[7]) {
                    NumIo[6] = iooi.MousePos.x;
                    NumIo[5] = screen_y - iooi.MousePos.y;
                    绘制颜色[0] = ImColor(0, 220, 0, 150);
                    usleep(500);  
                }
                绘制颜色[0] = ImColor(255, 0, 0, 150);
            }
        }

        if (!DrawIo[20]) {  
            IsAimLongAim = false;
            if (isDown == true) {
                usleep(1000);
                int random_offset_x = distribution_offset(generator);
                int random_offset_y = distribution_offset(generator);

                // 应用随机偏移量
                int final_x = NumIo[5] + random_offset_x;
                int final_y = NumIo[6] + random_offset_y;

                tx = final_x, ty = final_y;
                Touch_Up(6);
                isDown = false;
            }
            usleep(NumIo[9] * 1000);
            continue;
        }

        findminat();

        if (Gmin == -1) {
            IsAimLongAim = false;
            if (isDown == true) {
                usleep(1000);
                int random_offset_x = distribution_offset(generator);
                int random_offset_y = distribution_offset(generator);

                // 应用随机偏移量
                int final_x = NumIo[5] + random_offset_x;
                int final_y = NumIo[6] + random_offset_y;

                tx = final_x, ty = final_y;
                Touch_Up(6);
                isDown = false;
            }
            usleep(NumIo[9] * 1000);
            continue;
        }

        float ToReticleDistance = Aim[Gmin].ScreenDistance;  
        float FlyTime = Aim[Gmin].WodDistance / NumIo[11];
        float DropM = 540.0f * FlyTime * FlyTime;
        
        NowCoor[0] = Aim[Gmin].ObjAim.x;
        NowCoor[1] = Aim[Gmin].ObjAim.y;
        NowCoor[2] = Aim[Gmin].ObjAim.z;
        obj.x = NowCoor[0] + (Aim[Gmin].AimMovement.x * FlyTime*NumIo[22]);
        obj.y = NowCoor[1] + (Aim[Gmin].AimMovement.y * FlyTime*NumIo[22]);
        obj.z = NowCoor[2] + (Aim[Gmin].AimMovement.z * FlyTime*NumIo[22]) + DropM;

        if (fanhua.IsFiring == 1) {
            obj.z -= Aim[Gmin].WodDistance * NumIo[14] * GetWeaponId(fanhua.MyWeapon) * 2 + NumIo[91] + NumIo[49];
        }
        
        float cameras = fanhua.matrix[3] * obj.x + fanhua.matrix[7] * obj.y + fanhua.matrix[11] * obj.z + fanhua.matrix[15];
        vpvp = WorldIsScreen(obj, cameras);  

        zm_y = vpvp.x; 
        zm_x = ScreenX - vpvp.y;
        float AimDs = sqrt(pow(screen_x / 2 - vpvp.x, 2) + pow(screen_y / 2 - vpvp.y, 2));

        if (fanhua.IsAiming == 256) {
            if (DrawIo[25] && fanhua.IsFiring == 1) {
                fwjl = Aim[Gmin].ScreenDistance;
            } else {
                fwjl = NumIo[3];
            }
        } else {
            fwjl = NumIo[3];
        }

        if (zm_x <= 0 || zm_x >= ScreenX || zm_y <= 0 || zm_y >= ScreenY) { 
            IsAimLongAim = false;
            if (isDown == true) {
                usleep(1000);
                int random_offset_x = distribution_offset(generator);
                int random_offset_y = distribution_offset(generator);

                // 应用随机偏移量
                int final_x = NumIo[5] + random_offset_x;
                int final_y = NumIo[6] + random_offset_y;

                tx = final_x, ty = final_y;
                Touch_Up(6);
                isDown = false;
            }
            usleep(NumIo[9] * 1000);
            continue;
        }

        if (ToReticleDistance <= NumIo[3] || AimDs <= NumIo[3]) {
            switch ((int)NumIo[0]) {
                case 0:
                    if (fanhua.IsFiring != 1) {
                        IsAimLongAim = false;
                        if (isDown == true) {
                            usleep(1000);
                            int random_offset_x = distribution_offset(generator);
                            int random_offset_y = distribution_offset(generator);

                            // 应用随机偏移量
                            int final_x = NumIo[5] + random_offset_x;
                            int final_y = NumIo[6] + random_offset_y;

                            tx = final_x, ty = final_y;
                            Touch_Up(6);
                            isDown = false;
                        } 
                        usleep(NumIo[9] * 1000);
                        continue;
                    }
                    break;
                case 1:
                    if (fanhua.IsAiming != 256) {
                        IsAimLongAim = false;
                        if (isDown == true) {
                            usleep(1000);
                            int random_offset_x = distribution_offset(generator);
                            int random_offset_y = distribution_offset(generator);

                            // 应用随机偏移量
                            int final_x = NumIo[5] + random_offset_x;
                            int final_y = NumIo[6] + random_offset_y;

                            tx = final_x, ty = final_y;
                            Touch_Up(6);
                            isDown = false;
                        }
                        usleep(NumIo[9] * 1000);
                        continue;
                    }
                    break;
                case 2:
                    if (fanhua.IsFiring != 1 && fanhua.IsAiming != 256) {
                        IsAimLongAim = false;
                        if (isDown == true) {
                            usleep(1000);
                            int random_offset_x = distribution_offset(generator);
                            int random_offset_y = distribution_offset(generator);

                            // 应用随机偏移量
                            int final_x = NumIo[5] + random_offset_x;
                            int final_y = NumIo[6] + random_offset_y;

                            tx = final_x, ty = final_y;
                            Touch_Up(6);
                            isDown = false;
                        }
                        usleep(NumIo[9] * 1000);
                        continue;
                    }
                    break;
                case 3:
                    break;
            }

            float Acc = getScopeAcc((float)(90 / fanhua.Fov));

            if (isDown == false) {
                usleep(1000);
                if (NumIo[10] == 0.0f)
                    Touch_Down(6, (int)tx, (int)ty);
                else
                    Touch_Down(6, screen_y - (int)tx, screen_x-(int)ty);
                isDown = true;
                usleep(1000);
            }

            if (zm_x > ScrXH) {
                TargetX = -(ScrXH - zm_x) / NumIo[4] * Acc;
                if (TargetX + ScrXH > ScrXH * 2) {
                    TargetX = 0;
                }
            }
            else if (zm_x < ScrXH) {
                TargetX = (zm_x - ScrXH) / NumIo[4] * Acc; 
                if (TargetX + ScrXH < 0) {
                    TargetX = 0;
                }
            }

            if (zm_y > ScrYH) {
                TargetY = -(ScrYH - zm_y) / NumIo[4] * Acc;  
                if (TargetY + ScrYH > ScrYH * 2) {
                    TargetY = 0;
                }
            }
            else if (zm_y < ScrYH) {
                TargetY = (zm_y - ScrYH) / NumIo[4] * Acc;  
                if (TargetY + ScrYH < 0) {
                    TargetY = 0;
                }
            }

            if (TargetY >= 35 || TargetX >= 35 || TargetY <= -35 || TargetX <= -35) {
                if (isDown) {
                    usleep(1000);
                    int random_offset_x = distribution_offset(generator);
                    int random_offset_y = distribution_offset(generator);

                    // 应用随机偏移量
                    int final_x = NumIo[5] + random_offset_x;
                    int final_y = NumIo[6] + random_offset_y;

                    tx = final_x, ty = final_y;
                    Touch_Up(6);
                    isDown = false;
                }
                usleep(NumIo[9] * 1000);
                continue;
            }  

            tx += TargetX;
            ty += TargetY;

            if (tx >= NumIo[5] + NumIo[7] || tx <= NumIo[5] - NumIo[7] || ty >= NumIo[6] + NumIo[7] || ty <= NumIo[6] - NumIo[7]) {
                usleep(1000);
                // 只要滑屏达到了边界，直接还原至中心
                int random_offset_x = distribution_offset(generator);
                int random_offset_y = distribution_offset(generator);

                // 应用随机偏移量
                int final_x = NumIo[5] + random_offset_x;
                int final_y = NumIo[6] + random_offset_y;

                tx = final_x, ty = final_y;
                Touch_Up(6);
                usleep(3000);  
                if (!NumIo[10])
                    Touch_Down(6, (int)tx, (int)ty);
                else
                    Touch_Down(6, screen_y - (int)tx, screen_x - (int)ty);
                isDown = true;

                tx += TargetX;
                ty += TargetY;

                usleep(1000);
            }

            if (!NumIo[10])
                Touch_Move(6, (int)tx, (int)ty);
            else
                Touch_Move(6, screen_y - (int)tx, screen_x - (int)ty);

            isDown = true;
            usleep(NumIo[9] * 1000);
        } else { 
            IsAimLongAim = false;
            if (isDown) {
                int random_offset_x = distribution_offset(generator);
                int random_offset_y = distribution_offset(generator);

                // 应用随机偏移量
                int final_x = NumIo[5] + random_offset_x;
                int final_y = NumIo[6] + random_offset_y;

                tx = final_x, ty = final_y;
                Touch_Up(6);
                isDown = false;
                usleep(NumIo[9] * 1000);
            }  
        }
    }
}

#endif