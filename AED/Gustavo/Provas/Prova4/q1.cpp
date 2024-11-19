#include<bits/stdc++.h>

#define keytype int

#define endl '\n'

using namespace std;

typedef struct node {
    keytype key;
    node* right;
    node* left;
    int height;
} node;

typedef struct AVL {
    node* root;
    int size;
} AVL;

node* create_node(keytype k) {
    node* n = new node;
    n->key = k;
    n->left = n->right = nullptr;
    return n;
}

AVL* create_AVL() {
    AVL* bst = new AVL;
    bst->root = nullptr;
    bst->size = 0;
    return bst;
}

int h(node* rt) {
    if (rt == nullptr) {
        return -1;
    }
    return rt->height;
}

int getBalance(node* rt) {
    if (rt == nullptr) {
        return 0;
    }
    return h(rt->left) - h(rt->right);
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

node* inserthelp(node* rt, keytype k) {
    if (rt == nullptr) { return create_node(k); }
    if (rt->key > k) {
        rt->left = inserthelp(rt->left, k);
    } else {
        rt->right = inserthelp(rt->right, k);
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

void insert(AVL* bst, keytype k) {
    bst->root = inserthelp(bst->root, k);
    bst->size++;
}

void preorder(node* rt) {
    if (rt != nullptr) {
        cout << rt->key << endl;
        preorder(rt->left);
        preorder(rt->right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int n;
        cin >> n;
        AVL *avl = create_AVL();
        for (int j = 0; j < n; j++) {
            int newkey;
            cin >> newkey;
            insert(avl, newkey);
        }
        preorder(avl->root);
        cout << "END" << endl;
    }
    return 0;
}