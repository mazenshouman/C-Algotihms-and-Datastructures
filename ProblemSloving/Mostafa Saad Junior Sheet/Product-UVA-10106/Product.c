#include <stdio.h>
#include <string.h>

typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

#define FIRST_ARR           0
#define SECOND_ARR          1
#define MAX_LENGTH          255
#define NUMBER_OF_INPUTS    2
void reverseArr(uint8* arr, uint8 arrSize)
{
    uint8 counter;
    sint8 temp;
    for (counter = 0; counter < arrSize / 2; counter++)
    {
        temp = arr[counter];
        arr[counter] = arr[arrSize - counter - 1];
        arr[arrSize - counter - 1] = temp;
    }
}

uint8 GetBigger(uint8 firstValue, uint8 secondValue)
{
    uint8 returnValue;
    if (firstValue >= secondValue)
    {
        returnValue = firstValue;
    }
    else
    {
        returnValue = secondValue;
    }
    return returnValue;
}

#define GET_NUMBER(X) ((X)-'0')
int main()
{
    sint8 inputArr[NUMBER_OF_INPUTS][MAX_LENGTH] = { 0 };
    uint8 resultArr[1001] = {0};
    uint8  firstSize, secondSize, product, productCarry = 0, resultCarry = 0 ;
    uint16 loopingIndex=0, currentIndex=0 , temp;
    sint16 counter;
    while (scanf("%s%s", inputArr[FIRST_ARR],inputArr[SECOND_ARR])!=EOF)
    {
        memset(resultArr, 0, 1001);
        reverseArr((uint8*)inputArr[FIRST_ARR], (uint8)strlen(inputArr[FIRST_ARR]));
        reverseArr((uint8*)inputArr[SECOND_ARR], (uint8)strlen(inputArr[SECOND_ARR]));
        firstSize = (uint8)strlen(inputArr[FIRST_ARR]);
        secondSize = (uint8)strlen(inputArr[SECOND_ARR]);
        for (currentIndex = 0; currentIndex < firstSize; ++currentIndex)
        {
            for (loopingIndex = 0; loopingIndex < secondSize; ++loopingIndex)
            {
                /* get product by multiplying first digit of the first array by all elements of the second array + previous carry */
                product = GET_NUMBER(inputArr[SECOND_ARR][loopingIndex]) * GET_NUMBER(inputArr[FIRST_ARR][currentIndex])+productCarry;
                /* get next carry */
                productCarry = product / 10;
                /* add the first digit of the product to the result array */
                resultArr[currentIndex + loopingIndex] += product % 10 + resultCarry;
                /* check if there's carry in the current digit of the result and get it*/
                if(resultCarry = resultArr[currentIndex + loopingIndex] / 10)
                {
                    /* after getting the carry modify the current result to one digit */
                    resultArr[currentIndex + loopingIndex]%=10;
                }
            }
            /* check if there's carry on either the product or the result*/
            if (productCarry || resultCarry)
            {
                resultArr[currentIndex + loopingIndex] += productCarry + resultCarry;
                /* this check to get the limit of the result so if there's digit added over the end of the result make it into consideration*/
                if (currentIndex == firstSize-1) 
                {
                    loopingIndex++;
                }
            }
            productCarry = 0;
            resultCarry = 0;
        }
        counter = loopingIndex + currentIndex - 2;
        /* check if all the digits are zero */
        for(temp=0 ; temp<=counter ; temp++)
        {
            if(resultArr[temp])
                break;
        }
        /* if all of them are zeros then print zero */
        if(temp==counter+1)
        {
            putchar('0');
        }
        else
        {
            for (; counter >= 0; counter--)
            {
                printf("%d", resultArr[counter]);
            }
        }
        /* just put newline character */
        puts("");
    }

}
/*1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890*/