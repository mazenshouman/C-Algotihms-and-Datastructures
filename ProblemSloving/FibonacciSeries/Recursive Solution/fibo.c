#include <stdio.h>
#include "fibo.h"


returnType_t getFibonacci(dataType_t number){
  returnType_t returnValue;
  if(number==0){
    returnValue=0;
  }else if(number==1){
    returnValue=1;
  }else{
    returnValue = getFibonacci(number-1)+getFibonacci(number-2);
  }
  return returnValue;
}


