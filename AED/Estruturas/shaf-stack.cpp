// Stack abtract class
template <typename E> class Stack {
    private:
    void operator =(const Stack&) {} // Protect assignment
    Stack(const Stack&) {} // Protect copy constructor

    public:
    Stack() {} // Default constructor
    virtual ~Stack() {} // Base destructor

    // Reinitialize the stack.
    virtual void clear() = 0;

    // Push an element onto the top of the stack.
    virtual void push(const E& it) = 0;

    // Remove the element at the top of the stack.
    virtual E pop() = 0;

    // Return: A copy of the top element.
    virtual const E& topValue() const = 0;

    // Return: The number of elements in the stack.
    virtual int length() const = 0;
};

// Array-based stack implementation
template <typename E> class AStack: public Stack<E> {
    private:
    int maxSize; // Maximum size of stack
    int top; // Index for top element
    E *listArray; // Array holding stack elements

    public:
    AStack(int size =defaultSize) // Constructor
    { maxSize = size; top = 0; listArray = new E[size]; }
    ~AStack() { delete [] listArray; } // Destructor
    
    void clear() { top = 0; } // Reinitialize
    
    void push(const E& it) { // Put "it" on stack
        Assert(top != maxSize, "Stack is full");
        listArray[top++] = it;
    }

    E pop() { // Pop top element
    Assert(top != 0, "Stack is empty");
    return listArray[--top];
    }

    const E& topValue() const { // Return top element
        Assert(top != 0, "Stack is empty");
        return listArray[top-1];
    }

    int length() const { return top; } // Return length
};

// Linked stack implementation
template <typename E> class LStack: public Stack<E> {
    private:
    Link<E>* top; // Pointer to first element
    int size; // Number of elements

    public:
    LStack(int sz =defaultSize) // Constructor
    { top = NULL; size = 0; }
    ~LStack() { clear(); } // Destructor

    void clear() { // Reinitialize
        while (top != NULL) { // Delete link nodes
            Link<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    void push(const E& it) { // Put "it" on stack
        top = new Link<E>(it, top);
        size++;
    }

    E pop() { // Remove "it" from stack
        Assert(top != NULL, "Stack is empty");
        E it = top->element;
        Link<E>* ltemp = top->next;
        delete top;
        top = ltemp;
        size--;
        return it;
    }

    const E& topValue() const { // Return top value
        Assert(top != 0, "Stack is empty");
        return top->element;
    }

    int length() const { return size; } // Return length
};
