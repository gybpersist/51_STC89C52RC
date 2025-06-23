#include "Com\Com_Util.h"
#include "Int\Int_Key.h"

void main()
{
    
    //防止程序跑飞
    while(1){
        if (Int_Key_IsSW1Pressed())
        {
            //能进来说明按下了
            P00 = ~P00;
        }
        if (Int_Key_IsSW2Pressed())
        {
            //能进来说明按下了
            P01 = ~P01;
        }
        if (Int_Key_IsSW3Pressed())
        {
            //能进来说明按下了
            P02 = ~P02;
        }
        if (Int_Key_IsSW4Pressed())
        {
            //能进来说明按下了
            P03 = ~P03;
        }
    }
}