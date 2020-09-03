#include <stdio.h>
#include <string.h>

typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

#define IS_ODD(X)  ((X)%2)
uint32 GetInclusionExclusion(uint32 number , uint32 firstNumber , uint32 SecondNumber)
{
    uint32 local_Counter , returnCounter=0 , val1 , val2 , val3 , val4 , val5;
    uint64 currentValue;
    sint8 sign;
    for(val1=0 ; val1<2 ; val1++)
    {
        for(val2=0 ; val2<2 ; val2++)
        {
            for(val3=0 ; val3<2 ; val3++)
            {
                for(val4=0 ; val4<2 ; val4++)
                {
                    for(val5=0 ; val5<2 ; val5++)
                    {
                        local_Counter=0;
                        currentValue=1;
                        sign=1;
                        if(val1)
                        {
                            currentValue*=firstNumber;
                            ++local_Counter;
                        }
                        if(val2)
                        {
                            currentValue*=(firstNumber+SecondNumber);
                            ++local_Counter;
                        }
                        if(val3)
                        {
                            currentValue*=(firstNumber+2*SecondNumber);
                            ++local_Counter;
                        }
                        if(val4)
                        {
                            currentValue*=(firstNumber+3*SecondNumber);
                            ++local_Counter;
                        }
                        if(val5)
                        {
                            currentValue*=(firstNumber+4*SecondNumber);
                            ++local_Counter;
                        }
                        if(local_Counter==0)
                        {
                            continue;
                        }
                        if(!IS_ODD(local_Counter))
                        {
                            sign=-1;
                        }
                        returnCounter+=sign *(number/currentValue); 
                    }
                }
            }   
        }
    }
    return returnCounter;
}

int main()
{

    uint16 numberOfInputs;
    uint32 startOfRange , endOfRange , firstNumber , SecondNumber;
    scanf("%hu" , &numberOfInputs);
    while(numberOfInputs--)
    {
        scanf("%u %u %u %u" , &startOfRange , &endOfRange , &firstNumber , &SecondNumber);
        printf("%d\n" , GetInclusionExclusion(endOfRange-startOfRange+1 , firstNumber , SecondNumber));
    }  


    return 0;
}