class node
{
    public int data;
    public node next;
    public node prev;

    public node(int iNo)
    {
        this.data = iNo;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCLL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCLL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int iNo)
    {
        node newn = null;

        newn = new node(iNo);

        if((null == first) && (null == last))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        last.next = first;
        first.prev = last;
        iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = null;

        newn = new node(iNo);

        if((null == first) && (null == last))
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            newn.prev = last;
            last = newn;
        }
        last.next = first;
        first.prev = last;
        iCount++;
    }

    public void InsertAtPos(int iNo,int iPos)
    {
        node newn = null, temp = null;
        int iCnt = 0;

        if((iPos < 1) || (iPos > iCount+1))
        {
            System.out.println("Invalid Position");
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
            newn = new node(iNo);

            temp = first;
            for(iCnt = 1;iCnt < iPos-1;iCnt++) 
            {
                temp = temp.next;    
            }
            newn.next = temp.next;
            temp.next.prev = temp;
            newn.prev = temp;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if((null == first) && (null == last))
        {
            return;
        }
        else if(first == last) 
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            
            last.next = first;
            first.prev = last;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if((null == first) && (null == last))
        {
            return;
        }
        else if(first == last) 
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;
            
            last.next = first;
            first.prev = last;
        }
        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {
        node temp = null;
        int iCnt = 0;

        if((iPos < 1) || (iPos > iCount))
        {
            System.out.println("Invalid Position");
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
                temp = temp.next;    
            }
            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
        }
    }

    public void Display()
    {
        if((null == first) && (null == last))
        {
            System.out.println("Linked List is empty");
            return;
        }

        node temp = null;
        temp = first;

        System.out.print("<=>");
        do 
        {
            System.out.print("| "+temp.data+" |<=>");
            temp = temp.next;
        }while(temp != first);
        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

public class DoublyCircularLL 
{
    public static void main(String A[])
    {
        DoublyCLL dobj = new DoublyCLL();
        int iRet = 0;

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);
        dobj.InsertLast(121);

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        dobj.DeleteFirst();

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        dobj.DeleteLast();

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        dobj.InsertAtPos(105,5);

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        dobj.DeleteAtPos(5);

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);
    }    
}
