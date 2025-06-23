#include "Com\Com_Util.h"
#include "Int\Int_Key.h"
#include "Int\Int_DigtalTube.h"

void main()
{
    //初始化数码管
    Init_DigtalTube();
    //防止程序跑飞
    while(1){
        if (Int_Key_IsSW1Pressed())
        {
            //能进来说明按下了
            //显示520
            DigtalTube_setBuffer(520);
        }
        if (Int_Key_IsSW2Pressed())
        {
            //能进来说明按下了
            //显示520
            DigtalTube_setBuffer(1314);
        }
        if (Int_Key_IsSW3Pressed())
        {
            //能进来说明按下了
            //显示520
            DigtalTube_setBuffer(666);
        }
        if (Int_Key_IsSW4Pressed())
        {
            //能进来说明按下了
            //显示520
            DigtalTube_setBuffer(888);
        }
        //刷新数码管
        DigtalTube_Refresh();
    }
}