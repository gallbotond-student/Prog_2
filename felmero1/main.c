#include <stdio.h>

int smallestPartNum(int n) {
    int min = n % 10;
    while (n) {
        if (n % 10 < min) {
            min = n % 10;
        }
        n /= 10;
    }

    return min;
}

int smallestSum() {
    int n, sum = 0;

    do {
        scanf("%d", &n);
        sum += smallestPartNum(n);
    }while(n != 0);

    return sum;
}

int main() {
    printf("%d", smallestSum());
}
