#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

#define NUMBER_OF_INPUTS   4
int main(){

    uint64 inputArr[4];
    uint8 counter=0  , innerLoopCounter=0 , numberOfShoesToBuy=0;
    for(counter=0 ; counter<NUMBER_OF_INPUTS ; ++counter){
        scanf("%llu" , &inputArr[counter]);
        for(innerLoopCounter=counter ; innerLoopCounter>0 ; --innerLoopCounter){
            if(inputArr[counter]==inputArr[innerLoopCounter-1])
            {
                numberOfShoesToBuy++;
                break;
            }
        }
    }
    printf("%d" , numberOfShoesToBuy);
    return 0;
}