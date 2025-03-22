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

    void dijkstra(int src, int dest) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (pair<int, int> edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << (dist[dest] == INT_MAX ? -1 : dist[dest]) << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q, R, N, A, B, M, E;
    cin >> Q >> R >> N;
    Graph g(Q);
    for (int i = 0; i < R; i++) {
        cin >> A >> B >> M;
        g.addEdge(A, B, M);
    }

    for (int i = 0; i < N; i++) {
        cin >> E >> A >> B;
        if (E == 1) {
            cin >> M;
            g.addEdge(A, B, M);
        } else if (E == 2) {
            g.dijkstra(A, B);
        }
    }

    return 0;
}