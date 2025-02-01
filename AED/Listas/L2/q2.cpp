#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

# define int long long int

typedef struct node {
    int T;
    int C;
    int idx;
    node* right;
    node* left;
    int height;
} node;

typedef struct AVL {
    node* root;
    int size;
} AVL;

node* create_node(int T, int C, int idx) {
    node* n = new node;
    n->T = T;
    n->C = C;
    n->idx = idx;
    n->left = n->right = NULL;
    return n;
}

AVL* create_AVL() {
    AVL* avl = new AVL;
    avl->root = NULL;
    avl->size = 0;
    return avl;
}

node* findhelp(node* rt, int T) {
    if (rt == NULL) { return NULL; }
    if (rt->T > T) {
        return findhelp(rt->left, T);
    } else if (rt->T < T) {
        return findhelp(rt->right, T);
    } else {
        return rt;
    }
}

node* find(AVL* avl, int T) {
    return findhelp(avl->root, T);
}

int h(node* rt) {
    if (rt == NULL) {
        return -1;
    }
    return rt->height;
}

int getBalance(node* rt) {
    if (rt == NULL) {
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

node* inserthelp(node* rt, int T, int C, int size) {
    if (rt == NULL) { return create_node(T, C, size); }
    if (rt->T > T) {
        rt->left = inserthelp(rt->left, T, C, size);
    } else {
        rt->right = inserthelp(rt->right, T, C, size);
    }
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);

    // Left-Left
    if (balance > 1 && T < rt->left->T) {
        return rightRotate(rt);
    }
    // Right-Right
    if (balance < -1 && T >= rt->right->T) {
        return leftRotate(rt);
    }
    // Left-Right
    if (balance > 1 && T >= rt->left->T) {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    // Right-Left
    }
    if (balance < -1 && T < rt->right->T) {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;
}

void insert(AVL* avl, int T, int C) {
    avl->root = inserthelp(avl->root, T, C, avl->size);
    avl->size++;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    AVL* avl = create_AVL();

    string event;
    int T, C;
    cin >> event;
    while (event != "END") {
        cin >> T;
        if (event == "NEW") {
            cin >> C;
            insert(avl, T, C);
        }
        else {
            node* nd = find(avl, T);
            if (nd != NULL) {
            cout << nd->C << " " << nd->idx << endl;
            }
            else cout << "-1 -1" << endl;
        }
        cin >> event;
    }

    return 0;
}
