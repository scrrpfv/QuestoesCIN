#include <bits/stdc++.h>

using namespace std;

typedef struct E {
    int key;
    int value;
    int idx;
} E;

typedef struct dict {
    int m;
    int n;
    E **H;
    int *perm;
} Dict;

 int h(int key, int mod) {
    int temp = (int) floor((((double) key) / ((double) mod)));
    return (key - (mod * temp));
 }

Dict* create_dict(int size, int* perm) {
    Dict* d = new Dict;
    d->m = size;
    d->n = 0;
    d->H = new E*[size];
    d->perm = perm;
    return d;
}

E* create_entry(int key, int value) {
    E* e = new E;
    e->key = key;
    e->value = value;
    return e;
}

E* find(Dict *d, int k) {
    int pos;
    int i;
    if (d->n < d->m) {
        pos = h(k, d->m);
        if (d->H[pos] == NULL) {
            int newPos;
            i = 0;
            do {
                i++;
                int offset = d->perm[i-1];
                newPos = (pos + offset)%d->m;
            } while (d->H[newPos] != NULL);
            pos = newPos;
        }
    }
    E *e = d->H[pos];
    return e;
}

void insert(Dict *d, int k, int e) {
    if (d->n < d->m && find(d, k) == NULL) {
        int i;
        int pos = h(k, d->m);
        if (d->H[pos] != NULL) {
            i = 0;
            int newPos;
            do {
                i++;
                int offset = d->perm[i-1];
                newPos = (pos + offset)%d->m;
            } while (d->H[newPos] != NULL);
            pos = newPos;
        }
        E* entry = create_entry(k, e);
        entry->idx = i;
        d->H[pos] = entry;
        d->n++;
    }
}

int main() {
    int m;
    cin >> m;
    int perm[m-1];
    for (int i = 0; i < m - 1; i++) {
        cin >> perm[i];
    }

    Dict *d = create_dict(m, perm);

    E *e = create_entry(10, 5);
    insert(d, 10, 5);
    E *a = find(d, 10);
    cout << a->value;
    cout << a->idx;

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        char op[4];
        cin >> op;
        if (op[0] == 'a') {
            int key, value;
            cin >> key >> value;
            insert(d, key, value);
        } else {
            int key;
            cin >> key;
            E *e = find(d, key);
            int a = e->idx;
            int b = e->value;
            cout << a << b;
        }
    }
}