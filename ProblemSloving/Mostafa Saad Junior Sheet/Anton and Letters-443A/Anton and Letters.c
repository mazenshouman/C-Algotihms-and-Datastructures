#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;


#define MAX_NUMBER_OF_LETTERS 26
#define MAX_SIZE_OF_STRING    1000
int main()
{

    uint16 charArr[26]={0};
    uint8 counter=0;
    uint16 loopCounter=0;
    sint8 input[1000];
    fgets(input , sizeof(input) , stdin);
    while(input[loopCounter]!='}')
    {
        if((input[loopCounter]!='{')&&(input[loopCounter]!=' ')&&(input[loopCounter]!=','))
        {
            charArr[input[loopCounter]-'a']++;
        }
        loopCounter++;
    }
    for(loopCounter=0 ; loopCounter<MAX_NUMBER_OF_LETTERS ; ++loopCounter)
    {
        if(charArr[loopCounter]!=0)
        {
            counter++;
        }
    }
    printf("%d" , counter);
    return 0;
}