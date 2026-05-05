#define NEKO_H
#include <sys/fcntl.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/utsname.h>
#include <regex.h>
#include <dirent.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <sys/syscall.h>

#define MAX_PAYLOAD 1048

// dit 3.3
struct Memory_uct {
    int read_write; // 读或者写
    int pid;
    uintptr_t addr;
    void *buffer;
    size_t size;
};

// dit pro 3.3
struct Ditpro_uct {
    int read_write; // 读或者写
    int pid;
    uintptr_t addr;
    void *buffer;
    size_t size;
    int wendi; // 这个是判断只进行属于我们的操作,616
};

class c_driver {
private:
    bool ditbool;
    int sock_fd;
    struct sockaddr_nl dest_addr;
    struct nlmsghdr *nlh;
    struct iovec iov;
    struct msghdr msg;
    pid_t pid;
    int drivers_byte;

public:
    c_driver() {
        drivers_byte = 0;
        sock_fd = -1;
        nlh = NULL;
        
        printf("\033[37m");
        printf("\n欢迎使用巴巴托斯 Welcome ues winged Barbatos");
        printf("\n官方TG频道[巴巴托斯公益]@？？？");
        printf("\n官方TG频道[主频道]@？？？");
        printf("\n[0]Hook方案 (ditpro 3.3)");
        printf("\n[1]netlink方案 (dit 3.3)");
        printf("\n请输入选择的驱动程序：");
        
        int 选择值;
        scanf("%d", &选择值);
        
        if (选择值 == 1) {
            sock_fd = socket(PF_NETLINK, SOCK_RAW, 17);
            
            if (sock_fd < 0) {
                if (sock_fd != -1) {
                    close(sock_fd);
                    sock_fd = -1;
                }
                if (nlh != NULL) {
                    free(nlh);
                    nlh = NULL;
                }
                this->drivers_byte = 0;
                printf("[-] DIT驱动初始化失败，切换到ditPro驱动\n");
            } else {
                memset(&dest_addr, 0, sizeof(dest_addr));
                dest_addr.nl_family = AF_NETLINK;
                dest_addr.nl_pid = 0;
                dest_addr.nl_groups = 0;

                nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
                if (!nlh) {
                    perror("malloc");
                    exit(1);
                }
                memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD));
                nlh->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
                nlh->nlmsg_flags = 0;

                iov.iov_base = (void *)nlh;
                iov.iov_len = nlh->nlmsg_len;

                msg.msg_name = (void *)&dest_addr;
                msg.msg_namelen = sizeof(dest_addr);
                msg.msg_iov = &iov;
                msg.msg_iovlen = 1;
                
                this->ditbool = true;
                this->drivers_byte = 1;
                printf("[+] dit驱动初始化成功\n");
            }
        } else if (选择值 == 0) {
            this->drivers_byte = 0;
            printf("[+] 使用ditPro驱动\n");
        } else {
            printf("[-] 无效选择，默认使用ditPro驱动\n");
            this->drivers_byte = 0;
        }
    }

    ~c_driver() {
        if (sock_fd != -1 && (int)this->drivers_byte == 1)
            close(sock_fd);
        if (nlh != NULL && (int)this->drivers_byte == 1)
            free(nlh);
    }

    void initialize(pid_t pid) {
        this->pid = pid;
    }

    bool read(uintptr_t addr, void *buffer, size_t size) {
        if((int)this->drivers_byte == 1 && this->ditbool == true) {
            struct Memory_uct ptr;
            void *uctaddr = &ptr;
            ptr.addr = addr;
            ptr.buffer = buffer;
            ptr.pid = this->pid;
            ptr.read_write = 0x400;
            ptr.size = size;
            int bytelen = 8;
            char *source = (char *)&uctaddr;
            char *target = (char *)NLMSG_DATA(nlh);
            if(source == NULL || target == NULL)
                return false;
            while (bytelen--) {
                *target++ = *source++;
            }
            if (sendmsg(sock_fd, &msg, 0) < 0) {
                return false;
            }
        } else if((int)this->drivers_byte == 0) {
            struct Ditpro_uct ptr;
            ptr.read_write = 0x400;
            ptr.addr = addr;
            ptr.buffer = buffer;
            ptr.wendi = 616;
            ptr.pid = this->pid;
            ptr.size = size;
            
            if(syscall(__NR_lookup_dcookie, &ptr)) {
                return true;
            }
        }
        return true;
    }

    template <typename T>
    T read(uintptr_t addr) {
        T res;
        if (this->read(addr, &res, sizeof(T)))
            return res;
        return {};
    }

    bool write(uintptr_t addr, void *buffer, size_t size) {
        if((int)this->drivers_byte == 1 && this->ditbool == true) {
            struct Memory_uct ptr;
            void *uctaddr = &ptr;
            ptr.addr = addr;
            ptr.buffer = buffer;
            ptr.pid = this->pid;
            ptr.read_write = 0x200;
            ptr.size = size;
            int bytelen = 8;
            char *source = (char *)&uctaddr;
            char *target = (char *)NLMSG_DATA(nlh);
            if(source == NULL || target == NULL)
                return false;
            while (bytelen--) {
                *target++ = *source++;
            }
            if (sendmsg(sock_fd, &msg, 0) < 0) {
                return false;
            }
        } else if((int)this->drivers_byte == 0) {
            struct Ditpro_uct ptr;
            ptr.read_write = 0x200;
            ptr.addr = addr;
            ptr.buffer = buffer;
            ptr.wendi = 616;
            ptr.pid = this->pid;
            ptr.size = size;
            
            if(syscall(__NR_lookup_dcookie, &ptr)) {
                return true;
            }
        }
        return true;
    }

    template <typename T>
    bool write(uintptr_t addr, T value) {
        return this->write(addr, &value, sizeof(T));
    }

    uintptr_t getModuleBase(const char *module_name) { 
        FILE *fp; 
        long addr = 0; 
        char *pch; 
        char filename[64]; 
        char line[1024]; 
        snprintf(filename, sizeof(filename), "/proc/%d/maps", this->pid); 
        fp = fopen(filename, "r"); 
        if (fp != NULL) { 
            while (fgets(line, sizeof(line), fp)) { 
                if (strstr(line, module_name)) { 
                    pch = strtok(line, "-"); 
                    addr = strtoul(pch, NULL, 16); 
                    if (addr == 0x8000) addr = 0; 
                    break; 
                } 
            } 
            fclose(fp); 
        } 
        return addr; 
    }

    pid_t GetPid(char* name) {
        int id = -1; 
        DIR *dir; 
        FILE *fp; 
        char filename[64]; 
        char cmdline[64]; 
        struct dirent *entry; 
        dir = opendir("/proc"); 
        while ((entry = readdir(dir)) != NULL) { 
            id = atoi(entry->d_name); 
            if (id != 0) { 
                sprintf(filename, "/proc/%d/cmdline", id); 
                fp = fopen(filename, "r"); 
                if (fp) { 
                    fgets(cmdline, sizeof(cmdline), fp); 
                    fclose(fp); 
                    if (strcmp(name, cmdline) == 0) { 
                        return id; 
                    } 
                } 
            } 
        } 
        closedir(dir); 
        return -1; 
    }
};

static c_driver* driver = new c_driver();
