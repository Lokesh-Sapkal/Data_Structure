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

void Enqueue(PPNODE first, int iNo)     // InsertLast
{
    PNODE newn = NULL, temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
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

int Dequeue(PPNODE first)     // DeleteFirst
{
    int iValue = 0;
    PNODE temp = NULL;

    if(NULL == *first)
    {
        printf("LinkedList is empty");
        return 0;
    }
    else if((*first)->next == NULL)
    {
        iValue = (*first)->data;
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        iValue = (*first)->data;
        *first = temp->next;
        free(temp);
    }
    return iValue;
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | - ",first->data);
        first = first->next;
    }
    printf("\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    Enqueue(&head,11);
    Enqueue(&head,21);
    Enqueue(&head,51);
    Enqueue(&head,101);

    Display(head);

    iRet = Count(head);
    printf("Total elements in Queue is : %d\n",iRet);
    
    iRet = Dequeue(&head);
    printf("removed element is : %d\n",iRet);
    
    iRet = Dequeue(&head);
    printf("removed element is : %d\n",iRet);

    Display(head);

    iRet = Count(head);
    printf("Total elements in Queue is : %d\n",iRet);

    return 0;
}