#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;


sint8 My_Abs(sint8 value)
{
    return (value>0?value:value*-1);
}

#define NUMBER_OF_CHAR_TO_END(X)   ('z'-(X))
#define NUMBER_OF_CHAR_TO_START(X)  ((X)-'a')
int main(){
    uint16 numberOfRotations=0;
    sint8 previousChar='a';
    sint8 currentChar;
    sint8 temp;
    while(1)
    {
        scanf("%c" , &currentChar);
        if(currentChar=='\n')
        {
            break;
        }
        if(currentChar>previousChar)
        {
            if((currentChar-previousChar)<=(NUMBER_OF_CHAR_TO_START(previousChar)+NUMBER_OF_CHAR_TO_END(currentChar)+1))
            {
                numberOfRotations+=currentChar-previousChar;
             }
            else
            {
                numberOfRotations+=(NUMBER_OF_CHAR_TO_START(previousChar)+NUMBER_OF_CHAR_TO_END(currentChar)+1);
            }
        }
        else
        {
            if((previousChar-currentChar)<=(NUMBER_OF_CHAR_TO_START(currentChar)+NUMBER_OF_CHAR_TO_END(previousChar)+1))
            {
                numberOfRotations+=previousChar-currentChar;
            }
            else
            {
                numberOfRotations+=(NUMBER_OF_CHAR_TO_START(currentChar)+NUMBER_OF_CHAR_TO_END(previousChar)+1);
            }

        }
        previousChar=currentChar;
    }
    printf("%d" , numberOfRotations);
    return 0;
}