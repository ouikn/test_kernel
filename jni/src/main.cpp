using namespace std;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <fstream>
#include <string.h>
#include <time.h>

#include <malloc.h>
#include <iostream>
#include <fstream>
#include<iostream>
#include<ctime>

#include <draw.h>
#include <TouchHelper.h>

#include "结构体.h"
#include "封装函数.h"
#include "头定义.h"

#include "Android_draw/图片调用.h"
#include "Android_draw/手持图片/touxiang.h"
#include "FH.h"
#include "Android_draw/手持图片/繁华手持.h"
#include "Android_draw/手持图片/主页图标.h"
#include "Android_draw/手持图片/绘图图标.h"
#include "Android_draw/手持图片/瞄准图标.h"
#include "Android_draw/手持图片/物资图标.h"
#include "Android_draw/手持图片/设置图标.h"
#include "Android_draw/手持图片/人类类型绘制.h"
#include "Android_draw/手持图片/非人类类型绘制.h"
#include "Android_draw/手持图片/背景.h"
#include "Android_draw/手持图片/Linux.h"
#include "Android_draw/手持图片/Android.h"
static std::string android_version = "未知";
void init_android_version() {
    FILE* pipe = popen("getprop ro.build.version.release", "r");
    if (pipe) {
        char buffer[128];
        if (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0;
            android_version = buffer;
        } else {
            android_version = "获取失败";
        }
        pclose(pipe);
    } else {
        android_version = "无法执行命令";
    }
} 
int main() {
   printf("\n");
printf("\033[38;2;255;0;0m"); 
printf("███████╗██╗  ██╗      \n");
printf("\033[38;2;255;255;0m"); 
printf("██╔════╝██║  ██║      \n");
printf("\033[38;2;0;255;0m"); 
printf("█████╗  ███████║      \n");
printf("\033[38;2;79;193;202m"); 
printf("██╔══╝  ██╔══██║      \n");
printf("\033[38;2;15;38;255m"); 
printf("██║     ██║  ██║      \n");
printf("╚═╝     ╚═╝  ╚═╝      \n");
printf("\033[38;2;255;0;255m");
printf("██╗  ██╗███████╗██████╗ ███╗   ██╗███████╗██╗\n");
printf("██║ ██╔╝██╔════╝██╔══██╗████╗  ██║██╔════╝██║\n");
printf("█████╔╝ █████╗  ██████╔╝██╔██╗ ██║█████╗  ██║\n");
printf("██╔═██╗ ██╔══╝  ██╔══██╗██║╚██╗██║██╔══╝  ╚═╝\n");
printf("██║  ██╗███████╗██║  ██║██║ ╚████║███████╗██╗\n");
printf("╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝\n");
printf("\033[0m");   
init_android_version();
    const char* nobackground_path = "/sdcard/无后台";
    if (access(nobackground_path, F_OK) == 0) {
    pid_t pid = fork();
    if (pid > 0) {
        exit(0);
    } else if (pid == 0) {
    
    } else {
        fprintf(stderr, "[+]无后台模式开启失败\n");
        exit(1);
    }
}
const char* antirecord_path = "/sdcard/防录屏";
bool antiRecording = (access(antirecord_path, F_OK) == 0);

screen_config(); 
init_screen_x = screen_x + screen_y;
init_screen_y = screen_y + screen_x;

if (!init_vulkan(init_screen_x, init_screen_y, antiRecording)) {
    exit(0);
}
    draw_style[10] = 5;
    NumIoLoad("繁华配置");
    if (draw_style[10] == 5) {
        draw_style[10] = 1;
        启动和平精英();
    }
    if (draw_style[10] == 1) {
        printf("宝宝！原来你也玩和平精英啊！嘻嘻\n");
    }
    ImGui_init();
    TouchScreenHandle();
    std::thread aim_thread(AimBotAuto);
    aim_thread.detach();
    window_set();
    logo_png = VK.ImAgeHeadFile(touxiang, sizeof(touxiang));
    主页_png = VK.ImAgeHeadFile(png主页图标, sizeof(png主页图标));
    绘图_png = VK.ImAgeHeadFile(png绘图图标, sizeof(png绘图图标));
    瞄准_png = VK.ImAgeHeadFile(png瞄准图标, sizeof(png瞄准图标));
    物资_png = VK.ImAgeHeadFile(png物资图标, sizeof(png物资图标));
    设置_png = VK.ImAgeHeadFile(png设置图标, sizeof(png设置图标));
    背景_png = VK.ImAgeHeadFile(背景, sizeof(背景));
    人类_png = VK.ImAgeHeadFile(人类类型绘制, sizeof(人类类型绘制));
    非人类_png = VK.ImAgeHeadFile(非人类类型绘制, sizeof(非人类类型绘制));
    安卓_png = VK.ImAgeHeadFile(anzhuo, sizeof(anzhuo));
    驱动_png = VK.ImAgeHeadFile(linux, sizeof(linux));
    加载枪械图片();
    RenderingFPS.AotuFPS_init();
    RenderingFPS.setAffinity();
    ImGui_ImplAndroid_NewFrame(init_screen_x, init_screen_y);
    while (true) {
        auto start = std::chrono::high_resolution_clock::now();
        RenderingFPS.SetFps(NumIo[12]);
        RenderingFPS.AotuFPS();
        VK_Begin();
        if (fanhua.pid > 0 && fanhua.libUE4 > 0) {
            Draw_Main(ImGui::GetForegroundDrawList());
        }     
        Draw_Meun();
        VK_End();     
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);        
        if (elapsed.count() < 16) {
            std::this_thread::sleep_for(std::chrono::milliseconds(16 - elapsed.count()));
        }
    }
    shutdown();
    return 0;
}

#include "Android_draw/其他.h"
#define AIMBOT_SEPARATED
#include "Aim/Aim.h"
int AimCount, MaxPlayerCount, Gmin = -1;
float zm_x, zm_y;
bool IsAimLongAim = false;
char AimName[32];
Vec2 vpvp;
AimStruct Aim[100];
void Draw_Main(ImDrawList *Draw) {
if (draw_style[10] == 1) {
#include "Android_draw/hook.h"
}

if (DrawIo[21]) {
string ssf;  
ssf += "勿放控件，长按拖动";
auto textSize = ImGui::CalcTextSize(ssf.c_str(), 0, 32);
Draw->AddRectFilled({0,0}, {screen_x, screen_y},ImColor(0,0,0,110));
Draw->AddRectFilled({NumIo[6] - NumIo[7] / 2, screen_y - NumIo[5] + NumIo[7] / 2}, {NumIo[6] + NumIo[7] / 2, screen_y - NumIo[5] - NumIo[7] / 2}, 绘制颜色[0]); 
Draw->AddText(NULL, 32, {NumIo[6] - (textSize.x / 2), screen_y - NumIo[5]}, ImColor(255, 255, 255), ssf.c_str());
}
if (DrawIo[20] && fanhua.TotalUp) {
    if (DrawIo[45]) {
        if (Gmin != -1) {
Draw->AddCircle({screen_x / 2, screen_y / 2}, fwjl, ImColor(255,255,255,255), 0, 1.0f);
} else {
Draw->AddCircle({screen_x / 2, screen_y / 2}, NumIo[3], ImColor(255,255,255,255), 0, 1.0f); 
        }
    }
 }
if(DrawIo[44] && Gmin != -1) {
Draw->AddLine({screen_x / 2, screen_y / 2}, {vpvp.x, vpvp.y}, ImColor(255,255,255,255), 3.0f);
    }
}
#include "UI.h"
