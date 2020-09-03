#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef unsigned short uint16;
typedef unsigned long uint32;


int main(){
    uint32 numberOfGames=0 ,DCounter=0 , ACounter=0;
    sint8 input;
    scanf("%d" , &numberOfGames);
    getchar();
    while(numberOfGames--){
        scanf("%c" , &input);
        if(input=='D')
        {
            DCounter++;
        }else
        {
            ACounter++;
        }
    }
    if(DCounter==ACounter){
        printf("Friendship");
    }else if(DCounter>ACounter){
        printf("Danik");
    }else{
        printf("Anton");
    }
    return 0;
}