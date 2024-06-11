#define keytype int

typedef struct E {
    int v;
} E;

typedef struct node {
    keytype key;
    E* e;
    node* right;
    node* left;
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

node* inserthelp(node* rt, keytype k, E* e) {
    if (rt == nullptr) { return create_node(k, e); }
    if (rt->key > k) {
        rt->left = inserthelp(rt->left, k, e);
    } else {
        rt->right = inserthelp(rt->right, k, e);
    }
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