/*
 *  File 	   : Stack.h
 *  Created on : Jun 9, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef __STACK__
#define __STACK__

/************************************************************************
 *                       File Inclusion                                 *
 ************************************************************************/

/* I used this defines as there is no stdtype file here */
#ifndef __TYPES__
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
#endif

#include "stack_Cfg.h"

/************************************************************************
 *                       Macros And Types                               *
 ************************************************************************/


/************************************
 *          Status  macros          *
 ***********************************/
typedef uint8 stackStatus_t;
#define STACK_UNDERFLOW       (stackStatus_t)0
#define STACK_OVERFLOW        (stackStatus_t)1
#define STACK_NULL_POINTER    (stackStatus_t)2
#define STACK_E_OK            (stackStatus_t)3
#define STACK_E_NOT_OK        (stackStatus_t)4



/************************************
 *          Pointer to Function     *
 ***********************************/

/* used in traverse queue to apply operation on all elements of the stack */
typedef void (*functionPtr)(dataEntry_t* data);

#define STACK_EMPTY           (stackSize_t)0

/************************************
 *          Stack structure         *
 ***********************************/

typedef struct stack{
	dataEntry_t stackBuffer[STACK_MAX_SIZE];
	stackSize_t stackTop;
}Stack_s;


/************************************************************************/

/************************************************************************
 *                        functions' prototype                          *
 ************************************************************************/

/**************************************************************************************************************************************
 *  Function : createStack                                                                                                            *
 *  Param    : IN     : Name / Stack                                                                                                  *
 *                      Type / Stack_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : stackStatus_t                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function initialize the Stack with the initial values                                                             *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

stackStatus_t createStack(Stack_s* Stack);

/**************************************************************************************************************************************
 *  Function : pop                                                                                                                    *
 *  Param    : IN     : Name / stack                                                                                                  *
 *                      Type / Stack_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *           : Output  : Name / data                                                                                                  *
 *                      Type / dataEntry_t*                                                                                           *
 *                      Desc / takes the address of the variable which the data will be assigned to it                                *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Return   : stackStatus_t                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function remove element for the top of the stack                                                                  *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

stackStatus_t pop(Stack_s* stack  , dataEntry_t* data);

/**************************************************************************************************************************************
 *  Function : push                                                                                                                   *
 *  Param    : IN     : Name / stack                                                                                                  *
 *                      Type / Stack_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / data                                                                                                   *
 *                      Type / dataEntry_t*                                                                                           *
 *                      Desc / takes the data wanted to be inserted to the top of the stack                                           *
 *                                                                                                                                    *
 *  Return   : stackStatus_t                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function dequeue element from the front of the queue                                                              *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

stackStatus_t push(Stack_s* stack  , dataEntry_t* data);

/**************************************************************************************************************************************
 *  Function : clearStack                                                                                                             *
 *  Param    : IN     : Name / stack                                                                                                  *
 *                      Type / Stack_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : stackStatus_t                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return the stack to the initial state                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

stackStatus_t clearStack(Stack_s* stack);

/**************************************************************************************************************************************
 *  Function : StackTop                                                                                                               *
 *  Param    : IN     : Name / stack                                                                                                  *
 *                      Type / Stack_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *           : IN     : Name / data                                                                                                   *
 *                      Type / dataEntry_t*                                                                                           *
 *                      Desc / takes the address of the variable to return the top to it                                              *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : stackStatus_t                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function returns the value of the top element of the stack                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

stackStatus_t StackTop(Stack_s* stack, dataEntry_t* data);

/**************************************************************************************************************************************
 *  Function : traverseStack                                                                                                          *
 *  Param    : IN     : Name / stack                                                                                                  *
 *                      Type / Stack_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *           : IN     : Name / wantedFunction                                                                                         *
 *                      Type / functionPtr                                                                                            *
 *                      Desc / takes the function wanted to be excuted on each element                                                *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : stackStatus_t                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function go through each element and excute function passed to it from the caller function                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

stackStatus_t traverseStack(Stack_s* stack , functionPtr wantedFunction);

/**************************************************************************************************************************************
 *  Function : stackSize                                                                                                              *
 *  Param    : IN     : Name / stack                                                                                                  *
 *                      Type / Stack_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : stackStatus_t                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return the current size of the stack                                                                     *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

stackStatus_t stackSize(Stack_s* stack , stackSize_t* size);

/*************************************************************************************************************************************/

#endif



