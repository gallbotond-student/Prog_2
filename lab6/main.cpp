#include <iostream>
#include "stdlib.h"

int even_rec(int *t, int n) {
    if(n < 0){
        return 0;
    }
    else{
        if(n % 2 == 0){
            return even_rec(t, n - 1);
        }
        else{
            return t[n] + even_rec(t, n - 1);
        }
    }
}

int odd_rec(int *t, int n) {
    if(n < 0){
        return 0;
    }
    else{
        if(n % 2 == 1){
            return odd_rec(t, n - 1);
        }
        else{
            return t[n] + odd_rec(t, n - 1);
        }
    }
}

int main() {
    int n, *t;

    scanf("%d", &n);

    t = (int *)malloc(n * sizeof (int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }

    printf("\n%d", even_rec(t, n-1) - odd_rec(t, n));
}
