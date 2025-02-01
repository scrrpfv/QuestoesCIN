#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

typedef struct node {
    int ID;
    int WEI;
    node* right;
    node* left;
    int height;
} node;

typedef struct AVL {
    node* root;
} AVL;

node* create_node(int ID, int WEI) {
    node* n = new node;
    n->ID = ID;
    n->WEI = WEI;
    n->left = n->right = NULL;
    return n;
}

AVL* create_AVL() {
    AVL* avl = new AVL;
    avl->root = NULL;
    return avl;
}

node* findhelp(node* rt, int ID) {
    if (rt == NULL) { return NULL; }
    if (rt->ID > ID) {
        return findhelp(rt->left, ID);
    } else if (rt->ID < ID) {
        return findhelp(rt->right, ID);
    } else {
        return rt;
    }
}

node* find(AVL* avl, int ID) {
    return findhelp(avl->root, ID);
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

node* inserthelp(node* rt, int ID, int WEI) {
    if (rt == NULL) { return create_node(ID, WEI); }
    if (rt->ID > ID) {
        rt->left = inserthelp(rt->left, ID, WEI);
    } else {
        rt->right = inserthelp(rt->right, ID, WEI);
    }
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);

    // Left-Left
    if (balance > 1 && ID < rt->left->ID) {
        return rightRotate(rt);
    }
    // Right-Right
    if (balance < -1 && ID >= rt->right->ID) {
        return leftRotate(rt);
    }
    // Left-Right
    if (balance > 1 && ID >= rt->left->ID) {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    // Right-Left
    }
    if (balance < -1 && ID < rt->right->ID) {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;
}

void insert(AVL* avl, int ID, int WEI) {
    avl->root = inserthelp(avl->root, ID, WEI);
}

int getdepth(AVL* avl, int ID) {
    int d = 0;
    node* rt = avl->root;
    while (rt != NULL) {
        if (rt->ID > ID) {
            rt = rt->left;
        } else if (rt->ID < ID){
            rt = rt->right;
        } else return d;
        d++;
    }
    return -1;
}

int getrnk_help(AVL* avl, node* rt, int ID) {
    int x = 0;
    if (rt != NULL) {
        if (rt->ID < ID) {
            x = rt->WEI;
            x += getrnk_help(avl, rt->right, ID);
        }
        x += getrnk_help(avl, rt->left, ID);
    }
    return x;
}

int getrnk(AVL* avl, int ID) {
    int rnk = 0;
    rnk += getrnk_help(avl, avl->root, ID);
    return rnk;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    AVL* avl = create_AVL();

    int total = 0;

    string consulta;
    cin >> consulta;
    int ID, WEI;
    while (consulta != "END") {
        cin >> ID;
        if (consulta == "ADD") {
            cin >> WEI;
            total += WEI;

            cout << total << endl;

            node* nd = find(avl, ID);
            if (nd != NULL) {
                nd->WEI += WEI;
            }
            else {
                insert(avl, ID, WEI);
            }
        }
        else if (consulta == "WEI") {
            node* nd = find(avl, ID);
            if (nd != NULL) {
                int depth = getdepth(avl, ID);
                cout << nd->WEI << " " << depth << endl;
            }
            else {
                cout << "0 -1" << endl;
            }
        }
        else if (consulta == "RNK") {
            node* rt = find(avl, ID);
            int RNK = getrnk(avl, ID);
            cout << RNK << endl;
        }
        cin >> consulta;
    }

    return 0;
}
