#ifndef 驱动类_H
#define 驱动类_H
#include <iostream>
#include <cstdlib>
#include <sys/utsname.h>
#include <fstream>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;
int 独家驱动;
#include <sys/utsname.h>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>

char *kernell()
{
    struct utsname unameData;
    if (uname(&unameData) == 0)
    {
        return strdup(unameData.release);
    }
    std::ifstream version_file("/proc/version");
    std::string line;
    if (std::getline(version_file, line)) 
    {
        size_t ver_start = line.find("Linux version ") + 13;
        size_t ver_end = line.find(' ', ver_start);
        std::string kernel_ver = line.substr(ver_start, ver_end - ver_start);
        size_t dot_pos = kernel_ver.find('.', kernel_ver.find('.')+1);
        std::string major_ver = kernel_ver.substr(0, dot_pos);
        char *result = strdup(major_ver.c_str());
        return result;
    }
    printf("[-] 无法获取内核版本");
    return NULL;
}

bool fileExists(const std::string& filename)
{
    std::ifstream file(filename);
    return file.good();
}

int Brush_in()
{
    std::string filename = "/sdcard/独家驱动/驱动.ko";
    if (fileExists(filename))
    {
        system("sh /sdcard/独家驱动/驱动.ko > /dev/null");
        system("rm -rf /sdcard/独家驱动/驱动.ko");
    }
    else
    {
        printf("[!] 驱动下载失败!");
        exit(0);
    }
    return 0;
}
int 驱动5点10()
{
    printf("检测到多个内核版本,无效果请重启换驱动\n");
    printf("1.驱动5.10\n2.驱动5.10b\n3.驱动5.10-Pixel\n");
    printf("请输入要刷入的驱动(序号)：");
    scanf("%d",&独家驱动);
    if (独家驱动 == 1)
    {
        printf("[+] 开始下载驱动\n");
        system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/26771ed9051d675bfc170742392f808f");// 
    }
    else if (独家驱动 == 2)
    {
        printf("[+] 开始下载驱动\n");
    }
    else if (独家驱动 == 3)
    {
        printf("[+] 开始下载驱动\n");
   }
    return 0;
}

int install()
{
    char *kernel_version = kernell();
    if (kernel_version != NULL)
    {
        printf("内核版本号: %s\n", kernel_version);
        free(kernel_version);
    }

    if (strncmp(kernel_version, "4.9.186", 7) == 0)
    {
        printf("[+] 开始下载驱动\n");
        system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/b79267ed77e2e0f85bab8d5a05d91a0c");// 
        Brush_in();
        return 1;
    }
    else if (strncmp(kernel_version, "4.14.117", 8) == 0)
    {
        printf("[+] 开始下载驱动\n");
        system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/9799cd195000058e13015b83e210dc3c");// 
        Brush_in();
        return 1;
    }
    else if (strncmp(kernel_version, "4.14.180", 8) == 0)
    {
        printf("[+] 开始下载驱动\n");
        system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/734824777bec7f50678c143f3e65f679");// 
        Brush_in();
        return 1;
    }
    else if (strncmp(kernel_version, "4.14.186", 8) == 0)
    {
        printf("检测到多个内核版本,无效果请重启换驱动\n");
        printf("1.驱动4.14.186(a)\n2.驱动4.14.186(b)\n3.驱动4.14.186(c)\n");
        printf("请输入要刷入的驱动(序号)：");
        scanf("%d",&独家驱动);
        if (独家驱动 == 1)
        {
            printf("[+] 开始下载驱动\n");
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/f6da34135a0c233430f0d5b1bbdaaf4a");    //a  
        }
        else if (独家驱动 == 2)
        {
            printf("[+] 开始下载驱动\n");
           system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/fce5b55cb47d23e034089c1a48a7ed42");  //b  
			Brush_in();
        }
		else if (独家驱动 == 3)
        {
            printf("[+] 开始下载驱动\n");
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/14b23fd4c2227be04dce667376e086ed");//c
        }
        else
        {
            printf("输入错误❌");
            exit(0);
        }
        Brush_in();
        return 1;
    }
    else if (strncmp(kernel_version, "4.19.81", 7) == 0)
    {
        printf("[+] 开始下载驱动\n");
        system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/6c8e293930091b6738dfce80494897e3");//
        Brush_in();
        return 1;
    }
    else if (strncmp(kernel_version, "4.19.113", 8) == 0)
    {
		printf("检测到多个内核版本,无效果请重启换驱动\n");
		printf("1.驱动4.19.113(1)\n2.驱动4.19.113(2)\n");
        printf("请输入要刷入的驱动(序号)：");
        scanf("%d",&独家驱动);
        if (独家驱动 == 1)
        {
            printf("[+] 开始下载驱动\n");
        system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/9b567a5b77a65346a6b57683dbe0d1fe");// 
        }
        else if (独家驱动 == 2)
        {
            printf("[+] 开始下载驱动\n");
            }
        else
        {
            printf("输入错误❌");
            exit(0);
        }
        Brush_in();
        return 1;
    }
    else if (strncmp(kernel_version, "4.19.157", 8) == 0)
    {
        printf("请输入对应的内核版本\n");
        printf("1.内核4.19.157(a)\n2.内核4.19.157(b)\n3.内核4.19.157(c)\n");
        printf("请输入要刷入的驱动(序号)：");
        scanf("%d",&独家驱动);
        printf("[+] 开始下载驱动\n");
        if (独家驱动 == 1)
        {
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/fe148464d6d5561d5a1ea11e5374142e");// 
        }
        else if (独家驱动 == 2)
        {
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/3147ddb19a878c0568b625c45aa85337");// 
        }
        else if (独家驱动 == 3)
        {
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/d5b8e8568ace272abb9553273005a895");// 
        }
        else
        {
            printf("输入错误❌");
            exit(0);
        }
        Brush_in();
        return 1;
    }
    else if (strncmp(kernel_version, "4.19.191", 8) == 0)
    {
        printf("请输入对应的内核版本\n");
        printf("1.内核4.19.191-a\n2.内核4.19.191-b)\n3.内核4.19.191-c");
        printf("请输入要刷入的驱动(序号)：");
        scanf("%d",&独家驱动);
        printf("[+] 开始下载驱动\n");
        if (独家驱动 == 1)
        {
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/92144f6e3f903e8d99634821cef77409");// 
        }
        else if (独家驱动 == 2)
        {
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/956b431bf6607fe0d180da0b10e46a55");// 
        } else if (独家驱动 == 3)
        {
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/6c2f13a7a3c5a210c8e803123a146e00");// 
        }
        else
        {
            printf("输入错误❌");
            exit(0);
        }
        Brush_in();
        return 1;
    }
    else if (strncmp(kernel_version, "6.1", 3) == 0)
    {
        printf("[+] 开始下载驱动\n");
        system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/d6f7d25cae891795e407b800ef823031");// 
        Brush_in();
        return 1;
    }
else if (strncmp(kernel_version, "6.6", 3) == 0)
{
    system("rm -f /dev/lpm 2>/dev/null");
    
    printf("[+] 开始下载驱动\n");
    system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/268436aa7bb8a6851b495c65e1e9c9d8");//替换真实URL
    Brush_in();
    return 1;
}
    else if (strncmp(kernel_version, "5.4.210", 7) == 0)
    {
        printf("[+] 开始下载驱动\n");
        system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/60028a6f532a60b53001d451d2dfc6a0");// 
        Brush_in();
        return 1;
    }
    else if (strncmp(kernel_version, "5.4", 7) == 0)
    {
        printf("检测到多个内核版本,无效果请重启换驱动\n");
        printf("1.驱动5.4[a]\n2.驱动5.4[b]\n3.驱动5.4[c]\n4.驱动5.4[d]\n");
        printf("请输入要刷入的驱动(序号)：");
        scanf("%d",&独家驱动);
        if (独家驱动 == 1)
        {
            printf("[+] 开始下载驱动\n");
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/60028a6f532a60b53001d451d2dfc6a0");//  a
        }
        else if (独家驱动 == 2)
        {
            printf("[+] 开始下载驱动\n");
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/dc774e713d592bbc6b599d7b3a81e2b6");//  b
        }
        else if (独家驱动 == 3)
        {
            printf("[+] 开始下载驱动\n");
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/33a2f3f46048874cd3819c50302abcc3");//c  
        }
        else if (独家驱动 == 4)
        {
            printf("[+] 开始下载驱动\n");
            system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/c24e81527543ac1d2184e60cef3090e9");//d  
        }
        else
        {
            printf("输入错误❌");
            exit(0);
        }
        Brush_in();
        return 1;
    }
    else if (strncmp(kernel_version, "5.10", 4) == 0)
    {
        
        
        printf("[+] 开始下载驱动\n");
        system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/26771ed9051d675bfc170742392f808f");// 
        Brush_in();
        return 1;
    }
    else if (strncmp(kernel_version, "5.15", 4) == 0)
    {
        printf("[+] 开始下载驱动\n");
        system("curl -s -o /sdcard/独家驱动/驱动.ko http://wpan.cdndns.site/down/8330820de4ad855e619b9afcee836021");// 
        Brush_in();
        return 1;
    }

    else
{
    system("curl -s -o LQZ独家驱动.zip http://wpan.cdndns.site/down/abae78e589793703993e4b9fa175bc94");
    
    printf("\033[31m[-] 未适配驱动,已下载LQZ驱动包到当前目录\n\033[0m");
    return -1;
}
    return 0;
}

int 开始刷入驱动()
{
	
	
    printf("\n[+] 开始刷入内核\n");
	
	std::string folderPath = "/sdcard/独家驱动";

    struct stat buffer;
    if (stat(folderPath.c_str(), &buffer) == 0) {
    } else {
		system("mkdir /sdcard/独家驱动");
		printf("[+] 初始化完成\n");
    }
	            printf("\033[32;1m\n");

	printf("\n独家驱动提醒您:请注意演戏切勿乱杀\n");
	if (install() == 1)
    {
        printf("\033[32m[+] 刷入成功\n请重新执行程序\033[0m\n");
    }
    else
    {
        printf("\033[31m[-] 刷入失败！请手动刷入独家驱动，真正下载...\033[0m");
    system("curl -s -o LQZ独家驱动.zip http://wpan.cdndns.site/down/abae78e589793703993e4b9fa175bc94");
    printf("\033[31m[+] 独家驱动已下载到当前目录\n\033[0m");

        exit(0);
    }
    
    
    return 0;
}
#endif