#include <iostream>

using namespace std;

void merge(int *arr, int l, int r, int *idx)
{
    int m = (l + r) / 2;
    int temp[r];
    int tempidx[r];
    for(int i=0; i<=r; i++)
    {
        temp[i] = arr[i];
        tempidx[i] = idx[i];
    }
    int i1 = l;
    int i2 = m + 1;
    for(int curr=l; curr<=r; curr++)
    {
        if(i2 == m + 1)
        {
            arr[curr] = temp[i2++];
            idx[curr] = tempidx[i2+1];
        }
        else if(i2 > r)
        {
            arr[curr] = temp[i1++];
            idx[curr] = tempidx[i1+1];
        }
        else if(temp[i1] <= temp[i2])
        {
            arr[curr] = temp[i1++];
            idx[curr] = tempidx[i1+1];
        }
        else
        {
            arr[curr] = temp[i2++];
            idx[curr] = tempidx[i2+1];
        }
    }
}

void mergesort(int *arr, int l, int r, int *idx)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        mergesort(arr, l, m, idx);
        mergesort(arr, m + 1, r, idx);
        merge(arr, l, r, idx);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    for(int i=1; i<=c; i++)
    {
        int n_ins;
        int n_vag;
        cin >> n_ins >> n_vag;

        char nomes[n_ins][31];
        int notas[n_ins];
        int idades[n_ins];
        int idx[n_ins];

        for(int j=0; j<n_ins; j++)
        {
            cin >> nomes[j];
            cin >> notas[j];
            cin >> idades[j];
            idx[j] = j;
        }

        for(int j=0; j<n_vag; j++)
        {
            cout << notas[j];
        }

        mergesort(idades, 0, n_ins-1, idx);
        mergesort(notas, 0, n_ins-1, idx);

        for(int j=0; j<n_vag; j++)
        {
            cout << notas[j];
        }

        for(int j=0; j<n_vag; j++)
        {
            cout << nomes[idx[j]];
            cout << notas[j];
        }
    }

    return 0;
}