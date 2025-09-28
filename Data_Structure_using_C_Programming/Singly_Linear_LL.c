// Singly linear Linked List

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

void InsertFirst(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn)
    {
        printf("Unable to allocate the memory");
        return;
    }

    newn->data = iNo;
    newn->next = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn)
    {
        printf("Unable to allocate the memory");
        return;
    }

    newn->data = iNo;
    newn->next = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(NULL == *first)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        *first = temp->next;
        free(temp);
    }
}

void DeletetLast(PPNODE first)
{
    PNODE temp = NULL;

    if(NULL == *first)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;
    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

void InsertAtPos(PPNODE first,int iNo,int iPos)
{
    int iCount = 0, iCnt = 0;
    PNODE newn = NULL, temp = NULL;

    iCount = Count(*first);

    if((iPos < 1) || (iPos > iCount+1))
    {
        printf("Invalid position");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first,iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(first,iNo);
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

void DeleteAtPos(PPNODE first,int iPos)
{
    int iCount = 0, iCnt = 0;
    PNODE temp = NULL, target = NULL;

    iCount = Count(*first);

    if((iPos < 1) && (iPos > iCount))
    {
        printf("Invalid position");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if(iPos == iCount)
    {
        DeletetLast(first);
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
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);
    InsertLast(&head,151);

    Display(head);

    iRet = Count(head);

    printf("Number of elements in LinkedList is : %d\n",iRet);

    InsertAtPos(&head,41,3);

    Display(head);

    iRet = Count(head);

    printf("Number of elements in LinkedList is : %d\n",iRet);

    DeleteAtPos(&head,1);

    Display(head);

    iRet = Count(head);

    printf("Number of elements in LinkedList is : %d\n",iRet);

    return 0;
}