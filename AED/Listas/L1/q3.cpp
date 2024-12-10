#include <bits/stdc++.h>
#include <sstream>

using namespace std;

#define endl "\n"

typedef struct Node {
    string key;
    int e;
    Node* right;
    Node* left;
} Node;

typedef struct BST {
    Node* root;
    int size;
} BST;

Node* create_Node(string k, int e) {
    Node* n = new Node;
    n->key = k;
    n->e = e;
    n->left = n->right = NULL;
    return n;
}

BST* create_BST() {
    BST* bst = new BST;
    bst->root = NULL;
    bst->size = 0;
    return bst;
}

Node* inserthelp(Node* rt, string k, int e) {
    if (rt == NULL) { return create_Node(k, e); }
    if (rt->e > e) {
        rt->left = inserthelp(rt->left, k, e);
    } else {
        rt->right = inserthelp(rt->right, k, e);
    }
    return NULL;
}

void insert(BST* bst, string k, int e) {
    bst->root = inserthelp(bst->root, k, e);
    bst->size++;
}

Node* getmin(Node* rt) {
    if (rt->left == NULL) return rt;
    return getmin(rt->left);
}

Node* getmax(Node* rt) {
    if (rt->right == NULL) return rt;
    return getmin(rt->right);
}

Node* succ(Node* rt, int e) {
    if (rt == NULL)
        return NULL;
    if (rt->e == e && rt->right != NULL)
        return getmin(rt->right);
    Node* succ = NULL;
    Node* curr = rt; 
    while (curr != NULL) {
        if (e < curr->e) {
            succ = curr;
            curr = curr->left;
        }
        else if (e >= curr->e)
            curr = curr->right;
        else 
            break;
    }
    return succ;
}

Node* pred(Node* rt, int e) {
    if (rt == NULL)
        return NULL;
    if (rt->e == e && rt->left != NULL)
        return getmax(rt->left);
    Node* succ = NULL;
    Node* curr = rt; 
    while (curr != NULL) {
        if (e > curr->e) {
            succ = curr;
            curr = curr->right;
        }
        else if (e <= curr->e)
            curr = curr->left;
        else {
            break;
        }
    }
    return succ;
}

Node* findhelp(Node* rt, int k) {
    if (rt == NULL) { return NULL; }
    if (rt->e > k) {
        return findhelp(rt->left, k);
    } else if (rt->e < k) {
        return findhelp(rt->right, k);
    } else {
        return rt;
    }
}

Node* find(BST* bst, int k) {
    return findhelp(bst->root, k);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    BST* bst = create_BST();
    int K, p;
    string cmd, nome;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> cmd;
        if (cmd == "ADD") {
            cin >> nome >> p;
            if (find(bst, p)) {
                cout << nome << " ja esta no sistema." << endl;
            }
            else {
                insert(bst, nome, p);
                cout << nome << " inserido com sucesso!" << endl;
            }
        }
        else if (cmd == "PROX") {
            cin >> p;
            string n = find(bst, p)->key;
            Node* suc = succ(bst->root, p);
            Node* pre = pred(bst->root, p);
            if (suc == NULL && pre == NULL) {
                cout << "Apenas " << n << " existe no sistema..." << endl;
            }
            else if (pre == NULL) {
                cout << n << " e o menor! e logo apos vem " << suc << endl;
            }
            else if (suc == NULL) {
                cout << n << " e o maior! e logo atras vem " << pre << endl;
            }
            else {
                cout << n << " vem apos " << pre << " e antes de " << suc << endl;
            }
        }
    }

    return 0;
}
