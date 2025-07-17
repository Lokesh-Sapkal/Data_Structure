class node
{
    data
    next

    constructor(no)
    {
        this.data = no
        this.next = null
    }
}

class SinglyCLL
{
    #first
    #last
    #iCount

    constructor()
    {
        this.#first = null
        this.#last = null
        this.#iCount = 0
    }

    InsertFirst(iNo)
    {
        let newn = null

        newn = new node(iNo)

        if((null == this.#first) && (null == this.#last))
        {
            this.#first = newn
            this.#last = newn
        }
        else
        {
            newn.next = this.#first
            this.#first = newn
        }
        this.#last.next = this.#first
        this.#iCount++
    }

    InsertLast(iNo)
    {
        let newn = null

        newn = new node(iNo)

        if((null == this.#first) && (null == this.#last))
        {
            this.#first = newn
            this.#last = newn
        }
        else
        {
            this.#last.next = newn
            this.#last = newn
        }
        this.#last.next = this.#first
        this.#iCount++
    }

    InsertAtPos(iNo, iPos)
    {
        let newn = null
        let temp = null
        let iCnt = 0

        if((iPos < 1) || (iPos > this.#iCount+1))
        {
            console.log("Invalid Position")
            return
        }

        if(iPos == 1)
        {
            this.InsertFirst(iNo)
        }
        else if(iPos == this.#iCount+1) 
        {
            this.InsertLast(iNo)   
        }
        else
        {
            newn = new node(iNo)

            temp = this.#first
            for(iCnt = 1;iCnt < iPos-1;iCnt++)
            {
                temp = temp.next
            }
            newn.next = temp.next
            temp.next = newn
            this.#iCount++
        }
    }

    DeleteFirst()
    {
        if((null == this.#first) && (null == this.#last))
        {
            console.log("Linked List is empty")
            return
        }
        else if(this.#first == this.#last)
        {
            this.#first = null
            this.#last = null
        }
        else
        {
            this.#first = this.#first.next
            this.#last.next = this.#first
        }
        this.#iCount--
    }

    DeleteLast()
    {
        let temp = null

        if((null == this.#first) && (null == this.#last))
        {
            console.log("Linked List is empty")
            return
        }
        else if(this.#first == this.#last)
        {
            this.#first = null
            this.#last = null
        }
        else
        {
            temp = this.#first
            while(temp.next != this.#last)
            {
                temp = temp.next
            }
            this.#last = temp
            this.#last.next = this.#first
        }
        this.#iCount--
    }

    DeleteAtPos(iPos)
    {
        let temp = null
        let iCnt = 0

        if((iPos < 1) || (iPos > this.#iCount))
        {
            console.log("Invalid Position")
            return
        }

        if(iPos == 1)
        {
            this.DeleteFirst()
        }
        else if(iPos == this.#iCount) 
        {
            this.DeleteLast()
        }
        else
        {
            temp = this.#first
            for(iCnt = 1;iCnt < iPos-1;iCnt++)
            {
                temp = temp.next
            }

            temp.next = temp.next.next
            this.#iCount--
        }
    }

    Display()
    {
        let temp = null
        temp = this.#first
        do
        {
            process.stdout.write("| "+temp.data+" |->")
            temp = temp.next
        }while(temp != this.#last.next)
        console.log()
    }

    Count()
    {
        return this.#iCount
    }
}

console.log()
console.log("---------------------------------- For Number ----------------------------------------")
console.log()

const sobj = new SinglyCLL()
let iRet = 0

sobj.InsertFirst(51)
sobj.InsertFirst(21)
sobj.InsertFirst(11)

sobj.InsertLast(101)
sobj.InsertLast(111)
sobj.InsertLast(121)
sobj.InsertLast(151)

sobj.Display()

iRet = sobj.Count()

console.log("Number of nodes in LL is : "+iRet)

sobj.InsertAtPos(105,5)

sobj.Display()

iRet = sobj.Count()

console.log("Number of nodes in LL is : "+iRet)

sobj.DeleteAtPos(5)

sobj.Display()

iRet = sobj.Count()

console.log("Number of nodes in LL is : "+iRet)

sobj.DeleteFirst()

sobj.Display()

iRet = sobj.Count()

console.log("Number of nodes in LL is : "+iRet)

sobj.DeleteLast()

sobj.Display()

iRet = sobj.Count()

console.log("Number of nodes in LL is : "+iRet)

/////////////////////////////////////////////////////////////////////////
console.log()
console.log("---------------------------------- For Bigint ----------------------------------------")
console.log()

const sobj2 = new SinglyCLL()

sobj2.InsertFirst(516354653165n)
sobj2.InsertFirst(21876496896854n)
sobj2.InsertFirst(11874685466666n)

sobj2.InsertLast(101643618543166635n)
sobj2.InsertLast(111963959683565266n)
sobj2.InsertLast(121689365163656565n)
sobj2.InsertLast(1513638546354636565n)

sobj2.Display()

iRet = sobj2.Count()

console.log("Number of nodes in LL is : "+iRet)

sobj2.InsertAtPos(105,5)

sobj2.Display()

iRet = sobj2.Count()

console.log("Number of nodes in LL is : "+iRet)

sobj2.DeleteAtPos(5)

sobj2.Display()

iRet = sobj2.Count()

console.log("Number of nodes in LL is : "+iRet)

sobj2.DeleteFirst()

sobj2.Display()

iRet = sobj2.Count()

console.log("Number of nodes in LL is : "+iRet)

sobj2.DeleteLast()

sobj2.Display()

iRet = sobj2.Count()

console.log("Number of nodes in LL is : "+iRet)