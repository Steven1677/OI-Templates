#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

void merge(int *arr, int left, int mid, int right)
{
    static queue<int> q;
    int pl = left, pr = mid;
    int ql = mid + 1, qr = right;

    while (pl <= pr || ql <= qr) {
        if ((ql > qr) || (pl <= pr && arr[pl] <= arr[ql]))
            q.push(arr[pl++]);
        else
            q.push(arr[ql++]);
    }

    while (!q.empty())
    {
        arr[left++] = q.front();
        q.pop();
    }
}
void merge_sort(int *arr, int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}