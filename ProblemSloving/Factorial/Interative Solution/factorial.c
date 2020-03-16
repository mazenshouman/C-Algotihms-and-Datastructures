#include <stdio.h>
#include "factorial.h"


returnType_t factorial (dataType_t number){
  returnType_t productValue=1;
  if(number==0){
    productValue=1;
  }else if(number==1){
    productValue=1;
  }else{
    productValue= number*factorial(number-1);
  }
  return productValue;
}


