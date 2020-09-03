/*
 *  File 	   : Queue.c
 *  Created on : April 29, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
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
        /*this part can be removed it's not mandatory */
        #ifdef QUEUE_DYNAMIC_ARRAY_DIFFERENT_DATATYPES
        Queue_SizeType local_loopCounter;
        /* intializing the array*/
        for(local_loopCounter=0 ; local_loopCounter<QUEUE_MAX_SIZE ; local_loopCounter++)
        {
            Queue -> Queue_Buffer[local_loopCounter].Queue_EntryData = NULL;
            Queue -> Queue_Buffer[local_loopCounter]. Queue_EntryInfo . EntrySize=0;
        }
        #endif

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
    uint8 local_SizeCounter=0;

    #ifdef QUEUE_DYNAMIC_ARRAY_DIFFERENT_DATATYPES
    void * local_newStorage;
    #endif

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


            #ifdef QUEUE_STATIC_DIFFERENT_DATATYPES           
            /* add the element to the rear*/
            Queue -> Queue_Buffer[Queue->Queue_Rear]=*data;
            #endif


            #ifdef QUEUE_DYNAMIC_ARRAY_DIFFERENT_DATATYPES
            local_newStorage = (void*)malloc(data -> Queue_EntryInfo.EntrySize);
            if(local_newStorage==NULL)
            {
                returnValue = QUEUE_OVERFLOW;
            }
            else{
                memcpy(local_newStorage , data->Queue_EntryData , (size_t)data->Queue_EntryInfo.EntrySize);
                Queue -> Queue_Buffer[Queue->Queue_Rear].Queue_EntryData=local_newStorage;
                Queue -> Queue_Buffer[Queue->Queue_Rear].Queue_EntryInfo=data ->Queue_EntryInfo;
            }
            #endif

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
        }
        else
        {
            /* if you use this implementation the user must free the memory after using it*/
            #ifdef QUEUE_DYNAMIC_ARRAY_DIFFERENT_DATATYPES
            *data = Queue -> Queue_Buffer[Queue->Queue_Front];
            #endif 


            #ifdef QUEUE_STATIC_DIFFERENT_DATATYPES 
            /* return the element at the rear*/
            *data=Queue -> Queue_Buffer[Queue->Queue_Front];
            #endif

        
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
    if(Queue=NULL)
    {
        returnValue=QUEUE_NULL_POINTER;
    }
    else
    {
        #ifdef QUEUE_DYNAMIC_ARRAY_DIFFERENT_DATATYPES
        Queue_SizeType local_loopCounter;
        /* intializing the array*/
        for(local_loopCounter=0 ; local_loopCounter<QUEUE_MAX_SIZE ; local_loopCounter++)
        {
            if (Queue -> Queue_Buffer[local_loopCounter].Queue_EntryData != NULL)
            {
                free(Queue -> Queue_Buffer[local_loopCounter].Queue_EntryData);
                Queue -> Queue_Buffer[local_loopCounter].Queue_EntryData=NULL;
            }
            Queue -> Queue_Buffer[local_loopCounter]. Queue_EntryInfo . EntrySize=0;
        }
        #endif


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
}
 /**************************************************************************************************************************************/
int main()
{

    Queue_s myQueue;  
    Queue_DataType mazen , mazen1 , mazen2 , mazen3;
    int mazen_Id=10 , mazen1_Id=20 ,mazen2_Id=20;
    mazen.Queue_EntryData=&mazen_Id;
    mazen.Queue_EntryInfo.EntrySize=sizeof(mazen_Id);
    mazen.Queue_EntryInfo.EntryId=0;
    mazen1.Queue_EntryData=&mazen1_Id;
    mazen1.Queue_EntryInfo.EntrySize=sizeof(mazen1_Id);
    mazen1.Queue_EntryInfo.EntryId=1;
    mazen2.Queue_EntryData=&mazen2_Id;
    mazen2.Queue_EntryInfo.EntrySize=sizeof(mazen2_Id);
    mazen2.Queue_EntryInfo.EntryId=2;
    

    
    Queue_Create(& myQueue);
    Queue_Enqueue(& myQueue , &mazen2);
    Queue_Enqueue(& myQueue , &mazen1);
    Queue_Enqueue(& myQueue , &mazen);

    if(Queue_GetSize)
    {
        Queue_Dequeue(&myQueue , &mazen3);
        free(mazen3.Queue_EntryData);
        Queue_Dequeue(&myQueue , &mazen3);
        free(mazen3.Queue_EntryData);        
        Queue_Dequeue(&myQueue , &mazen3);

        
        
    }

    printf("%d %d" , *(int*)mazen3.Queue_EntryData , mazen3.Queue_EntryInfo.EntrySize);
    
    free(mazen3.Queue_EntryData);
}
