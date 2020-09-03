#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;



int main(){
    sint8 stonesArr[50];
    sint8 instrArr[50];
    uint8 stoneCounter=0 , instrCounter=0 , limit=0;
    scanf("%s" , stonesArr);
    getchar();
    scanf("%s" , instrArr);
    for(stoneCounter=0  , instrCounter=0 ; stonesArr[stoneCounter]&&instrArr[instrCounter]; instrCounter++){
        if(stonesArr[stoneCounter]== instrArr[instrCounter]){
            stoneCounter++;
        }
    }
    printf("%d" , stoneCounter+1);


    return 0;
}