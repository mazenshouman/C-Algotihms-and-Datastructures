/*
 *  File 	   : Queue.h
 *  Created on : May  9, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef __QUEUE__
#define __QUEUE__

/************************************************************************
 *                       File Inclusion                                 *
 ************************************************************************/


/* I used this defines as there is no stdtype file here */
#ifndef __TYPES__
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
#endif

#include "Queue_Cfg.h"

/************************************************************************
 *                       Macros And Types                               *
 ************************************************************************/

/************************************
 *           Error  macros          *
 ***********************************/

typedef uint8 Queue_ErrorType;
#define QUEUE_E_NOT_OK             (Queue_ErrorType)0                    
#define QUEUE_E_OK                 (Queue_ErrorType)1
#define QUEUE_NULL_POINTER         (Queue_ErrorType)2
#define QUEUE_UNDERFLOW            (Queue_ErrorType)3
#define QUEUE_OVERFLOW             (Queue_ErrorType)4


/************************************
 *          Status  macros          *
 ***********************************/

/* used for is _empty and is_full function */
typedef uint8 Queue_StatusType;
#define QUEUE_EMPTY                (Queue_StatusType)0
#define QUEUE_NOT_EMPTY            (Queue_StatusType)1
#define QUEUE_FULL                 (Queue_StatusType)2
#define QUEUE_NOT_FULL             (Queue_StatusType)3


/************************************
 *          Pointer to Function     *
 ***********************************/

/* used in traverse queue to apply operation on all elements of the queue */
typedef void(*ptrToFunction)(Queue_DataType* element);


/************************************
 *          Queue structure         *
 ***********************************/

typedef struct Queue{
    Queue_DataType  Queue_Buffer[QUEUE_MAX_SIZE];
    Queue_SizeType  Queue_Front;
    Queue_SizeType  Queue_Rear;
    Queue_SizeType  Queue_CurrentSize;
}Queue_s; 

/*------------------------------------------------------------------------------------------------------*/

/*******************************************
 *    Datatype Selection  macros           *
 *******************************************/

/************************************
 *         Static Multitype         *
 ***********************************/
#ifdef QUEUE_STATIC_DIFFERENT_DATATYPES

/*can add some macros to simplifing the way that the user determmines which member of the struct 
  will be used for this element (in case of enqueue or deqeue) (used for for static mutitype implementation)
*/

#define QUEUE_ELEMENT_DIGIT     1
#define QUEUE_ELEMENT_SIGN      2
#define QUEUE_ELEMENT_VALUE     3

#endif
/*------------------------------------------------------------------------------------------------------*/
/************************************
 *      Dynamic Array Multitype     *
 ***********************************/


#ifdef QUEUE_DYNAMIC_ARRAY_DIFFERENT_DATATYPES

/*can add some macros to simplifing the way that the user determmines which element will be dequeued
   and 
*/

/* this an example you need to move it to the main file for the file which you will create the queue */

#if 0

/*size is 1 byte and element 0 with this size*/
#define QUEUE_ELEMENT_DIGIT     1
/*size is 2 byte and element 0 with this size*/
#define QUEUE_ELEMENT_VALUE     2
/*size is 1 byte and element 1 with this size(0b00010001)*/
#define QUEUE_ELEMENT_SIGN      17

#endif

#endif

/*------------------------------------------------------------------------------------------------------*/

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
 *  Function : Queue_GetSize                                                                                                          *
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