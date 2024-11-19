#include <bits/stdc++.h>

using namespace std;

#define keytype int

typedef struct node {
    keytype key;
    node* right;
    node* left;
} node;

typedef struct BST {
    node* root;
    int size;
} BST;

node* create_node(keytype k) {
    node* n = new node;
    n->key = k;
    n->left = n->right = nullptr;
    return n;
}

BST* create_BST() {
    BST* bst = new BST;
    bst->root = nullptr;
    bst->size = 0;
    return bst;
}

void insert(BST* bst, keytype k) {
    bst->root = inserthelp(bst->root, k);
    bst->size++;
}

node* inserthelp(node* rt, keytype k) {
    if (rt == nullptr) { return create_node(k); }
    if (rt->key > k) {
        rt->left = inserthelp(rt->left, k);
    } else {
        rt->right = inserthelp(rt->right, k);
    }
}

void preorder(node* rt) {
    if (rt != nullptr) {
        cout << rt->key << " ";
    }
    preorder(rt->left);
    preorder(rt->right);
}

void inorder(node* rt) {
    inorder(rt->left);
    if (rt != nullptr) {
        cout << rt->key << " ";
    }
    inorder(rt->right);
}

void posorder(node* rt) {
    posorder(rt->left);
    posorder(rt->right);
    if (rt != nullptr) {
        cout << rt->key << " ";
    }
}

void main() {
    BST* bst = create_BST();
    
    int n;
    cin >> n;

    for (int i = 0; i<n; i++) {
        string input;
        cin >> input;
    }
}