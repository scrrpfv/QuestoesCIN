#include <bits/stdc++.h>

using namespace std;

struct heap {
    vector<pair<int,int>> arr;
    int max_size;
    int size;

    void swap(pair<int,int>& a, pair<int,int>& b) {
        pair<int,int> temp = a;
        a = b;
        b = temp;
    }

    void heapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int maior;
        if (l < size && arr[l].first > arr[i].first) {
            maior = l;
        } else {
            maior = i;
        }
        if (r < size && arr[r].first > arr[maior].first) {
            maior = r;
        }
        if (maior != i) {
            swap(arr[i], arr[maior]);
            heapify(maior);
        }
    }

    void build_heap() {
        for (int i = size / 2; i >= 0; i--) {
            heapify(i);
        }
    }

    void insert_heap(int v, int id) {
        arr[size] = make_pair(v, id);
        size++;
        int i = size;
        while (i > 0 && arr[i - 1] > arr[i / 2 - 1]) {
            swap(arr[i - 1], arr[i / 2 - 1]);
            i = i / 2;
        }
    }

    pair<int, int> remove_heap() {
        pair<int, int> removed = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return removed;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, V, S[N], B[N], C[N], T[N];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> B[i] >> C[i];
    }

    cin >> V;
    for (int i = 0; i < V; i++) {
        cin >> K;
        
    }
    return 0;
}