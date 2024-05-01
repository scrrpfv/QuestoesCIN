#include <stdio.h>

int binary_search(int *arr, int l, int r, int k) {
    if (r >= l) {
        int m = (l + r) / 2;
        if (k==arr[m]) {
            return m;
        }
        else if (k < arr[m]) {
            return binary_search(arr, l, m - 1, k);
        }
        else {
            return binary_search(arr, m + 1, r, k);
        }
    }
}