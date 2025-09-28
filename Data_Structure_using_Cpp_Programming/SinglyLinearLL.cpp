#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyLLL
{
    private:
        PNODE first;
        int iCount;

    public:
        SinglyLLL()
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

            if(NULL == first)
            {
                first = newn;
            }
            else
            {
                newn->next = first;
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

            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" |"<<"->";
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
                delete target;

                iCount--;
            }
        }
};

int main()
{
    SinglyLLL sobj;
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