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

class DoublyLLL
{
    private node first;
    private int iCount;

    public DoublyLLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int iNo)
    {
        node newn = null;

        newn = new node(iNo);

        if(null == first) 
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = null, temp = null;

        newn = new node(iNo);

        if(null == first) 
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null) 
            {
                temp = temp.next;
            }
            temp.next = newn;
            newn.prev = temp;
        }
        iCount++;
    }

    public void InsertAtPos(int iNo, int iPos)
    {
        node newn = null, temp = null;
        int iCnt = 0;

        if((iPos < 1) || (iPos > iCount+1)) 
        {
            System.out.print("Invalid Position");
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
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;

            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if(null == first)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
            first.prev = null;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(null == first)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            temp = first;

            while(temp.next.next != null) 
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {
        node temp = null;
        int iCnt = 0;

        if((iPos < 1) || (iPos > iCount)) 
        {
            System.out.print("Invalid Position");
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
        node temp = null;
        temp = first;
        System.out.print("null<-");
        while(temp != null) 
        {
            System.out.print("| "+temp.data+" |<=>");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }
}

public class DoublyLinearLL 
{
    public static void main(String A[])
    {
        DoublyLLL dobj = null;
        int iRet = 0;

        dobj = new DoublyLLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);
        dobj.InsertLast(121);

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of elements in LinkedList are : "+iRet);

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

        System.out.println("Number of elements in LinkedList are : "+iRet);

        dobj.DeleteAtPos(5);

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of elements in LinkedList are : "+iRet);
    }    
}
