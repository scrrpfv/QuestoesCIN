#include <bits/stdc++.h>

using namespace std;

typedef struct E {
    string key;
    int value;
    int idx;
} E;

typedef struct dict {
    int m;
    int n;
    E **H;
} Dict;

 int h(string key, int mod) {
    int hash = 19;
    for (int i = 0; i < key.size(); i++) {
        hash *= int(key[i]) * i;
    }
    return hash;
 }

Dict* create_dict(int size) {
    Dict* d = new Dict;
    d->m = size;
    d->n = 0;
    d->H = new E*[size];
    return d;
}

E* create_entry(string key, int value) {
    E* e = new E;
    e->key = key;
    e->value = value;
    return e;
}

E* find(Dict *d, string k) {
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
            } while (d->H[newPos]->key != k);
            pos = newPos;
        }
    }
    E *e = d->H[pos];
    return e;
}

void insert(Dict *d, string k, int e) {
    if (d->n < d->m && find(d, k) == NULL) {
        int i;
        int pos = h(k, d->m);
        if (d->H[pos] != NULL) {
            i = 0;
            int newPos;
            do {
                i++;
                int offset = 0;
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

}