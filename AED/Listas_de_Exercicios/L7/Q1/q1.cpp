#include <bits/stdc++.h>

using namespace std;

vector<int> r_move = {-2, -2, -1, -1, 1, 1, 2, 2};
vector<int> c_move = {-1, 1, -2, 2, -2, 2, -1, 1};

bool visit_neighbours(vector<vector<int>>& v, int r, int c, int size_x, int size_y) {
    for (int i = 0; i < 8; i++) {
        int new_r = r + r_move[i];
        int new_c = c + c_move[i];
        if (v[new_r][new_c] == 1) {
            v[new_r][new_c] = 2;
            visit_neighbours(v, new_r, new_c, size_x, size_y);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int>> board;

    int size;
    cin >> size;
    int k = 1;
    while (size > 0) {
        int s = 0;
        int offsets[size];
        int sizes[size];
        int max_size;

        for (int i = 0; i < size; i++) {
            int a, b;
            cin >> a >> b;
            offsets[i] = a;
            sizes[i] = b;
            if ((a + b) > max_size) max_size = a + b;
        }

        board.resize(size);
        for(int i = 0; i < size; i++) {
            board[i].resize(max_size);
            int n = max_size - offsets[i] + sizes[i];
            fill(board.begin() + offsets[i], board.end() + n, 1);
        }

        visit_neighbours(board, 0, 0, size, max_size);

        cout << "Case " << k << ", " << s << " squares can not be reached." << endl;
        k++;
        cin >> size;
    }

    return 0;
}
