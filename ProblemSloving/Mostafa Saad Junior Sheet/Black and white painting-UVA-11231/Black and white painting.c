#include <stdio.h>
#include <math.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned int uint32; 
typedef unsigned long long uint64;

#define DEFALUT_NUMBER_OF_ROWS    7
#define DEFALUT_NUMBER_OF_COLUMNS 7
#define BLACK                     0
#define WHITE                     1

#define IS_ODD(X)  ((X)%2)
int main()
{
    uint16 rows , cols , lastBoxColor;
    uint32 numberOfPaintings;
    while(1)
    {
        scanf("%hu%hu%hu" , &rows , &cols , &lastBoxColor);
        if(rows==cols && rows==0)
        {
            break;
        }
        numberOfPaintings=((rows-DEFALUT_NUMBER_OF_ROWS)*(cols-DEFALUT_NUMBER_OF_COLUMNS)+(lastBoxColor))/2;
        printf("%d\n" , numberOfPaintings);
    }
    return 0;
}