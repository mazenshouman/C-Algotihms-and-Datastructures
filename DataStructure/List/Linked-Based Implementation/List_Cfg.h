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
#define LIST_DYNAMIC_DIFFERENT_DATATYPES

#endif

/* this macros used for static single datatype implementation*/
#define LIST_DYNAMIC_SINGLE_DATATYPE



/*------------------------------------------------------------------------------------------------------*/

/**************************************************************************
 *                        DATATYPE  CONFIGURATION                         *
 *************************************************************************/



/************************************
 *         Dynamic Multitype         *
 ***********************************/

/* will be implemented later */
#ifdef LIST_DYNAMIC_DIFFERENT_DATATYPES


/* will be implemented with void pointer for each element along with size datatype to identify the size need to be allocated for each element 
   in the node structre when inseting the element (revise queue array-based dynamic mutitype) */


#endif


/*------------------------------------------------------------------------------------------------------*/

/************************************
 *      static single datatype     *
 ***********************************/
#ifdef LIST_DYNAMIC_SINGLE_DATATYPE

typedef uint8 List_EntryType;

#endif
/*------------------------------------------------------------------------------------------------------*/


/**************************************************************************
 *                        CONFIGURATION PARAMETERS                        *
 *************************************************************************/

/*select the datatype of the element if the structure name changes */
typedef List_EntryType List_DataType;

/*select the max size of the List in terms of the type(must be signed  datatype as the initial value for the rear is negative)*/
typedef sint8 List_SizeType;


/*************************************************************************/


#endif