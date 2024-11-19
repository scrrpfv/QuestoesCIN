#include <bits/stdc++.h>

using namespace std;

typedef struct graph {
    int **matrix;
    int numEdges;
    int *mark;
} graph;

graph * create_graph(int n) {
    graph * g = new graph;
    g->mark = new int[n];
    g->matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        g->matrix[i] = new int[n];
    }
    g->numEdges = 0;
    
    return g;
}

int first(graph* g, int v) {
    for (int i = 0; i < g->numEdges; i++) {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->numEdges;
}

int next(graph* g, int v, int w) {
    for (int i = w + 1; i < g->numEdges; i++) {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->numEdges;
}

void set_edge(graph* g, int i, int j, int wt) {
    if (wt != 0) {
        if (g->matrix[i][j] == 0) {
            g->numEdges++;
        }
        g->matrix[i][j] = wt;
        g->matrix[j][i] = wt;
    }
}

void del_edge(graph* g, int i, int j) {
    if (g->matrix[i][j] != 0) {
        g->numEdges--;
    }
    g->matrix[i][j] = 0;
}

void set_mark(graph* g, int v, int mark) {
    g->mark[v] = mark;
    if (mark) {
        cout << v << " ";
    }
}

bool get_mark(graph* g, int v) {
    return g->mark[v];
}

void BFS(graph* g, int start) {
    queue<int> q;
    q.push(start);
    set_mark(g, start, 1);
    while (q.size() > 0) {
        int v = q.front();
        q.pop();
        int w = first(g, v);
        while (w < g->numEdges) {
            if (!get_mark(g, w)) {
                set_mark(g, w, 1);
                q.push(w);
            }
            w = next(g, v, w);
        }
    }
}

void DFS(graph* g, int v) {
    // antes de visitar
    set_mark(g, v, 1);
    int w = first(g, v);
    while (w < g->numEdges) {
        if (!get_mark(g, w)) {
            DFS(g, w);
        }
        w = next(g, v, w);
    }
}

void traverse_BFS(graph* g, int v) {
    for (int v = 0; v < g->numEdges; v++) {
        set_mark(g, v, 0);
    }
    BFS(g, v);
}

void traverse_DFS(graph* g, int v) {
    for (int v = 0; v < g->numEdges; v++) {
        set_mark(g, v, 0);
    }
    DFS(g, v);
}

int main() {
    int n, q;
    cin >> n >> q;
    
    graph *g = create_graph(n);

    for (int i = 0; i < q; i++) {
        string op;
        cin >> op;

        if (op[0] == 'a') {
            int v1, v2;
            cin >> v1 >> v2;
            set_edge(g, v1, v2, 1);

        } else if (op[0] == 'B') {
            int start;
            cin >> start;
            traverse_BFS(g, start);
            cout << endl;

        } else {
            int start;
            cin >> start;
            traverse_DFS(g, start);
            cout << endl;

        }
    }

    return 0;
}