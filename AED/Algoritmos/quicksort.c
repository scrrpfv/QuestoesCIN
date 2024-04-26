#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int r)
{
	int p = arr[l];
	int i = l;
	int j = r + 1;
	while(i < j)
	{
		while(arr[i] < p & i < r)
		{
			i++;
		}
		while(arr[j] > p)
		{
			j--;
		}
		swap(arr[i], arr[j]);
	}
	swap(arr[i], arr[j]);
	swap(arr[l], arr[j]);
	return j;
}

void quicksort(int *arr, int l, int r)
{
	int s = partition(arr, l, r);
	quicksort(arr, l, s - 1);
 	quicksort(arr, s + 1, r);
}