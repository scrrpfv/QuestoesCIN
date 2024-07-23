#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
    n++; s++;
    vector<int> v;
    vector<int> w;
    v.resize(n);
    w.resize(n);

    for(int i = 1; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> matrix;
    matrix.resize(n);
    for(int i = 0; i < n; i++) {
        matrix[i].resize(s);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s; j++) {
            if (i == 0 | j == 0) {
                matrix[i][j] = 0;
            }
            else if (w[i] <= j) {
                matrix[i][j] = max(matrix[i-1][j], v[i] + matrix[i-1][j-w[i]]);
            }
            else {
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }

    cout << matrix[n-1][s-1];

    return 0;
}