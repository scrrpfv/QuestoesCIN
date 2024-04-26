#include <stdio.h>

void merge(int *arr, int l, int r)
{
	int temp[r+1];
	for(int i=l; i<=r; i++)
	{
		temp[i] = arr[i];
	}
	int m = (l + r) / 2;
	int i1 = l, i2 = m + 1;
	for(int c=l; c<=r; c++)
	{
		if(i1 == m + 1)
		{
			arr[c] = temp[i2++];
		}
		else if(i2 > r)
		{
			arr[c] = temp[i1++];
		}
		else if(temp[i1] <= temp[i2])
		{
			arr[c] = temp[i1++];
		}
		else
		{
			arr[c] = temp[i2++];
		}
	}
}

void mergesort(int *arr, int l, int r)
{
	if(l < r)
	{
		int m = (l + r) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, r);
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

		mergesort(arr, 0, n-1);

		for(int j=0; j<n; j++)
		{
			printf("%d", arr[j]);
			if(j < n - 1) {printf(" ");}
		}
		printf("\n");
    }

    return 0;
}