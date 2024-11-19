#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoare_partition(int *arr, int l, int r) {
	int p = arr[l];
	int i = l;
	int j = r + 1;

	do {
		do { i++; } while (arr[i] < p && i < r);
		do { j--; } while (arr[j] > p);

		swap(&arr[i], &arr[j]);
	} while (i < j);

	swap(&arr[i], &arr[j]);
	swap(&arr[l], &arr[j]);
	return j;
}

void quicksort(int *arr, int l, int r) {
	if (l < r) {
		int s = hoare_partition(arr, l, r);
		quicksort(arr, l, s - 1);
		quicksort(arr, s + 1, r);
	}
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    long long int sum = 0;
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int m;
    scanf("%d", &m);

    quicksort(arr, 0, n-1);

    for(int i=0; i<m; i++) {
        int q;
        scanf("%d", &q);

        long long int out = sum - arr[n-q];
		printf("%lld\n", out);
    }
    return 0;
}
