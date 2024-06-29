#include <bits/stdc++.h>

using namespace std;

typedef struct graph {
    int **matrix;
    int numEdges;
    bool *mark;
} graph;

graph * create_graph(int n) {
    graph * g;
    g->mark = new bool[n];
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
    }
}

void del_edge(graph* g, int i, int j) {
    if (g->matrix[i][j] != 0) {
        g->numEdges--;
    }
    g->matrix[i][j] = 0;
}

void set_mark(graph* g, int v, bool mark) {
    g->mark[v] = mark;
}

bool get_mark(graph* g, int v) {
    return g->mark[v];
}

void graph_traverse(graph* g) {
    for (int v = 0; v < g->numEdges; v++) {
        set_mark(g, v, false);
    }
    for (int v = 0; v < g->numEdges; v++) {
        if (!get_mark(g, v)) {
            BFS(g, v);
        }
    }
}

void BFS(graph* g, int start) {
    queue<int> q;
    q.push(start);
    set_mark(g, start, true);
    while (q.size() > 0) {
        int v = q.front();
        q.pop();
        // antes de visitar
        int w = first(g, v);
        while (w < g->numEdges) {
            if (!get_mark(g, w)) {
                set_mark(g, w, true);
                q.push(w);
            }
            w = next(g, v, w);
        }
        // depois de visitar
    }
}