/*
 *  File 	   : List.c
 *  Created on : May 26, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#include <stdio.h>
#include <malloc.h>
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

 List_StatusType List_Create(List_s * list)
 {
    List_StatusType returnStatus=LIST_E_OK;
    if(list==NULL)
    {
        returnStatus=LIST_NULL_POINTER;
    }
    else
    {
        list -> List_Head=NULL;
        list -> List_CurrentPtr=NULL;
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

List_StatusType List_InsetElement(List_s * list , List_DataType* element , List_SizeType position)
{
    List_StatusType returnStatus=LIST_E_OK;
    ListNode* temp=NULL;
    if(list==NULL || element==NULL)
    {
        returnStatus=LIST_NULL_POINTER;
    }
    else
    {
        /*precondition check .. that the position given is in range of the list*/
        if((position<(List_SizeType)LIST_EMPTY)||(position>list->List_CurrentSize))
        {
            returnStatus=LIST_POSITION_OUT_OF_RANGE;
        }
        else
        {
            /* create new node */
            temp=(ListNode*)malloc(sizeof(ListNode));
            /* check for heap overflow */
            if(temp==NULL)
            {   
                returnStatus=LIST_OVERFLOW;
            }
            else
            {
                temp->data=*element;
                temp->nextNode=NULL;
                /*handle odd case that the element wanted to be inserted on the first position of the list  */
                if(position==0)
                {
                    /* this line handles both cases if the list has items or it was empty list */
                    temp->nextNode = list->List_Head;
                    list->List_Head = temp;
                    list->List_CurrentPtr=temp;
                    list->List_CurrentPos=position;
                }
                else
                {
                    /* check if the last inserted or deleted element was in position greater or equal to the wanted position so we need
                       to loop from the head
                    */
                    if(list->List_CurrentPos >= position)
                    {
                        list->List_CurrentPtr=list->List_Head;
                        list->List_CurrentPos=0;
                    }
                    /* loop until you reach the node before the wanted position */
                    for(;list->List_CurrentPos<(position-1) ; ++list->List_CurrentPos)
                    {
                        list->List_CurrentPtr=list->List_CurrentPtr->nextNode;
                    }
                    /* make the temp node's next points to the node which will follow it */
                    temp->nextNode=list->List_CurrentPtr->nextNode;
                    /* then make temp node be the next of the previous node */
                    list->List_CurrentPtr->nextNode=temp;
                }
                list -> List_CurrentSize++;
            }
        }
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

List_StatusType List_DeleteElement(List_s * list , List_DataType* element , List_SizeType position)
{
    List_StatusType returnStatus=LIST_E_OK;
    ListNode* temp=NULL;
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
        else
        {
            /*handle special case that the element wanted to be deleted from the first position of the list  */
            if(position==0)
            {
                list->List_CurrentPtr=list->List_Head;
                *element=list->List_CurrentPtr->data;
                list->List_Head=list->List_Head->nextNode;
                free(list->List_CurrentPtr);
                list->List_CurrentPtr=list->List_Head;
                list->List_CurrentPos=position;
            }
            else
            {
                /* check if the last inserted or deleted element was in position greater or equal to the wanted position so we need
                    to loop from the head
                */
                if(list->List_CurrentPos >= position)
                {
                    list->List_CurrentPtr=list->List_Head;
                    list->List_CurrentPos=0;
                }
                /* loop until you reach the node before the wanted position */
                for(;list->List_CurrentPos<(position-1) ; ++list->List_CurrentPos)
                {
                    list->List_CurrentPtr=list->List_CurrentPtr->nextNode;
                }
                /* make the temp ptr points to the wanted node to be deleted */
                temp=list->List_CurrentPtr->nextNode;
                /* return data to the caller function */
                *element=temp->data;
                /* make the node before wanted node to be deleted points to the next of this node */
                list->List_CurrentPtr->nextNode=temp->nextNode;
                /* free the node */
                free(temp);
            }
            --list -> List_CurrentSize;
        }
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

List_StatusType List_RetrieveElement(List_s * list , List_DataType* element , List_SizeType position)
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
        else
        {
            /* check if the last inserted or deleted element was in position greater than the wanted position so we need
                to loop from the head
            */
            if(list->List_CurrentPos > position)
            {
                list->List_CurrentPtr=list->List_Head;
                list->List_CurrentPos=0;
            }
            /* loop until you reach the node before the wanted position */
            for(;list->List_CurrentPos<position ; ++list->List_CurrentPos)
            {
                list->List_CurrentPtr=list->List_CurrentPtr->nextNode;
            }
            /* return data to the caller function */
            *element=list->List_CurrentPtr->data;
        }
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

List_StatusType List_ReplaceElement(List_s * list , List_DataType* element , List_SizeType position)
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
        else
        {
            /* check if the last inserted or deleted element was in position greater than the wanted position so we need
                to loop from the head
            */
            if(list->List_CurrentPos > position)
            {
                list->List_CurrentPtr=list->List_Head;
                list->List_CurrentPos=0;
            }
            /* loop until you reach the node before the wanted position */
            for(;list->List_CurrentPos<position ; ++list->List_CurrentPos)
            {
                list->List_CurrentPtr=list->List_CurrentPtr->nextNode;
            }
            /* return data to the caller function */
            list->List_CurrentPtr->data=*element;
        }
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
    List_StatusType returnStatus;
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
    List_StatusType returnStatus;
    if(list==NULL)
    {
        returnStatus=LIST_NULL_POINTER;
    }
    else
    {
        returnStatus=LIST_NOT_FULL;
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
        while(list->List_Head!=NULL)
        {
            list->List_CurrentPtr=list->List_Head->nextNode;
            free(list->List_Head);
            list->List_Head=list->List_CurrentPtr;
        }
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
    ListNode* temp;
    /*check for the null pointer  */

    if((list==NULL) || (ptr==NULL))
    {
        returnValue= LIST_NULL_POINTER;
    }
    else
    {
        for(temp=list->List_Head ; temp!=NULL ; temp=temp->nextNode){
            ptr(&(temp -> data));
        }
    }
}

 /**************************************************************************************************************************************/
 void Print(List_DataType* data)
 {
     printf("%d\n" , *data);
 }
 int main()
 {
     List_s newList;
     List_DataType x=10 , y=20  , z=30;
     List_Create(&newList);
     
     printf("%d\n" , List_InsetElement(&newList , &x , 0));
     List_InsetElement(&newList , &y , 1);     
     List_InsetElement(&newList , &z , 2);
     List_DeleteElement(&newList , &y , 1);
     List_InsetElement(&newList , &y , 1);
     
     
     List_Traverse(&newList , Print);
     return 0;
 }