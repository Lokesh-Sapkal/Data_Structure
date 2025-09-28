class node
{
    data
    next
    prev

    constructor(no)
    {
        this.data = no
        this.next = null
        this.prev = null
    }
}

class DoublyLLL
{
    #first
    #icount

    constructor()
    {
        this.#first = null
        this.#icount = 0
    }

    InsertFirst(iNo)
    {
        let newn = null

        newn = new node(iNo)

        if(null == this.#first)
        {
            this.#first = newn
        }
        else 
        {
            newn.next = this.#first
            this.#first.prev = newn
            this.#first = newn
        }
        this.#icount++
    }

    InsertLast(iNo)
    {
        let temp = null
        let newn = null

        newn = new node(iNo)

        if(null == this.#first)
        {
            this.#first = newn
        }
        else 
        {
            temp = this.#first

            while(temp.next != null) 
            {
                temp = temp.next
            }
            temp.next = newn
            newn.prev = temp
        }
        this.#icount++
    }

    InsertAtPos(iNo, iPos)
    {
        let newn = null
        let temp = null
        let iCnt = 0

        if((iPos < 1) || (iPos > this.#icount+1))
        {
            console.log("Invalid Position")
            return
        }

        if(iPos == 1)
        {
            this.InsertFirst(iNo)
        }
        else if (iPos == this.#icount+1)
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
            temp.next.prev = newn
            newn.prev = temp
            temp.next = newn

            this.#icount++
        }
    }

    DeleteFirst()
    {
        if(null == this.#first)
        {
            console.log("LikedList is empty")
            return
        }
        else if(null == this.#first.next) 
        {
            this.#first = null
        }
        else
        {
            this.#first = this.#first.next
        }
        this.#icount--
    }

    DeleteLast()
    {
        let temp = null

        if(null == this.#first)
        {
            console.log("LikedList is empty")
            return
        }
        else if(null == this.#first.next) 
        {
            this.#first = null
        }
        else
        {
            temp = this.#first

            while(temp.next.next != null) 
            {
                temp = temp.next
            }
            temp.next = null
        }
        this.#icount--
    }

    DeleteAtPos(iPos)
    {
        let temp = null
        let iCnt = 0

        if((iPos < 1) || (iPos > this.#icount+1))
        {
            console.log("Invalid Position")
            return
        }

        if(iPos == 1)
        {
            this.InsertFirst(iNo)
        }
        else if (iPos == this.#icount+1)
        {
            this.InsertLast(iNo)
        }
        else
        {
            temp = this.#first
            for(iCnt = 1;iCnt < iPos-1;iCnt++)
            {
                temp = temp.next
            }

            temp.next = temp.next.next
            temp.next.prev = temp

            this.#icount--
        }
    }

    Display()
    {
        let temp = this.#first
        process.stdout.write("null<-")
        while(temp != null)
        {
            process.stdout.write("| "+temp.data+" |<=>")
            temp = temp.next
        }
        console.log("null")
    }

    Count()
    {
        return this.#icount
    }
}

console.log()
console.log("---------------------------------- For Number ----------------------------------------")
console.log()

const dobj = new DoublyLLL()
let iRet = 0

dobj.InsertFirst(51)
dobj.InsertFirst(21)
dobj.InsertFirst(11)

dobj.InsertLast(101)
dobj.InsertLast(111)
dobj.InsertLast(121)
dobj.InsertLast(151)

dobj.Display()

iRet = dobj.Count()

console.log("Number of elements in LL is : "+iRet)

dobj.InsertAtPos(105,5)

dobj.Display()

iRet = dobj.Count()

console.log("Number of elements in LL is : "+iRet)

dobj.DeleteAtPos(5)

dobj.Display()

iRet = dobj.Count()

console.log("Number of elements in LL is : "+iRet)

dobj.DeleteFirst()

dobj.Display()

iRet = dobj.Count()

console.log("Number of elements in LL is : "+iRet)

dobj.DeleteLast()

dobj.Display()

iRet = dobj.Count()

console.log("Number of elements in LL is : "+iRet)

//////////////////////////////////////////////////////////////
console.log()
console.log("---------------------------------- For Bigint ----------------------------------------")
console.log()

const sobj2 = new DoublyLLL()

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