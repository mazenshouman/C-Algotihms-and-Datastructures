/*
  stack Linked-based implementation
*/

#include <stdio.h>
#include "stack.h"

stackStatus_t createStack(Stack_s* stack){
  stackStatus_t returnStatus=E_OK;
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    stack ->stackTop = NULL;
    stack ->size = STACK_EMPTY;
  }
  return returnStatus;
}
stackStatus_t pop(Stack_s* stack  , dataEntry_t* data){
  stackStatus_t returnStatus=E_OK;
  stackNode_s* pTempNode;
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    if(stack ->stackTop==NULL){
      returnStatus=STACK_UNDERFLOW;
    }
    else{
      pTempNode = stack -> stackTop;
      stack -> stackTop = stack -> stackTop -> nextNode;
      data* = pTempNode -> data;
      free(pTempNode);
      --stack -> size;
    }
  }
  return returnStatus;
}
stackStatus_t push(Stack_s* stack  , dataEntry_t* data){
  stackStatus_t returnStatus=E_OK;
  stackNode_s * pTempNode= (stackNode_s*)malloc(sizeof(stackNode_s));
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    if(pTempNode==NULL){
      returnStatus=STACK_OVERFLOW;
    }
    else{
      pTempNode -> data = *data; 
      pTempNode -> nextNode = stack -> stackTop;
      ++stack -> size;
    }
  }
  return returnStatus;
}
stackStatus_t clearStack(Stack_s* stack){
  stackStatus_t returnStatus=E_OK;
  stackNode_s * pTempNode = stack -> stackTop;
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    while(pTempNode!=NULL){
      pTempNode = stack -> stackTop;
      free(stack ->stackTop);
      stack ->stackTop = pTempNode;
    }
    stack -> size = STACK_EMPTY;
  }
  return returnStatus;
}

stackStatus_t StackTop(Stack_s* stack , dataEntry_t* data){
  stackStatus_t returnStatus=E_OK;
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    if(stack ->stackTop==NULL){
      returnStatus=STACK_UNDERFLOW;
    }
    else{
      *data=stack-> stackTop -> data;
    }
  }
  return returnStatus;
}

stackStatus_t traverseStack(Stack_t* stack , functionPtr wantedFunction){
  stackStatus_t returnStatus=E_OK;
  stackNode_s * pTempNode = stack -> stackTop;
  if(stack==NULL){
    returnStatus=NULL_POINTER;
  }
  else{
    while(pTempNode!=NULL){
      wantedFunction(pTempNode -> data);
      pTempNode=pTempNode -> nextNode;
    }
  }
  return returnStatus;
}

stackStatus_t stackSize(Stack_t* stack , stackSize_t* size){
  size = stack-> size;
}
