#include <stdio.h>
#include "Stack.h"



status createStack(stack_t ** stack , stackSize_t size){
    status currentStatus = E_OK;
    if(stack==NULL){
        currentStatus = E_NOT_OK;
    }else{
        /*create stack from the type stack_t to carry the pointers of the stack*/
        stack_t* newStack = (stack_t*)malloc(sizeof(stack_t));
        if(newStack==NULL){
            currentStatus = E_NOT_OK;
        }else{
            /*create stack with size given as parameter*/
            newStack -> bottom = (StackDataType_t*)malloc(sizeof(StackDataType_t)*size);
            newStack -> stackPointer = NULL;
            newStack -> top = newStack->bottom + (size-1);
            *stack = newStack;
        }
    }
    return currentStatus;
}

status pushToStack(stack_t * stack , StackDataType_t data){
    status currentStatus = E_OK;
    if(stack==NULL){
        currentStatus = E_NOT_OK;
    }else{
        /*check for the overflow*/
        if(stack ->stackPointer == stack ->top){
            currentStatus = STACK_OVERFLOW;
        }else{
            /*check if the stack is empty*/
            if(stack->stackPointer==NULL){
                stack->stackPointer=stack->bottom;
                /*if stack was not empty the inceament the stack pointer and add the element*/
            }else{
                (stack->stackPointer)++;
            }
            *(stack->stackPointer)=data;
        }
    }
    return currentStatus;
}


status popFromStack(stack_t * stack , StackDataType_t *data){
    status currentStatus = E_OK;
    if(stack==NULL){
        currentStatus = E_NOT_OK;
    }else{
        /*stack is empty*/
        if(stack -> stackPointer == NULL){
            currentStatus=STACK_UNDERFLOW;
        }else{
            *data=*(stack->stackPointer);
            if(stack->stackPointer==stack->bottom){
                stack->stackPointer=NULL;
            }
            else{
                stack->stackPointer--;
            }
        }
    }
    return currentStatus;
}
