#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef unsigned short uint16;
typedef unsigned long uint32;


#define BOB_WEIGHT_INCREASE     2;
#define LIMAK_WEIGHT_INCREASE   3;
int main(){

    uint16 LimakWeight , BobWeight;
    uint8 loopCounter=0;
    scanf("%hu%hu" , &LimakWeight , &BobWeight);
    while(LimakWeight<=BobWeight)
    {   
        LimakWeight*=LIMAK_WEIGHT_INCREASE;
        BobWeight*=BOB_WEIGHT_INCREASE;
        loopCounter++;
    }
    printf("%d" , loopCounter);
    return 0;
}