#include <stdio.h>
#include "stdlib.h"

float szamjegyekAtlaga(int n){
    int osszeg = 0, oszto = 0;
    while(n){
        osszeg += n % 10;
        oszto ++;
        n /= 10;
    }

    return (float)osszeg / oszto;
}

void minMaxNum(int n, int *min, int *max){
    *min = n % 10, *max = n % 10;
    while(n){
        if(n % 10 > *max){
            *max = n % 10;
        }
        if(n % 10 < *min){
            *min = n % 10;
        }
        n /= 10;
    }
}

void numberStat(int n){
    int stat[10] = {0};
    while(n){
        stat[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < 10; ++i) {
        printf("\nNumber %d: %d times", i, stat[i]);
    }
}

void Product(){
    int product = 1, n;
    scanf("%d", &n);
    while (n) {
        product *= n;
        scanf("%d", &n);
    }

    printf("Product: %d", product);
}

void Series(int n){
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            printf("%d, ", i);
        }
    }
}

int averageBetween(int n, int *t){
    int n, *t;

    scanf("%d", &n);

    t = malloc(n * sizeof (int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }

    for (int i = 2; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == t[j]){
                for (int k = j; k < n; ++k) {
                    if(t[j] > t[k]){
                        int a = t[j];
                        for (int j = j; j < n - 1; ++j) {
                            t[j] = t[j+1];
                        }
                        t[n - 1] = a;
                    }
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                printf("%d ");
            }
            printf("\n");
        }
    }
}

void matrixRendez() {

}

int main() {
    int n, min = INT_MAX, max = INT_MIN, *t;

    scanf("%d", &n);
//    printf("\nSzamjegyek atlaga: %f", szamjegyekAtlaga(n));
//    minMaxNum(n, &min, &max);
//    printf("\nLegkisebb szamjegy: %d\nLegnagyobb szamjegy: %d", min, max);
//    numberStat(n);
//    Series(10);
    t = malloc(n * sizeof (int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", t[i]);
    }
}
