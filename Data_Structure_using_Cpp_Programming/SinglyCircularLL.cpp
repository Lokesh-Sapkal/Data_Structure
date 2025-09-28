#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCLL()
        {
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int iNo)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = iNo;
            newn->next = NULL;

            if((NULL == first) && (NULL == last))
            {
                first = newn;
                last = newn;

                last->next = first;
            }
            else
            {
                newn->next = first;
                first = newn;

                last->next = first;
            }
            iCount++;
        }
        void InsertLast(int iNo)
        {
            PNODE newn = NULL, temp = NULL;

            newn = new NODE;

            newn->data = iNo;
            newn->next = NULL;

            if((NULL == first) && (NULL == last))
            {
                first = newn;
                last = newn;

                last->next = first;
            }
            else
            {
                temp = first;

                while (temp->next != first)
                {
                    temp = temp->next;
                }
                
                temp->next = newn;
                last = newn;
                last->next = first;
            }
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
            }
            iCount--;
        }
        void DeleteLast()
        {
            PNODE temp = NULL;

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
                temp = first;

                while(temp->next->next != first)
                {
                    temp = temp->next;
                }

                delete temp->next;
                last = temp;
                last->next = first;
            }
            iCount--;
        }
        void Display()
        {
            if((NULL == first) && (NULL == last))
            {
                cout<<"LinkedList is empty\n";
                return;
            }
            PNODE temp = NULL;
            temp = first;

            cout<<"->";
            do
            {
                cout<<"| "<<temp->data<<" |->";
                temp = temp->next;
            } while(temp != first);
            cout<<"\n";
        }
        int Count()
        {
            return iCount;
        }
        void InsertAtPos(int iNo, int iPos)
        {
            int iCnt = 0;
            PNODE newn = NULL, temp = NULL;

            if((iPos < 1) || (iPos > iCount+1))
            {
                cout<<"Invalid position\n";
                return;
            }

            if(iPos == 1)
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
                
                temp = first;
                for(iCnt = 1;iCnt < iPos-1;iCnt++)
                {
                    temp = temp->next;
                }
                
                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }
        }
        void DeleteAtPos(int iPos)
        {
            int iCnt = 0;
            PNODE target = NULL, temp = NULL;

            if((iPos < 1) || (iPos > iCount))
            {
                cout<<"Invalid position\n";
                return;
            }

            if(iPos == 1)
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
                for(iCnt = 1;iCnt < iPos-1;iCnt++)
                {
                    temp = temp->next;
                }
                
                target = temp->next;
                temp->next = target->next;
                delete target;

                iCount--;
            }
        }
};

int main()
{
    SinglyCLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    
    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    // sobj.DeleteFirst();

    // sobj.Display();

    // iRet = sobj.Count();

    // cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    // sobj.DeleteLast();

    // sobj.Display();

    // iRet = sobj.Count();

    // cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    sobj.InsertAtPos(105,5);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    sobj.DeleteAtPos(5);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    return 0;
}