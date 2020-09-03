#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

uint16 GetBigger(uint16 firstValue , uint16 secondValue)
{
    return (firstValue >= secondValue ? firstValue : secondValue);
}

int main(){
    uint8 maxValue=6;
    uint16 firstEntry , secondEntry;
    scanf("%hu" , &firstEntry);
    scanf("%hu" , &secondEntry);
    firstEntry=GetBigger(firstEntry , secondEntry);
    firstEntry = maxValue-firstEntry+1;
    secondEntry= firstEntry;
    while(firstEntry>1)
    {
        if((!(maxValue%firstEntry)) && (!(secondEntry%firstEntry)))
        {
            secondEntry/=firstEntry;
            maxValue/=firstEntry;
            break;
        }
        firstEntry-=2;
    }
    if(secondEntry==0){
        maxValue=1;
    }
    printf("%d/%d" , secondEntry , maxValue);




    return 0;
}