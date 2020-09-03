#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;


int main()
{
    sint8 sign;
    uint64  currentTotalPacks, input;
    uint16 numberOfRequests , counter=0;
    scanf("%hu%llu" , &numberOfRequests , &currentTotalPacks);
    getchar();
    while(numberOfRequests--)
    {
        scanf("%c %llu" , &sign , &input);
        getchar();
        if(sign=='+')
        {
            currentTotalPacks+=input;
        }
        else
        {
            if(currentTotalPacks<input)
            {
                counter++;
            }
            else
            {
                currentTotalPacks-=input;
            }
        }
    }
    printf("%llu %d" , currentTotalPacks , counter);



    return 0;
}