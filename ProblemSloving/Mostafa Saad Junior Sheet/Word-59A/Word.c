#include <stdio.h>
#include <string.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;

#define IS_LOWER(X)   (((X)>='a') && ((X)<='z'))
#define DIFFERENCE_BETWEEN_CASES    32
typedef uint8 caseType;
#define LOWER_CASE    (caseType)1
#define UPPER_CASE    (caseType)0

void changeCase(sint8*arr , caseType Case)
{
    if(Case==LOWER_CASE){
        while(*arr){
            if(!IS_LOWER(*arr)){
                *arr+=DIFFERENCE_BETWEEN_CASES;
            }
            arr++;
        }
    }
    else{
        while(*arr){
            if(IS_LOWER(*arr)){
                *arr-=DIFFERENCE_BETWEEN_CASES;
            }
            arr++;
        }
    }
}

int main(){
    sint8 alphaCaseCounter=0;
    uint8 counter=0;
    sint8 input[100];
    while(1){
        scanf("%c" , &input[counter]);
        if(input[counter]=='\n'){
            break;
        }
        else{
            if(IS_LOWER(input[counter])){
                ++alphaCaseCounter;
            }else{
                --alphaCaseCounter;
            }
        }
        counter++;
    }
    input[counter]='\0';
    if(alphaCaseCounter>=0){
        changeCase(input , LOWER_CASE);
    }else{
        changeCase(input , UPPER_CASE);
    }
    printf("%s" , input);
}