#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int **matrix;
}triangleMatrix;

triangleMatrix *readFromFile(char *fileName) {
    FILE *filePtr = fopen(fileName, "r");
    if(filePtr == NULL) { printf("Error reading file. "); return NULL;}

    triangleMatrix *m = malloc(sizeof(triangleMatrix));

    fscanf(filePtr, "%d", &m->size);

    m->matrix = (int **) malloc(m->size * sizeof(int *));

    for (int i = 0; i <= m->size; i++) {
        m->matrix[i] = (int *) malloc((i + 1) * sizeof(int));
        for (int j = 0; j < i; j++) {
            fscanf(filePtr, "%d", &m->matrix[i][j]);
        }
    }

    fclose(filePtr);

    return m;
}

void printMatrix(triangleMatrix *m) {
    for (int i = 0; i <= m->size; ++i) {
        for (int j = 0; j < i; ++j) {
            printf("%d  ",  m->matrix[i][j]);
        }
        printf("\n");
    }
}

void greedyRoute(triangleMatrix *m)  {
    int j = 0, sum = m->matrix[1][0];
    printf("Greedy %d", m->matrix[1][0]);

    for (int i = 2; i <= m->size; ++i) {
        if(m->matrix[i][j] < m->matrix[i][j+1]) {
            sum += m->matrix[i][j];
            printf("->%d", m->matrix[i][j]);
        }
        else {
            int x = m->matrix[i][j+1];
            sum += x;
            printf("->%d", m->matrix[i][j+1]);
            j++;
        }
    }

    printf(": %d\n", sum);
}

int greedyRoute_Rec(triangleMatrix *m, int i, int j) {
    if(i == m->size) {
        int min = m->matrix[i][j] < m->matrix[i][j+1] ? m->matrix[i][j] : m->matrix[i][j+1];
        printf("->%d", min);
        return min;
    }
    else if(i == 1) {
        printf("Greedy recursive %d", m->matrix[i][j]);
        return m->matrix[i][j] + greedyRoute_Rec(m, i+1, j);
    }
    else if(m->matrix[i][j] < m->matrix[i][j+1]) {
        printf("->%d", m->matrix[i][j]);
        return m->matrix[i][j] + greedyRoute_Rec(m, i+1, j);
    }
    else {
        printf("->%d", m->matrix[i][j+1]);
        return m->matrix[i][j+1] + greedyRoute_Rec(m, i+1, j+1);
    }
}

int backtrackRoute(triangleMatrix *m, int i, int j, int *t) {
    if(i == m->size) {
        return m->matrix[i][j] < m->matrix[i][j+1];
    }
}

int main() {
    triangleMatrix *m;

    m = readFromFile("input.txt");

    printMatrix(m);

    greedyRoute(m);
    printf(": %d", greedyRoute_Rec(m, 1, 0));
}
