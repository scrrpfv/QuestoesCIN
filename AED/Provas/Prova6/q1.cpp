#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

typedef struct duo {
    int idx;
    int weight;
} duo;

typedef struct edge {
    int v1;
    int v2;
    int w;
} edge;

typedef struct graph {
    vector<vector<duo>> adj;
    vector<int> mark;
    int size;
} graph;

graph* create_graph(int size) {
    graph* g = new graph;
    g->adj.resize(size);
    g->mark.resize(size);
    g->size = size;
    return g;
}

bool edge_comp(edge e1, edge e2) {
    return e1.w > e2.w;
}

int soma(vector<int> v, int size) {
    int c = 0;
    for (int i = 0; i < size; i++) {
        c += v[i];
    }
    return c;
}

int Prim(graph* g, vector<int> D, vector<int> V) {
    for (int i = 0; i < g->size; i++) {
        D[i] = INT_MAX;
        V[i] = -1;
    }
    edge e; e.v1 = e.v2 = e.w = 0;
    vector<edge> h;
    h.push_back(e);
    D[0] = 0;
    for (int i = 0; i < g->size; i++) {
        int v, p;
        do {
            pop_heap(h.begin(), h.end(), edge_comp);
            p = h.back().v1;
            v = h.back().v2;
            h.pop_back();
        } while (g->mark[v] != 0);
        g->mark[v] = 1;
        V[v] = p;
        for (auto w : g->adj[v]) {
            if (g->mark[w.idx] != 1 && D[w.idx] > w.weight) {
                D[w.idx] = w.weight;
                e.v1 = v;
                e.v2 = w.idx;
                e.w = D[w.idx];
                h.push_back(e);
                push_heap(h.begin(), h.end(), edge_comp);
            }
        }
    }
    return soma(D, g->size);
}

int main() {
    int i = 1;
    while (true) {
        int c, o;
        cin >> c >> o;
        if (c == 0) return 0;

        graph* g = create_graph(c);
        for (int i = 0; i < o; i++) {
            int v1;
            int v2;
            int w;
            cin >> v1 >> v2 >> w;
            duo d1, d2;
            d1.idx = v2;
            d2.idx = v1;
            d1.weight = d2.weight = w;
            g->adj[v1].push_back(d1);
            g->adj[v2].push_back(d2);
        }
        vector<int> D;
        vector<int> V;
        D.resize(o);
        V.resize(o);
        int cost = Prim(g, D, V);

        cout << "Caso " << i << ": " << cost << endl;
        i++;
    }
}