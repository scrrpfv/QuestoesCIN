#include <bits/stdc++.h>

typedef struct Node {
    int value;
    Node* next;
    Node* prev;
} Node;

typedef struct list {
    Node* head;
    Node* tail;
    Node* curr;
    int size;
} List;

Node* create_node(int v) {
    Node* n = new Node;
    n->value = v;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

List* create_list() {
    List* l = new List;
    l->curr = l->tail = l->head = NULL;
    l->size = 0;
    return l;
}

void add_first(List* l, Node* n) {
    l->head = l->tail = l->curr = n;
    l->size++;
}

void add_head(List* l, Node* n) {
    if (l->head != NULL) {
        l->head->prev = n;
        n->next = l->head;
        l->head = n;
    }
    else {
        add_first(l, n);
    }
    l->size++;
}

void add_tail(List* l, Node* n) {
    if (l->tail != NULL) {
        l->tail->next = n;
        n->prev = l->tail;
        l->tail = n;
    }
    else {
        add_first(l, n);
    }
    l->size++;
}

void insert_after(List* l, Node* n) {
    if (n->prev == NULL) {
        add_tail(l, n);
    }
    else if (n->next == NULL) {
        add_head(l, n);
    }
    else {
        l->curr->next->prev = n;
        n->next = l->curr->next;
        l->curr->next = n;
        n->prev = l->curr;
        l->curr = n;
    }
    l->size++;
}

void insert_before(List* l, Node* n) {
        if (n->prev == NULL) {
        add_tail(l, n);
    }
    else if (n->next == NULL) {
        add_head(l, n);
    }
    else {
        l->curr->prev->next = n;
        n->prev = l->curr->prev;
        l->curr->prev = n;
        n->next = l->curr;
        l->curr = n;
    }
    l->size++;
}

int remove_tail(List* l) {
    int r = l->tail->value;
    if (l->tail == l->head) {
        l->tail = l->head = l->curr = NULL;
    }
    else {
        l->tail = l->tail->next;
        l->tail->prev = NULL;
    }
    free(l->tail);
    l->size--;
    return r;
}

int remove_head(List* l) {
    int r = l->tail->value;
    if (l->tail == l->head) {
        l->tail = l->head = l->curr = NULL;
    }
    else {
        l->head = l->head->prev;
        l->head->next = NULL;
    }
    free(l->tail);
    l->size--;
    return r;
}

int remove_curr(List* l) {
    Node* temp = l->curr;
    int r = l->curr->value;
    if (l->curr == NULL) {
        return NULL;
    }
    else if (l->curr->prev == NULL) {
        remove_tail(l);
        l->curr = l->tail;
    }
    else if (l->curr->next == NULL) {
        remove_head(l);
        l->curr = l->head;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        l->curr = temp->next;
    }
    free(temp);
    l->size--;
    return r;
}