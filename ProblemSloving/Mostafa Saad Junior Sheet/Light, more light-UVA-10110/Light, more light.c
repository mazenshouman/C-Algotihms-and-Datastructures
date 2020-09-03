#include <stdio.h>
#include <math.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32; 
typedef unsigned long long uint64;

/* Sol 2*//*
typedef uint8 Sqrt_returnType;
#define SQRT_EXIST          (Sqrt_returnType)1
#define SQRT_NOT_EXISTS     (Sqrt_returnType)0

Sqrt_returnType checkSqr(uint32 number)
{
    Sqrt_returnType returnValue=SQRT_NOT_EXISTS; 
    uint32 counter;
    uint64 result=0;
    for(counter=1 ; result<number ; counter++)
    {
        result=counter*counter;
        if(result==number)
        {
            returnValue=SQRT_EXIST;
            break;
        }
    }
    return returnValue;
}
*/
int main()
{
    uint32 input , counter , loopCounter  ,temp;
    while(1)
    {
        scanf("%u" , &input);
        if(input==0)
        {
            break;
        }
/***************************************************************************************************************************************/
        /* Sol 1*/
        /*O(N*M)*//*TLE*/
        /*
        /*  loop on all values from one to the number and chech if the number is divisable by
            the number and at the end check if the total count is odd or even
        *//*
        counter=0;
        for(loopCounter=1 ; loopCounter<=input ; loopCounter++)
        {
            if(input%loopCounter==0)
            {
                counter++;
            }
        }


        if(counter%2)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        */
/***************************************************************************************************************************************/
        /* Sol 2*/
        /* using sqrt you can find if the factors are even or odd so if the number have sqrt then the factors will be odd*/
        /*O(n*\/m)  *//*TLE*//*
        if(checkSqr(input)==SQRT_EXIST)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        */
/***************************************************************************************************************************************/
        /*Sol 2 another sol using the Sqrt from the math.h header file*/

        temp=(unsigned int)sqrt(input);/*I don't know why but you must cast this fucntion to unsigned int before assigning it to the variable
         or it will produce TLE (I will check the assembly to find the reason for that)*/
        if(temp*temp==input)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
    
}