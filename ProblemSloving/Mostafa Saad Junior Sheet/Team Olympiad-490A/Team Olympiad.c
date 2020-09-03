#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

#define MAX_VALUE   3
#define MAX_INPUT_SIZE  5000


uint16 GetMin(uint16 first , uint16 second , uint16 third)
{
    uint16 returnValue;
    if(first<=second && first<=third)
    {
        returnValue=first;
    }
    else if(second<=first && second<=third)
    {
        returnValue=second;
    }
    else
    {
        returnValue=third;
    }
    return returnValue;
}

int main()
{
    uint16 indexArr[MAX_VALUE]={0};
    uint16 valueArr[MAX_VALUE][MAX_INPUT_SIZE];
    uint16 numberOfInputs;
    uint16 minValue,counter;
    uint16 input;
    scanf("%hu" , &numberOfInputs);
    for(counter=1 ; counter<=numberOfInputs ; counter++)
    {
        scanf("%hu" , &input);
        valueArr[input-1][indexArr[input-1]]=counter;
        indexArr[input-1]++;
    }
    counter=0;
    minValue=GetMin(indexArr[0],indexArr[1] , indexArr[2]);
    printf("%d\n" , minValue);
    while(counter<=minValue-1)
    {
        printf("%d %d %d\n" , valueArr[0][counter] , valueArr[1][counter] ,valueArr[2][counter]);
        counter++;
    }





    return 0;
}