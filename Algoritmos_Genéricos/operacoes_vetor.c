#include <stdio.h>

int arr_sum(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int arr_most(int *arr, int n, int (*compare)(int, int)) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (compare(arr[i], max)) {
            max = arr[i];
        }
    }
    return max;
}

int dot_product(int *arr1, int *arr2, int n) {
    int p = 0;
    for (int i = 0; i < n; i++) {
        p += arr1[i]*arr2[i];
    }
    return p;
}

