template <typename E> class List { // List ADT
    private:
    void operator =(const List&) {} // Protect assignment
    List(const List&) {} // Protect copy constructor

    public:
    List() {} // Default constructor
    virtual ~List() {} // Base destructor

    // Clear contents from the list, to make it empty.
    virtual void clear() = 0;

    // Insert an element at the current location.
    virtual void insert(const E& item) = 0;

    // Append an element at the end of the list.
    virtual void append(const E& item) = 0;

    // Remove and return the current element.
    virtual E remove() = 0;

    // Set the current position to the start of the list
    virtual void moveToStart() = 0;
    
    // Set the current position to the end of the list
    virtual void moveToEnd() = 0;

    // Move the current position one step left.
    virtual void prev() = 0;

    // Move the current position one step right.
    virtual void next() = 0;

    // Return: The number of elements in the list.
    virtual int length() const = 0;

    // Return: The position of the current element.
    virtual int currPos() const = 0;

    // Set current position.
    virtual void moveToPos(int pos) = 0;

    // Return: The current element.
    virtual const E& getValue() const = 0;
};

template <typename E> // Array-based list implementation
class AList : public List<E> {
    private:
    int maxSize; // Maximum size of list
    int listSize; // Number of list items now
    int curr; // Position of current element
    E* listArray; // Array holding list elements

    public:
    AList(int size=defaultSize) { // Constructor
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }

    ~AList() { delete [] listArray; } // Destructor
    void clear() { // Reinitialize the list
        delete [] listArray; // Remove the array
        listSize = curr = 0; // Reset the size
        listArray = new E[maxSize]; // Recreate array
    }

    // Insert "it" at current position
    void insert(const E& it) {
        Assert(listSize < maxSize, "List capacity exceeded");
        for(int i=listSize; i>curr; i--) // Shift elements up
            listArray[i] = listArray[i-1]; // to make room
        listArray[curr] = it;
        listSize++; // Increment list size
        }
        void append(const E& it) { // Append "it"
            Assert(listSize < maxSize, "List capacity exceeded");
            listArray[listSize++] = it;
    }

    // Remove and return the current element.
    E remove() {
        Assert((curr>=0) && (curr < listSize), "No element");
        E it = listArray[curr]; // Copy the element
        for(int i=curr; i<listSize-1; i++) // Shift them down
        listArray[i] = listArray[i+1];
        listSize--; // Decrement size
        return it;
    }

    void moveToStart() { curr = 0; } // Reset position

    void moveToEnd() { curr = listSize; } // Set at end

    void prev() { if (curr != 0) curr--; } // Back up

    void next() { if (curr < listSize) curr++; } // Next

    // Return list size
    int length() const { return listSize; }

    // Return current position
    int currPos() const { return curr; }

    // Set current list position to "pos"
    void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=listSize), "Pos out of range");
        curr = pos;
    }

    const E& getValue() const { // Return current element
        Assert((curr>=0)&&(curr<listSize),"No current element");
        return listArray[curr];
    }
};

// Linked list implementation
template <typename E> class LList: public List<E> {
    private:
    Link<E>* head; // Pointer to list header
    Link<E>* tail; // Pointer to last element
    Link<E>* curr; // Access to current element
    int cnt; // Size of list

    void init() { // Intialization helper method
        curr = tail = head = new Link<E>;
        cnt = 0;
    }

    void removeall() { // Return link nodes to free store
        while(head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

    public:
    LList(int size=defaultSize) { init(); } // Constructor
    ~LList() { removeall(); } // Destructor

    void print() { const }; // Print list contents

    void clear() { removeall(); init(); } // Clear list

    // Insert "it" at current position
    void insert(const E& it) {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr) tail = curr->next; // New tail
        cnt++;
    }
    void append(const E& it) { // Append "it" to list
        tail = tail->next = new Link<E>(it, NULL);
        cnt++;
    }

    // Remove and return current element
    E remove() {
        Assert(curr->next != NULL, "No element");
        E it = curr->next->element; // Remember value
        Link<E>* ltemp = curr->next; // Remember link node
        if (tail == curr->next) tail = curr; // Reset tail
        curr->next = curr->next->next; // Remove from list
        delete ltemp; // Reclaim space
        cnt--; // Decrement the count
        return it;
    }

    void moveToStart() // Place curr at list start
    { curr = head; }

    void moveToEnd() // Place curr at list end
    { curr = tail; }

    // Move curr one step left; no change if already at front
    void prev() {
        if (curr == head) return; // No previous element
        Link<E>* temp = head;
        // March down list until we find the previous element
        while (temp->next!=curr) temp=temp->next;
        curr = temp;
    }

    // Move curr one step right; no change if already at end
    void next() { if (curr != tail) curr = curr->next; }

    int length() const { return cnt; } // Return length

    // Return the position of the current element
    int currPos() const {
        Link<E>* temp = head;
        int i;
        for (i=0; curr != temp; i++)
        temp = temp->next;
        return i;
    }

    // Move down list to "pos" position
    void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
    }

    const E& getValue() const { // Return current element
        Assert(curr->next != NULL, "No value");
        return curr->next->element;
    }
};