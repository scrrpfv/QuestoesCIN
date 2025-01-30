#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

typedef struct E {
    int ID;
    int WEI;
    int RNK;
} E;

typedef struct node {
    E* e;
    node* right;
    node* left;
    int height;
} node;

typedef struct AVL {
    node* root;
    int size;
} AVL;

node* create_node(E* e) {
    node* n = new node;
    n->e = e;
    n->left = n->right = nullptr;
    return n;
}

AVL* create_AVL() {
    AVL* avl = new AVL;
    avl->root = nullptr;
    avl->size = 0;
    return avl;
}

node* findhelp(node* rt, int ID) {
    if (rt == nullptr) { return nullptr; }
    if (rt->e->ID > ID) {
        return findhelp(rt->left, ID);
    } else if (rt->e->ID < ID) {
        return findhelp(rt->right, ID);
    } else {
        return rt;
    }
}

node* find(AVL* avl, int ID) {
    return findhelp(avl->root, ID);
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

node* inserthelp(node* rt, E* e) {
    if (rt == nullptr) { return create_node(e); }
    if (rt->e->ID > e->ID) {
        rt->left = inserthelp(rt->left, e);
    } else {
        rt->right = inserthelp(rt->right, e);
    }
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);

    // Left-Left
    if (balance > 1 && e->ID < rt->left->e->ID) {
        return rightRotate(rt);
    }
    // Right-Right
    if (balance < -1 && e->ID >= rt->right->e->ID) {
        return leftRotate(rt);
    }
    // Left-Right
    if (balance > 1 && e->ID >= rt->left->e->ID) {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    // Right-Left
    }
    if (balance < -1 && e->ID < rt->right->e->ID) {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;
}

void insert(AVL* avl, E* e) {
    avl->root = inserthelp(avl->root, e);
    avl->size++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    AVL* avl = create_AVL();

    int total = 0;

    string consulta;
    cin >> consulta;
    int ID, w;
    while (consulta != "END") {
        cin >> ID;
        if (consulta == "ADD") {
            cin >> w;
            total += w;

            cout << total << endl;

            node* nd = find(avl, ID);
            if (nd != NULL) {
                nd->e->WEI += w;
            }
            else {
                E* e = new E;
                e->ID = ID;
                e->WEI = w;
                insert(avl, e);
            }
        }
        else if (consulta == "WEI") {
            node* nd = find(avl, ID);
            if (nd != NULL) {
                int depth = (avl->root->height - 1) - nd->height;
                cout << nd->e->WEI << " " << depth << endl;
            }
            else {
                cout << "0 -1" << endl;
            }
        }
        else if (consulta == "RNK") {
            
        }
        cin >> consulta;
    }

    return 0;
}
