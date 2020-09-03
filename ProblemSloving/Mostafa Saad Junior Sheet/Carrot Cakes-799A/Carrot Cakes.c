#include <stdio.h>
#include <math.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;


int main()
{
    uint16 numberOfCakes , timeForbake , numberOfCakesPerOven , timeForSecondOven;
    scanf("%hu%hu%hu%hu" , &numberOfCakes , & timeForbake , & numberOfCakesPerOven , &timeForSecondOven);
    if(numberOfCakesPerOven>=numberOfCakes || (timeForbake*ceil(numberOfCakes/numberOfCakesPerOven))<timeForSecondOven)
    {
        printf("NO");
    }
    else
    {
        if(((timeForbake*ceil(numberOfCakes*1.0/numberOfCakesPerOven))-(timeForbake))>timeForSecondOven)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
    }
    return 0;
}