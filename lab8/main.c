#include <stdio.h>
#include "stdlib.h"

void bool_print(int n, int m, int **bm) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", bm[i][j]);
        }
        printf("\n");
    }
}

void bool_init(int ***bm, int n, int m, int * apa, int * szin) {
    *bm = (int **)malloc(n * sizeof (int *));
    for (int i = 0; i < n; ++i) {
        (*bm)[i] = (int *) malloc(m * sizeof (int));
        for (int j = 0; j < m; ++j) {
            bm[i][j] = 0;
        }
    }

    bool_print(n, m, bm);

    apa = malloc(n * sizeof())
}

void melysegi_menet(int **bm, int n, int *szin, int *apa){
    printf("%d", n);
    szin[n] = 2;
    for (int i = 0; i < n; ++i) {
        if(szin[i] == 2) {
            apa[i] = n;
            melysegi_menet(bm, n, szin, apa);
        }
    }
    szin[n] = 0;
}

void melysegi(int n, int m, int **bm, int *szin, int *apa) {
    for (int i = 0; i < n; ++i) {
        szin[i] = 1;
        apa[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        if(szin[i] == 1) {
            melysegi_menet(bm, i, szin, apa);
        }
    }
}

int main() {
    int n, m, **bm, *apa, *szin;

    scanf("%d%d", &n, &m);

    bool_init(&bm, n, m);

    bool_print(n, m, bm);

    melysegi
}
