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
    
    int find(vector<int>& parent, int u) {
        if (u != parent[u]) {
            parent[u] = find(parent, parent[u]);
        }
        return parent[u];
    }
    
    vector<pair<int, pair<int, int>>> mst() {
        vector<pair<int, pair<int, int>>> edges;
        for (int u = 0; u < V; u++) {
            for (auto &[v, weight] : adj[u]) {
                edges.push_back({weight, {u, v}});
            }
        }
        sort(edges.begin(), edges.end());

        vector<int> parent(V);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        vector<pair<int, pair<int, int>>> result;
        for (auto &[weight, uv] : edges) {
            int u = uv.first, v = uv.second;
            int set_u = find(parent, u), set_v = find(parent, v);
            if (set_u != set_v) {
                result.push_back({weight, {u, v}});
                parent[set_u] = set_v;
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N, A, B, C;
    cin >> M >> N;
    Graph g(M);
    for (int i = 0; i < N; i++) {
        cin >> A >> B >> C;
        g.addEdge(A, B, C);
    }
    auto mst_edges = g.mst();
    int total_weight = 0;
    for (auto &[weight, uv] : mst_edges) {
        total_weight += weight;
    }
    cout << total_weight << endl;

    return 0;
}