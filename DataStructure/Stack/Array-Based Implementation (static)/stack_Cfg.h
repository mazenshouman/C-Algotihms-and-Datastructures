/*
 *  File 	   : Stack_Cfg.h
 *  Created on : Jun 9, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef __STACK_CFG__
#define __STACK_CFG__

/************************************************************************
 *                       Macros And Types                               *
 ************************************************************************/

/********************************************************
 *         Implementation Selection Macros              *
 ********************************************************/

/* this macro used for static mutitype implementation*/
#define STACK_STATIC_DIFFERENT_DATATYPES


#if 0
/* this macros used for static single type implementation*/
#define STACK_STAITC_SINGLE_DATATYPES
#endif

/***************************************************
 *              DATATYPE  CONFIGURATION            *
 **************************************************/

#ifdef STACK_STATIC_DIFFERENT_DATATYPES
/*create EntryType of type struct which contatins two parts the info part and union part. info part, which determines
  which member of the union the current element is of it's type and union contains all possible types that the current
  program will use and this part is configurable by the user
  - user must fill the info part of the structure and switch on that part when he poping the element to determine
    which member of the struct this element represents
*/


/*this configurable part which contains all the member that will be exists in the program
  you can change this struct to any data type you want to be in stack's elements
  (but take care this implementation will cause waste of memeory so don't use it unless
  you have to use stack with different data type in the same program)
*/
typedef union
{
    uint16  value;
    uint8   digit;
    uint8   sign;
}Stack_EntryTypes;


/*this struct will be used as the stack element datatype*/
typedef struct
{
    uint8             Stack_EntryInfo;
    Stack_EntryTypes  StackS_EntryData;
}Stack_EntryType_s;

#endif


/*------------------------------------------------------------------------------------------------------*/

/************************************
 *     Static Single data type       *
 ***********************************/
/* you can change the datatype as you want depend on your application*/
#ifdef STACK_STAITC_SINGLE_DATATYPES
typedef uint8 Stack_EntryTypes;
#endif

/*------------------------------------------------------------------------------------------------------*/


/**************************************************************************
 *                        CONFIGURATION PARAMETERS                        *
 *************************************************************************/

/*select the data type of the elements  */
typedef Stack_EntryType_s dataEntry_t;

/*select the max size of the stack in term of the data type */
typedef uint8 stackSize_t;

/*select the max size of the stack buffer which can't exceed the size of the stack size data type*/
#define STACK_MAX_SIZE  (stackSize_t)10

/*************************************************************************/

#endif
