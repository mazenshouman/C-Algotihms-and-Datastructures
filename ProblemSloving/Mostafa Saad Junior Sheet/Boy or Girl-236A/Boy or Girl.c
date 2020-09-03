#include <stdio.h>
#include <string.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;

#define NUMBER_OF_ALPHABETS   26

#define IS_EVEN(X)    (((X)%2)?(0):(1))

int main(){
    sint8 alphabetFreqArr[NUMBER_OF_ALPHABETS]={0};
    sint8 input;
    uint8 numberOfUniqueAlpa=0;
    memset(alphabetFreqArr , 0 , NUMBER_OF_ALPHABETS);
    do{
        scanf("%c" , &input);
        if(alphabetFreqArr[input-'a']==0)
        {
            alphabetFreqArr[input-'a']++;
            numberOfUniqueAlpa++;
        }
    } while(input!='\n');
    if(IS_EVEN(numberOfUniqueAlpa-1))
    {
        printf("CHAT WITH HER!");
    }
    else
    {
        printf("IGNORE HIM!");
    }
    return 0;
}
