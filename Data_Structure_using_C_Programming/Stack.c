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

void Push(PPNODE first, int iNo)     // InsertFirst
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    newn->next = *first;
    *first = newn;
}

int Pop(PPNODE first)     // DeleteFirst
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
    printf(" ----\n");
    while(first != NULL)
    {
        printf("| %d |\n",first->data);
        printf(" ----\n");
        first = first->next;
    }
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

    Push(&head,11);
    Push(&head,21);
    Push(&head,51);
    Push(&head,101);

    Display(head);

    iRet = Count(head);
    printf("Total elements in Stack is : %d\n",iRet);
    
    iRet = Pop(&head);
    printf("Poped element is : %d\n",iRet);
    
    iRet = Pop(&head);
    printf("Poped element is : %d\n",iRet);

    Display(head);

    iRet = Count(head);
    printf("Total elements in Stack is : %d\n",iRet);

    return 0;
}