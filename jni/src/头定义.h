int PlayerId;
struct NumberAnimation {
    string current;
    string next;
    float progress = 0.0f;
    bool animating = false;
};
enum AnimationMode {
    ANIM_HORIZONTAL,
    ANIM_VERTICAL,
    ANIM_BEZIER
};
float animationDamping = 0.07f;
void UpdateAnimation(float &value, float target, float damping) {
    value += (target - value) * damping;
    if (fabs(target - value) < 0.005f) {
        value = target;
    }
}
static AnimationMode currentAnimationMode = ANIM_HORIZONTAL;
NumberAnimation playerAnim;
NumberAnimation botAnim;

using namespace std;
timer RenderingFPS;
float globalFontScale = 1.3f; 
struct FontSettings {
    float scale = 1.0f;
    float minScale = 0.5f;
    float maxScale = 2.0f;
    bool dirty = false;
    void SetScale(float newScale) {
        scale = std::clamp(newScale, minScale, maxScale);
        dirty = true;
    }
    void ApplyScale(ImGuiIO& io) {
        if (dirty) {
            io.FontGlobalScale = scale;
            dirty = false;
        }
    }
};
static FontSettings globalFontSettings;
ImTextureID logo_png, 主页_png, 绘图_png, 瞄准_png, 物资_png, 设置_png, 背景_png, 人类_png, 非人类_png, 安卓_png, 驱动_png;
bool DrawIo[50];
float NumIo[50];
bool 物资[50];
ImColor 物资颜色[50];
ImColor 绘制颜色[16];
float 绘制粗细[16];
float draw_style[20];
float thickness[150];
float fwjl = NumIo[3];
Data fanhua;
WuziData wz;
string wht, flp;
void Draw_Meun();
void NumIoLoad(const char *name);
void AimBotAuto();
void Draw_Main(ImDrawList *Draw);
void 启动和平精英() {
    string command = "am start -n com.vng.pubgmobile/com.epicgames.ue4.SplashActivity";
    system(command.c_str());
}

void CleanData() {
DrawIo[3] = true;
DrawIo[5] = true;
DrawIo[6] = true;
DrawIo[20] = true;
DrawIo[25] = true;
DrawIo[10] = true;
DrawIo[8] = true;
DrawIo[2] = true;
物资颜色[0] = ImColor(255,255,255,255);
物资颜色[1] = ImColor(255,255,255,255);
物资颜色[2] = ImColor(255,255,255,255);
物资颜色[3] = ImColor(255,255,255,255);
物资颜色[4] = ImColor(255,255,255,255);
物资颜色[5] = ImColor(255,255,255,255);
物资颜色[6] = ImColor(255,255,255,255);
物资颜色[7] = ImColor(255,255,255,255);
物资颜色[8] = ImColor(255,255,255,255);
物资颜色[9] = ImColor(255,255,255,255);
物资颜色[10] = ImColor(255,255,255,255);
物资颜色[11] = ImColor(255,255,255,255);
物资颜色[12] = ImColor(255,255,255,255);
物资颜色[13] = ImColor(255,255,255,255);
物资颜色[14] = ImColor(255,255,255,255);
物资颜色[15] = ImColor(255,255,255,255);
物资颜色[16] = ImColor(255,255,255,255);
物资颜色[17] = ImColor(255,255,255,255);
物资颜色[18] = ImColor(255,255,255,255);
物资颜色[19] = ImColor(255,255,255,255);
物资颜色[20] = ImColor(255,255,255,255);
绘制颜色[0] = ImColor(255,0,0,150);
绘制颜色[1] = {1.0f,0.0f,0.0f,1.0f};
绘制颜色[2] = ImColor(255,255,255,255);
绘制颜色[3] = ImColor(0,0,0,25);
绘制颜色[4] = ImColor(0,0,0,0);
绘制颜色[5] = ImColor(255,0,0,255);
绘制颜色[6] = ImColor(255,255,255,255);
绘制颜色[7] = ImColor(255,0,0,255);
绘制颜色[8] = ImColor(255,255,255,255);
绘制粗细[1] = 1.5f;
绘制粗细[2] = 1.5f;
绘制粗细[3] = 1.5f;
绘制粗细[4] = 1.5f;
绘制粗细[5] = 2.5f;
绘制粗细[6] = 2.5f;
NumIo[1] = 300.0f;  
NumIo[2] = 400.0f;
NumIo[3] = 120.0f;
NumIo[4] = 15.0f;
NumIo[5] = 650.0f;
NumIo[6] = 1400.0f;
NumIo[7] = 150.0f;
NumIo[9] = 3.5f; 
NumIo[10] = 0.0f;
NumIo[11] = 600.0f;
NumIo[12] = 90;
NumIo[13] = 0.0f;
NumIo[14] = 1.5f;
NumIo[15] = 0.0f;
NumIo[16] = 100.0f;
NumIo[17] = 80.0f;
NumIo[18] = 80.0f;
NumIo[19] = 150.0f;
NumIo[20] = 50.0f;
NumIo[21] = 50.0f;
NumIo[22] = 1.0f;
NumIo[31] = 50;
NumIo[32] = 200;
NumIo[40] = 100.0f;
NumIo[49] = 1.0f;

draw_style[3] = 120;
draw_style[7] = 1;
draw_style[8] = 100;
draw_style[9] = 100;
draw_style[1] = 1;
draw_style[2] = 0;
NumIo[8] = 0;
}

FILE *numSave = nullptr;
void NumIoSave(const char *name) {
if (numSave == nullptr) {
string SaveFile = "/data";
SaveFile += "/";
SaveFile += name;
numSave = fopen(SaveFile.c_str(), "wb+");
}
fseek(numSave, 0, SEEK_SET);
fwrite(DrawIo, sizeof(bool) * 50, 1, numSave);
fwrite(NumIo, sizeof(float) * 50, 1, numSave);
fwrite(draw_style, sizeof(float) * 20, 1, numSave);
fwrite(&绘制粗细, sizeof(float) * 16, 1, numSave);
fwrite(&绘制颜色, sizeof(ImColor) * 16, 1, numSave);
fflush(numSave);
fsync(fileno(numSave));
}
void NumIoLoad(const char *name) {
if (numSave == nullptr) {
string SaveFile = "/data";
SaveFile += "/";
SaveFile += name;
numSave = fopen(SaveFile.c_str(), "rb+");
}
if (numSave != nullptr) {
fseek(numSave, 0, SEEK_SET);
fread(DrawIo, sizeof(bool) * 50, 1, numSave);
fread(NumIo, sizeof(float) * 50, 1, numSave);
fread(draw_style, sizeof(float) * 20, 1, numSave);
fread(&绘制粗细, sizeof(float) * 16, 1, numSave);
fread(&绘制颜色, sizeof(ImColor) * 16, 1, numSave);
} else {
CleanData();
}
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
bool validateInput(const string& input, const vector<string>& validOptions) {
    string lowerInput = input;
    transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
    for (const auto& opt : validOptions) {
        if (lowerInput == opt) return true;
    }
    return false;
}