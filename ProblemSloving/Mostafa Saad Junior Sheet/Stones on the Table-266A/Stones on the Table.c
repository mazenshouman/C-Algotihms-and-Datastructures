#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;



int main()
{
   sint8 currentChar , previousChar;
   uint16 numberOfInputs=0;
   uint8 counter=0;
   scanf("%hu" ,&numberOfInputs);
   getchar();
   scanf("%c" , &previousChar);
   while(numberOfInputs--)
   {
        scanf("%c" , &currentChar);
        if(currentChar==previousChar)
        {
            counter++;
        }
        else
        {
            previousChar=currentChar;
        }
   }
   printf("%d" , counter);
}