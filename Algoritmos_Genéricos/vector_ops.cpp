#include <bits/stdc++.h>

using namespace std;

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

int gt(int v1, int v2) {
    return v1 > v2;
}

int main() {

    int arr1[4] = {5,3,2,4};
    int arr2[6] = {0,1,2,8,3};

    int sum = arr_sum(arr1, 4);
    int max = arr_most(arr2, 6, gt);
    int dot = dot_product(arr1, arr2, 4); // will use arr2 just up to position 4

    cout << sum << "\n";
    cout << max << "\n";
    cout << dot << "\n";

    return 0;
}