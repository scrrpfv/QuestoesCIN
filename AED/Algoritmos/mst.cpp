#include <bits/stdc++.h>

using namespace std;

typedef struct graph {
    vector<vector<int>> adj;
    vector<int> mark;
    vector<int> pred;
    int size;
} graph;

void Prim(graph* g, vector<int> d, vector<int> v) {
    for (int i = 0; i < g->size; i++) {
        d[i] = INT_MAX;
        v[i] = -1;
    }
    vector<int> heap = {0, 0, 0};
    make_heap(heap.begin(), heap.end(), greater<>{});
    d[0] = 0;

}