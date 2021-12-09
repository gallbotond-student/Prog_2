#include <stdio.h>
#include "stdlib.h"

typedef struct{
    int u, v;
    float suly;
}EL;

void egyesit(int *fa, int n, int egyik, int masik){
    for (int i = 0; i < n; ++i) {
        if(fa[i] == masik)
            fa[i] = egyik;
    }
}

int main() {
    FILE *f;
    int el, csp;

    f = fopen("graf.txt", "r");

    if(!f){
        printf("\nUnable to open file.");
        return 0;
    }

    fscanf(f, "%d%d", &csp, &el);

    EL *elek = malloc(el * sizeof(EL));

    if(!elek) {
        printf("\nSikertelen helyfoglalas.");
        return 0;
    }

    for (int i = 0; i < el; ++i) {
        fscanf(f, "%d%d%f", &elek[i].u, &elek[i].v, &elek[i].suly);
    }

//    for (int i = 0; i < el; ++i) {
//        printf("\n%d %d %f", elek[i].u, elek[i].v, elek[i].suly);
//    }

    for (int i = 0; i < el - 1; ++i) {
        for (int j = i + 1; j < el; ++j) {
            if(elek[i].suly > elek[j].suly){
                EL k = elek[j];
                elek[j] = elek[i];
                elek[i] = k;
            }
        }
    }

    int *fa = malloc(csp * sizeof(int));
    if(!fa) {
        printf("\nMemory allocation failed.");
        return 0;
    }

    for (int i = 0; i < el; ++i) {
        fa[i] = i;
    }

    for (int i = 0; i < el; ++i) {
        printf("\n%d %d %f", elek[i].u, elek[i].v, elek[i].suly);
    }

    float osszSuly = 0;
    int egyik, masik;
    for (int i = 0; i < el; ++i) {
        egyik = fa[elek[i].u];
        masik = fa[elek[i].v];
        if(egyik != masik) {
            osszSuly += elek[i].suly;
            printf("\n %d, %d, %f", elek[i].u, elek[i].v, elek[i].suly);
            egyesit(fa, csp, egyik, masik);
        }
    }

    printf("\n %.2f osszsuly.", osszSuly);

    return 0;
}
