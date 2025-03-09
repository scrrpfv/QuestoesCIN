#include <bits/stdc++.h>

using namespace std;

struct Labirinto {
    int M;
    int N;
    vector<vector<int>> matriz;

    int printMatriz() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    int bfs() {
        queue<array<int, 3>> q;
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matriz[i][j] == 2) {
                    q.push({i, j, 0});
                    matriz[i][j] = 1;
                }
            }
        }
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            array<int, 3> p = q.front();
            q.pop();

            for (pair<int, int> d : directions) {
                int x = p[0] + d.first;
                int y = p[1] + d.second;
                int dist = p[2] + 1;

                if (x >= 0 && x < M && y >= 0 && y < N && matriz[x][y] != 1) {
                    if (matriz[x][y] == 3) {
                        return dist;
                    }

                    q.push({x, y, dist});
                    matriz[x][y] = 1;
                }
            }
        }

        return -1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Labirinto lab;
    cin >> lab.M >> lab.N;
    lab.matriz.resize(lab.M, vector<int>(lab.N));
    for (int i = 0; i < lab.M; i++) {
        for (int j = 0; j < lab.N; j++) {
            cin >> lab.matriz[i][j];
        }
    }

    int dist = lab.bfs();
    if (dist == -1) {
        cout << "Labirinto Impossivel" << endl;
    } else {
        cout << dist << endl;
    }

    return 0;
}
