#include <bits/stdc++.h>

using namespace std;

typedef struct HEAP {
    int* arr;
    int size;
} HEAP;

void bottom_up(struct HEAP *h) {
    for (int i = (int)(h->size/2); i > 0 ; i--) {
        int k = i;
        int v = h->arr[k];
        bool heap = false;
        
        while (!heap && 2*k <= h->size) {
            int j = 2*k;
            if (j < h->size) {
                if (h->arr[j] > h->arr[j+1] && h->arr[j+1] != 0) {
                    j++;
                }
            }
            if (v <= h->arr[j]) {
                heap = true;
            } else {
                h->arr[k] = h->arr[j];
                k = j;
            }
        }
        h->arr[k] = v;
    }
}

HEAP* create_heap(int* array, int size) {
    HEAP* newheap = new HEAP;
    newheap->arr = array;
    newheap->size = size;
    bottom_up(newheap);
    return newheap;
}

int getsum(HEAP* h) {
    int r1 = h->arr[1];
    if (h->arr[2] > h->arr[3] && h->arr[3] > 0) {
        int temp = h->arr[2];
        h->arr[2] = h->arr[3];
        h->arr[3] = temp;
    }
    int r2 = h->arr[2];

    long long int sum = r1 + r2;

    h->arr[1] = h->arr[h->size];
    h->arr[h->size] = 0;
    h->arr[2] = sum;
    h->size--;

    bottom_up(h);
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int size;
    cin >> size;
    while (size > 0) {
        int array[size+1];
        array[0] = 0;
        for (int i = 1; i<=size; i++) {
            cin >> array[i];
        }

        HEAP* heap = create_heap(array, size);

        long long int cost = 0;
        while (heap->size > 1) {
            cost += getsum(heap);
        }
        cout << cost;

        cin >> size;
        if (size > 0) {
            cout << endl;
        }
    }
    return 0;
}
