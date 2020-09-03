/*
 *  File 	   : Queue_Cfg.h
 *  Created on : May 9, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef __QUEUE_CFG__
#define __QUEUE_CFG__

/************************************************************************
 *                       Macros And Types                               *
 ************************************************************************/



/*************************************************************************
 *                   Implementation Selection Macros                     *
 *************************************************************************/
#if 0
/* this macro used for static mutitype implementation*/
#define QUEUE_STATIC_DIFFERENT_DATATYPES

#endif

/* this macros used for dynamic array mutitype implementation*/
#define QUEUE_DYNAMIC_ARRAY_DIFFERENT_DATATYPES




/*------------------------------------------------------------------------------------------------------*/

/**************************************************************************
 *                        DATATYPE  CONFIGURATION                         *
 *************************************************************************/



/************************************
 *         Static Multitype         *
 ***********************************/

#ifdef QUEUE_STATIC_DIFFERENT_DATATYPES
/*create EntryType of type struct which contatins two parts the info part and union part. info part, which determines
  which member of the union the current element is of it's type and union contains all possible types that the current
  program will use and this part is configurable by the user 
  - user must fill the info part of the structure and switch on that part when he dequeue element to determine
  which member of the struct this element represents
*/


/*this configurable part which contains all the member that will be exists in the program
  you can change this struct to any data type you want to be in queue elements
  (but take care this implementation will cause waste of memeory so don't use it unless
  you have to use queues with different data type in the same program)
*/
typedef union
{
    uint8   digit;
    uint8   sign;
    uint16  value;
}Queue_EntryTypes;


/*this struct will be used as the queue element datatype*/
typedef struct
{
    uint8             Queue_EntryInfo;
    Queue_EntryTypes  Queue_EntryData;
}Queue_EntryType_s;

#endif


/*------------------------------------------------------------------------------------------------------*/

/************************************
 *      Dynamic Array Multitype     *
 ***********************************/


#ifdef QUEUE_DYNAMIC_ARRAY_DIFFERENT_DATATYPES

/* you can change this size depending on the max value that the system will take from the user */
typedef uint8 Queue_EntrySizeType;

/* configurable Id so that if there was matching size elements you can use it to differentiate between them  */
typedef uint8 Queue_EntryIdType;

/*this struct will be used as the guide for both the implementation function and the user 
  determine the size of the memeber and which member this element belongs to by the id in case
  of match size elements 
*/

/*
  you can change the members of this struct to bit-field as it wont affect the implementaion side
*/
typedef struct
{
    Queue_EntrySizeType EntrySize;
    Queue_EntryIdType   EntryId;
}Queue_EntryInfo_s;

typedef struct
{
    Queue_EntryInfo_s           Queue_EntryInfo;
    void*                       Queue_EntryData;
}Queue_EntryType_s;

#endif


/*------------------------------------------------------------------------------------------------------*/


/**************************************************************************
 *                        CONFIGURATION PARAMETERS                        *
 *************************************************************************/

/*select the datatype of the element if the structure name changes */
typedef Queue_EntryType_s Queue_DataType;

/*select the max size of the queue in terms of the type(must be signed  datatype as the initial value for the rear is negative)*/
typedef sint8 Queue_SizeType;

/*select the max size of the queue buffer*/
#define QUEUE_MAX_SIZE (Queue_SizeType)10



/*************************************************************************/


#endif