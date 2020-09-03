/*
 *  File 	   : Queue.c
 *  Created on : April 29, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#include <stdio.h>
#include "Queue.h"

/**************************************************************************************************************************************
 *  Function : Queue_Create                                                                                                           *
 *  Param    : IN     : Name / Queue                                                                                                  *
 *                      Type / Queue_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : Queue_ErrorType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function initialize the Queue with the initial values                                                             *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Queue_ErrorType Queue_Create(Queue_s* Queue)
{   
    Queue_ErrorType returnValue=QUEUE_E_OK;
    if(Queue==NULL)
    {
        returnValue=QUEUE_NULL_POINTER;
    }
    else
    {
        /*the front must be initialized with value higher than rear by one (Empty Condition)
        *as I'm implementing circular queue
        **/
       /*so if we want to omit the size from the stack to save space the condition for empty queue will be equal to the codition
        *for the full queue so in this situation we have to leave one empty place at the queue to distinguish between empty and full queue
        */
        Queue -> Queue_Rear = -1;
        Queue -> Queue_Front = 0;
        Queue -> Queue_CurrentSize = (Queue_SizeType)QUEUE_EMPTY;
    }
    return returnValue;
}

/**************************************************************************************************************************************
 *  Function : Queue_Enqueue                                                                                                          *
 *  Param    : IN     : Name / Queue                                                                                                  *
 *                      Type / Queue_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *           : IN     : Name / data                                                                                                   *
 *                      Type / Queue_DataType*                                                                                        *
 *                      Desc / takes the data wanted to be enqueued                                                                   *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : Queue_ErrorType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function enqueue element in the rear of the queue                                                                 *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Queue_ErrorType Queue_Enqueue(Queue_s* Queue , Queue_DataType* data)
{
    Queue_ErrorType returnValue=QUEUE_E_OK;

    /*check for the null pointer  */

    if(Queue==NULL)
    {
        returnValue= QUEUE_NULL_POINTER;
    }
    else
    {
        /* check if the stack is full or not */
        if(Queue_IsFull(Queue)==QUEUE_FULL)
        {
            returnValue = QUEUE_OVERFLOW;
        }else{
            /* increment rear by one but care for the overlapping */
            Queue -> Queue_Rear = (Queue -> Queue_Rear+1)%QUEUE_MAX_SIZE;
            /* add the element to the rear*/
            Queue -> Queue_Buffer[Queue->Queue_Rear]=*data;
            /* increase current size by one */
            ++Queue->Queue_CurrentSize;
        }
    }
    return returnValue;
}

/**************************************************************************************************************************************
 *  Function : Queue_Dequeue                                                                                                          *
 *  Param    : IN     : Name / Queue                                                                                                  *
 *                      Type / Queue_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / data                                                                                                   *
 *                      Type / Queue_DataType*                                                                                        *
 *                      Desc / takes the data wanted to be enqueued                                                                   *
 *                                                                                                                                    *
 *  Return   : Queue_ErrorType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function dequeue element from the front of the queue                                                              *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Queue_ErrorType Queue_Dequeue(Queue_s* Queue , Queue_DataType* data)
{
    Queue_ErrorType returnValue=QUEUE_E_OK;

    /*check for the null pointer  */

    if(Queue==NULL)
    {
        returnValue= QUEUE_NULL_POINTER;
    }
    else
    {
        /* check if the stack is empty or not */
        if(Queue_IsEmpty(Queue)==QUEUE_EMPTY)
        {
            returnValue = QUEUE_UNDERFLOW;
        }else{
            /* return the element at the rear*/
            *data=Queue -> Queue_Buffer[Queue->Queue_Front];
            /* increment front by one but care for the overlapping */
            Queue->Queue_Front = (Queue->Queue_Front+1)%QUEUE_MAX_SIZE;
            /* decrement current size by one */
            --Queue->Queue_CurrentSize;
        }
    }
    return returnValue;
}

/**************************************************************************************************************************************
 *  Function : Queue_IsEmpty                                                                                                          *
 *  Param    : IN     : Name / Queue                                                                                                  *
 *                      Type / Queue_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : Queue_StatusType                                                                                                       *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return wether the queue is empty or not                                                                  *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Queue_StatusType Queue_IsEmpty(Queue_s* Queue)
{
    Queue_StatusType returnValue;
    if(Queue -> Queue_CurrentSize == (Queue_SizeType)QUEUE_EMPTY)
    {
        returnValue=QUEUE_EMPTY;
    }
    else
    {
        returnValue=QUEUE_NOT_EMPTY;
    }
    return returnValue;
}

/**************************************************************************************************************************************
 *  Function : Queue_IsFull                                                                                                           *
 *  Param    : IN     : Name / Queue                                                                                                  *
 *                      Type / Queue_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : Queue_StatusType                                                                                                       *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return wether the queue is full or not                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Queue_StatusType Queue_IsFull(Queue_s* Queue)
{   
     Queue_StatusType returnValue;
    if(Queue -> Queue_CurrentSize == QUEUE_MAX_SIZE)
    {
        returnValue=QUEUE_FULL;
    }
    else
    {
        returnValue=QUEUE_NOT_FULL;
    }
    return returnValue;
}


/**************************************************************************************************************************************
 *  Function : Queue_GetSize                                                                                                           *
 *  Param    : IN     : Name / Queue                                                                                                  *
 *                      Type / Queue_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : Queue_StatusType                                                                                                       *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return the current size of the queue                                                                     *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Queue_SizeType Queue_GetSize(Queue_s* Queue)
{
    return Queue -> Queue_CurrentSize;
}

/**************************************************************************************************************************************
 *  Function : Queue_Clear                                                                                                            *
 *  Param    : IN     : Name / Queue                                                                                                  *
 *                      Type / Queue_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : Queue_StatusType                                                                                                       *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return the queue to the initial state                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Queue_ErrorType Queue_Clear(Queue_s* Queue)
{
    Queue_ErrorType returnValue=QUEUE_E_OK;
    if(Queue==NULL)
    {
        returnValue=QUEUE_NULL_POINTER;
    }
    else
    {
        Queue -> Queue_Rear = -1;
        Queue -> Queue_Front = 0;
        Queue -> Queue_CurrentSize = (Queue_SizeType)QUEUE_EMPTY;
    }
    return returnValue;
}

/**************************************************************************************************************************************
 *  Function : Queue_Traverse                                                                                                         *
 *  Param    : IN     : Name / Queue                                                                                                  *
 *                      Type / Queue_s*                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *           : IN     : Name / ptr                                                                                                    *
 *                      Type / ptrToFunction                                                                                          *
 *                      Desc / takes the function wanted to be excuted on each element                                                *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : Queue_ErrorType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function go through each element and excute function passed to it from the caller function                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Queue_ErrorType Queue_Traverse(Queue_s* Queue , ptrToFunction ptr)
{
    Queue_ErrorType returnValue=QUEUE_E_OK;
    Queue_SizeType loopCounter , currentPos=0;
    /*check for the null pointer  */

    if((Queue==NULL) || (ptr==NULL))
    {
        returnValue= QUEUE_NULL_POINTER;
    }
    else
    {
        for(currentPos=Queue -> Queue_Front , loopCounter=0 ; loopCounter<Queue->Queue_CurrentSize ; ++loopCounter){
            ptr(&(Queue -> Queue_Buffer[currentPos]));
            currentPos=(currentPos+1)%QUEUE_MAX_SIZE;
        }
    }
    return returnValue;
}
 /**************************************************************************************************************************************/
