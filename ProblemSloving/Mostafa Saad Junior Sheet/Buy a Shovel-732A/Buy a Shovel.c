#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;




int main()
{
    uint32 shovelPrice;
    uint16 coinValue;
    uint8 counter=1;
    scanf("%u%hu" , &shovelPrice , &coinValue);
    while(((shovelPrice*counter)%10 != coinValue)&& ((shovelPrice*counter)%10!=0)){
        counter++;
    }
    printf("%d" , counter);

    return 0;

}
