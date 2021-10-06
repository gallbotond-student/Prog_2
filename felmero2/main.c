#include <stdio.h>
#include "stdlib.h"

void oddReversePrint (int n, int m, int **t) {
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 1) {
            for (int j = m - 1; j >= 0; j--) {
                printf("%d ", t[i][j]);
            }
        }
        else {
            for (int j = 0; j < m; ++j) {
                printf("%d ", t[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {

    int n, m, **t;
    FILE *f;

    f = fopen("./in.txt", "r");

    if (!f) {
        printf("NO FILE! \n");
        return 0;
    }
    fscanf(f, "%d%d", &n, &m);

    t = (int **)malloc(n * sizeof (int *));
    for (int i = 0; i < n; ++i) {
        t[i] = (int *) malloc(m * sizeof (int));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fscanf(f, "%d", &t[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    oddReversePrint(n, m, t);

    for (int i = 0; i < n; ++i) {
        free(t[i]);
    }
    free(t);

    fclose(f);
}
