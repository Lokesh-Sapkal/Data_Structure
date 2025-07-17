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

class Queue
{
    #first
    #iCount

    constructor()
    {
        this.#first = null
        this.#iCount = 0
    }

    Enqueue(iNo)           // InsertLast
    {
        let newn = null
        let temp = null

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
        }
        this.#iCount++
    }
    
    Dequeue()               // DeleteFirst
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
            process.stdout.write("| "+temp.data+" | - ")
            temp = temp.next
        }
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

const qobj1 = new Queue()
let iRet = 0

qobj1.Enqueue(11)
qobj1.Enqueue(21)
qobj1.Enqueue(51)
qobj1.Enqueue(101)
qobj1.Enqueue(111)
qobj1.Enqueue(121)
qobj1.Enqueue(151)

qobj1.Display()

iRet = qobj1.Count()

console.log("Number of nodes in LL is : "+iRet)

iRet = qobj1.Dequeue()

console.log("Removed element is : "+iRet)

iRet = qobj1.Dequeue()

console.log("Removed element is : "+iRet)

qobj1.Display()

iRet = qobj1.Count()

console.log("Number of nodes in LL is : "+iRet)

/////////////////////////////////////////////////////////////////////////////

console.log()
console.log("---------------------------------- For Bigint ----------------------------------------")
console.log()

const qobj2 = new Queue()

qobj2.Enqueue(11874685466666n)
qobj2.Enqueue(21876496896854n)
qobj2.Enqueue(51635465643165n)
qobj2.Enqueue(10164361166635n)
qobj2.Enqueue(11196683565266n)
qobj2.Enqueue(12168163656565n)
qobj2.Enqueue(15136354636565n)

qobj2.Display()

iRet = qobj2.Count()

console.log("Number of nodes in LL is : "+iRet)

iRet = qobj2.Dequeue()

console.log("Removed element is : "+iRet)

iRet = qobj2.Dequeue()

console.log("Removed element is : "+iRet)

qobj2.Display()

iRet = qobj2.Count()

console.log("Number of nodes in LL is : "+iRet)