#include <iostream>
#include "stdlib.h"

int binary_search(int *t, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;

        if (t[mid] == x)
            return mid;

        if (t[mid] > x)
            return binary_search(t, l, mid-1, x);

        return binary_search(t, mid+1, r, x);
    }

    return -1;
}

int max(int *t, int l, int r)
{
    int mid = (l + r)/2;

    if(l == r)
        return t[l];
    else
        if(max(t, l, mid) > max(t, mid+1, r))
            return max(t, l, mid);
        else
            return max(t, mid+1, r);
}

int min(int *t, int l, int r)
{
    int mid = (l + r)/2;

    if(l == r)
        return t[l];
    else
    if(min(t, l, mid) < min(t, mid+1, r))
        return min(t, l, mid);
    else
        return min(t, mid+1, r);
}

int main() {
    int n, *t, x;

    scanf("%d%d", &n, &x);

    t = (int *)malloc(n * sizeof (int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }

    printf("%d %d %d", binary_search(t, 0, n - 1, x), max(t, 0, n-1), min(t, 0, n - 1));
}
