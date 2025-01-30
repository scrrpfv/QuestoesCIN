#include<bits/stdc++.h>

#define keytype int

using namespace std;

typedef struct E {
    int v;
} E;

typedef struct node {
    keytype key;
    E* e;
    node* right;
    node* left;
    int height;
} node;

typedef struct BST {
    node* root;
    int size;
} BST;

node* create_node(keytype k, E* e) {
    node* n = new node;
    n->key = k;
    n->e = e;
    n->left = n->right = nullptr;
    return n;
}

BST* create_BST() {
    BST* bst = new BST;
    bst->root = nullptr;
    bst->size = 0;
    return bst;
}

E* find(BST* bst, keytype k) {
    return findhelp(bst->root, k);
}

E* findhelp(node* rt, keytype k) {
    if (rt == nullptr) { return nullptr; }
    if (rt->key > k) {
        return findhelp(rt->left, k);
    } else if (rt->key < k) {
        return findhelp(rt->right, k);
    } else {
        return rt->e;
    }
}

void insert(BST* bst, keytype k, E* e) {
    bst->root = inserthelp(bst->root, k, e);
    bst->size++;
}

int getBalance(node* rt) {
    if (rt == nullptr) {
        return 0;
    }
    return h(rt->left) - h(rt->right);
}

int h(node* rt) {
    if (rt == nullptr) {
        return -1;
    }
    return rt->height;
}

node* rightRotate(node* rt) {
    node* l = rt->left;
    node* lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    return l;
}

node* leftRotate(node* rt) {
    node* r = rt->right;
    node* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    return r;
}

node* inserthelp(node* rt, keytype k, E* e) {
    if (rt == nullptr) { return create_node(k, e); }
    if (rt->key > k) {
        rt->left = inserthelp(rt->left, k, e);
    } else {
        rt->right = inserthelp(rt->right, k, e);
    }
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);

    if (balance < -1 && k >= rt->right->key) {
        return leftRotate(rt);
    }
    if (balance > 1 && k < rt->left->key) {
        return rightRotate(rt);
    }
    if (balance > 1 && k >= rt->left->key) {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if (balance < -1 && k < rt->right->key) {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }
    return rt;
}

E* remove(BST* bst, keytype k) {
    E* temp = findhelp(bst->root, k);
    if (temp != nullptr) {
        bst->root = removehelp(bst->root, k);
        bst->size--;
    }
}

node* removehelp(node* rt, keytype k) {
    if (rt == nullptr) { return nullptr; }
    if (rt->key > k) {
        rt->left = removehelp(rt->left, k);
    } else if (rt->key < k) {
        rt->right = removehelp(rt->right, k);
    } else {
        if (rt->left == nullptr) { return rt->right; }
        else if (rt->right == nullptr) { return rt->left; }
        else {
            node* temp = getmin(rt->right);
            rt->e = temp->e;
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }
    }
    return rt;
}

node* getmin(node* rt) {
    if (rt->left == nullptr) { return rt; }
    return getmin(rt->left);
}

node* deletemin(node* rt) {
    if (rt->left == nullptr) { return rt->right; }
    rt->left = deletemin(rt->left);
    return rt;
}

void preorder(node* rt) {
    if (rt != nullptr) {
        //do something
    }
    preorder(rt->left);
    preorder(rt->right);
}

void inorder(node* rt) {
    inorder(rt->left);
        if (rt != nullptr) {
        //do something
    }
    inorder(rt->right);
}

void posorder(node* rt) {
    posorder(rt->left);
    posorder(rt->right);
        if (rt != nullptr) {
        //do something
    }
}

int main() {
    return 0;
}