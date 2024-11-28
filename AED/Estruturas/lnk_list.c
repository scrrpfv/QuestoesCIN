typedef struct E {
    int value;
} E;

typedef struct link {
    E element;
    Link* next;
} Link;

typedef struct list {
    Link head;
    Link tail;
    Link curr;
    int size;
} List;

Link create_link_(Link* nextval) {
    Link n;
    n.next = nextval;
    return n;
}

Link create_link(E it, Link* nextval) {
    Link n;
    n.element = it;
    n.next = nextval;
    return n;
}

List create_list() {
    List l;
    E none;
    l.curr = l.tail = l.head = create_link_(0);
    l.size = 0;
    return l;
}