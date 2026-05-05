#ifndef 物资_H
#define 物资_H

using namespace std;
char *dzdz(int dzid) {
switch (dzid) {

//站立一系列
case 8:
 return"立正";
break;
case 521:
 return"开镜";
break;
case 648:
 return"开火";
break;
case 649:
 return"开火";
break;
case 1032:
 return"探头";
break;
case 1033:
 return"探头";
break;
case 136:
 return"开火";
break;
case 137:
case 139:
 return"开火";
break;
case 1160:
 return"探头";
break;
case 1161:
 return"探头";
break;
case 1544:
 return"开镜";
break;
case 1545:
 return"开镜";
break;
case 1672:
 return"开火";
break;
case 1673:
 return"开火";
break;
case 8200:
 return"挥拳";
break;
case 8201:
case 8203:
 return"挥拳";
break;
case 267:
 return"换弹";
break;
case 17417:
 return"投掷";
break;
//蹲下一系列
case 16:
 return"蹲下";
break;
case 17:
case 147:
 return"开火";
break;
case 656:
 return"开火";
break;
case 657:
 return"开火";
break;
case 1040:
 return"探头";
break;
case 1041:
 return"探头";
break;
case 528:
 return"开镜";
break;
case 529:
 return"开镜";
break;
case 1168:
 return"开火";
break;
case 1169:
 return"开火";
break;
case 1552:
 return"开镜";
break;
case 1553:
 return"开镜";
break;
case 1680:
 return"开火";
break;
case 1681:
 return"开火";
break;
case 8209:
 return"挥拳";
break;
case 275:
 return"换弹";
break;
case 2064:
 return"换枪";
break;
case 16401:
 return"投掷";
break;
case 17425:
 return"投掷";
break;
case 65553:
 return"打药";
break;
//趴下一系列
case 32:
 return"趴下";
break;
case 33:
case 34:
case 35:
 return"趴下";
break;
case 544:
 return"开镜";
break;
case 545:
 return"开镜";
break;
case 672:
 return"开火";
break;
case 289:
case 291:
 return"换弹";
break;
case 16417:
 return"投掷";
break;
//跳跃一系列
case 72:
 return"跳跃";
break;
case 73:
case 75:
 return"跳跃";
break;
case 8264:
 return"跳拳";
break;
case 8265:
case 8267:
 return"跳拳";
break;
case 203:
 return"开火";
break;
case 331:
 return"换弹";
break;
//车一系列
case 524296:
 return"开车";
break;
case 1048584:
 return"没动";
break;
case 3145736:
 return"探头";
break;
case 3145864:
 return"开火";
break;
case 3146248:
 return"开镜";
break;
case 3146376:
 return"开火";
break;
case 3145992:
 return"换弹";
break;
case 3162120:
 return"投掷";
break;
//游泳
case 4194307:
case 4194305:
 return"游泳";
break;
//倒地

//其它一系列
case 16777226:
 return"攀爬";
break;
case 10:
 return"跑跳";
break;
case 8202:
 return"跳拳";
break;
case 268435464:
 return"跳舞";
break;
case 1073741832:
 return"立正";
break;


case 329:
case 328:
case 288:
case 272:
case 273:
case 264:
case 265:
return "换弹";
break;

case 9:
return "行走";
break;

case 11:
return "跑路";
break;

case 16777224:
return "翻墙";
break;


case 16392:
case 17416:
case 16400:
case 17424:
case 16416:
case 16456:
case 16393:
case 16457:
return "投掷";
break;


case 520:
return "开镜";
break;

case 65545:
return "打药";
break;

case 200:
case 201:
return "跳枪";
break;

case 144:
case 145:
return "蹲着";
break;

case 160:
return "趴下";
break;

case 8208:
return "蹲拳";
break;

case 8211:
return "蹲跑";
break;

case 19:
return "蹲跑";
break;

case 131072:
case 524303:
case 524304:
case 524289:
return "倒地";
break;

case 2056:
case 2057:
case 2059:
case 2065:
case 2067:
case 2081:
case 2080:
case 2083:
case 2121:
case 2120:
case 2123:
return "切枪";
break;

case 4194304:
return "游泳";
break;

case 65544:
case 65552:

case 65568:
return "打药";
break;


default:
return "未知";
break;
}
return nullptr;
} 

int GetWeapon(int Wuqi) {
switch (Wuqi) {
//突击步枪
case 101008:
return 30; //M762
break;
case 1010081:
return 31; //M762破损
break;
case 1010082:
return 32; //M762修复
break;
case 1010083:
return 33; //M762完好
break;
case 1010084:
return 34; //M762改进
break;
case 1010085:
return 35; //M762精制
break;
case 1010086:
return 37; //M762独眼
break;
case 1010087:
return 38; //M762钢铁
break;

case 101001:
return 50; //AKM
break;
case 1010011:
return 51; //AKM破损
break;
case 1010012:
return 52; //AKM修复
break;
case 1010013:
return 53; //AKM完好
break;
case 1010014:
return 54; //AKM改进
break;
case 1010015:
return 55; //AKM精制
break;
case 1010016:
return 57; //AKM独眼
break;
case 1010017:
return 58; //AKM钢铁
break;

case 101004:
return 20; //M416
break;
case 1010041:
return 21; //M416破损
break;
case 1010042:
return 22; //M416修复
break;
case 1010043:
return 23; //M416完好
break;
case 1010044:
return 24; //M416改进
break;
case 1010045:
return 25; //M416精制
break;
case 1010046:
return 27; //M416独眼
break;
case 1010047:
return 28; //M416钢铁
break;

case 101003:
return 40; //SCAR_L
break;
case 1010031:
return 41; //SCAR_L破损
break;
case 1010032:
return 42; //SCAR_L修复
break;
case 1010033:
return 43; //SCAR_L完好
break;
case 1010034:
return 44; //SCAR_L改进
break;
case 1010035:
return 45; //SCAR_L精制
break;
case 1010036:
return 47; //SCAR_L独眼
break;
case 1010037:
return 48; //SCAR_L钢铁
break;

case 101002:
return 90; //M16A4
break;
case 1010021:
return 91; //M16A4破损
break;
case 1010022:
return 92; //M16A4修复
break;
case 1010023:
return 93; //M16A4完好
break;
case 1010024:
return 94; //M16A4改进
break;
case 1010025:
return 95; //M16A4精制
break;
case 1010026:
return 97; //M16A4独眼
break;
case 1010027:
return 98; //M16A4钢铁
break;

case 101009:
return 100; //MK47
break;
case 1010091:
return 101; //MK47破损
break;
case 1010092:
return 102; //MK47修复
break;
case 1010093:
return 103; //MK47完好
break;
case 1010094:
return 104; //MK47改进
break;
case 1010095:
return 105; //MK47精制
break;
case 1010096:
return 107; //MK47独眼
break;
case 1010097:
return 108; //MK47钢铁
break;

case 101006:
return 70; //AUG
break;
case 1010061:
return 71; //AUG破损
break;
case 1010062:
return 72; //AUG修复
break;
case 1010063:
return 73; //AUG完好
break;
case 1010064:
return 74; //AUG改进
break;
case 1010065:
return 75; //AUG精制
break;
case 1010066:
return 77; //AUG独眼
break;
case 1010067:
return 78; //AUG钢铁
break;

case 101005:
return 120; //狗砸
break;
case 1010051:
return 121; //狗砸破损
break;
case 1010052:
return 122; //狗砸修复
break;
case 1010053:
return 123; //狗砸完好
break;
case 1010054:
return 124; //狗砸改进
break;
case 1010055:
return 125; //狗砸精制
break;
case 1010056:
return 127; //狗砸独眼
break;
case 1010057:
return 128; //狗砸钢铁
break;

case 101010:
return 80; //G36C
break;
case 1010101:
return 81; //G36C破损
break;
case 1010102:
return 82; //G36C修复
break;
case 1010103:
return 83; //G36C完好
break;
case 1010104:
return 84; //G36C改进
break;
case 1010105:
return 85; //G36C精制
break;
case 1010106:
return 87; //G36C独眼
break;
case 1010107:
return 88; //G36C钢铁
break;

case 101007:
return 60; //QBZ
break;
case 1010071:
return 61; //QBZ破损
break;
case 1010072:
return 62; //QBZ修复
break;
case 1010073:
return 63; //QBZ完好
break;
case 1010074:
return 64; //QBZ改进
break;
case 1010075:
return 65; //QBZ精制
break;
case 1010076:
return 67; //QBZ独眼
break;
case 1010077:
return 68; //QBZ钢铁
break;

case 101011:
return 310; //AC_VAL
break;
case 1010111:
return 311; //AC_VAL破损
break;
case 1010112:
return 312; //AC_VAL修复
break;
case 1010113:
return 313; //AC_VAL完好
break;
case 1010114:
return 314; //AC_VAL改进
break;
case 1010115:
return 315; //AC_VAL精制
break;
case 1010116:
return 317; //AC_VAL独眼
break;
case 1010117:
return 318; //AC_VAL钢铁
break;

case 101012:
return 110; //蜜獾突击步枪
break;
case 1010121:
return 111; //蜜獾突击步枪破损
break;
case 1010122:
return 112; //蜜獾突击步枪修复
break;
case 1010123:
return 113; //蜜獾突击步枪完好
break;
case 1010124:
return 114; //蜜獾突击步枪改进
break;
case 1010125:
return 115; //蜜獾突击步枪精制
break;
case 1010126:
return 117; //蜜獾突击步枪独眼
break;
case 1010127:
return 118; //蜜獾突击步枪钢铁
break;
//连狙
case 103009:
return 790; //SLR
break;
case 1030091:
return 791; //SLR破损
break;
case 1030092:
return 792; //SLR修复
break;
case 1030093:
return 793; //SLR完好
break;
case 1030094:
return 794; //SLR改进
break;
case 1030095:
return 795; //SLR精制
break;
case 1030096:
return 797; //SLR独眼
break;
case 1030097:
return 798; //SLR钢铁
break;

case 103005:
return 800; //VSS
break;
case 1030051:
return 801; //VSS破损
break;
case 1030052:
return 802; //VSS修复
break;
case 1030053:
return 803; //VSS完好
break;
case 1030054:
return 804; //VSS改进
break;
case 1030055:
return 805; //VSS精制
break;
case 1030056:
return 807; //VSS独眼
break;
case 1030057:
return 808; //VSS钢铁
break;

case 103006:
return 750; //Mini14
break;
case 1030061:
return 751; //Mini14破损
break;
case 1030062:
return 752; //Mini14修复
break;
case 1030063:
return 753; //Mini14完好
break;
case 1030064:
return 754; //Mini14改进
break;
case 1030065:
return 755; //Mini14精制
break;
case 1030066:
return 757; //Mini14独眼
break;
case 1030067:
return 758; //Mini14钢铁
break;

case 103010:
return 770; //QBU
break;
case 1030101:
return 771; //QBU破损
break;
case 1030102:
return 772; //QBU修复
break;
case 1030103:
return 773; //QBU完好
break;
case 1030104:
return 774; //QBU改进
break;
case 1030105:
return 775; //QBU精制
break;
case 1030106:
return 777; //QBU独眼
break;
case 1030107:
return 778; //QBU钢铁
break;

case 103004:
return 780; //SKS
break;
case 1030041:
return 781; //SKS破损
break;
case 1030042:
return 782; //SKS修复
break;
case 1030043:
return 783; //SKS完好
break;
case 1030044:
return 784; //SKS改进
break;
case 1030045:
return 785; //SKS精制
break;
case 1030046:
return 787; //SKS独眼
break;
case 1030047:
return 788; //SKS钢铁
break;

case 103007:
return 730; //MK14
break;
case 1030071:
return 731; //MK14破损
break;
case 1030072:
return 732; //MK14修复
break;
case 1030073:
return 733; //MK14完好
break;
case 1030074:
return 734; //MK14改进
break;
case 1030075:
return 735; //MK14精制
break;
case 1030076:
return 737; //MK14独眼
break;
case 1030077:
return 738; //MK14钢铁
break;

case 103014:
return 740; //MK20_H
break;
case 1030141:
return 741; //MK20_H破损
break;
case 1030142:
return 742; //MK20_H修复
break;
case 1030143:
return 743; //MK20_H完好
break;
case 1030144:
return 744; //MK20_H改进
break;
case 1030145:
return 745; //MK20_H精制
break;
case 1030146:
return 747; //MK20_H独眼
break;
case 1030147:
return 748; //MK20_H钢铁
break;

case 103013:
return 710; //M417
break;
case 1030131:
return 711; //M417破损
break;
case 1030132:
return 712; //M417修复
break;
case 1030133:
return 713; //M417完好
break;
case 1030134:
return 714; //M417改进
break;
case 1030135:
return 715; //M417精制
break;
case 1030136:
return 717; //M417独眼
break;
case 1030137:
return 718; //M417钢铁
break;
//连狙
case 103012:
return 520; //AMR
break;
case 1030121:
return 521; //AMR破损
break;
case 1030122:
return 522; //AMR修复
break;
case 1030123:
return 523; //AMR完好
break;
case 1030124:
return 524; //AMR改进
break;
case 1030125:
return 525; //AMR精制
break;
case 1030126:
return 527; //AMR独眼
break;
case 1030127:
return 528; //AMR钢铁
break;

case 103003:
return 510; //AWM
break;
case 1030031:
return 511; //AWM破损
break;
case 1030032:
return 512; //AWM修复
break;
case 1030033:
return 513; //AWM完好
break;
case 1030034:
return 514; //AWM改进
break;
case 1030035:
return 515; //AWM精制
break;
case 1030036:
return 517; //AWM独眼
break;
case 1030037:
return 518; //AWM钢铁
break;

case 103002:
return 550; //M24
break;
case 1030021:
return 551; //M24破损
break;
case 1030022:
return 552; //M24修复
break;
case 1030023:
return 553; //M24完好
break;
case 1030024:
return 554; //M24改进
break;
case 1030025:
return 555; //M24精制
break;
case 1030026:
return 557; //M24独眼
break;
case 1030027:
return 558; //M24钢铁
break;

case 103011:
return 570; //莫辛纳甘
break;
case 1030111:
return 571; //莫辛纳甘破损
break;
case 1030112:
return 572; //莫辛纳甘修复
break;
case 1030113:
return 573; //莫辛纳甘完好
break;
case 1030114:
return 574; //莫辛纳甘改进
break;
case 1030115:
return 575; //莫辛纳甘精制
break;
case 1030116:
return 577; //莫辛纳甘独眼
break;
case 1030117:
return 578; //莫辛纳甘钢铁
break;

case 103001:
return 530; //_98K
break;
case 1030011:
return 531; //_98K破损
break;
case 1030012:
return 532; //_98K修复
break;
case 1030013:
return 533; //_98K完好
break;
case 1030014:
return 534; //_98K改进
break;
case 1030015:
return 535; //_98K精制
break;
case 1030016:
return 537; //_98K独眼
break;
case 1030017:
return 538; //_98K钢铁
break;

case 103008:
return 560; //Win94
break;
case 1030081:
return 561; //Win94破损
break;
case 1030082:
return 562; //Win94修复
break;
case 1030083:
return 563; //Win94完好
break;
case 1030084:
return 564; //Win94改进
break;
case 1030085:
return 565; //Win94精制
break;
case 1030086:
return 567; //Win94独眼
break;
case 1030087:
return 568; //Win94钢铁
break;
//机关枪
case 105001:
return 550; //M249
break;
case 1050011:
return 551; //M249破损
break;
case 1050012:
return 552; //M249修复
break;
case 1050013:
return 553; //M249完好
break;
case 1050014:
return 554; //M249改进
break;
case 1050015:
return 555; //M249精制
break;
case 1050016:
return 557; //M249独眼
break;
case 1050017:
return 558; //M249钢铁
break;

case 105002:
return 1010; //DP_28
break;
case 1050021:
return 1011; //DP_28破损
break;
case 1050022:
return 1012; //DP_28修复
break;
case 1050023:
return 1013; //DP_28完好
break;
case 1050024:
return 1014; //DP_28改进
break;
case 1050025:
return 1015; //DP_28精制
break;
case 1050026:
return 1017; //DP_28独眼
break;
case 1050027:
return 1018; //DP_28钢铁
break;

case 105010:
return 1030; //MG3
break;
case 1050101:
return 1031; //MG3破损
break;
case 1050102:
return 1032; //MG3修复
break;
case 1050103:
return 1033; //MG3完好
break;
case 1050104:
return 1034; //MG3改进
break;
case 1050105:
return 1035; //MG3精制
break;
case 1050106:
return 1037; //MG3独眼
break;
case 1050107:
return 1038; //MG3钢铁
break;

case 107001:
return 1410; //十字弩
break;
case 1070011:
return 1411; //十字弩破损
break;
case 1070012:
return 1412; //十字弩修复
break;
case 1070013:
return 1413; //十字弩完好
break;
case 1070014:
return 1414; //十字弩改进
break;
case 1070015:
return 1415; //十字弩精制
break;
case 1070016:
return 1417; //十字弩独眼
break;
case 1070017:
return 1418; //十字弩钢铁
break;

case 107007:
return 1420; //爆炸猎弓
break;
case 1070071:
return 1421; //爆炸猎弓破损
break;
case 1070072:
return 1422; //爆炸猎弓修复
break;
case 1070073:
return 1423; //爆炸猎弓完好
break;
case 1070074:
return 1424; //爆炸猎弓改进
break;
case 1070075:
return 1425; //爆炸猎弓精制
break;
case 1070076:
return 1427; //爆炸猎弓独眼
break;
case 1070077:
return 1428; //爆炸猎弓钢铁
break;
//冲锋枪
case 102001:
return 350; //UZI
break;
case 1020011:
return 351; //UZI破损
break;
case 1020012:
return 352; //UZI修复
break;
case 1020013:
return 353; //UZI完好
break;
case 1020014:
return 354; //UZI改进
break;
case 1020015:
return 355; //UZI精制
break;
case 1020016:
return 357; //UZI独眼
break;
case 1020017:
return 358; //UZI钢铁
break;

case 102003:
return 380; //维克托
break;
case 1020031:
return 381; //维克托破损
break;
case 1020032:
return 382; //维克托修复
break;
case 1020033:
return 383; //维克托完好
break;
case 1020034:
return 384; //维克托改进
break;
case 1020035:
return 385; //维克托精制
break;
case 1020036:
return 387; //维克托独眼
break;
case 1020037:
return 388; //维克托钢铁
break;

case 100103:
return 360; //野牛 PP_19
break;
case 1001031:
return 361; //野牛 PP_19破损
break;
case 1001032:
return 362; //野牛 PP_19修复
break;
case 1001033:
return 363; //野牛 PP_19完好
break;
case 1001034:
return 364; //野牛 PP_19改进
break;
case 1001035:
return 365; //野牛 PP_19精制
break;
case 1001036:
return 367; //野牛 PP_19独眼
break;
case 1001037:
return 368; //野牛 PP_19钢铁
break;

case 102007:
return 320; //MP5K
break;
case 1020071:
return 321; //MP5K破损
break;
case 1020072:
return 322; //MP5K修复
break;
case 1020073:
return 323; //MP5K完好
break;
case 1020074:
return 324; //MP5K改进
break;
case 1020075:
return 325; //MP5K精制
break;
case 1020076:
return 327; //MP5K独眼
break;
case 1020077:
return 328; //MP5K钢铁
break;

case 102002:
return 340; //UMP45
break;
case 1020021:
return 341; //UMP45破损
break;
case 1020022:
return 342; //UMP45修复
break;
case 1020023:
return 343; //UMP45完好
break;
case 1020024:
return 344; //UMP45改进
break;
case 1020025:
return 345; //UMP45精制
break;
case 1020026:
return 347; //UMP45独眼
break;
case 1020027:
return 348; //UMP45钢铁
break;

case 102004:
return 370; //汤姆逊
break;
case 1020041:
return 371; //汤姆逊破损
break;
case 1020042:
return 372; //汤姆逊修复
break;
case 1020043:
return 373; //汤姆逊完好
break;
case 1020044:
return 374; //汤姆逊改进
break;
case 1020045:
return 375; //汤姆逊精制
break;
case 1020046:
return 377; //汤姆逊独眼
break;
case 1020047:
return 378; //汤姆逊钢铁
break;

case 102105:
return 330; //P90
break;
case 1021051:
return 331; //P90破损
break;
case 1021052:
return 332; //P90修复
break;
case 1021053:
return 333; //P90完好
break;
case 1021054:
return 334; //P90改进
break;
case 1021055:
return 335; //P90精制
break;
case 1021056:
return 337; //P90独眼
break;
case 1021057:
return 338; //P90钢铁
break;

case 102005:
return 360; //野牛
break;
case 1020051:
return 361; //野牛破损
break;
case 1020052:
return 362; //野牛修复
break;
case 1020053:
return 363; //野牛完好
break;
case 1020054:
return 364; //野牛改进
break;
case 1020055:
return 365; //野牛精制
break;
case 1020056:
return 367; //野牛独眼
break;
case 1020057:
return 368; //野牛钢铁
break;
//霰弹枪
case 104001:
return 930; //S686
break;
case 1040011:
return 931; //S686破损
break;
case 1040012:
return 932; //S686修复
break;
case 1040013:
return 933; //S686完好
break;
case 1040014:
return 934; //S686改进
break;
case 1040015:
return 935; //S686精制
break;
case 1040016:
return 937; //S686独眼
break;
case 1040017:
return 938; //S686钢铁
break;

case 104002:
return 920; //S1897
break;
case 1040021:
return 921; //S1897破损
break;
case 1040022:
return 922; //S1897修复
break;
case 1040023:
return 923; //S1897完好
break;
case 1040024:
return 924; //S1897改进
break;
case 1040025:
return 925; //S1897精制
break;
case 1040026:
return 927; //S1897独眼
break;
case 1040027:
return 928; //S1897钢铁
break;

case 104003:
return 910; //S12K
break;
case 1040031:
return 911; //S12K破损
break;
case 1040032:
return 912; //S12K修复
break;
case 1040033:
return 913; //S12K完好
break;
case 1040034:
return 914; //S12K改进
break;
case 1040035:
return 915; //S12K精制
break;
case 1040036:
return 917; //S12K独眼
break;
case 1040037:
return 918; //S12K钢铁
break;

case 104004:
return 900; //DBS
break;
case 1040041:
return 901; //DBS破损
break;
case 1040042:
return 902; //DBS修复
break;
case 1040043:
return 903; //DBS完好
break;
case 1040044:
return 904; //DBS改进
break;
case 1040045:
return 905; //DBS精制
break;
case 1040046:
return 907; //DBS独眼
break;
case 1040047:
return 908; //DBS钢铁
break;

case 104100:
return 0; //SPAS_12 没有
break;
case 1041001:
return 1; //SPAS_12破损
break;
case 1041002:
return 2; //SPAS_12修复
break;
case 1041003:
return 3; //SPAS_12完好
break;
case 1041004:
return 4; //SPAS_12改进
break;
case 1041005:
return 5; //SPAS_12精制
break;
case 1041006:
return 7; //SPAS_12独眼
break;
case 1041007:
return 8; //SPAS_12钢铁
break;
//投掷爆炸物
case 602001:
return 1510; //闪光弹
break;
case 602002:
return 1520; //烟雾弹
break;
case 602003:
return 1530; //燃烧瓶
break;
case 602004:
return 1540; //手榴弹
break;
//近战武器
case 108001:
return 1310; //砍刀
break;
case 108002:
return 1320; //撬棍
break;
case 108003:
return 1330; //镰刀
break;
case 108004:
return 1340; //平底锅
break;
case 0:
return 10; //拳头
break;
case 9808001:
return 1131; //P92手枪破损
break;
case 9808002:
return 1132; //P92手枪修复
break;
case 9808003:
return 1133; //P92手枪完好
break;
case 9808008:
return 1121; //P1911手枪破损
break;
case 9808009:
return 1122; //P1911手枪修复
break;
case 9808010:
return 1123; //P1911手枪完好
break;
case 9808015:
return 1161; //左轮手枪破损
break;
case 9808016:
return 1162; //左轮手枪修复
break;
case 9808017:
return 1163; //左轮手枪完好
break;
case 9808022:
return 1111; //P18C手枪破损
break;
case 9808023:
return 1112; //P18C手枪修复
break;
case 9808024:
return 1113; //P18C手枪完好
break;
case 9808029:
return 1141; //R45手枪破损
break;
case 9808030:
return 1142; //R45手枪修复
break;
case 9808031:
return 1143; //R45手枪完好
break;
case 9808036:
return 1181; //短管霰弹枪破损
break;
case 9808037:
return 1182; //短管霰弹枪修复
break;
case 9808038:
return 1183; //短管霰弹枪完好
break;
case 9808043:
return 1192; //蝎式手枪修复
break;
case 9808044:
return 1193; //蝎式手枪完好
break;
case 9808045:
return 1194; //蝎式手枪改进
break;
case 9808046:
return 1191; //蝎式手枪破损
break;
case 9808050:
return 1172; //沙漠之鹰手枪修复
break;
case 9808051:
return 1173; //沙漠之鹰手枪完好
break;
case 9808052:
return 1174; //沙漠之鹰手枪改进
break;
case 9808053:
return 1171; //沙漠之鹰手枪破损
break;
case 9808057:
return 2; //TMP_9手枪修复  没有
break;
case 9808058:
return 3; //TMP_9手枪完好
break;
case 9808059:
return 4; //TMP_9手枪改进
break;
case 9808060:
return 1150; //信号枪
break;
case 9808061:
return 1; //TMP_9手枪破损
break;
case 9809001:
return 1411; //十字弩破损
break;
case 9809002:
return 1412; //十字弩修复
break;
case 9809003:
return 1413; //十字弩完好
break;
case 9809009:
return 1429; //爆炸猎弓骑警
break;
case 9809010:
return 1429; //爆炸猎弓
break;
case 9810001:
return 931; //S686霰弹枪破损
break;
case 9810002:
return 932; //S686霰弹枪修复
break;
case 9810003:
return 933; //S686霰弹枪完好
break;
case 9810008:
return 921; //S1897霰弹枪破损
break;
case 9810009:
return 922; //S1897霰弹枪修复
break;
case 9810010:
return 923; //S1897霰弹枪完好
break;
case 9810015:
return 915; //S12K霰弹枪精制
break;
case 9810016:
return 912; //S12K霰弹枪修复
break;
case 9810017:
return 913; //S12K霰弹枪完好
break;
case 9810018:
return 914; //S12K霰弹枪改进
break;
case 9810022:
return 902; //DBS霰弹枪修复
break;
case 9810023:
return 903; //DBS霰弹枪完好
break;
case 9810024:
return 904; //DBS霰弹枪改进
break;
case 9810025:
return 905; //DBS霰弹枪精制
break;
case 9810029:
return 2; //SPAS_12霰弹枪修复  没有
break;
case 9810030:
return 3; //SPAS_12霰弹枪完好
break;
case 9810031:
return 4; //SPAS_12霰弹枪改进
break;
case 9810032:
return 5; //SPAS_12霰弹枪精制
break;
case 9810036:
return 2; //AA12_G霰弹枪修复  没有
break;
case 9810037:
return 3; //AA12_G霰弹枪完好
break;
case 9810038:
return 4; //AA12_G霰弹枪改进
break;
case 9810041:
return 5; //AA12_G霰弹枪精制
break;
case 9811001:
return 351; //UZI冲锋枪破损
break;
case 9811002:
return 352; //UZI冲锋枪修复
break;
case 9811003:
return 353; //UZI冲锋枪完好
break;
case 9811004:
return 354; //UZI冲锋枪改进
break;
case 9811008:
return 341; //UMP45冲锋枪破损
break;
case 9811009:
return 342; //UMP45冲锋枪修复
break;
case 9811010:
return 343; //UMP45冲锋枪完好
break;
case 9811011:
return 344; //UMP45冲锋枪改进
break;
case 9811015:
return 386; //维克托冲锋枪卓越
break;
case 9811016:
return 383; //维克托冲锋枪完好
break;
case 9811017:
return 384; //维克托冲锋枪改进
break;
case 9811018:
return 385; //维克托冲锋枪精制
break;
case 9811019:
return 386; //维克托冲锋枪卓越
break;
case 9811020:
return 388; //维克托冲锋枪黑鹰
break;
case 9811021:
return 387; //维克托冲锋枪铁爪
break;
case 9811022:
return 371; //汤姆逊冲锋枪破损
break;
case 9811023:
return 372; //汤姆逊冲锋枪修复
break;
case 9811024:
return 373; //汤姆逊冲锋枪完好
break;
case 9811025:
return 374; //汤姆逊冲锋枪改进
break;
case 9811029:
return 361; //野牛冲锋枪破损
break;
case 9811030:
return 362; //野牛冲锋枪修复
break;
case 9811031:
return 363; //野牛冲锋枪完好
break;
case 9811036:
return 326; //MP5K冲锋枪卓越
break;
case 9811037:
return 323; //MP5K冲锋枪完好
break;
case 9811038:
return 324; //MP5K冲锋枪改进
break;
case 9811039:
return 325; //MP5K冲锋枪精制
break;
case 9811040:
return 326; //MP5K冲锋枪卓越
break;
case 9811041:
return 328; //MP5K冲锋枪黑鹰
break;
case 9811042:
return 327; //MP5K冲锋枪铁爪
break;
case 9811043:
return 2; //AKS_74U冲锋枪修复   没有
break;
case 9811044:
return 3; //AKS_74U冲锋枪完好
break;
case 9811045:
return 4; //AKS_74U冲锋枪改进
break;
case 9811046:
return 5; //AKS_74U冲锋枪精制
break;
case 9811047:
return 6; //AKS_74U冲锋枪卓越
break;
case 9811048:
return 7; //AKS_74U冲锋枪铁爪
break;
case 9811049:
return 8; //AKS_74U冲锋枪黑鹰
break;
case 9811050:
return 336; //P90冲锋枪卓越
break;
case 9811051:
return 333; //P90冲锋枪完好
break;
case 9811052:
return 334; //P90冲锋枪改进
break;
case 9811053:
return 335; //P90冲锋枪精制
break;
case 9811054:
return 336; //P90冲锋枪卓越
break;
case 9811055:
return 338; //P90冲锋枪黑鹰
break;
case 9811056:
return 337; //P90冲锋枪铁爪
break;
case 9812002:
return 56; //AKM突击步枪卓越
break;
case 9812003:
return 53; //AKM突击步枪完好
break;
case 9812004:
return 54; //AKM突击步枪改进
break;
case 9812005:
return 55; //AKM突击步枪精制
break;
case 9812006:
return 56; //AKM突击步枪卓越
break;
case 9812007:
return 58; //AKM突击步枪黑鹰
break;
case 9812008:
return 57; //AKM突击步枪铁爪
break;
case 9812009:
return 91; //M16A4突击步枪破损
break;
case 9812010:
return 92; //M16A4突击步枪修复
break;
case 9812011:
return 93; //M16A4突击步枪完好
break;
case 9812012:
return 94; //M16A4突击步枪改进
break;
case 9812015:
return 46; //SCAR_L突击步枪卓越
break;
case 9812016:
return 43; //SCAR_L突击步枪完好
break;
case 9812017:
return 44; //SCAR_L突击步枪改进
break;
case 9812018:
return 45; //SCAR_L突击步枪精制
break;
case 9812019:
return 46; //SCAR_L突击步枪卓越
break;
case 9812020:
return 48; //SCAR_L突击步枪黑鹰
break;
case 9812021:
return 47; //SCAR_L突击步枪铁爪
break;
case 9812022:
return 27; //M416突击步枪铁爪
break;
case 9812023:
return 26; //M416突击步枪卓越
break;
case 9812024:
return 23; //M416突击步枪完好
break;
case 9812025:
return 24; //M416突击步枪改进
break;
case 9812026:
return 25; //M416突击步枪精制
break;
case 9812027:
return 26; //M416突击步枪卓越
break;
case 9812028:
return 28; //M416突击步枪黑鹰
break;
case 9812029:
return 126; //狗砸突击步枪卓越
break;
case 9812030:
return 124; //狗砸突击步枪改进
break;
case 9812031:
return 125; //狗砸突击步枪精制
break;
case 9812032:
return 126; //狗砸突击步枪卓越
break;
case 9812033:
return 128; //狗砸突击步枪黑鹰
break;
case 9812034:
return 127; //狗砸突击步枪铁爪
break;
case 9812036:
return 76; //AUG突击步枪卓越
break;
case 9812037:
return 74; //AUG突击步枪改进
break;
case 9812038:
return 75; //AUG突击步枪精制
break;
case 9812039:
return 76; //AUG突击步枪卓越
break;
case 9812040:
return 78; //AUG突击步枪黑鹰
break;
case 9812041:
return 77; //AUG突击步枪铁爪
break;
case 9812043:
return 66; //QBZ突击步枪卓越
break;
case 9812044:
return 63; //QBZ突击步枪完好
break;
case 9812045:
return 64; //QBZ突击步枪改进
break;
case 9812046:
return 65; //QBZ突击步枪精制
break;
case 9812047:
return 66; //QBZ突击步枪卓越
break;
case 9812048:
return 68; //QBZ突击步枪黑鹰
break;
case 9812049:
return 67; //QBZ突击步枪铁爪
break;
case 9812050:
return 36; //M762突击步枪卓越
break;
case 9812051:
return 33; //M762突击步枪完好
break;
case 9812052:
return 34; //M762突击步枪改进
break;
case 9812053:
return 35; //M762突击步枪精制
break;
case 9812054:
return 36; //M762突击步枪卓越
break;
case 9812055:
return 38; //M762突击步枪黑鹰
break;
case 9812056:
return 37; //M762突击步枪铁爪
break;
case 9812057:
return 101; //MK47突击步枪破损
break;
case 9812058:
return 102; //MK47突击步枪修复
break;
case 9812059:
return 103; //MK47突击步枪完好
break;
case 9812060:
return 104; //MK47突击步枪改进
break;
case 9812064:
return 86; //G36C突击步枪卓越
break;
case 9812065:
return 83; //G36C突击步枪完好
break;
case 9812066:
return 84; //G36C突击步枪改进
break;
case 9812067:
return 85; //G36C突击步枪精制
break;
case 9812068:
return 86; //G36C突击步枪卓越
break;
case 9812069:
return 88; //G36C突击步枪黑鹰
break;
case 9812070:
return 87; //G36C突击步枪铁爪
break;
case 9812071:
return 311; //AC_VAL突击步枪破损
break;
case 9812072:
return 312; //AC_VAL突击步枪修复
break;
case 9812073:
return 313; //AC_VAL突击步枪完好
break;
case 9812074:
return 314; //AC_VAL突击步枪改进
break;
case 9812078:
return 116; //蜜獾突击步枪卓越
break;
case 9812079:
return 113; //蜜獾突击步枪完好
break;
case 9812080:
return 114; //蜜獾突击步枪改进
break;
case 9812081:
return 115; //蜜獾突击步枪精制
break;
case 9812082:
return 116; //蜜獾突击步枪卓越
break;
case 9812083:
return 118; //蜜獾突击步枪黑鹰
break;
case 9812084:
return 117; //蜜獾突击步枪铁爪
break;
case 9812085:
return 6; //FAMAS突击步枪卓越  没有
break;
case 9812086:
return 3; //FAMAS突击步枪完好
break;
case 9812087:
return 4; //FAMAS突击步枪改进
break;
case 9812088:
return 5; //FAMAS突击步枪精制
break;
case 9812089:
return 6; //FAMAS突击步枪卓越
break;
case 9812090:
return 8; //FAMAS突击步枪黑鹰
break;
case 9812091:
return 7; //FAMAS突击步枪铁爪
break;
case 9812092:
return 29; //M416卡德
break;
case 9813001:
return 556; //M249轻机枪卓越
break;
case 9813002:
return 554; //M249轻机枪改进
break;
case 9813003:
return 555; //M249轻机枪精制
break;
case 9813004:
return 556; //M249轻机枪卓越
break;
case 9813005:
return 558; //M249轻机枪黑鹰
break;
case 9813006:
return 557; //M249轻机枪铁爪
break;
case 9813008:
return 1011; //DP_28轻机枪破损
break;
case 9813009:
return 1012; //DP_28轻机枪修复
break;
case 9813010:
return 1013; //DP_28轻机枪完好
break;
case 9813022:
return 1036; //MG3轻机枪卓越
break;
case 9813023:
return 1034; //MG3轻机枪改进
break;
case 9813024:
return 1035; //MG3轻机枪精制
break;
case 9813025:
return 1036; //MG3轻机枪卓越
break;
case 9813026:
return 1038; //MG3轻机枪黑鹰
break;
case 9813027:
return 1037; //MG3轻机枪铁爪
break;
case 9813029:
return 6; //PKM轻机枪卓越  没有
break;
case 9813030:
return 4; //PKM轻机枪改进
break;
case 9813031:
return 5; //PKM轻机枪精制
break;
case 9813032:
return 6; //PKM轻机枪卓越
break;
case 9813033:
return 8; //PKM轻机枪黑鹰
break;
case 9813034:
return 7; //PKM轻机枪铁爪
break;
case 9814001:
return 532; //_98K狙击枪修复
break;
case 9814002:
return 533; //_98K狙击枪完好
break;
case 9814003:
return 534; //_98K狙击枪改进
break;
case 9814008:
return 556; //M24狙击枪卓越
break;
case 9814009:
return 553; //M24狙击枪完好
break;
case 9814010:
return 554; //M24狙击枪改进
break;
case 9814011:
return 555; //M24狙击枪精制
break;
case 9814012:
return 556; //M24狙击枪卓越
break;
case 9814013:
return 558; //M24狙击枪黑鹰
break;
case 9814014:
return 557; //M24狙击枪铁爪
break;
case 9814015:
return 516; //AWM狙击枪卓越
break;
case 9814016:
return 514; //AWM狙击枪改进
break;
case 9814017:
return 515; //AWM狙击枪精制
break;
case 9814018:
return 516; //AWM狙击枪卓越
break;
case 9814019:
return 518; //AWM狙击枪黑鹰
break;
case 9814020:
return 517; //AWM狙击枪铁爪
break;
case 9814022:
return 571; //莫辛纳甘狙击枪破损
break;
case 9814023:
return 572; //莫辛纳甘狙击枪修复
break;
case 9814024:
return 573; //莫辛纳甘狙击枪完好
break;
case 9814029:
return 561; //Win94狙击枪破损
break;
case 9814030:
return 562; //Win94狙击枪修复
break;
case 9814031:
return 563; //Win94狙击枪完好
break;
case 9814036:
return 526; //AMR狙击枪卓越
break;
case 9814037:
return 524; //AMR狙击枪改进
break;
case 9814038:
return 525; //AMR狙击枪精制
break;
case 9814039:
return 526; //AMR狙击枪卓越
break;
case 9814040:
return 528; //AMR狙击枪黑鹰
break;
case 9814041:
return 527; //AMR狙击枪铁爪
break;
case 9814043:
return 546; //M200狙击枪卓越
break;
case 9814044:
return 543; //M200狙击枪完好
break;
case 9814045:
return 544; //M200狙击枪改进
break;
case 9814046:
return 545; //M200狙击枪精制
break;
case 9814047:
return 546; //M200狙击枪卓越
break;
case 9814048:
return 548; //M200狙击枪黑鹰
break;
case 9814049:
return 547; //M200狙击枪铁爪
break;
case 9814050:
return 4; //SVD狙击枪改进  没有
break;
case 9814051:
return 5; //SVD狙击枪精制
break;
case 9814052:
return 6; //SVD狙击枪卓越
break;
case 9814053:
return 6; //SVD狙击枪卓越
break;
case 9815001:
return 786; //SKS射手步枪卓越
break;
case 9815002:
return 783; //SKS射手步枪完好
break;
case 9815003:
return 784; //SKS射手步枪改进
break;
case 9815004:
return 785; //SKS射手步枪精制
break;
case 9815005:
return 786; //SKS射手步枪卓越
break;
case 9815006:
return 788; //SKS射手步枪黑鹰
break;
case 9815007:
return 787; //SKS射手步枪铁爪
break;
case 9815008:
return 801; //VSS射手步枪破损
break;
case 9815009:
return 802; //VSS射手步枪修复
break;
case 9815010:
return 803; //VSS射手步枪完好
break;
case 9815015:
return 751; //Mini14射手步枪破损
break;
case 9815016:
return 752; //Mini14射手步枪修复
break;
case 9815017:
return 753; //Mini14射手步枪完好
break;
case 9815018:
return 754; //Mini14射手步枪改进
break;
case 9815022:
return 736; //MK14射手步枪卓越
break;
case 9815023:
return 733; //MK14射手步枪完好
break;
case 9815024:
return 734; //MK14射手步枪改进
break;
case 9815025:
return 735; //MK14射手步枪精制
break;
case 9815026:
return 736; //MK14射手步枪卓越
break;
case 9815027:
return 738; //MK14射手步枪黑鹰
break;
case 9815028:
return 737; //MK14射手步枪铁爪
break;
case 9815029:
return 796; //SLR射手步枪卓越
break;
case 9815030:
return 793; //SLR射手步枪完好
break;
case 9815031:
return 794; //SLR射手步枪改进
break;
case 9815032:
return 795; //SLR射手步枪精制
break;
case 9815033:
return 796; //SLR射手步枪卓越
break;
case 9815034:
return 798; //SLR射手步枪黑鹰
break;
case 9815035:
return 797; //SLR射手步枪铁爪
break;
case 9815036:
return 771; //QBU射手步枪破损
break;
case 9815037:
return 772; //QBU射手步枪修复
break;
case 9815038:
return 773; //QBU射手步枪完好
break;
case 9815039:
return 774; //QBU射手步枪改进
break;
case 9815043:
return 716; //M417射手步枪卓越
break;
case 9815044:
return 713; //M417射手步枪完好
break;
case 9815045:
return 714; //M417射手步枪改进
break;
case 9815046:
return 715; //M417射手步枪精制
break;
case 9815047:
return 716; //M417射手步枪卓越
break;
case 9815048:
return 718; //M417射手步枪黑鹰
break;
case 9815049:
return 717; //M417射手步枪铁爪
break;
case 9815050:
return 746; //MK20_H射手步枪卓越
break;
case 9815051:
return 743; //MK20_H射手步枪完好
break;
case 9815052:
return 744; //MK20_H射手步枪改进
break;
case 9815053:
return 745; //MK20_H射手步枪精制
break;
case 9815054:
return 746; //MK20_H射手步枪卓越
break;
case 9815055:
return 748; //MK20_H射手步枪黑鹰
break;
case 9815056:
return 747; //MK20_H射手步枪铁爪
break;
case 9815064:
return 726; //MK12射手步枪卓越
break;
case 9815065:
return 723; //MK12射手步枪完好
break;
case 9815066:
return 724; //MK12射手步枪改进
break;
case 9815067:
return 725; //MK12射手步枪精制
break;
case 9815068:
return 726; //MK12射手步枪卓越
break;
case 9815069:
return 728; //MK12射手步枪黑鹰
break;
case 9815070:
return 727; //MK12射手步枪铁爪
break;
case 9815071:
return 9; //M134_装甲重机枪  没有
break;
default:
return 0;
break;}
return 0;
}

inline std::string tou(int 头)
{
std::string StateName = "无";
if (头 == 0) {
 StateName = "无"; 
}
if (头 == 502001||头 == 502004||头 == 502101) {
 StateName = "一"; 
}
if (头 == 502002||头 == 502005||头 == 502102) {
 StateName = "二"; 
}
if (头 == 502003||头 == 502006||头 == 502103) {
 StateName = "三"; 
}
if (头 == 502104) {
 StateName = "四"; 
}
if (头 == 502107) {
 StateName = "四·"; 
}
if (头 == 502110) {
 StateName = "四·"; 
}
if (头 == 502105) {
 StateName = "五"; 
}
if (头 == 502108) {
 StateName = "五·"; 
}
if (头 == 502111) {
 StateName = "五·"; 
}
if (头 == 502106) {
 StateName = "六"; 
}
if (头 == 502109) {
 StateName = "六·"; 
}
if (头 == 502112) {
 StateName = "六·"; 
}
if (头 == 9804001) {
 StateName = "一"; 
}
if (头 == 9804002) {
 StateName = "二"; 
}
if (头 == 9804003) {
 StateName = "三"; 
}
if (头 == 9804004) {
 StateName = "四"; 
}
if (头 == 9804005) {
 StateName = "四"; 
}
if (头 == 9804006) {
 StateName = "四"; 
}
if (头 == 9804007) {
 StateName = "五"; 
}
if (头 == 9804008) {
 StateName = "五"; 
}
if (头 == 9804009) {
 StateName = "五"; 
}
if (头 == 9804010) {
 StateName = "六"; 
}
if (头 == 9804011) {
 StateName = "六"; 
}
if (头 == 9804012) {
 StateName = "六"; 
}
if (头 == 9804013) {
 StateName = "七"; 
}
if (头 == 9804014) {
 StateName = "七"; 
}
if (头 == 9804015) {
 StateName = "七"; 
}
if (头 == 9804016) {
 StateName = "夜"; 
}
if (头 == 9804017) {
 StateName = "七"; 
}
if (头 == 9804018) {
 StateName = "七"; 
}
if (头 == 9804019) {
 StateName = "七"; 
}
return StateName;
}

inline std::string jia(int 甲) {
std::string StateName = "无";
if (甲 == 0) {
 StateName = "无"; 
}
if (甲 == 503001||甲 == 503004||甲 == 503101) {
 StateName = "一"; 
}
if (甲 == 503002||甲 == 503005||甲 == 503102) {
 StateName = "二"; 
}
if (甲 == 503003||甲 == 503006||甲 == 503103) {
 StateName = "三"; 
}
if (甲== 503104) {
 StateName = "四"; 
}
if (甲 == 503107) {
 StateName = "四·"; 
}
if (甲 == 503110) {
 StateName = "四·"; 
}
if (甲== 503105) {
 StateName = "五"; 
}
if (甲 == 503108) {
 StateName = "五·"; 
}
if (甲 == 503111) {
 StateName = "五·"; 
}
if (甲== 503106) {
 StateName = "六"; 
}
if (甲 == 503109) {
 StateName = "六·"; 
}
if (甲 == 503112) {
 StateName = "六·"; 
}
if (甲 == 9804020) {
 StateName = "腿"; 
}
if (甲 == 9805001) {
 StateName = "一"; 
}
if (甲 == 9805002) {
 StateName = "二"; 
}
if (甲 == 9805003) {
 StateName = "三"; 
}
if (甲 == 9805004) {
 StateName = "四"; 
}
if (甲 == 9805005) {
 StateName = "四"; 
}
if (甲 == 9805006) {
 StateName = "四"; 
}
if (甲 == 9805007) {
 StateName = "五"; 
}
if (甲 == 9805008) {
 StateName = "五"; 
}
if (甲 == 9805009) {
 StateName = "五"; 
}
if (甲 == 9805010) {
 StateName = "六"; 
}
if (甲 == 9805011) {
 StateName = "六"; 
}
if (甲 == 9805012) {
 StateName = "六"; 
}
if (甲 == 9805013) {
 StateName = "七"; 
}
if (甲 == 9805014) {
 StateName = "七"; 
}
if (甲 == 9805015) {
 StateName = "七"; 
}
if (甲 == 9805016) {
 StateName = "七"; 
}
if (甲 == 9805017) {
 StateName = "七"; 
}
if (甲 == 9805018) {
 StateName = "七"; 
}
if (甲 == 9805020) {
 StateName = "机"; 
}
if (甲 == 9805021) {
 StateName = "四"; 
}
if (甲 == 9805022) {
 StateName = "四"; 
}
if (甲 == 9805023) {
 StateName = "四"; 
}
if (甲 == 9805024) {
 StateName = "五"; 
}
if (甲 == 9805025) {
 StateName = "五"; 
}
if (甲 == 9805026) {
 StateName = "五"; 
}
if (甲 == 9805027) {
 StateName = "六"; 
}
if (甲 == 9805028) {
 StateName = "六"; 
}
if (甲 == 9805029) {
 StateName = "六"; 
}
if (甲 == 9805030) {
 StateName = "七"; 
}
if (甲 == 9805031) {
 StateName = "七"; 
}
if (甲 == 9805032) {
 StateName = "七"; 
}
if (甲 == 9805033) {
 StateName = "七"; 
}
if (甲 == 9805034) {
 StateName = "七"; 
}
if (甲 == 9805035) {
 StateName = "七"; 
}
if (甲 == 9805098) {
 StateName = "七"; 
}
if (甲 == 9805099) {
 StateName = "七"; 
}
return StateName;
}
 inline std::string bao(int 包) {
 std::string StateName = "无";
 if (包 == 0) {
 StateName = "无"; 
 }
 if (包 == 501001||包 == 501004||包 == 501101) {
  StateName = "一"; 
 }
 if (包 == 501002||包 == 501005||包 == 501102) {
  StateName = "二"; 
 }
 if (包 == 501003||包 == 501006||包 == 501103) {
  StateName = "三"; 
 }
 if (包 == 501104||包 == 501107||包 == 501110) {
  StateName = "四"; 
 }
 if (包 == 501105||包 == 501108||包 == 501111) {
  StateName = "五"; 
 }
 if (包 == 501106||包 == 501109||包 == 501112) {
  StateName = "六"; 
 }
 if (包 == 9806001) {
  StateName = "一"; 
 }
 if (包 == 9806002) {
  StateName = "二"; 
 }
 if (包 == 9806003) {
  StateName = "三"; 
 }
 if (包 == 9806004) {
  StateName = "四"; 
 }
 if (包 == 9806005) {
  StateName = "四"; 
 }
 if (包 == 9806006) {
  StateName = "四"; 
 }
 if (包 == 9806007) {
  StateName = "五"; 
 }
 if (包 == 9806008) {
  StateName = "五"; 
 }
 if (包 == 9806009) {
  StateName = "五"; 
 }
 if (包 == 9806010) {
  StateName = "六"; 
 }
 if (包 == 9806011) {
  StateName = "六"; 
 }
 if (包 == 9806012) {
  StateName = "六"; 
 }
 if (包 == 9806013) {
  StateName = "七"; 
 }
 if (包 == 9806014) {
  StateName = "七"; 
 }
 if (包 == 9806015) {
  StateName = "七"; 
 }
 if (包 == 9806016) {
  StateName = "七"; 
 }
 if (包 == 9806017) {
  StateName = "七"; 
 }
 if (包 == 9806018) {
  StateName = "七"; 
 }
 return StateName;
 }
#endif
