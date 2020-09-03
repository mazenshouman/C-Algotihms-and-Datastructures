#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

#define MAX_NUMBER          3

int main()
{
    sint8 arr[MAX_NUMBER]={0};
    sint8 input;
    while(1)
    {
        scanf("%c"  , &input);
        if(input=='\n')
        {
            break;
        }
        else if(input!=' ')
        {
            arr[input-'1']++;
        }
    }
    for(input=0 ; input<MAX_NUMBER ; input++){
        if(arr[input])
        {
            printf("%c" , input+'1');
            --arr[input];
            break;
        }   
    }
    for(input=0 ; input<MAX_NUMBER ; input++)
    {
        while(arr[input])
        {
            printf("+%c" , input+'1');
            --arr[input];
        }
    }
    return 0;
}