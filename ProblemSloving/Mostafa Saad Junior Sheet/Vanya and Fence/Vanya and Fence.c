#include <stdio.h>

typedef unsigned char uint8;    
typedef unsigned short uint16;
typedef unsigned long uint32;

int main(){
    uint16 numberOfInputs=0 , fenceHeight=0 , totalWidth=0;
    uint32 input;
    scanf("%hu%hu" , &numberOfInputs , & fenceHeight);
    while(numberOfInputs--)
    {
        scanf("%hu",&input);
        if(input>fenceHeight){
            totalWidth+=2;
        }else{
            totalWidth+=1;
        }
    }
    printf("%d", totalWidth);
    return 0;
}
 