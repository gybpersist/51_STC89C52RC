#include "Com\Com_Util.h"
#include "Int\Int_DigtalTube.h"
#include "Int\Int_MatrixKey.h"

void main()
{
    u8 key = 0;
    //初始化数码管
    Int_DigtalTube_Init();
    Int_DigtalTube_setBuffer(key);
    //防止程序跑飞
    while(1){
        //在死循环中调用矩阵按钮的扫描函数,并把返回值给数码管去显示
        key = Int_MatrixKey_CheckKey();

        if (key)
        {
            Int_DigtalTube_setBuffer(key);
        }
        

        //刷新
        Int_DigtalTube_Refresh();
    }
}