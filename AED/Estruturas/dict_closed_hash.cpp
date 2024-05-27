#include <bits/stdc++.h>

using namespace std;

typedef struct E {
    int value;
} E;

typedef struct dict {
    int m;
    int n;
    int* H;
    int (*h)(int);
} Dict;

int h_int(int key) {
    return abs(key)%10;
}

Dict* create_dict(int size, int (*h)(int)) {
    Dict* d;
    d->m = size;
    d->H = new int[size];
    d->h = h;
    return d;
}

void insert(Dict *d, int k, E e) {
    
}
