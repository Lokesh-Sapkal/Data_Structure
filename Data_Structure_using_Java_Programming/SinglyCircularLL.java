class node
{
    public int data;
    public node next;

    public node(int iNo)
    {
        this.data = iNo;
        this.next = null;
    }
}

class SinglyCLL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCLL()
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
            first = newn;
        }
        last.next = first;
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
            last = newn;
        }
        last.next = first;
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
        }
        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

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
            temp = first;

            while(temp.next.next != first) 
            {
                temp = temp.next;
            }

            last.next = null;
            last = temp;
            last.next = first;
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
            iCount--;
        }
    }

    public void Display()
    {
        if((null == first) || (null == last)) 
        {
            return;    
        }
        node temp = null;
        temp = first;
        System.out.print("->");
        do 
        {
            System.out.print("| "+temp.data+" |->");
            temp = temp.next;
        }while(temp != first);
        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

public class SinglyCircularLL 
{
    public static void main(String A[])
    {
        SinglyCLL sobj = new SinglyCLL();
        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        sobj.DeleteFirst();

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        sobj.DeleteLast();

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        sobj.InsertAtPos(105,5);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        sobj.DeleteAtPos(5);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);
    }    
}
