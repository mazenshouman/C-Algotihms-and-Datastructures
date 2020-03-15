#ifndef __STACK__
#define __STACK__

#include "stack_Cfg.h"
#ifndef __TYPES__
  typedef unsigned char uint8;
  typedef signed char sint8;
  typedef unsigned long int32;
#endif

typedef void (*functionPtr)(dataEntry_t* data);

typedef uint8 stackStatus_t;
#define STACK_UNDERFLOW (stackStatus_t)0;
#define STACK_OVERFLOW  (stackStatus_t)1;
#define NULL_POINTER    (stackStatus_t)2;
#define E_OK            (stackStatus_t)3;
#define E_NOT_OK        (stackStatus_t)4;

#define STACK_EMPTY  (stackSize_t)0;

typedef struct Node{
  dataEntry_t data;
  struct Node* nextNode;
}StackNode_s;

typedef struct stack{
  stackNode_s* stackTop;
  stackSize_t size;
}Stack_s;

stackStatus_t createStack(Stack_s* Stack);
stackStatus_t pop(Stack_s* stack  , dataEntry_t* data);
stackStatus_t push(Stack_s* stack  , dataEntry_t* data);
stackStatus_t clearStack(Stack_s* stack);
stackStatus_t traverseStack(Stack_t* stack , functionPtr wantedFunction);
stackStatus_t stackSize(Stack_t* stack , stackSize_t* size);

#endif



