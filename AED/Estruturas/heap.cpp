typedef struct heap {
    int* arr;
    int max_size;
    int size;
} heap;

void insert_topdown(heap* h, int v) {
    int k = 1;
    bool heap = false;
    while (!heap) {
        int j = 2*k;
        if (j < h->size) {
            if (h->arr[j] < h->arr[j+1]) {
                j++;
            }
        }
        if (v >= h->arr[j]) {
            heap = true;
        } else {
            h->arr[k] = h->arr[j];
            k = j;
        }
    }
    h->arr[k] = v;
}