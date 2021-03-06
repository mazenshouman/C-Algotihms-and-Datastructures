/*
 *  File 	   : Stack.h
 *  Created on : Jun 9, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

/************************************************************************
 *                       File Inclusion                                 *
 ************************************************************************/

#include "stack.h"

/************************************************************************/

/************************************************************************
 *                        functions' Implementation                     *
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

stackStatus_t createStack(Stack_s* stack)
{
	stackStatus_t returnStatus = STACK_E_OK;
	if (stack == NULL)
	{
		returnStatus = STACK_NULL_POINTER;
	}
	else
	{
		stack->stackTop = STACK_EMPTY;
	}
	return returnStatus;
}

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

stackStatus_t pop(Stack_s* stack, dataEntry_t* data)
{
	stackStatus_t returnStatus = STACK_E_OK;
	if (stack == NULL)
	{
		returnStatus = STACK_NULL_POINTER;
	}
	else
	{
		if (stack->stackTop == STACK_EMPTY)
		{
			returnStatus = STACK_UNDERFLOW;
		}
		else
		{
			--stack->stackTop;
			*data = stack->stackBuffer[stack->stackTop];
		}
	}
	return returnStatus;
}

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

stackStatus_t push(Stack_s* stack, dataEntry_t* data)
{
	stackStatus_t returnStatus = STACK_E_OK;
	if (stack == NULL)
	{
		returnStatus = STACK_NULL_POINTER;
	}
	else
	{
		if (stack->stackTop == STACK_MAX_SIZE)
		{
			returnStatus = STACK_OVERFLOW;
		}
		else
		{
			stack->stackBuffer[stack->stackTop] = *data;
			++stack->stackTop;
		}
	}
	return returnStatus;
}

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

stackStatus_t clearStack(Stack_s* stack)
{
	stackStatus_t returnStatus = STACK_E_OK;
	if (stack == NULL)
	{
		returnStatus = STACK_NULL_POINTER;
	} else
	{
		stack->stackTop = STACK_EMPTY;
	}
	return returnStatus;
}

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

stackStatus_t StackTop(Stack_s* stack, dataEntry_t* data)
{
	stackStatus_t returnStatus = STACK_E_OK;
	if (stack == NULL)
	{
		returnStatus = STACK_NULL_POINTER;
	}
	else
	{
		if (stack->stackTop == STACK_EMPTY)
		{
			returnStatus = STACK_UNDERFLOW;
		}
		else
		{
			*data = stack->stackBuffer[stack->stackTop - 1];
		}
	}
	return returnStatus;
}

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

stackStatus_t traverseStack(Stack_s* stack, functionPtr wantedFunction)
{
	stackStatus_t returnStatus = STACK_E_OK;
	stackSize_t loopCounter;
	if (stack == NULL)
	{
		returnStatus = STACK_NULL_POINTER;
	}
	else
	{
		for (loopCounter = stack->stackTop; loopCounter >= STACK_EMPTY ;--loopCounter)
		{
			wantedFunction(&(stack->stackBuffer[loopCounter]));
		}
	}
	return returnStatus;
}

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

stackStatus_t stackSize(Stack_s* stack, stackSize_t* size)
{
	stackStatus_t returnStatus = STACK_E_OK;
	*size = stack->stackTop;
	return returnStatus;
}

/*************************************************************************************************************************************/

