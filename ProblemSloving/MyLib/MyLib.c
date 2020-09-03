#include "stdio.h"
#include "MyLib.h"



/**********************************************************************
 *                   Functions' Implementations                       *   
 * ********************************************************************/

/**************************************************************************************************************************************
 *  Function : Get_GCD_Rec                                                                                                            *
 *  Param    : IN     : Name / firstNumber                                                                                            *
 *                      Type / uint32                                                                                                 *
 *                      Desc / takes the first number                                                                                 *
 *           : IN     : Name / secondNumber                                                                                           *
 *                      Type / uint32                                                                                                 *
 *                      Desc / takes the second number                                                                                *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : uint32                                                                                                                 *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function returns the GCD for two numbers using recursion                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

uint32 Get_GCD_Rec(uint32 firstNumber , uint32 secondNumber)
{
    uint32 returnValue;
    if(secondNumber==0)
    {
        returnValue=firstNumber;
    }
    else
    {
        /* this will take the bigger number and get modules with smaller number ..if it equals zero so the smaller number is the gcd else keep 
            taking the result of the modules and get modules for the smaller number modules the result for the last modules
            Ex:
            gcd(4 ,6) (swap)-> gcd(6 , 4%6) -> gcd(6 , 4) -> gcd(4 , 6%4) -> gcd(2 , 4%2) -> gcd(2 , 0) -> return 2;
        */
        returnValue=Get_GCD_Rec(secondNumber , firstNumber%secondNumber);
    }
    return returnValue;
}


/**************************************************************************************************************************************
 *  Function : Get_GCD_Iter                                                                                                           *
 *  Param    : IN     : Name / firstNumber                                                                                            *
 *                      Type / uint32                                                                                                 *
 *                      Desc / takes the first number                                                                                 *
 *           : IN     : Name / secondNumber                                                                                           *
 *                      Type / uint32                                                                                                 *
 *                      Desc / takes the second number                                                                                *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : uint32                                                                                                                 *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function returns the GCD for two numbers using iteration                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

uint32 Get_GCD_Iter(uint32 firstNumber , uint32 secondNumber)
{
    uint32 returnValue , oldFirst;
    while(secondNumber!=0)
    {
        oldFirst=firstNumber;
        firstNumber=secondNumber;/* newfirst=oldsecond */
        secondNumber=oldFirst%secondNumber;/* newSecond=oldfirst%oldsecond */
    }
    return firstNumber;
}

/**************************************************************************************************************************************
 *  Function : convertNumberToString                                                                                                  *
 *  Param    : IN     : Name / Value                                                                                                  *
 *                      Type / uint16                                                                                                 *
 *                      Desc / the value wanted to converted to string                                                                *
 *                      Name / String                                                                                                 *
 *                      Type / sint8*                                                                                                 *
 *                      Desc / the address of the string wanted to return the result to it                                            *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : uint32                                                                                                                 *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function Converts number to string                                                                                *
 *             -->macro like function CONVERT_DIGIT_TO_CHAR(X) must be included in the code<--                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/
void convertNumberToString(uint16 Value , sint8* String)
{
    /* create variable to save the curretnt last digit on it*/
    uint8 currentDigit=0;

    /* variable to store the current position in the string */
    uint8 currentPos=0;

    /* variable to start form the first place of the string to invert the string */
    uint8 tempPos=0;


    /*coner Cases*/
    if(Value==0)
    {
        String[currentPos++]='0';
    }
    /*loop until the variable equal zero*/
    while(Value)
    {
        /* take the first digit of the number */
        currentDigit=Value%10;

        /* detuct the taken digit from the value */
        Value/=10;

        /*put the current digit into the string*/
        String[currentPos]=CONVERT_DIGIT_TO_CHAR((sint8)currentDigit);
        
        currentPos++;
    }
    /* put null at the end of the string */
    String[currentPos]='\0';

    /* reduce the current pos by one to leave the null character at it's place */
    --currentPos;

    for(tempPos=0   ; tempPos<currentPos ; ++tempPos , --currentPos)
    {
        swapToValues(&String[tempPos] , &String[currentPos]);
    } 
}

/**************************************************************************************************************************************
 *  Function : swapToValues                                                                                                           *
 *  Param    : IN     : Name / firstValue                                                                                             *
 *                      Type / MyLib_Swap_t*                                                                                          *
 *                      Desc / the address of the first value wanted to be swapped                                                    *
 *                      Name / secondValue                                                                                            *
 *                      Type / MyLib_Swap_t*                                                                                          *
 *                      Desc / the address of the second value wanted to be swapped                                                   *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : uint32                                                                                                                 *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function swap to values                                                                                           *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

void swapToValues(MyLib_Swap_t* firstValue  , MyLib_Swap_t* secondValue)
{
    MyLib_Swap_t tempVar = *firstValue;
    *firstValue = *secondValue;
    *secondValue = tempVar; 
}
