#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef unsigned short uint16;
typedef unsigned long uint32;

#define NUMBER_OF_ROWS      (uint8)5
#define NUMBER_OF_COLUMNS   (uint8)5
#define ROW_MID             (uint8)3
#define COLUMN_MID          (uint8)3

uint8 myAbs(uint8 firstValue , uint8 secondValue){
    uint8 returnValue;
    if(firstValue > secondValue){
        returnValue=firstValue-secondValue;
    }else
    {
        returnValue=secondValue-firstValue;
    }
    return returnValue;
}


int main()
{
    uint8 rowCounter , columnCounter , flag=0 ,  numberOfMoves;
    uint16 input;
    for(rowCounter=0 ; rowCounter<NUMBER_OF_ROWS ; ++rowCounter){
        /*if(flag==1){
            break;
        }*/
        for(columnCounter=0 ; columnCounter<NUMBER_OF_COLUMNS ; ++columnCounter){
            scanf("%hu",&input);
            if(input){
                numberOfMoves=myAbs(rowCounter+1 , ROW_MID)+ myAbs(columnCounter+1 , COLUMN_MID);
            }
        }
    }
    printf("%d" , numberOfMoves);
}