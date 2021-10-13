#include <iostream>

int power(int x, int y) {
    int z = 1;
    while(y--) {
        z *= x;
    }
    return z;
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void bubbbleSort(int *t, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if(t[j] > t[j + 1]) {
                swap(&t[j], &t[j + 1]);
            }
        }
    }
}

int minIndex(int *t, int i, int n) {
    int min = t[i], minIndex = i;
    for (int j = i; j < n; ++j) {
        if(t[j] < min) {
            min = t[j];
            minIndex = j;
        }
    }

    return minIndex;
}

void selectionSort(int *t, int n) {
    for (int i = 0; i < n; ++i) {
        int j = minIndex(t, i, n);
        swap(&t[i], &t[j]);
    }
}

int main() {
    int x, y;

    scanf("%d%d", &x, &y);

    swap(&x, &y);
    printf("%d\n", power(x, y));

    int n;

    scanf("%d", &n);

    int *t = (int *) malloc(n * sizeof (int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }

    bubbbleSort(t, n);
//    selectionSort(t, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", t[i]);
    }
}
