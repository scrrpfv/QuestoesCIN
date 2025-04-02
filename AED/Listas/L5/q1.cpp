#include <bits/stdc++.h>

using namespace std;

struct heap {
    vector<pair<int,float>> arr;
    int size;

    void swap(pair<int,float>& a, pair<int,float>& b) {
        pair<int,float> temp = a;
        a = b;
        b = temp;
    }

    void heapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int maior;
        if (l < size && arr[l].second > arr[i].second) {
            maior = l;
        } else {
            maior = i;
        }
        if (r < size && arr[r].second > arr[maior].second) {
            maior = r;
        }
        if (maior != i) {
            swap(arr[i], arr[maior]);
            heapify(maior);
        }
    }

    void build_heap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    void change_value(int id, float v) {
        cout << "Changing value of " << id << " to " << v << endl;
        arr[id].second = v;
        heapify(id);
    }

    void remove() {
        cout << "Removing " << arr[0].first << " " << arr[0].second << endl;
        swap(arr[0], arr[size - 1]);
        size--;
        heapify(0);
    }

    void print_heap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i].first << " " << arr[i].second << endl;
        }
    }

    void clear() {
        arr.clear();
    }
};

float f(int s, int t, int b) {
    return (float)(s - t * t * b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;      // Quantidade de brinquedos
    int K;      // Quantidade de créditos
    int V;      // Quantidade de visitas
    int M;      // Menor custo
    int D;      // Diversão atual
    cin >> N;
    int S[N];   // Diversão base
    int B[N];   // Fator de aborrecimento
    int C[N];   // Custo de uso
    int T[N];   // Quantidade de usos
    int d;      // Diversão

    heap H;     // Heap contendo diversão por custo
    
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> B[i] >> C[i];
    }
    M = min_element(C, C + N) - C;
    cin >> V;
    for (int i = 0; i < V; i++) {
        H.size = N;
        cin >> K;
        fill(T, T + N, 0);
        D = 0;

        for (int i = 0; i < N; i++) {
            H.arr.push_back({i, f(S[i], T[i], B[i])/C[i]});
        }
        H.build_heap();
        H.print_heap();
        cout << endl;
        while (K > M && H.size > 0) {
            int id = H.arr[0].first;
            while (H.size > 0 && (C[id] > K || f(S[id], T[id], B[id]) <= 0)) {
                cout << "C: " << C[id] << " K: " << K << " " << (C[id] > K) << (f(S[id], T[id], B[id]) <= 0) << endl;
                H.remove();
                if (H.size == 0) {
                    break;
                }
                id = H.arr[0].first;
                cout << "New id: " << id << " " << H.arr[1].second << " C: " << C[id] << " K: " << K << " " << (C[id] > K) << (f(S[id], T[id], B[id]) <= 0) << endl;
            }
            
            d = f(S[id], T[id], B[id]);
            D += d;
            cout << "K "<< K << " " << id << " " << H.arr[0].second << endl;
            K -= C[id];
            T[id]++;
            H.change_value(0, f(S[id], T[id], B[id])/(float)C[id]);
            cout << "Heap: " << endl;
            H.print_heap();
            cout << "D: " << D << endl;
        }
        cout << i << ": " << D << endl;
        H.clear();
    }
    return 0;
}