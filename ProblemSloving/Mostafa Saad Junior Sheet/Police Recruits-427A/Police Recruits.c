#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;


int main()
{
    uint32 numberOfInputs=0 , numberOfCrimes=0;
    uint32 numberOfPoilceOfficer=0;
    sint16 currentInput;
    scanf("%u" , &numberOfInputs);
    while(numberOfInputs--)
    {
        scanf("%hd" , &currentInput);
        if(currentInput==-1)
        {
            if(numberOfPoilceOfficer>0)
            {
                --numberOfPoilceOfficer;    
            }
            else
            {
                numberOfCrimes++;
            }
        }
        else
        {
            numberOfPoilceOfficer+=currentInput;
        }
    }
    printf("%d" , numberOfCrimes);
}