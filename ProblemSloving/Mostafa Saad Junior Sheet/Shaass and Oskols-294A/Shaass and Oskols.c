#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;



#define MAX_NUMBER_OF_LINES 100

int main()
{

    uint16 birdsArr[MAX_NUMBER_OF_LINES+1];
    uint16 numberOfLines , numberOfShots;
    uint16 birdNumber , lineNumber;
    uint8 counter=0;

    scanf("%hu" , &numberOfLines);
    for(counter=1 ; counter<=numberOfLines ; ++counter)
    {
        scanf("%hu" , &birdsArr[counter]);
    }
    scanf("%hu" , &numberOfShots);
    while(numberOfShots--)
    {
        scanf("%hu %hu" , &lineNumber , &birdNumber);
        if(lineNumber>1)
        {
            birdsArr[lineNumber-1]+=birdNumber-1;
        }
        if(lineNumber<numberOfLines){
            birdsArr[lineNumber+1]+=birdsArr[lineNumber]-birdNumber;
        }
        birdsArr[lineNumber]=0;
    }

    for(counter=1  ; counter<=numberOfLines ; ++counter){
        printf("%d\n" , birdsArr[counter]);
    }

    return 0;
}