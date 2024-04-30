#include <bits/stdc++.h>

using namespace std;

typedef struct {
    char nome[31];
    int nota;
    int idade;
} candidato;

bool comp_idade(candidato a, candidato b) { return a.idade >= b.idade; }
bool comp_nota(candidato a, candidato b) { return a.nota >= b.nota; }

void merge(candidato *arr, int l, int r, bool (*func_comp)(candidato, candidato)) {
    candidato temp[r+1];
    for(int i = 0; i <= r; i++) {
        temp[i] = arr[i];
    }

    int m = (l + r) / 2;
    int i1 = l, i2 = m + 1;

    for (int c=l; c<=r; c++) {
        if (i1 == m + 1) {
            arr[c] = temp[i2++];
        }
        else if (i2 > r) {
            arr[c] = temp[i1++];
        }
        else if (func_comp(temp[i1], temp[i2])) {
            arr[c] = temp[i1++];
        }
        else {
            arr[c] = temp[i2++];
        }
    }
}

void mergesort(candidato *arr, int l, int r, bool (*func_comp)(candidato, candidato)) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(arr, l, m, func_comp);
        mergesort(arr, m + 1, r, func_comp);
        merge(arr, l, r, func_comp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        int n_ins; cin >> n_ins;
        int n_vag; cin >> n_vag;

        candidato arr[n_ins];

        for (int j = 0; j < n_ins; j++) {
            cin >> arr[j].nome;
            cin >> arr[j].nota;
            cin >> arr[j].idade;
        }

        mergesort(arr, 0, n_ins-1, comp_idade);
        mergesort(arr, 0, n_ins-1, comp_nota);

        cout << "cargo " << c << ":" << endl;
        for (int j = 0; j < min(n_vag, n_ins); j++) {
            cout << arr[j].nome << endl;
        }
        for (int j = 0; j < n_vag-n_ins; j++) {
            cout << "x" << endl;
        }
    }
    return 0;
}