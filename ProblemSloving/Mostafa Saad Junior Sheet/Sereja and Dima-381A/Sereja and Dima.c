#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;


#define IS_ODD(X)  ((X)%2)

int main()
{   
    uint32 dimaCounter=0 , SerejaCounter=0;
    uint16 inputArr[1000];
    uint16 frontCurrentIndex=0 , backCurrentIndex=0 , numberOfCards=0 , oddFlag=0;

    scanf("%hu" , &numberOfCards);
    backCurrentIndex=numberOfCards-1;
    for(frontCurrentIndex=0 ; frontCurrentIndex<numberOfCards ; ++frontCurrentIndex)
    {
        scanf("%hu" , &inputArr[frontCurrentIndex]);
    }
    frontCurrentIndex=0;
    if(IS_ODD(numberOfCards)){
        oddFlag=1;
    }
    while(numberOfCards--){
        if(inputArr[frontCurrentIndex]>inputArr[backCurrentIndex])
        {
            if(IS_ODD(numberOfCards))
            {
                SerejaCounter+=inputArr[frontCurrentIndex++];
            }
            else{
                dimaCounter+=inputArr[frontCurrentIndex++];    
            }
        }
        else
        {
            if(IS_ODD(numberOfCards))
            {
                SerejaCounter+=inputArr[backCurrentIndex--];
            }
            else{
                dimaCounter+=inputArr[backCurrentIndex--];    
            }
        }
    }
    if(oddFlag){
        printf("%d %d" , dimaCounter ,SerejaCounter);
    }
    else{
        printf("%d %d" , SerejaCounter ,dimaCounter);
    }
}