#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount = 0;

    public:
        DoublyCLL()
        {
            first = NULL;
            last = NULL;
            iCount = 0;
        }

        void InsertFirst(int iNo)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = iNo;
            newn->next = NULL;
            newn->prev = NULL;

            if ((NULL == first) && (NULL == last))
            {
                first = newn;
                last = newn;
            }
            else
            {
                newn->next = first;
                first->prev = newn;
                first = newn;
            }
            last->next = first;
            first->prev = last;
            iCount++;
        }

        void InsertLast(int iNo)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = iNo;
            newn->next = NULL;
            newn->prev = NULL;

            if ((NULL == first) && (NULL == last))
            {
                first = newn;
                last = newn;
            }
            else
            {
                last->next = newn;
                newn->prev = last;

                last = newn;
            }
            last->next = first;
            first->prev = last;
            iCount++;
        }
        
        void DeleteFirst()
        {
            if((NULL == first) && (NULL == last))
            {
                return;
            }
            else if(first == last)
            {
                delete first;
                first = NULL;
                last = NULL;
            }
            else
            {
                first = first->next;
                delete last->next;

                last->next = first;
                first->prev = last;
            }
            iCount--;
        }

        void DeleteLast()
        {
            if((NULL == first) && (NULL == last))
            {
                return;
            }
            else if(first == last)
            {
                delete last;
                first = NULL;
                last = NULL;
            }
            else
            {
                last = last->prev;
                delete last->next;

                last->next = first;
                first->prev = last;
            }
            iCount--;
        }

        void Display()
        {
            PNODE temp = NULL;

            if ((NULL == first) && (NULL == last))
            {
                cout<<"Linked List is empty\n";
                return;
            }

            temp = first;
            cout<<"<=> ";
            do
            {
                cout<<"| "<<temp->data<<" | <=> ";
                temp = temp->next;
            } while(temp != first);

            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int iNo,int iPos)
        {
            PNODE newn = NULL, temp = NULL;
            int iCnt = 0;

            if ((iPos < 1) || (iPos > iCount+1))
            {
                cout<<"Invalid position\n";
                return;
            }

            if (iPos == 1)
            {
                InsertFirst(iNo);
            }
            else if (iPos == iCount+1)
            {
                InsertLast(iNo);
            }
            else
            {
                newn = new NODE;
                newn->data = iNo;
                newn->next = NULL;
                newn->prev = NULL;

                temp = first;
                for (iCnt = 1;iCnt < iPos-1;iCnt++)
                {
                    temp = temp->next;
                }
                
                newn->next = temp->next;
                temp->next->prev = newn;
                newn->prev = temp;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int iPos)
        {
            int iCnt = 0;
            PNODE temp = NULL;

            if ((iPos < 1) || (iPos > iCount))
            {
                cout<<"Invalid position\n";
                return;
            }

            if (iPos == 1)
            {
                DeleteFirst();
            }
            else if (iPos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = first;
                for (iCnt = 1;iCnt < iPos-1;iCnt++)
                {
                    temp = temp->next;
                }
                
                temp->next = temp->next->next;
                delete temp->next->prev;
                temp->next->prev = temp;

                iCount--;
            }
        }
};

int main()
{
    DoublyCLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    
    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    dobj.InsertLast(151);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    dobj.InsertAtPos(105,5);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    dobj.DeleteAtPos(5);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    return 0;
}