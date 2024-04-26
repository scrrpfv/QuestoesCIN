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

	do
	{
		do
		{
			i++;
		} while(arr[i] < p && i < r);
		do
		{
			j--;
		} while(arr[j] > p);
		swap(&arr[i], &arr[j]);
	} while(i < j);

	swap(&arr[i], &arr[j]);
	swap(&arr[l], &arr[j]);
	return j;
}

void quicksort(int *arr, int l, int r)
{
	if(l < r)
	{
		int s = partition(arr, l, r);
		quicksort(arr, l, s - 1);
		quicksort(arr, s + 1, r);
	}
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i=0; i<cases; i++)
    {
        int n;
		scanf("%d", &n);
		int arr[n];

		for(int j=0; j<n; j++)
		{
			scanf("%d", &arr[j]);
		}

        quicksort(arr, 0, n-1);

        for(int j=0; j<n; j++)
		{
			printf("%d", arr[j]);
			if(j < n - 1) {printf(" ");}
		}
		printf("\n");
    }

    return 0;
}