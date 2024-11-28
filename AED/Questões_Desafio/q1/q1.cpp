#include <bits/stdc++.h>

using namespace std;

typedef struct iLink {
    iLink* next;
    iLink* prev;
    int element;
} iLink;

typedef struct List {
    iLink* head;
    iLink* tail;
    iLink* curr;
    int size;
} List;

typedef struct sLink {
    sLink* next;
    char op;
} sLink;

typedef struct Stack {
    sLink* top;
    int size;
} Stack;

void next(List* l) {
    l->curr = l->curr->next;
}

void prev(List* l) {
    l->curr = l->curr->prev;
}

void remove_curr(List* l) {
    Link* to_remove = l->curr;

    if (l->head == l->tail) {
        l->head = l->tail = l->curr = NULL;
    }
    else {
        if (l->curr == l->head) {
            l->head = l->curr->next;
            l->head->prev = NULL;
        }
        else if (l->curr == l->tail) {
            l->tail = l->curr->prev;
            l->tail->next = NULL;
        }
        else {
            l->curr->prev->next = l->curr->next;
            l->curr->next->prev = l->curr->prev;
        }
    }
}

List* create_list() {
    List* l = (List*)malloc(sizeof(List));
    l->curr = NULL;
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

Link* create_link(char op, int element) {
    Link* k = (Link*)malloc(sizeof(Link));
    k->next = NULL;
    k->prev = NULL;
    k->element = element;
    k->op = op;
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

int main() {
    string str;
    cin >> str;


}