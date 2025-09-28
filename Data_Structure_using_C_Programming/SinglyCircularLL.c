// Singly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if((NULL == *first) && (NULL == *last))
    {
        *first = newn;
        *last = newn;
        (*last)->next = *first;
    }
    else
    {
        newn->next = *first;
        *first = newn;
        (*last)->next = *first;
    }
}

void InsertLast(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL, temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if((NULL == *first) && (NULL == *last))
    {
        *first = newn;
        *last = newn;
        (*last)->next = *first;
    }
    else
    {   
        (*last)->next = newn;
        *last = newn;
        (*last)->next = *first;
    }
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    if((NULL == *first) || (NULL == *last))
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*last)->next);
        (*last)->next = *first;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if((NULL == *first) || (NULL == *last))
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next != *last)
        {
            temp = temp->next;
        }
        
        *last = temp;
        free(temp->next);
        (*last)->next = *first;
    }
}

void Display(PNODE first, PNODE last)
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }

    printf("->");
    do
    {
        printf("| %d |->",first->data);
        first = first->next;
    } while(first != last->next);
    printf("\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    do
    {
        iCount++;
        first = first->next;
    } while(first != last->next);

    return iCount;
}

void InsertAtPos(PPNODE first, PPNODE last, int iNo, int iPos)
{
    int iCount = 0, iCnt = 0;
    iCount = Count(*first,*last);
    PNODE newn = NULL , temp = NULL;

    if((iPos < 1) || (iPos > iCount+1))
    {
        printf("Invalid position\n");
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(first,last,iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(first,last,iNo);
    }
    else
    {
        temp = *first;

        for(iCnt = 1;iCnt < iPos-1;iCnt++)
        {
            temp = temp->next;
        }
        
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = iNo;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{
    int iCount = 0, iCnt = 0;
    iCount = Count(*first,*last);
    PNODE target = NULL , temp = NULL;

    if((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid position\n");
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;

        for(iCnt = 1;iCnt < iPos-1;iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}


int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number of elements in Singly Circular LinkedList is : %d\n",iRet);

    InsertAtPos(&head,&tail,105,-1);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number of elements in Singly Circular LinkedList is : %d\n",iRet);

    DeleteAtPos(&head,&tail,5);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number of elements in Singly Circular LinkedList is : %d\n",iRet);

    return 0;
}