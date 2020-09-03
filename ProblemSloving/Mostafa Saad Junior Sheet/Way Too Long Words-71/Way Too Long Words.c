#include <stdio.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

#define WORD_MAX_SIZE       100
#define MAX_WORD_LENGTH     10
#define FIRST_CHAR_INDEX    0

int main()
{
    uint16 numberOfWords;
    sint8 wordTempArr[WORD_MAX_SIZE];
    uint8 counter=0 , currentIndex=0;

    scanf("%hu" , &numberOfWords);
    getchar();
    while(numberOfWords--)
    {
        counter=0; 
        currentIndex=0;
        while(1)
        {
            scanf("%c" , &wordTempArr[currentIndex]);
            if(wordTempArr[currentIndex]=='\n')
            {
                if(currentIndex<=MAX_WORD_LENGTH)
                {
                    wordTempArr[currentIndex]='\0';
                    printf("%s\n" , wordTempArr);
                }
                else
                {
                    printf("%c%d%c\n" , wordTempArr[FIRST_CHAR_INDEX] , currentIndex-2 , wordTempArr[currentIndex-1]);
                }
                break;
            }
            currentIndex++;
        }
    }
    












    return 0;
}