#include "Com\Com_Util.h"
#include "Int\Int_DigtalTube.h"


void main()
{
    //初始化数码管
    Int_DigtalTube_Init();
    Int_DigtalTube_setBuffer(12345678.123);
    //防止程序跑飞
    while(1){
        //刷新
        Int_DigtalTube_Refresh();
    }
}