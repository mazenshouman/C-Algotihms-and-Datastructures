#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef unsigned short uint16;
typedef unsigned long uint32;

#define NUMBER_OF_PROBLEMS_PER_ROW 3

int main(){
    uint16 numberOfProblems , inputCounter=0 , numberOfProblemsToBeSolved=0 , tempVar;
    uint8 loopCounter ;
    scanf("%hu" , &numberOfProblems);
    while(numberOfProblems--){
        inputCounter=0;
        for(loopCounter=0 ; loopCounter<NUMBER_OF_PROBLEMS_PER_ROW ;++loopCounter)
        {
            scanf("%hu" , &tempVar);
            if(tempVar)
                inputCounter++;
        }
        if(inputCounter>=2)
        {
            numberOfProblemsToBeSolved++;
        }
    }
    printf("%d" , numberOfProblemsToBeSolved);
}