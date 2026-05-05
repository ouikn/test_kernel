AimCount = 0;
fanhua.PlayerCount = 0;
fanhua.BotCount = 0;
float cornerRadius = 7.0f;

fanhua.Gname = driver->read<uintptr_t>(fanhua.libUE4 + 0x11A98608);
fanhua.Uworld = driver->read<uintptr_t>(fanhua.libUE4 + 0x12161358);
fanhua.Uleve = driver->read<uintptr_t>(fanhua.Uworld + 0x90);
fanhua.Arrayaddr = driver->read<uintptr_t>(fanhua.Uleve + 0xA0);
fanhua.Count = driver->read<int>(fanhua.Uleve + 0xA8);
fanhua.Oneself = driver->read<uintptr_t>(driver->read<uintptr_t>(driver->read<uintptr_t>(driver->read<uintptr_t>(driver->read<uintptr_t>(fanhua.libUE4 + 0x12161358) + 0x98)+0x88)+0x30)+0x32a8);
fanhua.MyTeam = driver->read<int>(fanhua.Oneself + 0xac0);
driver->read(driver->read<uintptr_t>(fanhua.Oneself + 0x278) + 0x200, &fanhua.MyPos, 12);
driver->read(fanhua.Matrixs, &fanhua.matrix, 16 * 4);
fanhua.Fov = driver->read<float>(driver->read<uintptr_t>(driver->read<uintptr_t>(fanhua.Oneself + 0x5588) + 0x608) + 0x630);
fanhua.IsFiring = driver->read<int>(fanhua.Oneself + 0x23e0);
fanhua.IsAiming = driver->read<int>(fanhua.Oneself + 0x1668);
fanhua.angle = driver->read<float>(fanhua.Oneself + 0x1a8);
char *CasName;
for (int i = 0; i < fanhua.Count; i ++) {
fanhua.Objaddr = driver->read<uintptr_t>(fanhua.Arrayaddr + 8 * i);
if (fanhua.Oneself == fanhua.Objaddr || fanhua.Objaddr <= 0x10000000 || fanhua.Objaddr % 4 != 0 || fanhua.Objaddr >= 0x10000000000)
continue;
uintptr_t object = driver->read<uintptr_t>(fanhua.Objaddr + 0x278);
if (object <= 0xffff || object == 0 || object <= 0x10000000 || object % 4 != 0 || object >= 0x10000000000)
continue;
if (driver->read<float>(fanhua.Objaddr + 0x3518) != 479.5) {
GetClassName(wz.Name, fanhua.Gname, driver->read<int>(fanhua.Objaddr + 0x18));
driver->read(object + 0x1F0, &wz.Pos, 12);
GetDistance(wz.Pos, fanhua.MyPos, &wz.Distance);
WorldToScreen(&wz.ScreenPos, &wz.camera, &wz.w, wz.Pos);
} else {
int State = driver->read<int>(fanhua.Objaddr + 0x1538);
if (State == 1048576 || State == 1048592 || State == 1048577 || State == 0)
continue;
fanhua.TeamID = driver->read<int>(fanhua.Objaddr + 0xac0);
if (fanhua.TeamID == fanhua.MyTeam || fanhua.TeamID < 1)
continue;
	if (DrawIo[1000]) {
	float 观透Team = NumIo[49];
fanhua.TeamID = driver->read<int>(fanhua.Objaddr + 0xac0);
if (观透Team == fanhua.TeamID){
continue;
}
}
fanhua.Health = (driver->read<float>(fanhua.Objaddr + 0xed8) / driver->read<float>(fanhua.Objaddr + 0xee0)) * 100;
if (fanhua.Health > 100)
continue;
driver->read(object + 0x200, &fanhua.Pos, 12); 
GetDistance(fanhua.Pos, fanhua.MyPos, &fanhua.Distance); 
WorldToScreen(&fanhua.ScreenPos, &fanhua.camera, &fanhua.w, fanhua.Pos); 
if (driver->read<int>(fanhua.Objaddr +  0xadc)) fanhua.IsBot = 1; else fanhua.IsBot = 0;
if (fanhua.IsBot) fanhua.BotCount++; else fanhua.PlayerCount++;
if(DrawIo[17])
{
if (fanhua.IsBot == 1)
{
 continue;
}
}
if (fanhua.w < 0 || fanhua.w > screen_x)
continue;
if (driver->read<uintptr_t>(fanhua.Objaddr + 0x1000)) {
driver->read(driver->read<uintptr_t>(fanhua.Objaddr + 0xf30) + 0x1330, &fanhua.Predict, sizeof(fanhua.Predict)); 
} else {
driver->read(object + 0x71c, &fanhua.Predict, sizeof(fanhua.Predict)); 
}
fanhua.敌人头 = driver->read<int>(driver->read<uintptr_t>(fanhua.Objaddr + 0x49b0) + 0x1FC);
fanhua.敌人甲 = driver->read<int>(driver->read<uintptr_t>(fanhua.Objaddr + 0x49b0) + 0x234);
fanhua.敌人包 = driver->read<int>(driver->read<uintptr_t>(fanhua.Objaddr + 0x49b0) + 0x1C4);

fanhua.敌方动作 = driver->read<int>(driver->read<uint64_t>(fanhua.Objaddr + 0x1538));
fanhua.dqzd = driver->read<int>(driver->read<uintptr_t>(driver->read<uintptr_t>(fanhua.Objaddr + 0x3190) + 0x678) + 0x19e0);
fanhua.zdmax = driver->read<int>(driver->read<uintptr_t>(driver->read<uintptr_t>(fanhua.Objaddr + 0x3190) + 0x678) + 0x19e4);
fanhua.scwq = driver->read<uintptr_t>(driver->read<uintptr_t>(driver->read<uintptr_t>(fanhua.Objaddr + 0x3190) + 0x678) + 0xbd0);
fanhua.Mesh = driver->read<uintptr_t>(fanhua.Objaddr + 0x600);
fanhua.Human = fanhua.Mesh + 0x1f0;
fanhua.Bone = driver->read<uintptr_t>(fanhua.Mesh + 0x7f8) + 0x30;
int BoneCount = driver->read<uint64_t>(fanhua.Mesh + 0x7f8+8);
getUTF8(fanhua.PlayerName, driver->read<uintptr_t>(fanhua.Objaddr + 0xa40));

int p = (BoneCount == 68) ? 33 : 32;
int o = (BoneCount == 68) ? 34 : 33;
int a = (BoneCount == 68) ? 13 : 63;
int b = (BoneCount == 68) ? 35 : 62;
int c = (BoneCount == 68) ? 55 : 52;
int d = (BoneCount == 68) ? 59 : 56;
int e = (BoneCount == 68) ? 56 : 53;
int f = (BoneCount == 68) ? 60 : 57;
int g = (BoneCount == 68) ? 57 : 54;
int h = (BoneCount == 68) ? 61 : 58;

FTransform meshtrans = getBone(fanhua.Human);
FMatrix c2wMatrix = TransformToMatrix(meshtrans);

FTransform headtrans = getBone(fanhua.Bone + 5 * 48);
FMatrix boneMatrix = TransformToMatrix(headtrans);
fanhua.Head.Pos = MarixToVector(MatrixMulti(boneMatrix, c2wMatrix));
fanhua.Head.Pos.z += 7; 

fanhua.Head.ScreenPos = WorldToScreen(fanhua.Head.Pos, fanhua.matrix, fanhua.camera);
FTransform chesttrans = getBone(fanhua.Bone + 4 * 48);
FMatrix boneMatrix1 = TransformToMatrix(chesttrans);
fanhua.Chest.Pos = MarixToVector(MatrixMulti(boneMatrix1, c2wMatrix));

fanhua.Chest.ScreenPos = WorldToScreen(fanhua.Chest.Pos, fanhua.matrix, fanhua.camera);
FTransform pelvistrans = getBone(fanhua.Bone + 0 * 48);
FMatrix boneMatrix2 = TransformToMatrix(pelvistrans);
fanhua.Pelvis.Pos = MarixToVector(MatrixMulti(boneMatrix2, c2wMatrix));

fanhua.Pelvis.ScreenPos = WorldToScreen(fanhua.Pelvis.Pos, fanhua.matrix, fanhua.camera);
FTransform lshtrans = getBone(fanhua.Bone + 11 * 48);
FMatrix boneMatrix3 = TransformToMatrix(lshtrans);
fanhua.Left_Shoulder.Pos = MarixToVector(MatrixMulti(boneMatrix3, c2wMatrix));

fanhua.Left_Shoulder.ScreenPos = WorldToScreen(fanhua.Left_Shoulder.Pos, fanhua.matrix, fanhua.camera);
FTransform rshtrans = getBone(fanhua.Bone + p * 48);
FMatrix boneMatrix4 = TransformToMatrix(rshtrans);
fanhua.Right_Shoulder.Pos = MarixToVector(MatrixMulti(boneMatrix4, c2wMatrix));

fanhua.Right_Shoulder.ScreenPos = WorldToScreen(fanhua.Right_Shoulder.Pos, fanhua.matrix, fanhua.camera);
FTransform lelbtrans = getBone(fanhua.Bone + 12 * 48);
FMatrix boneMatrix5 = TransformToMatrix(lelbtrans);
fanhua.Left_Elbow.Pos = MarixToVector(MatrixMulti(boneMatrix5, c2wMatrix));

fanhua.Left_Elbow.ScreenPos = WorldToScreen(fanhua.Left_Elbow.Pos, fanhua.matrix, fanhua.camera);
FTransform relbtrans = getBone(fanhua.Bone + o * 48);
FMatrix boneMatrix6 = TransformToMatrix(relbtrans);
fanhua.Right_Elbow.Pos = MarixToVector(MatrixMulti(boneMatrix6, c2wMatrix));

fanhua.Right_Elbow.ScreenPos = WorldToScreen(fanhua.Right_Elbow.Pos, fanhua.matrix, fanhua.camera);
FTransform lwtrans = getBone(fanhua.Bone + a * 48);
FMatrix boneMatrix7 = TransformToMatrix(lwtrans);
fanhua.Left_Wrist.Pos = MarixToVector(MatrixMulti(boneMatrix7, c2wMatrix));

fanhua.Left_Wrist.ScreenPos = WorldToScreen(fanhua.Left_Wrist.Pos, fanhua.matrix, fanhua.camera);
FTransform rwtrans = getBone(fanhua.Bone + b * 48);
FMatrix boneMatrix8 = TransformToMatrix(rwtrans);
fanhua.Right_Wrist.Pos = MarixToVector(MatrixMulti(boneMatrix8, c2wMatrix));

fanhua.Right_Wrist.ScreenPos = WorldToScreen(fanhua.Right_Wrist.Pos, fanhua.matrix, fanhua.camera);
FTransform Llshtrans = getBone(fanhua.Bone + c * 48);
FMatrix boneMatrix9 = TransformToMatrix(Llshtrans);
fanhua.Left_Thigh.Pos = MarixToVector(MatrixMulti(boneMatrix9, c2wMatrix));

fanhua.Left_Thigh.ScreenPos = WorldToScreen(fanhua.Left_Thigh.Pos, fanhua.matrix, fanhua.camera);
FTransform Lrshtrans = getBone(fanhua.Bone + d * 48);
FMatrix boneMatrix10 = TransformToMatrix(Lrshtrans);
fanhua.Right_Thigh.Pos = MarixToVector(MatrixMulti(boneMatrix10, c2wMatrix));

fanhua.Right_Thigh.ScreenPos = WorldToScreen(fanhua.Right_Thigh.Pos, fanhua.matrix, fanhua.camera);
FTransform Llelbtrans = getBone(fanhua.Bone + e * 48);
FMatrix boneMatrix11 = TransformToMatrix(Llelbtrans);
fanhua.Left_Knee.Pos = MarixToVector(MatrixMulti(boneMatrix11, c2wMatrix));

fanhua.Left_Knee.ScreenPos = WorldToScreen(fanhua.Left_Knee.Pos, fanhua.matrix, fanhua.camera);
FTransform Lrelbtrans = getBone(fanhua.Bone + f * 48);
FMatrix boneMatrix12 = TransformToMatrix(Lrelbtrans);
fanhua.Right_Knee.Pos = MarixToVector(MatrixMulti(boneMatrix12, c2wMatrix));

fanhua.Right_Knee.ScreenPos = WorldToScreen(fanhua.Right_Knee.Pos, fanhua.matrix, fanhua.camera);
FTransform Llwtrans = getBone(fanhua.Bone + g * 48);
FMatrix boneMatrix13 = TransformToMatrix(Llwtrans);
fanhua.Left_Ankle.Pos = MarixToVector(MatrixMulti(boneMatrix13, c2wMatrix));

fanhua.Left_Ankle.ScreenPos = WorldToScreen(fanhua.Left_Ankle.Pos, fanhua.matrix, fanhua.camera);
FTransform Lrwtrans = getBone(fanhua.Bone + h * 48);
FMatrix boneMatrix14 = TransformToMatrix(Lrwtrans);
fanhua.Right_Ankle.Pos = MarixToVector(MatrixMulti(boneMatrix14, c2wMatrix));

fanhua.Right_Ankle.ScreenPos = WorldToScreen(fanhua.Right_Ankle.Pos, fanhua.matrix, fanhua.camera);
#include "绘图与物资/绘图.h"
}
#include "绘图与物资/物资.h"
}
MaxPlayerCount = AimCount;
fanhua.TotalUp = fanhua.PlayerCount + fanhua.BotCount;
