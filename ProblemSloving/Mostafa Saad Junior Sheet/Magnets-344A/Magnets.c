#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;

typedef uint8 strMatchType;
#define MATACH_STR      (strMatchType)1
#define NOT_MATCH_STR   (strMatchType)0
#define STRING_SIZE  3

strMatchType simpleStrCmp(const sint8* firstStr , const sint8* secondStr)
{
    strMatchType returnValue=1;
    while(*firstStr){
        if(*firstStr++!=*secondStr++){
            returnValue=0;
            break;
        }
    }
    return returnValue;
}

void simpleStrCpy(const sint8* sourceStr , sint8* destStr){
    while((*destStr++=*sourceStr++));
}

 
int main(){
    uint32 numberOfInputs , numberOfGroups=1;
    sint8 PreviousStr[STRING_SIZE];
    sint8 CurrentStr[STRING_SIZE];
    scanf("%u" , &numberOfInputs);
    scanf("%s" , PreviousStr);
    while(--numberOfInputs){
        scanf("%s" , CurrentStr);
        if(simpleStrCmp(CurrentStr , PreviousStr)==NOT_MATCH_STR){
            numberOfGroups++;
        }
        simpleStrCpy(CurrentStr , PreviousStr);
    }
    printf("%d" , numberOfGroups);
    return 0;
}