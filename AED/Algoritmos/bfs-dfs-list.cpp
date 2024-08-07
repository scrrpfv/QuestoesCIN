#include <bits/stdc++.h>

using namespace std;

typedef struct graph {
    vector<vector<int>> adj;
    vector<int> mark;
} graph;

graph* create_graph(int size) {
    graph* g = new graph;
    g->adj.resize(size);
    g->mark.resize(size);
    return g;
}

void BFS(graph* g, int start) {
    queue<int> q;
    q.push(start);
    g->mark[start] = 1;
    while (q.size() > 0) {
        int v = q.front();
        q.pop();
        for (auto w : g->adj[v]) {
            if (!g->mark[w]) {
                g->mark[w] = 1;
                q.push(w);
            }
        }
    }
}

void DFS(graph* g, int v) {
    g->mark[v] = 1;
    for (auto w : g->adj[v]) {
        if (!g->mark[w]) {
            DFS(g, w);
        }
    }
}