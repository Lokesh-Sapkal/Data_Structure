#include<iostream>
using namespace std;

struct node1
{
    int data;
    struct node1* next;
};

struct node2
{
    int data;
    struct node2* next;
    struct node2* prev;
};

typedef struct node1 SNODE;
typedef struct node1* SPNODE;

typedef struct node2 DNODE;
typedef struct node2* DPNODE;

class SinglyLLL
{
    private:
        SPNODE first;
        int iCount;

    public:
        SinglyLLL()
        {
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int iNo)
        {
            SPNODE newn = NULL;

            newn = new SNODE;
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
            SPNODE newn = NULL, temp = NULL;

            newn = new SNODE;
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
            SPNODE temp = NULL;

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
            SPNODE temp = NULL;

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
            SPNODE temp = NULL;
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
            SPNODE newn = NULL , temp = NULL;
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
                newn = new SNODE;
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
            SPNODE temp = NULL, target = NULL;
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

class SinglyCLL
{
    private:
        SPNODE first;
        SPNODE last;
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
            SPNODE newn = NULL;

            newn = new SNODE;

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
            SPNODE newn = NULL, temp = NULL;

            newn = new SNODE;

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
            SPNODE temp = NULL;

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
            SPNODE temp = NULL;
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
            SPNODE newn = NULL, temp = NULL;

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
                newn = new SNODE;
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
            SPNODE target = NULL, temp = NULL;

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

class DoublyLLL
{
    private:
        DPNODE first;
        int iCount;

    public:
        DoublyLLL()
        {
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int iNo)
        {
            DPNODE newn = NULL;

            newn = new DNODE;
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
            DPNODE newn = NULL, temp = NULL;

            newn = new DNODE;
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
            DPNODE temp = NULL;

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
            DPNODE temp = NULL;

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
            DPNODE temp = NULL;
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
            DPNODE newn = NULL , temp = NULL;
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
                newn = new DNODE;
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
            DPNODE temp = NULL, target = NULL;
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

class DoublyCLL
{
    private:
        DPNODE first;
        DPNODE last;
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
            DPNODE newn = NULL;

            newn = new DNODE;
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
            DPNODE newn = NULL;

            newn = new DNODE;
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
            DPNODE temp = NULL;

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
            DPNODE newn = NULL, temp = NULL;
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
                newn = new DNODE;
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
            DPNODE temp = NULL;

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
    SinglyLLL slobj;
    SinglyCLL scobj;
    DoublyLLL dlobj;
    DoublyCLL dcobj;

    int iRet = 0;

    cout<<"---------------------------------------------------------------------------\n";
    cout<<"---------------------- Singly Linear Linked List --------------------------\n";
    cout<<"---------------------------------------------------------------------------\n";

    slobj.InsertFirst(51);
    slobj.InsertFirst(21);
    slobj.InsertFirst(11);
    
    slobj.InsertLast(101);
    slobj.InsertLast(111);
    slobj.InsertLast(121);

    slobj.Display();

    iRet = slobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    slobj.InsertAtPos(105,5);

    slobj.Display();

    iRet = slobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    slobj.DeleteAtPos(5);

    slobj.Display();

    iRet = slobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    slobj.DeleteFirst();

    slobj.Display();

    iRet = slobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    slobj.DeleteLast();

    slobj.Display();

    iRet = slobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    cout<<"---------------------------------------------------------------------------\n";
    cout<<"--------------------- Singly Circular Linked List -------------------------\n";
    cout<<"---------------------------------------------------------------------------\n";

    scobj.InsertFirst(51);
    scobj.InsertFirst(21);
    scobj.InsertFirst(11);
    
    scobj.InsertLast(101);
    scobj.InsertLast(111);
    scobj.InsertLast(121);

    scobj.Display();

    iRet = scobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    scobj.InsertAtPos(105,5);

    scobj.Display();

    iRet = scobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    scobj.DeleteAtPos(5);

    scobj.Display();

    iRet = scobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    scobj.DeleteFirst();

    scobj.Display();

    iRet = scobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    scobj.DeleteLast();

    scobj.Display();

    iRet = scobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    cout<<"---------------------------------------------------------------------------\n";
    cout<<"---------------------- Doubly Linear Linked List --------------------------\n";
    cout<<"---------------------------------------------------------------------------\n";

    dlobj.InsertFirst(51);
    dlobj.InsertFirst(21);
    dlobj.InsertFirst(11);
    
    dlobj.InsertLast(101);
    dlobj.InsertLast(111);
    dlobj.InsertLast(121);

    dlobj.Display();

    iRet = dlobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    dlobj.InsertAtPos(105,5);

    dlobj.Display();

    iRet = dlobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    dlobj.DeleteAtPos(5);

    dlobj.Display();

    iRet = dlobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    dlobj.DeleteFirst();

    dlobj.Display();

    iRet = dlobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    dlobj.DeleteLast();

    dlobj.Display();

    iRet = dlobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    cout<<"---------------------------------------------------------------------------\n";
    cout<<"--------------------- Doubly Circular Linked List -------------------------\n";
    cout<<"---------------------------------------------------------------------------\n";

    dcobj.InsertFirst(51);
    dcobj.InsertFirst(21);
    dcobj.InsertFirst(11);
    
    dcobj.InsertLast(101);
    dcobj.InsertLast(111);
    dcobj.InsertLast(121);

    dcobj.Display();

    iRet = dcobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    dcobj.InsertAtPos(105,5);

    dcobj.Display();

    iRet = dcobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    dcobj.DeleteAtPos(5);

    dcobj.Display();

    iRet = dcobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    dcobj.DeleteFirst();

    dcobj.Display();

    iRet = dcobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    dcobj.DeleteLast();

    dcobj.Display();

    iRet = dcobj.Count();

    cout<<"Number of nodes in Linked List : "<<iRet<<"\n";

    cout<<"---------------------------------------------------------------------------\n";
    cout<<"--------------------------- Thank You -------------------------------------\n";
    cout<<"---------------------------------------------------------------------------\n";

    return 0;
}