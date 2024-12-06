#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

typedef struct Node {
    Node* prev;
    int value;
    int size;
} Node;

void push(Node*& top, int value) {
    Node* node = new Node;
    node->prev = top;
    node->value = value;
    node->size = top->size + 1;
    top = node;
}

Node* create_stack() {
    Node* stack = new Node;
    stack->prev = NULL;
    stack->value = 0;
    stack->size = 0;
    return stack;
}

int pop(Node*& top) {
    int x = top->value;
    Node* temp = top;
    top = top->prev;
    return x;
}

void solve(int z) {
    Node* stack = create_stack();
    int x, d;
    cin >> x;
    while (x != 0) {
        push(stack, x);
        while (stack->prev->prev != NULL && stack->value%2 == stack->prev->value%2) {
            d = abs(pop(stack) - pop(stack));
            push(stack, d);
        }
        cin >> x;
    }
    cout << "Pilha " << z << ": " << stack->size << " " << stack->value << endl;
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
