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

class DoublyLLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLLL()
        {
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int iNo)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = iNo;
            newn->next = NULL;
            newn->prev = NULL;

            if(NULL == first)
            {
                first = newn;
            }
            else
            {
                newn->next = first;
                newn->next->prev = newn;
                first = newn;
            }

            iCount++;
        }
        void InsertLast(int iNo)
        {
            PNODE newn = NULL, temp = NULL;

            newn = new NODE;
            newn->data = iNo;
            newn->next = NULL;
            newn->prev = NULL;

            if(NULL == first)
            {
                first = newn;
            }
            else
            {
                temp = first;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                
                temp->next = newn;
                newn->prev = temp;
            }

            iCount++;
        }
        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(NULL == first)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;
                first = first->next;
                first->prev = NULL;
                delete temp;
            }

            iCount--;
        }
        void DeleteLast()
        {
            PNODE temp = NULL;

            if(NULL == first)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                
                delete temp->next;
                temp->next = NULL;
            }

            iCount--;
        }
        void Display()
        {
            PNODE temp = NULL;
            temp = first;

            cout<<"NULL<-";
            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" |"<<"<=>";
                temp = temp->next;
            }
            cout<<"NULL\n";
        }
        int Count()
        {
            return iCount;
        }
        void InsertAtPos(int iNo, int iPos)
        {
            PNODE newn = NULL , temp = NULL;
            int iCnt = 0;

            if((iPos < 1) || (iPos > iCount+1))
            {
                cout<<"Invalid position";
                return;
            }
            
            if(iPos == 1)
            {
                InsertFirst(iNo);
            }
            else if(iPos == iCount+1)
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

                for(iCnt = 1;iCnt < iPos-1;iCnt++)
                {
                    temp = temp->next;
                }
                
                newn->next = temp->next;
                newn->prev = temp;
                temp->next = newn;

                iCount++;
            }
        }
        void DeleteAtPos(int iPos)
        {
            PNODE temp = NULL, target = NULL;
            int iCnt = 0;

            if((iPos < 1) || (iPos > iCount))
            {
                cout<<"Invalid position";
                return;
            }
            
            if(iPos == 1)
            {
                DeleteFirst();
            }
            else if(iPos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = first;

                for(iCnt = 1;iCnt < iPos-1;iCnt++)
                {
                    temp = temp->next;
                }
                
                target = temp->next;
                temp->next = target->next;
                target->next->prev = temp;
                delete target;

                iCount--;
            }
        }
};

int main()
{
    DoublyLLL dobj;
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

    dobj.InsertAtPos(125,7);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    dobj.DeleteAtPos(5);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    return 0;
}