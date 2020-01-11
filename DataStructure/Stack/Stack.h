#ifndef
#define __Stack__

/*std_types*/
typedef unsigned char uint8;
typedef signed char sint8;

typedef uint8 status;
#define E_NOT_OK            (status)0
#define E_OK                (status)1
#define STACK_OVERFLOW      (status)2
#define STACK_UNDERFLOW     (status)3

typedef sint8 StackDataType_t;
typedef int stackSize_t;

typedef struct{
    StackDataType_t * bottom;
    StackDataType_t * stackPointer;
    StackDataType_t * top;
}stack_t;


status createStack(stack_t ** stack , stackSize_t size);

status pushToStack(stack_t * stack , StackDataType_t data);

status popFromStack(stack_t * stack , StackDataType_t *data);


#enfif