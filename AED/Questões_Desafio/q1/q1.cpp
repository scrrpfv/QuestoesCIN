#include <bits/stdc++.h>

using namespace std;

typedef struct Link {
    Link* next;
    Link* prev;
    int is_op;
    char op;
    int value;
} Link;

typedef struct List {
    Link* head;
    Link* tail;
    Link* curr;
    int size;
} List;

void next(List* l) {
    l->curr = l->curr->next;
}

void prev(List* l) {
    l->curr = l->curr->prev;
}

void remove(List* l, Link* x) {
    if (x->prev != NULL) {
        x->prev->next = x->next;
        x->next->next->prev = x->next;
    }
    else {
        l->tail = x->next;
    }
    if (x->next != NULL) {
        x->next->prev = x->next;
    }
    l->size--;
}

List* create_list() {
    List* l = new List;
    l->curr = NULL;
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

Link* create_link(int is_op, char op, int value) {
    Link* k = new Link;
    k->next = NULL;
    k->prev = NULL;
    k->is_op = is_op;
    k->op = op;
    k->value = value;
    return k;
}

void insert_link(List* l, Link* k) {
    if (l->curr == NULL) {
        l->head = l->tail = k;
        k->prev = k->next = NULL;
    }
    else if (l->curr == l->head) {
        k->next = l->head;
        k->prev = NULL;
        l->head->prev = k;
        l->head = k;
    }
    else {
        k->prev = l->curr->prev;
        k->next = l->curr;
        l->curr->prev->next = k;
        l->curr->prev = k;
    }
    l->curr = k;

    l->size++;
}

typedef struct Stack {
    Link* top;
    int size;
} Stack;

Stack* create_stack () {
    Stack* s = new Stack;
    s->size = 0;
    s->top = NULL;
    return s;
}

void push(Stack* s, Link* l) {
    l->prev = s->top;
    s->top = l;
    s->size++;
}

Link* pop(Stack* s) {
    Link* p = s->top;
    s->top = s->top->prev;
    s->size--;
}

int main() {
    string str;
    cin >> str;

    Stack* s = create_stack();
    List* l = create_list();

    for (char& c : str) {
        if (c != '(') {
            if (c == '+' | c == '-' | c == '/' | c == '*' | c == '^') {
                Link* x = create_link(1, c, 0);
                push(s, x);
            }
            else if (c == ')') {
                l->curr = l->head;
                insert_link(l, pop(s));
            }
            else {
                l->curr = l->head;
                int ic = c - '0';
                Link* x = create_link(0, ' ', ic);
                insert_link(l, x);
            }
        }
    }
}