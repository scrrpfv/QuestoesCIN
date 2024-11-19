#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

typedef struct graph {
    vector<vector<int>> matrix;
    int size;
    vector<int> mark;
} graph;

typedef struct group {
    string conts[3];
} group;

graph * create_graph(int n) {
    graph * g = new graph;
    g->mark.resize(n);
    g->matrix.resize(n);
    for (int i = 0; i < n; i++) {
        g->matrix[i].resize(n);
    }
    g->size = n;
    
    return g;
}

int first(graph* g, int v) {
    for (int i = 0; i < g->size; i++) {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->size;
}

int next(graph* g, int v, int w) {
    for (int i = w + 1; i < g->size; i++) {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->size;
}

void set_edge(graph* g, int i, int j) {
    g->matrix[i][j] = 1;
    g->matrix[j][i] = 1;
}

void BFS(graph* g, vector<int>& ranks, int start) {
    queue<int> q;
    q.push(start);
    g->mark[start] = 1;

    ranks[start] = 0;
    int curr_rank = 1;

    while (q.size() > 0) {
        int v = q.front();
        q.pop();
        curr_rank = ranks[v] + 1;

        int w = first(g, v);
        while (w < g->size) {
            if (!g->mark[w]) {
                g->mark[w] = 1;
                q.push(w);
                ranks[w] = curr_rank;
            }
            w = next(g, v, w);
        }
    }
}

int main() {
    int t; cin >> t;
    map<string, int> conts;
    vector<group> groups;

    for (int i = 0; i < t; i++) {
        int n; cin >> n;

        for (int j = 0; j < n; j++) {
            group gp;
            cin >> gp.conts[0] >> gp.conts[1] >> gp.conts[2];
            groups.push_back(gp);

            for (string ct : gp.conts) {
                conts.insert_or_assign(ct, -1);
            }
        }

        int idx = 0;
        for (auto& cont : conts) {
            cont.second = idx;
            idx++;
        }

        graph *g = create_graph(idx);

        for (int j = 0; j < n; j++) {
            group k = groups[j];
            int id0 = conts[k.conts[0]];
            int id1 = conts[k.conts[1]];
            int id2 = conts[k.conts[2]];
            set_edge(g, id0, id1);
            set_edge(g, id0, id2);
            set_edge(g, id1, id2);
        }

        int start = conts["Ahmad"];
        vector<int> ranks;
        ranks.resize(idx);
        fill(ranks.begin(), ranks.end(), -1);
        BFS(g, ranks, start);

        cout << idx << endl;
        
        vector<pair<const string, int>> list;
        for (auto cont : conts) {
            list.push_back(cont);
        }

        vector<int> printed;
        bool running = true;
        bool found = false;
        int r = 0;
        while (running) {
            for (int j = 0; j < idx; j++) {
                if (ranks[list[j].second] == r) {
                    found = true;
                    int rank = ranks[list[j].second];
                    cout << list[j].first << " " << rank << endl;
                }
            }
            r ++;
            running = found;
            found = false;
        }
        for (int j = 0; j < idx; j++) {
            if (ranks[list[j].second] == -1) {
                cout << list[j].first << " undefined" << endl;
            }
        }
    }
    return 0;
}