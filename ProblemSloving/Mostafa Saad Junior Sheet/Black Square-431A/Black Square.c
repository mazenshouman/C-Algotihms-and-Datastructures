#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;


#define NUMBER_OF_VER_STRIPS      4
#define CONVERT_CHAR_TO_NUMBER(X)   ((X)-'0')
int main(){

    uint16 stripsCalArr[NUMBER_OF_VER_STRIPS];
    sint8 currentInput;
    uint8 stripNumber=0;
    uint32 calCounter=0;
    while(stripNumber<NUMBER_OF_VER_STRIPS)
    {
        scanf("%hu" , &stripsCalArr[stripNumber++]);
    }
    getchar();
    while(1)
    {
        scanf("%c" , &currentInput);
        if(currentInput=='\n'){
            break;
        }
        calCounter+=stripsCalArr[CONVERT_CHAR_TO_NUMBER(currentInput)-1];
    }
    printf("%d" , calCounter);

    return 0;
}
