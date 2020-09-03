/*
 *  File 	   : Queue.c
 *  Created on : May 4, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#include <stdio.h>
#include <malloc.h>
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
    if(Queue=NULL)
    {
        returnValue=QUEUE_NULL_POINTER;
    }
    else
    {
        /*just initialize the two pointers and the size with the initial values*/
        Queue -> Queue_Rear = NULL;
        Queue -> Queue_Front = NULL;
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
    QueueNode_s* newNode;
    /*check for the null pointer  */

    if(Queue==NULL)
    {
        returnValue= QUEUE_NULL_POINTER;
    }
    else
    {
        /* create new node */
        newNode = (QueueNode_s*)malloc(sizeof(QueueNode_s));
        /* check if the stack is full or not */
        if(newNode==NULL)
        {
            returnValue = QUEUE_OVERFLOW;
        }
        else
        {
            /*initialize the new node*/
            newNode->data=*data;
            newNode ->nextNode = NULL;

            /*append the new node at the end of the queue if the queue is not empty*/

            /*if the queue is empty*/
            if(Queue_IsEmpty(Queue)==QUEUE_EMPTY)
            {
                Queue -> Queue_Front = newNode;
            }
            else
            {
                Queue -> Queue_Rear -> nextNode = newNode;    
            }
            /* add the element to the rear*/
            Queue -> Queue_Rear = newNode;
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
    QueueNode_s* TempNodePtr;
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
        }
        else
        {
            /* return the element at the rear*/
            *data=Queue->Queue_Front->data;

            /* hold the current Node with TempPTr*/
            TempNodePtr = Queue ->Queue_Front;

            /*make the front points to the next node*/
            Queue -> Queue_Front = Queue -> Queue_Front -> nextNode;

            /*free the node pointed to it by the temp ptr*/
            free(TempNodePtr);

            /* check if the Queue is empty now (there was one element in the queue before dequeue) */
            if(Queue_IsEmpty(Queue)==QUEUE_EMPTY)
            {
                Queue -> Queue_Rear = NULL;
            }

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
    if(!Queue -> Queue_Front)
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
    /*useless function in case of linked implementation because the only ways the queue get full if the heap is full
    * which we check that when enqueueing new node
    * */
     Queue_StatusType returnValue;
    returnValue=QUEUE_NOT_FULL;
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
    if(Queue=NULL)
    {
        returnValue=QUEUE_NULL_POINTER;
    }
    else
    {
        while(Queue -> Queue_Front)
        {
            Queue -> Queue_Rear = Queue -> Queue_Front -> nextNode;
            free(Queue -> Queue_Front);
            Queue -> Queue_Front = Queue -> Queue_Rear;
        }    
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
    QueueNode_s* currentNode=NULL;
    /*check for the null pointer  */

    if((Queue==NULL) || (ptr==NULL))
    {
        returnValue= QUEUE_NULL_POINTER;
    }
    else
    {
        for(currentNode=Queue -> Queue_Front ; currentNode ; currentNode=currentNode -> nextNode){
            ptr(&(currentNode -> data));
        }
    }
}
 /**************************************************************************************************************************************/
