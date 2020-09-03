/*
 *  File 	   : List.c
 *  Created on : May 26, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#include <stdio.h>
#include "List.h"


/************************************************************************/

/************************************************************************
 *                        functions' Implementation                     *
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

 List_StatusType	List_Create	(List_s * list)
 {
    List_StatusType returnStatus=LIST_E_OK;
    if(list==NULL)
    {
        returnStatus=LIST_NULL_POINTER;
    }
    else
    {
        list -> List_CurrentSize=(List_SizeType)LIST_EMPTY;
    }
    return returnStatus;
 }

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

List_StatusType 	List_InsetElement	(List_s * list , List_DataType* element , List_SizeType position)
{
    List_StatusType returnStatus=LIST_E_OK;
    List_SizeType local_loopCounter;
    if(list==NULL || element==NULL)
    {
        returnStatus=LIST_NULL_POINTER;
    }
    else
    {
        if((position<(List_SizeType)LIST_EMPTY)||(position>list->List_CurrentSize))
        {
            returnStatus=LIST_POSITION_OUT_OF_RANGE;
        }
        for(local_loopCounter=list->List_CurrentSize ; local_loopCounter>position ; local_loopCounter--)
        {
            list->List_Buffer[local_loopCounter]=list->List_Buffer[local_loopCounter-1];            
        }
        list -> List_Buffer[position]=*element;
        list -> List_CurrentSize++;
    }
    return returnStatus;
}

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

List_StatusType 	List_DeleteElement	(List_s * list , List_DataType* element , List_SizeType position)
{
    List_StatusType returnStatus=LIST_E_OK;
    List_SizeType local_loopCounter;
    if(list==NULL || element==NULL)
    {
        returnStatus=LIST_NULL_POINTER;
    }
    else
    {
        if((position<(List_SizeType)LIST_EMPTY)||(position>list->List_CurrentSize-1))
        {
            returnStatus=LIST_POSITION_OUT_OF_RANGE;
        }
        *element=list -> List_Buffer[position];
        for(local_loopCounter=position ; local_loopCounter<list->List_CurrentSize ; local_loopCounter++)
        {
            list->List_Buffer[local_loopCounter]=list->List_Buffer[local_loopCounter+1];            
        }
        list -> List_CurrentSize--;
    }
    return returnStatus;
}

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

List_StatusType 	List_RetrieveElement	(List_s * list , List_DataType* element , List_SizeType position)
{
    List_StatusType returnStatus=LIST_E_OK;
    if(list==NULL || element==NULL)
    {
        returnStatus=LIST_NULL_POINTER;
    }
    else
    {
        if((position<(List_SizeType)LIST_EMPTY)||(position>list->List_CurrentSize-1))
        {
            returnStatus=LIST_POSITION_OUT_OF_RANGE;
        }
        *element=list -> List_Buffer[position];
    }
    return returnStatus;
}

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
 *  Desc     : This function replace element from the list with another element given from the caller function                        *                                                                                                *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

List_StatusType 	List_ReplaceElement	(List_s * list , List_DataType* element , List_SizeType position)
{
    List_StatusType returnStatus=LIST_E_OK;
    List_DataType local_TempVar;
    if(list==NULL || element==NULL)
    {
        returnStatus=LIST_NULL_POINTER;
    }
    else
    {
        if((position<(List_SizeType)LIST_EMPTY)||(position>list->List_CurrentSize-1))
        {
            returnStatus=LIST_POSITION_OUT_OF_RANGE;
        }
        list -> List_Buffer[position]=*element;
    }
    return returnStatus;
}

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

List_StatusType List_IsEmpty(List_s* list)
{
    List_StatusType returnStatus=LIST_E_OK;
    if(list==NULL)
    {
        returnStatus=LIST_NULL_POINTER;
    }
    else
    {
        if(list -> List_CurrentSize==(List_SizeType)LIST_EMPTY)
        {
            returnStatus=(List_StatusType)LIST_EMPTY;
        }
        else
        {
            returnStatus=(List_StatusType)LIST_NOT_EMPTY;
        }
    }
    return returnStatus;
}

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

List_StatusType List_IsFull(List_s* list)
{
    List_StatusType returnStatus=LIST_E_OK;
    if(list==NULL)
    {
        returnStatus=LIST_NULL_POINTER;
    }
    else
    {
        if(list -> List_CurrentSize==LIST_MAX_SIZE)
        {
            returnStatus=(List_StatusType)LIST_FULL;
        }
        else
        {
            returnStatus=(List_StatusType)LIST_NOT_FULL;
        }
    }
    return returnStatus;
}

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

List_SizeType List_GetSize(List_s* list)
{
    return list -> List_CurrentSize;
}

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

List_StatusType List_Destroy(List_s* list)
{
    List_StatusType returnStatus=LIST_E_OK;
    if(list==NULL)
    {
        returnStatus=LIST_NULL_POINTER;
    }
    else
    {
        list -> List_CurrentSize=(List_SizeType)LIST_EMPTY;
    }
    return returnStatus;
}

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

List_StatusType List_Traverse(List_s* list , ListPtrToFunction ptr)
{
    List_StatusType returnValue=LIST_E_OK;
    List_SizeType loopCounter;
    /*check for the null pointer  */

    if((list==NULL) || (ptr==NULL))
    {
        returnValue= LIST_NULL_POINTER;
    }
    else
    {
        for(loopCounter=(List_SizeType)LIST_EMPTY ; loopCounter<list->List_CurrentSize ; ++loopCounter){
            ptr(&(list -> List_Buffer[loopCounter]));
        }
    }
}

 /**************************************************************************************************************************************/