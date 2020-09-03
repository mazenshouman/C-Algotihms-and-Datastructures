#include <stdio.h>
#include <string.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
void convertToUpperCase(sint8* arr){
    while(*arr){
        if(*arr>'Z'){
            *arr-=32;
        }
        arr++;
    }
}

#define NUMBER_OF_STRINGS    2
int main(){

    uint8 firstArr[1000],secondArr[1000] , counter=0 ;
    sint16 differenceCounter=0;
    scanf("%s" , firstArr);
    convertToUpperCase(firstArr);
    getchar();
    scanf("%s" , secondArr);
    convertToUpperCase(secondArr);
    while(firstArr[counter]){
        if(firstArr[counter]!=secondArr[counter])
        {
            if(firstArr[counter]>secondArr[counter]){
                differenceCounter++;
            }else{                
                differenceCounter--;
            }
            break;
        }
        counter++;
    }
    printf("%d" , differenceCounter);
}