#include <stdio.h>
#include <math.h>
typedef signed char sint8;
typedef unsigned char uint8;    
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned int uint32; 
typedef unsigned long long uint64;



typedef uint8 choiceType;
#define NOT_GOOD    (choiceType)0
#define GOOD        (choiceType)1 
int main()
{
    choiceType flag=NOT_GOOD;
    uint32 step , mod , loop;
    const sint8* arrString[2]={"Bad Choice","Good Choice"};
    while(scanf("%u%u" , &step , &mod)!=EOF)
    {
        if(step==1)
        {
            flag=GOOD;
        }
        else if(step != mod)
        {
            for(loop=2 ; loop<=step ; loop++)
            {
                if((mod%loop==0) && (step%loop==0))
                {
                    flag=NOT_GOOD;
                    break;
                }
                flag=GOOD;
            }
        }
        else
        {
           flag=NOT_GOOD;
        }
        printf("%10d%10d    %s\n\n" , step , mod  , arrString[flag]);
    }
    
    return 0;
}