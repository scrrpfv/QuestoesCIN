#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

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
        free(temp);
    }
    return x;
}


void solve(int z) {
    Stack* s = create_stack();
    int x, d;
    cin >> x;
    while (x != 0) {
        push(s, x);
        while (s->size > 1 && s->top->value%2 == s->top->prev->value%2) {
            d = abs(pop(s) - pop(s));
            if (d != 0) push(s, d);
        }
        cin >> x;
    }
    if (s->size > 0) {
        cout << "Pilha " << z << ": " << s->size << " " << s->top->value << endl;
    }
    else {
        cout << "Pilha " << z << ": 0 -1" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i+1);
    }
    return 0;
}
