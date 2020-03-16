#include <stdio.h>
#include "fibo.h"


returnType_t getFibonacci(dataType_t number){
  returnType_t returnValue;
  returnType_t firstNumber=0;
  returnType_t secondNumber=1;
  if(number==0){
    returnValue=0;
  }else if(number==1){
    returnValue=1;
  }else{
    while(number>=2){
      returnValue=firstNumber + secondNumber;
      firstNumber=secondNumber;
      secondNumber=returnValue;
      --number;
    }
  }
  return returnValue;
}


