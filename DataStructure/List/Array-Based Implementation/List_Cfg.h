/*
 *  File 	   : List_Cfg.h
 *  Created on : May 26, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef __LIST_CFG__
#define __LIST_CFG__

/************************************************************************
 *                       Macros And Types                               *
 ************************************************************************/



/*************************************************************************
 *                   Implementation Selection Macros                     *
 *************************************************************************/
#if 0
/* this macro used for static mutitype implementation(struct with union datatype)*/
#define LIST_STATIC_DIFFERENT_DATATYPES

#endif

/* this macros used for static single datatype implementation*/
#define LIST_STATIC_SINGLE_DATATYPE




/*------------------------------------------------------------------------------------------------------*/

/**************************************************************************
 *                        DATATYPE  CONFIGURATION                         *
 *************************************************************************/



/************************************
 *         Static Multitype         *
 ***********************************/

#ifdef LIST_STATIC_DIFFERENT_DATATYPES
/*create EntryType of type struct which contatins two parts the info part and union part. info part, which determines
  which member of the union the current element is of it's type and union contains all possible types that the current
  program will use and this part is configurable by the user 
  - user must fill the info part of the structure and switch on that part when he dequeue element to determine
  which member of the struct this element represents
*/


/*this configurable part which contains all the member that will be exists in the program
  you can change this struct to any data type you want to be in list elements
  (but take care this implementation will cause waste of memeory so don't use it unless
  you have to use lists with different data type in the same program)
*/
typedef union
{
    uint8   digit;
    uint8   sign;
    uint16  value;
}List_EntryTypes;


/*this struct will be used as the List element datatype*/
typedef struct
{
    uint8             List_EntryInfo;
    List_EntryTypes  List_EntryData;
}List_EntryType_s;

#endif


/*------------------------------------------------------------------------------------------------------*/

/************************************
 *      static single datatype     *
 ***********************************/
#ifdef LIST_STATIC_SINGLE_DATATYPE

typedef uint8 List_EntryType_s;

#endif
/*------------------------------------------------------------------------------------------------------*/


/**************************************************************************
 *                        CONFIGURATION PARAMETERS                        *
 *************************************************************************/

/*select the datatype of the element if the structure name changes */
typedef List_EntryType_s List_DataType;

/*select the max size of the List in terms of the type(must be signed  datatype as the initial value for the rear is negative)*/
typedef sint8 List_SizeType;

/*select the max size of the List buffer*/
#define LIST_MAX_SIZE (List_SizeType)10



/*************************************************************************/


#endif