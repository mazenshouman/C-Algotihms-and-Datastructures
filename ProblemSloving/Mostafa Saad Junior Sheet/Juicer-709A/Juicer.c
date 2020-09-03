#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;


int main()
{
    uint32 numberOfOranges , OrangeMaxSize , juicerMaxSize;
    uint32 input;
    uint64 totalSum=0;
    uint32 result=0;
    scanf("%u%u%u" , &numberOfOranges , &OrangeMaxSize , &juicerMaxSize );
    while(numberOfOranges--)
    {
        scanf("%u" , &input);
        if(input<=OrangeMaxSize)
        {
            totalSum+=input;
        }
        if(totalSum>juicerMaxSize)
        {
            ++result;
            totalSum=0;
        }
    }
    printf("%d" , result);

    return 0;
}