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

class Stack
{
    #first
    #iCount

    constructor()
    {
        this.#first = null
        this.#iCount = 0
    }

    Push(iNo)           // InsertFirst
    {
        let newn = null

        newn = new node(iNo)

        newn.next = this.#first
        this.#first = newn

        this.#iCount++
    }
    
    Pop()               // DeleteFirst
    {
        let element = 0

        if(null == this.#first)
        {
            console.log("Stack is empty")
            return
        }
        else
        {
            element = this.#first.data
            this.#first = this.#first.next
            this.#iCount--
            return element
        }
    }

    Display()
    {
        let temp = null
        temp = this.#first

        while(temp != null)
        {
            console.log("| "+temp.data+" |")
            temp = temp.next
        }
    }

    Count()
    {
        return this.#iCount
    }
}

console.log()
console.log("---------------------------------- For Number ----------------------------------------")
console.log()

const sobj = new Stack()
let iRet = 0

sobj.Push(11)
sobj.Push(21)
sobj.Push(51)
sobj.Push(101)
sobj.Push(111)
sobj.Push(121)
sobj.Push(151)

sobj.Display()

iRet = sobj.Count()

console.log("Number of nodes in Stack is : "+iRet)

iRet = sobj.Pop()

console.log("Poped element is : "+iRet)

iRet = sobj.Pop()

console.log("Poped element is : "+iRet)

sobj.Display()

iRet = sobj.Count()

console.log("Number of nodes in Stack is : "+iRet)

/////////////////////////////////////////////////////////////////////////////

console.log()
console.log("---------------------------------- For Bigint ----------------------------------------")
console.log()

const sobj2 = new Stack()

sobj2.Push(11874685466666n)
sobj2.Push(21876496896854n)
sobj2.Push(51635465643165n)
sobj2.Push(10164361166635n)
sobj2.Push(11196683565266n)
sobj2.Push(12168163656565n)
sobj2.Push(15136354636565n)

sobj2.Display()

iRet = sobj2.Count()

console.log("Number of nodes in Stack is : "+iRet)

iRet = sobj2.Pop()

console.log("Poped element is : "+iRet)

iRet = sobj2.Pop()

console.log("Poped element is : "+iRet)

sobj2.Display()

iRet = sobj2.Count()

console.log("Number of nodes in Stack is : "+iRet)