#include <bits/stdc++.h>

using namespace std;

#define keytype int

bool first;

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

node* inserthelp(node* rt, keytype k) {
    if (rt == nullptr) { return create_node(k); }
    if (rt->key > k) {
        rt->left = inserthelp(rt->left, k);
    } else {
        rt->right = inserthelp(rt->right, k);
    }
    return rt;
}

void insert(BST* bst, keytype k) {
    bst->root = inserthelp(bst->root, k);
    bst->size++;
}

void preorder(node* rt) {
    if (rt != nullptr) {
        if (!first) {
            cout << " ";
        }
        cout << rt->key;
        first = false;
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(node* rt) {
    if (rt != nullptr) {
        inorder(rt->left);
        if (!first) {
            cout << " ";
        }
        cout << rt->key;
        first = false;
        inorder(rt->right);
    }
}

void posorder(node* rt) {
    if (rt != nullptr) {
        posorder(rt->left);
        posorder(rt->right);
        if (!first) {
            cout << " ";
        }
        cout << rt->key;
        first = false;
    }
}

int main() {
    BST* bst = create_BST();
    
    int n;
    cin >> n;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        insert(bst, k);
    }

    first = true;
    cout << "Pre order : ";
    preorder(bst->root);
    cout << endl;

    first = true;
    cout << "In order  : ";
    inorder(bst->root);
    cout << endl;
    
    first = true;
    cout << "Post order: ";
    posorder(bst->root);
    cout << endl;

    return 0;
}