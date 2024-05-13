// Abstract queue class
template <typename E> class Queue {
    private:
    void operator =(const Queue&) {} // Protect assignment
    Queue(const Queue&) {} // Protect copy constructor

    public:
    Queue() {} // Default
    
    virtual ~Queue() {} // Base destructor
    
    // Reinitialize the queue. The user is responsible for
    // reclaiming the storage used by the queue elements.
    virtual void clear() = 0;

    // Place an element at the rear of the queue.
    // it: The element being enqueued.
    virtual void enqueue(const E&) = 0;

    // Remove and return element at the front of the queue.
    // Return: The element at the front of the queue.
    virtual E dequeue() = 0;
    
    // Return: A copy of the front element.
    virtual const E& frontValue() const = 0;
    
    // Return: The number of elements in the queue.
    virtual int length() const = 0;
};

// Array-based queue implementation
template <typename E> class AQueue: public Queue<E> {
    private:
    int maxSize; // Maximum size of queue
    int front; // Index of front element
    int rear; // Index of rear element
    E *listArray; // Array holding queue elements

    public:
    AQueue(int size=defaultSize) { // Constructor
        // Make list array one position larger for empty slot
        maxSize = size+1;
        rear = 0; front = 1;
        listArray = new E[maxSize];
    }

    ~AQueue() { delete [] listArray; } // Destructor
    
    void clear() { rear = 0; front = 1; } // Reinitialize
    
    void enqueue(const E& it) { // Put "it" in queue
        Assert(((rear+2) % maxSize) != front, "Queue is full");
        rear = (rear+1) % maxSize; // Circular increment
        listArray[rear] = it;
    }

    E dequeue() { // Take element out
        Assert(length() != 0, "Queue is empty");
        E it = listArray[front];
        front = (front+1) % maxSize; // Circular increment
        return it;
    }

    const E& frontValue() const { // Get front value
        Assert(length() != 0, "Queue is empty");
        return listArray[front];
    }

    virtual int length() const // Return length
    { return ((rear+maxSize) - front + 1) % maxSize; }
};

// Linked queue implementation
template <typename E> class LQueue: public Queue<E> {
    private:
    Link<E>* front; // Pointer to front queue node
    Link<E>* rear; // Pointer to rear queue node
    int size; // Number of elements in queue

    public:
    LQueue(int sz =defaultSize) // Constructor
    { front = rear = new Link<E>(); size = 0; }
    ~LQueue() { clear(); delete front; } // Destructor

    void clear() { // Clear queue
        while(front->next != NULL) { // Delete each link node
            rear = front;
            delete rear;
        }
        rear = front;
        size = 0;
    }

    void enqueue(const E& it) { // Put element on rear
        rear->next = new Link<E>(it, NULL);
        rear = rear->next;
        size++;
    }

    E dequeue() { // Remove element from front
        Assert(size != 0, "Queue is empty");
        E it = front->next->element; // Store dequeued value
        Link<E>* ltemp = front->next; // Hold dequeued link
        front->next = ltemp->next; // Advance front
        if (rear == ltemp) rear = front; // Dequeue last element
        delete ltemp; // Delete link
        size --;
        return it; // Return element value
    }

    const E& frontValue() const { // Get front element
        Assert(size != 0, "Queue is empty");
        return front->next->element;
    }
    
    virtual int length() const { return size; }
};