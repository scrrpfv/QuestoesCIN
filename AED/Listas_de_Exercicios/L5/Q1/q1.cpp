#include <bits/stdc++.h>

using namespace std;

typedef struct graph {
    vector<vector<int>> adj;
    vector<int> mark;
} graph;

typedef struct contestant {
    string name;
    int rank;
} contestant;

graph* create_graph() {
    graph* g = new graph;
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

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<contestant> list;
        graph* g = create_graph();

        for (int j = 0; j < n; j++) {
            string group[3];
            cin >> group[0] >> group[1] >> group[2];

            for (string p : group) {
                if (find(list.begin(), list.end(), p) == list.end()) {
                    contestant newc;
                    newc.name = p;
                    list.push_back(newc);
                }
            }
        }
    }
    return 0;
}