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
                cout<<"Invalid position\n";
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
                cout<<"Invalid position\n";
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
                cout<<"Invalid position\n";
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
                cout<<"Invalid position\n";
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

    int iRet = 0, Option = 0, iNo = 0,iPos = 0;

    while(1)
    {
        cout<<"Select 1 for Singly Linear LinkedList \n";
        cout<<"Select 2 for Singly Circular LinkedList \n";
        cout<<"Select 3 for Doubly Linear LinkedList \n";
        cout<<"Select 4 for Doubly Circular LinkedList \n";

        cin>>Option;

        if((Option >= 1) && (Option <= 4))
        {
            switch (Option)
            {
                case 1:
                    while (1)
                    {
                        cout<<"Enter 1 for InsertFirst\n";
                        cout<<"Enter 2 for InsertLast\n";
                        cout<<"Enter 3 for InsertAtPos\n";
                        cout<<"Enter 4 for DeleteFirst\n";
                        cout<<"Enter 5 for DeleteLast\n";
                        cout<<"Enter 6 for DeleteAtPos\n";
                        cout<<"Enter 7 for Display\n";
                        cout<<"Enter 8 for Count\n";
                        
                        cin>>Option;

                        switch (Option)
                        {
                            case 1:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                slobj.InsertFirst(iNo);

                                break;

                            case 2:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                slobj.InsertLast(iNo);
                                break;
                            
                            case 3:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                cout<<"Enter the position : ";
                                cin>>iPos;

                                slobj.InsertAtPos(iNo,iPos);
                                break;
                            
                            case 4:
                                slobj.DeleteFirst();
                                break;
                                
                            case 5:
                                slobj.DeleteLast();
                                break;

                            case 6:
                                cout<<"Enter the position : ";
                                cin>>iPos;

                                slobj.DeleteAtPos(iPos);
                                break;

                            case 7:
                                slobj.Display();
                                break;

                            case 8:
                                iRet = slobj.Count();
                                cout<<"Number of nodes in Linked List : "<<iRet<<"\n";
                                break;
                            
                            default:
                                cout<<"Invalid Input\n";
                                break;
                        }
                    }
                    break;

                case 2:
                    while (1)
                    {
                        cout<<"Enter 1 for InsertFirst\n";
                        cout<<"Enter 2 for InsertLast\n";
                        cout<<"Enter 3 for InsertAtPos\n";
                        cout<<"Enter 4 for DeleteFirst\n";
                        cout<<"Enter 5 for DeleteLast\n";
                        cout<<"Enter 6 for DeleteAtPos\n";
                        cout<<"Enter 7 for Display\n";
                        cout<<"Enter 8 for Count\n";
                        
                        cin>>Option;

                        switch (Option)
                        {
                            case 1:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                scobj.InsertFirst(iNo);

                                break;

                            case 2:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                scobj.InsertLast(iNo);
                                break;
                            
                            case 3:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                cout<<"Enter the position : ";
                                cin>>iPos;

                                scobj.InsertAtPos(iNo,iPos);
                                break;
                            
                            case 4:
                                scobj.DeleteFirst();
                                break;
                                
                            case 5:
                                scobj.DeleteLast();
                                break;

                            case 6:
                                cout<<"Enter the position : ";
                                cin>>iPos;

                                scobj.DeleteAtPos(iPos);
                                break;

                            case 7:
                                scobj.Display();
                                break;

                            case 8:
                                iRet = scobj.Count();
                                cout<<"Number of nodes in Linked List : "<<iRet<<"\n";
                                break;
                            
                            default:
                                cout<<"Invalid Input\n";
                                break;
                        }
                    }
                    break;

                case 3:
                    while (1)
                    {
                        cout<<"Enter 1 for InsertFirst\n";
                        cout<<"Enter 2 for InsertLast\n";
                        cout<<"Enter 3 for InsertAtPos\n";
                        cout<<"Enter 4 for DeleteFirst\n";
                        cout<<"Enter 5 for DeleteLast\n";
                        cout<<"Enter 6 for DeleteAtPos\n";
                        cout<<"Enter 7 for Display\n";
                        cout<<"Enter 8 for Count\n";
                        
                        cin>>Option;

                        switch (Option)
                        {
                            case 1:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                dlobj.InsertFirst(iNo);

                                break;

                            case 2:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                dlobj.InsertLast(iNo);
                                break;
                            
                            case 3:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                cout<<"Enter the position : ";
                                cin>>iPos;

                                dlobj.InsertAtPos(iNo,iPos);
                                break;
                            
                            case 4:
                                dlobj.DeleteFirst();
                                break;
                                
                            case 5:
                                dlobj.DeleteLast();
                                break;

                            case 6:
                                cout<<"Enter the position : ";
                                cin>>iPos;

                                dlobj.DeleteAtPos(iPos);
                                break;

                            case 7:
                                dlobj.Display();
                                break;

                            case 8:
                                iRet = dlobj.Count();
                                cout<<"Number of nodes in Linked List : "<<iRet<<"\n";
                                break;
                            
                            default:
                                cout<<"Invalid Input\n";
                                break;
                        }
                    }
                    break;

                case 4:
                    while (1)
                    {
                        cout<<"Enter 1 for InsertFirst\n";
                        cout<<"Enter 2 for InsertLast\n";
                        cout<<"Enter 3 for InsertAtPos\n";
                        cout<<"Enter 4 for DeleteFirst\n";
                        cout<<"Enter 5 for DeleteLast\n";
                        cout<<"Enter 6 for DeleteAtPos\n";
                        cout<<"Enter 7 for Display\n";
                        cout<<"Enter 8 for Count\n";
                        
                        cin>>Option;

                        switch (Option)
                        {
                            case 1:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                dcobj.InsertFirst(iNo);

                                break;

                            case 2:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                dcobj.InsertLast(iNo);
                                break;
                            
                            case 3:
                                cout<<"Enter the element : ";
                                cin>>iNo;

                                cout<<"Enter the position : ";
                                cin>>iPos;

                                dcobj.InsertAtPos(iNo,iPos);
                                break;
                            
                            case 4:
                                dcobj.DeleteFirst();
                                break;
                                
                            case 5:
                                dcobj.DeleteLast();
                                break;

                            case 6:
                                cout<<"Enter the position : ";
                                cin>>iPos;

                                dcobj.DeleteAtPos(iPos);
                                break;

                            case 7:
                                dcobj.Display();
                                break;

                            case 8:
                                iRet = dcobj.Count();
                                cout<<"Number of nodes in Linked List : "<<iRet<<"\n";
                                break;
                            
                            default:
                                cout<<"Invalid Input\n";
                                break;
                        }
                    }
                    break;
            
                default:
                    break;
            }   
        }
        else
        {
            cout<<"Invalid Input\n";
        }
        break;
    }
    
    
    return 0;
}