#include <bits/stdc++.h>
#include <sstream>

using namespace std;

#define endl "\n"

// Definição Stack
typedef struct Node {
    Node* prev;
    int value;
} Node;

typedef struct Stack {
    Node* head;
    Node* top;
    int size;
} Stack;

Node* newnode(int value) {
    Node* node = new Node;
    node->value = value;
    node->prev = NULL;
    return node;
}

void push(Stack* s, int value) {
    Node* n = newnode(value);
    if (s->size == 0) {
        n->prev = s->head;
    }
    else {
        n->prev = s->top;
    }
    s->top = n;
    s->size++;
}

Stack* create_stack() {
    Stack* s = new Stack;
    s->head = s->top = NULL;
    s->size = 0;
    return s;
}

int pop(Stack* s) {
    int x = 0;
    if (s->size > 0) {
        Node* temp = s->top;
        x = s->top->value;
        if (s->size > 1) {
            s->top = s->top->prev;
        }
        else {
            s->top = s->head;
        }
        s->size--;
        delete temp;
    }
    return x;
}

// Definição Lista
typedef struct lNode {
    Stack* stack;
    lNode* next;
    lNode* prev;
} lNode;

typedef struct List {
    lNode* head;
    lNode* tail;
    int size;
} List;

lNode* create_lNode() {
    lNode* n = new lNode;
    n->stack = create_stack();
    n->next = NULL;
    n->prev = NULL;
    return n;
}

List* create_list() {
    List* l = new List;
    l->tail = l->head = NULL;
    l->size = 0;
    return l;
}

void add_first(List* l, lNode* n) {
    l->head = l->tail = n;
    l->size++;
}

void add_head(List* l, lNode* n) {
    if (l->head != NULL) {
        l->head->prev = n;
        n->next = l->head;
        l->head = n;
    }
    else {
        add_first(l, n);
        return;
    }
    l->size++;
}

void add_tail(List* l, lNode* n) {
    if (l->tail != NULL) {
        l->tail->next = n;
        n->prev = l->tail;
        l->tail = n;
    }
    else {
        add_first(l, n);
        return;
    }
    l->size++;
}

void remove_tail(List* l) {
    if (l->tail == NULL) return;
    lNode* r = l->tail;
    if (l->tail == l->head) {
        l->tail = l->head = NULL;
    }
    else {
        l->tail = l->tail->prev;
        l->tail->next = NULL;
    }
    delete r->stack;
    delete r;
    l->size--;
}

void remove_head(List* l) {
    if (l->head == NULL) return;
    lNode* r = l->head;
    if (l->tail == l->head) {
        l->head = l->tail = NULL;
    }
    else {
        l->head = l->head->next;
        l->head->prev = NULL;
    }
    delete r->stack;
    delete r;
    l->size--;
}

lNode* access(List* l, int pos) {
    lNode* x = l->head;
    for (int i = 0; i < pos; i++) {
        x = x->next;
    }
    return x;
}

void remove(List* l, lNode* n) {
    if (l->size == 1) {
        l->head = l->tail = NULL;
    }
    else {
        if (n->next != NULL) {
            n->next->prev = n->prev;
        }
        else {
            l->tail = n->prev;
        }
        if (n->prev != NULL) {
            n->prev->next = n->next;
        }
        else {
            l->head = n->next;
        }
    }
    delete n;
    l->size--;
}

void solve(int p) {
    string line;
    int S, C;
    List* l = create_list();
    cin >> line;
    while (line != "END") {
        istringstream is(line);
        is >> S;
        cin >> C;

        if (S == 0) {
            add_head(l, create_lNode());
        }
        else if (S > l->size) {
            add_tail(l, create_lNode());
        }
        lNode* n = access(l, S-1);
        if (n->stack->size > 0 && n->stack->top->value == C) {
            pop(n->stack);
            if (n->stack->size == 0) {
                remove(l, n);
            }
        }
        else {
            push(n->stack, C);
        }
        cin >> line;
    }
    cout << "caso " << p << ":";
    lNode* m = l->head;
    while (m != NULL) {
        cout << " " << m->stack->top->value;
        m = m->next;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        solve(i);
    }
    return 0;
}
