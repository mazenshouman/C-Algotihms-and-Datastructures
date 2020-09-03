#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;



int main()
{
    uint16 lengthOfWord , maxNumberOfDisLetters;
    uint8 counter=0;

    scanf("%hu %hu",  &lengthOfWord , &maxNumberOfDisLetters);
    
    while(lengthOfWord--)
    {
        printf("%c" , 'a'+counter);
        counter = (counter+1)%maxNumberOfDisLetters;
    }
    return 0;
}
