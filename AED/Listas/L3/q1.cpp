#include <bits/stdc++.h>

using namespace std;

struct Node {
    int dest;
    Node* next;
};

struct Graph {
    int V;
    Node** adj;

    Graph(int V) {
        this->V = V;
        adj = new Node*[V];
        for (int i = 0; i < V; ++i)
            adj[i] = nullptr;
    }

    void addEdge(int v, int w) {
        Node* newNode = new Node{w, adj[v]};
        adj[v] = newNode;

        newNode = new Node{v, adj[w]};
        adj[w] = newNode;
    }

    void printGraph() {
        for (int i = 0; i < V; ++i) {
            Node* temp = adj[i];
            cout << i << ": ";
            if (!temp) {
                cout << "Lista Vazia";
            }
            while (temp) {
                cout << temp->dest << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void dfs() {
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        dfsUtil(0, visited);
    }

    void dfsUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        Node* temp = adj[v];
        while (temp) {
            if (!visited[temp->dest]) {
                dfsUtil(temp->dest, visited);
            }
            temp = temp->next;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V;
    cin >> V;
    Graph g(V);

    int v1, v2, f;
    f = 1;
    while (f) {
        cin >> v1 >> v2 >> f;
        g.addEdge(v1, v2);
    }
    g.printGraph();
    cout << endl;
    g.dfs();
    return 0;
}