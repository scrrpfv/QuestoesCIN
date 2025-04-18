#include <iostream>

using namespace std;

struct heap {
    int* arr;
    int max_size;
    int size;

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int maior;
        if (l < size && arr[l] > arr[i]) {
            maior = l;
        } else {
            maior = i;
        }
        if (r < size && arr[r] > arr[maior]) {
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

    void insert_heap(int v) {
        arr[size] = v;
        size++;
        int i = size;
        while (i > 0 && arr[i - 1] > arr[i / 2 - 1]) {
            swap(arr[i - 1], arr[i / 2 - 1]);
            i = i / 2;
        }
    }

    int remove_heap() {
        int removed = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return removed;
    }
};

int main() {
    heap h;
    int arr[10] = {10, 4, 8, 7, 2, 1, 30, 25, 19, 17};
    h.arr = arr;
    h.max_size = 10;
    h.size = 10;
    
    h.build_heap();
    
    cout << "heap: ";
    for (int i = 0; i < h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << "\n";
}
