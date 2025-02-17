#include <iostream>

using namespace std;

typedef struct heap {
    int* arr;
    int max_size;
    int size;
} heap;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(heap* h, int i) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int maior;
    if (l < h->size && h->arr[l] > h->arr[i]) {
        maior = l;
    } else {
        maior = i;
    }
    if (r < h->size && h->arr[r] > h->arr[maior]) {
        maior = r;
    }
    if (maior != i) {
        swap(h->arr[i], h->arr[maior]);
        heapify(h, maior);
    }
}

void build_heap(heap *h) {
    for (int i = h->size / 2; i >= 0; i--) {
        heapify(h, i);
    }
}

void insert_heap(heap* h, int v) {
    h->arr[h->size] = v;
    h->size++;
    int i = h->size;
    while (i > 0 && h->arr[i - 1] > h->arr[i/2 - 1]) {
        swap(h->arr[i - 1], h->arr[i/2 - 1]);
        i = i/2;
    }
}

int main() {
    heap* h = new heap;
    int arr[10] = {10, 4, 8, 7, 2, 1, 30, 25, 19, 17};
    h->arr = arr;
    h->max_size = 10;
    h->size = 10;
    
    build_heap(h);
    
    cout << "heap: ";
    for (int i = 0; i < h->size; i++) {
        cout << h->arr[i] << " ";
    }
    cout << "\n";
}
