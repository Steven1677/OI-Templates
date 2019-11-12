#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int a[N];

void QuickSort(int l, int r)
{
    int i = l, j = r;
    int pivot = a[(rand() % (r - l + 1)) + l];
    do
    {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
    }while (i <= j);
    if (l < j) QuickSort(l, j);
    if (i < r) QuickSort(i, r);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    QuickSort(0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}