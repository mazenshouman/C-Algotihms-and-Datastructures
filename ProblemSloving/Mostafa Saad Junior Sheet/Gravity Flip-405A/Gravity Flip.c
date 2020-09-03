#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef unsigned short uint16;
typedef unsigned long uint32;

void swap(uint16 * firstValue , uint16* secondValue){
    *firstValue +=*secondValue;
    *secondValue =*firstValue-*secondValue;
    *firstValue -=*secondValue;
}

void BubbleSort(uint16* arr  , uint16 size){
    uint8 NumberOfIteration , innerLoopCounter;
    for(NumberOfIteration=0 ; NumberOfIteration < size-1 ; ++NumberOfIteration)
    {
        for(innerLoopCounter=0 ; innerLoopCounter<size-NumberOfIteration-1 ; ++innerLoopCounter){
            if(arr[innerLoopCounter]>arr[innerLoopCounter+1]){
                swap(&arr[innerLoopCounter] , &arr[innerLoopCounter+1]);
            }
        }
    }
}

int main()
{
    uint16 arr[100] , counter=0;
    uint16 input;
    scanf("%hu" , &input);
    while(input--){
        scanf("%hu" , &arr[counter++]);
    }
    BubbleSort(arr , counter);
    for(input=0 ; input < counter ; ++input){
        printf("%d " , arr[input]);
    }
    return 0;
}