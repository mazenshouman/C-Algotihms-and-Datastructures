/*
 *  File 	   : Queue.h
 *  Created on : May 4, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef __QUEUE__
#define __QUEUE__

/************************************************************************
 *                       Macros And Types                               *
 ************************************************************************/
#ifndef __TYPES__
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
#endif

#include "Queue_Cfg.h"

/*
 * Error state macros
 * */

typedef uint8 Queue_ErrorType;
#define QUEUE_E_NOT_OK             (Queue_ErrorType)0                    
#define QUEUE_E_OK                 (Queue_ErrorType)1
#define QUEUE_NULL_POINTER         (Queue_ErrorType)2
#define QUEUE_UNDERFLOW            (Queue_ErrorType)3
#define QUEUE_OVERFLOW             (Queue_ErrorType)4

typedef uint8 Queue_StatusType;
#define QUEUE_EMPTY                (Queue_StatusType)0
#define QUEUE_NOT_EMPTY            (Queue_StatusType)1
#define QUEUE_FULL                 (Queue_StatusType)2
#define QUEUE_NOT_FULL             (Queue_StatusType)3



typedef void(*ptrToFunction)(Queue_DataType* element);

typedef struct QueueNode{
    Queue_DataType data;
    struct QueueNode* nextNode;
}QueueNode_s;

typedef struct Queue{
    QueueNode_s*  Queue_Front;
    QueueNode_s*  Queue_Rear;
    Queue_SizeType  Queue_CurrentSize;
}Queue_s; 


/************************************************************************/

/************************************************************************
 *                        functions' prototype                          *
 ************************************************************************/

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

Queue_ErrorType Queue_Create(Queue_s* Queue);

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

Queue_ErrorType Queue_Enqueue(Queue_s* Queue , Queue_DataType* data);

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

Queue_ErrorType Queue_Dequeue(Queue_s* Queue , Queue_DataType* data);

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

Queue_StatusType Queue_IsEmpty(Queue_s* Queue);

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

Queue_StatusType Queue_IsFull(Queue_s* Queue);

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

Queue_SizeType Queue_GetSize(Queue_s* Queue);

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

Queue_ErrorType Queue_Clear(Queue_s* Queue);

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

Queue_ErrorType Queue_Traverse(Queue_s* Queue , ptrToFunction ptr);

 /**************************************************************************************************************************************/









#endif