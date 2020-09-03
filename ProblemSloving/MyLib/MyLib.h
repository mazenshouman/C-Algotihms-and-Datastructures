#ifndef __MY_LIB__
#define __MY_LIB__


/**********************************************************************
 *                     types and file inclusions                      *
 * ********************************************************************/
#include <stdio.h>
#include <string.h>

typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;


typedef sint8 MyLib_Swap_t;

/**********************************************************************
 *                     Macros like function                           *
 * ********************************************************************/


#define IS_ODD(X)                           (((X)&1))
#define IS_EVEN(X)                          (!((X)&1))
#define CONVERT_DIGIT_TO_CHAR(X)            ((X)+'0')





/**********************************************************************
 *                     Functions' prototypes                          *
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

uint32 Get_GCD_Rec(uint32 firstNumber , uint32 secondNumber);

/**************************************************************************************************************************************
 *  Function : Get_GCD_Iter                                                                                                            *
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

uint32 Get_GCD_Iter(uint32 firstNumber , uint32 secondNumber);


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
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

void convertNumberToString(uint16 Value , sint8* String);

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

void swapToValues(MyLib_Swap_t* firstValue  , MyLib_Swap_t* secondValue);


#endif