#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;

#define MAX_VALUE_FOR_COLOR 100
int main()
{
    uint8 hostFreqArr[MAX_VALUE_FOR_COLOR]={0};
    uint8 gustFreqArr[MAX_VALUE_FOR_COLOR]={0};
    uint16 gustColor , hostColor;
    uint16 numberOfInputs;
    uint16 numberOfMatches=0;
    scanf("%hu" , &numberOfInputs);
    while(numberOfInputs--)
    {
        scanf("%hu%hu" , &hostColor , &gustColor);
        hostFreqArr[hostColor-1]++;
        gustFreqArr[gustColor-1]++;
    }
    for(numberOfInputs=0 ; numberOfInputs<MAX_VALUE_FOR_COLOR ; ++numberOfInputs)
    {
        if(hostFreqArr[numberOfInputs]>0 && gustFreqArr[numberOfInputs]>0)
        {
            numberOfMatches+=hostFreqArr[numberOfInputs]*gustFreqArr[numberOfInputs];
        }
    }
    printf("%d" , numberOfMatches);
    return 0;
}