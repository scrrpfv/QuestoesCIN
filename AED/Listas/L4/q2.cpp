#include <bits/stdc++.h>

using namespace std;

struct Graph {
    int V;
    vector<vector<pair<int,int>>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w, int M) {
        adj[v].emplace_back(w, M);
    }
    // TODO: implementar kruskal e mst
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N, A, B, C;
    cin >> M >> N;
    Graph g(M);
    for (int i = 0; i < N; i++) {

    }

    return 0;
}