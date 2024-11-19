#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

typedef struct graph {
    vector<vector<int>> adj;
    vector<int> mark;
    vector<int> pred;
} graph;

graph* create_graph(int size) {
    graph* g = new graph;
    g->adj.resize(size);
    g->mark.resize(size);
    g->pred.resize(size);
    return g;
}

void traceback(graph* g, int v, int start) {
    vector<int> path;
    while (v != start) {
        path.insert(path.begin(), v);
        v = g->pred[v];
    }
    path.insert(path.begin(), v);
    for (int i = 0; i < path.size() - 1; i++) {
        cout << path[i] << " ";
    }
    cout << path[path.size() - 1] << endl;
}

void BFS(graph* g, int start, int end) {
    if (start == end) {
        cout << start << endl;
        return;
    }
    queue<int> q;
    q.push(start);
    g->mark[start] = 1;
    while (q.size() > 0) {
        int v = q.front();
        q.pop();
        for (int w : g->adj[v]) {
            if (!g->mark[w]) {
                g->mark[w] = 1;
                g->pred[w] = v;
                if (w == end) {
                    traceback(g, w, start);
                    return;
                }
                q.push(w);
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    int c; cin >> c;
    for (int i = 0; i < c; i++) {
        cout << "Caso " << i + 1 << endl;
        int v, a; cin >> v >> a;
        graph* g = create_graph(v);

        for (int j = 0; j < a; j++) {
            int v1, v2; cin >> v1 >> v2;

            g->adj[v1].push_back(v2);
            g->adj[v2].push_back(v1);
        }

        for (int j = 0; j < v; j++) {
            sort(g->adj[j].begin(), g->adj[j].end());
        }
        
        int p; cin >> p;
        
        for (int j = 0; j < p; j++) {
            fill(g->pred.begin(), g->pred.end(), -1);
            fill(g->mark.begin(), g->mark.end(), 0);
            int v1, v2; cin >> v1 >> v2;
            BFS(g, v1, v2);
        }
    }
}