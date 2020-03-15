/*
  stack array-based implementation (fixed size array configured in cfg file)
*/

#include <stdio.h>
#include "stack.h"

stackStatus_t createStack(Stack_s* stack){
  stackStatus_t returnStatus=E_OK;
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    stack -> stackTop = STACK_EMPTY;
  }
  return returnStatus;
}
stackStatus_t pop(Stack_s* stack  , dataEntry_t* data){
  stackStatus_t returnStatus=E_OK;
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    if(stackTop==STACK_EMPTY){
      returnStatus=STACK_UNDERFLOW;
    }
    else{
      --stack->stackTop;
      *data=stack->stackBuffer[stack->stackTop];
    }
  }
  return returnStatus;
}
stackStatus_t push(Stack_s* stack  , dataEntry_t* data){
  stackStatus_t returnStatus=E_OK;
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    if(stackTop==STACK_MAX_SIZE){
      returnStatus=STACK_OVERFLOW;
    }
    else{
      stack->stackBuffer[stack->stackTop]=*data;
      ++stack->stackTop;
    }
  }
  return returnStatus;
}
stackStatus_t clearStack(Stack_s* stack){
  stackStatus_t returnStatus=E_OK;
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    stack -> stackTop = STACK_EMPTY;
  }
  return returnStatus;
}

stackStatus_t StackTop(Stack_s* stack , dataEntry_t* data){
  stackStatus_t returnStatus=E_OK;
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    if(stackTop==STACK_EMPTY){
      returnStatus=STACK_UNDERFLOW;
    }
    else{
      *data=stack->stackBuffer[stack->stackTop-1];
    }
  }
  return returnStatus;
}

stackStatus_t traverseStack(Stack_t* stack , functionPtr wantedFunction){
  stackStatus_t returnStatus=E_OK;
  stackSize_t loopCounter;
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    for(loopCounter=stack->stackTop; loopCounter>=STACK_EMPTY ; --loopCounter){
      wantedFunction(&(stack->stackBuffer[loopCounter]));
    }
  }
  return returnStatus;
}

stackStatus_t stackSize(Stack_t* stack , stackSize_t* size){
  size = stack-> stackTop;
}
