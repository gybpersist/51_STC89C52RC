#include "Com/Com_Util.h"
//把数码管的头文件导入
#include "Int/Int_DigtalTube.h"

void main()
{
    //初始化数码管
    Init_DigtalTube();

    DigtalTube_setBuffer(555666);
    //防止程序跑飞
    while(1){
        DigtalTube_Refresh();
    }
}