/*
 *  File 	   : List.h
 *  Created on : May 26, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef __LIST__
#define __LIST__
/************************************************************************
 *                         File Inclusion                               *
 ************************************************************************/
#ifndef __TYPES__
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
#endif

#include "List_Cfg.h"

/************************************************************************
 *                       Macros And Types                               *
 ************************************************************************/


typedef uint8 List_StatusType;
#define LIST_EMPTY                 (List_StatusType)0
#define LIST_E_NOT_OK              (List_StatusType)1                    
#define LIST_E_OK                  (List_StatusType)2
#define LIST_NULL_POINTER          (List_StatusType)3
#define LIST_UNDERFLOW             (List_StatusType)4
#define LIST_OVERFLOW              (List_StatusType)5
#define LIST_NOT_EMPTY             (List_StatusType)6
#define LIST_FULL                  (List_StatusType)7
#define LIST_NOT_FULL              (List_StatusType)8
#define LIST_POSITION_OUT_OF_RANGE (List_StatusType)9



typedef void(*ListPtrToFunction)(List_DataType* element);



struct Node{
    List_DataType  data;
    struct Node*   nextNode;
};
typedef struct Node ListNode;

typedef struct List{
    ListNode*      List_Head;
    ListNode*      List_CurrentPtr;
    List_SizeType  List_CurrentPos;
    List_SizeType  List_CurrentSize;
}List_s; 



/************************************************************************/

/************************************************************************
 *                        functions' prototype                          *
 ************************************************************************/

/**************************************************************************************************************************************
 *  Function : List_Create                                                                                                            *
 *  Param    : IN     : Name / list                                                                                                   *
 *                      Type / List_s *                                                                                               *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : List_StatusType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function initialize the list with the initial values                                                              *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

 List_StatusType	List_Create	(List_s * list);

/**************************************************************************************************************************************
 *  Function : List_InsetElement                                                                                                      *
 *  Param    : IN     : Name / list                                                                                                   *
 *                      Type / List_s*                                                                                                *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *           : IN     : Name / element                                                                                                *
 *                      Type / List_DataType*                                                                                         *
 *                      Desc / takes the data wanted to be inserted                                                                   *
 *           : IN     : Name / position                                                                                               *
 *                      Type / List_SizeType                                                                                          *
 *                      Desc / takes the position of the data                                                                         *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : List_StatusType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function add the given element to any position in the list                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

List_StatusType 	List_InsetElement	(List_s * list , List_DataType* element , List_SizeType position);

/**************************************************************************************************************************************
 *  Function : List_DeleteElement                                                                                                      *
 *  Param    : IN     : Name / list                                                                                                   *
 *                      Type / List_s*                                                                                                *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *           : IN     : Name / element                                                                                                *
 *                      Type / List_DataType*                                                                                         *
 *                      Desc / takes address of the variable wanted to return the element to it                                       *
 *           : IN     : Name / position                                                                                               *
 *                      Type / List_SizeType                                                                                          *
 *                      Desc / takes the position of the element                                                                      *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : List_StatusType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function delete element from the list and return it to the caller function                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

List_StatusType 	List_DeleteElement	(List_s * list , List_DataType* element , List_SizeType position);

/**************************************************************************************************************************************
 *  Function : List_RetrieveElement                                                                                                   *
 *  Param    : IN     : Name / list                                                                                                   *
 *                      Type / List_s*                                                                                                *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *           : IN     : Name / element                                                                                                *
 *                      Type / List_DataType*                                                                                         *
 *                      Desc / takes address of the variable wanted to return the element to it                                       *
 *           : IN     : Name / position                                                                                               *
 *                      Type / List_SizeType                                                                                          *
 *                      Desc / takes the position of the element                                                                      *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : List_StatusType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return element from the list and doesn't remove it from the list                                         *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

List_StatusType 	List_RetrieveElement	(List_s * list , List_DataType* element , List_SizeType position);

/**************************************************************************************************************************************
 *  Function : List_ReplaceElement                                                                                                    *
 *  Param    : IN     : Name / list                                                                                                   *
 *                      Type / List_s*                                                                                                *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *           : IN     : Name / element                                                                                                *
 *                      Type / List_DataType*                                                                                         *
 *                      Desc / takes address of the variable wanted to return the element to it                                       *
 *           : IN     : Name / position                                                                                               *
 *                      Type / List_SizeType                                                                                          *
 *                      Desc / takes the position of the element                                                                      *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : List_StatusType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function replace element from the list with another element given from the caller function and return the         *
 *             replaced element to it                                                                                                 *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

List_StatusType 	List_ReplaceElement	(List_s * list , List_DataType* element , List_SizeType position);

/**************************************************************************************************************************************
 *  Function : List_IsEmpty                                                                                                           *
 *  Param    : IN     : Name / List                                                                                                   *
 *                      Type / List_s*                                                                                                *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : List_StatusType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return wether the list is empty or not                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

List_StatusType List_IsEmpty(List_s* list);

/**************************************************************************************************************************************
 *  Function : List_IsFull                                                                                                           *
 *  Param    : IN     : Name / List                                                                                                   *
 *                      Type / List_s*                                                                                                *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : List_StatusType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return wether the list is full or not                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

List_StatusType List_IsFull(List_s* list);

/**************************************************************************************************************************************
 *  Function : List_GetSize                                                                                                           *
 *  Param    : IN     : Name / list                                                                                                   *
 *                      Type / List_s*                                                                                                *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : List_SizeType                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return the current size of the list                                                                      *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

List_SizeType List_GetSize(List_s* list);

/**************************************************************************************************************************************
 *  Function : List_Destroy                                                                                                           *
 *  Param    : IN     : Name / list                                                                                                   *
 *                      Type / List_s*                                                                                                *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : List_StatusType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function reinital the list                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

List_StatusType List_Destroy(List_s* list);

/**************************************************************************************************************************************
 *  Function : List_Traverse                                                                                                          *
 *  Param    : IN     : Name / list                                                                                                   *
 *                      Type / List_s*                                                                                                *
 *                      Desc / takes address of the created structure from the caller function                                        *
 *           : IN     : Name / ptr                                                                                                    *
 *                      Type / ListPtrToFunction                                                                                      *
 *                      Desc / takes the function wanted to be excuted on each element                                                *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : List_StatusType                                                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function go through each element and excute function passed to it from the caller function                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

List_StatusType List_Traverse(List_s* list , ListPtrToFunction ptr);

 /**************************************************************************************************************************************/


#endif