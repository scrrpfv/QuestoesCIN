#include <bits/stdc++.h>

using namespace std;

typedef struct link_int {
    char op;
    int isint;
    int element;
    Link* next;
    Link* previous;
} Link;

typedef struct list {
    Link head;
    Link tail;
    Link curr;
    int size;
} List;

