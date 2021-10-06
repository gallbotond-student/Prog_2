#include <stdio.h>
#include "stdlib.h"
#include "math.h"

// 3. feladat
//int main() {
//    int n, m, p, *t;
//
//    scanf("%d%d%d", &n, &m, &p);
//
//    t = (int *) malloc(n * sizeof (int));
//
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &t[i]);
//    }
//
//    for (int i = 0; i < m; ++i) {
//        printf("%d ", t[i]);
//    }
//
//    printf("\n");
//
//    for (int i = n - 1; i >= n - p; i--) {
//        printf("%d ", t[i]);
//    }
//    free(t);
//}

// 4. feladat
//int main() {
//    int n;
//
//    scanf("%d", &n);
//
//    int **t = (int **) malloc(n * sizeof (int *));
//
//    for (int i = 0; i < n; ++i) {
//        t[i] = (int *) malloc(n * sizeof (int));
//    }
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if(i == j){
//                t[i][j] = 0;
//            }
//            else if(i < j){
//                t[i][j] = 9;
//            }
//            else{
//                t[i][j] = 6;
//            }
//        }
//    }
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            printf("%d ", t[i][j]);
//        }
//        printf("\n");
//    }
//
//    for (int i = 0; i < n; ++i) {
//        free(t[i]);
//    }
//    free(t);
//}

typedef struct{
    float x, y;
    int visited;
}pont;

float Tavolsag(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (y2 - y1));
}

// 5. feladat
//int main()
//{
//    float x1, y1, x2, y2;
//    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
//
//    printf("\nDistance: %f", Tavolsag(x1, y1, x2, y2));
//}


int LegkozelebbiPont(int n, int p, pont * points){
    int minTav = INT_MAX, minIndex = 0;

    for (int i = 0; i < n; ++i) {
        if(i + 1 == p){
            continue;
        }
        else if(minTav > Tavolsag(points[i].x, points[i].y, points[p - 1].x, points[p - 1].y)){
            minTav = Tavolsag(points[i].x, points[i].y, points[p - 1].x, points[p - 1].y);
            minIndex = i + 1;
        }
    }

    return minIndex;
}

// 6. feladat
//int main()
//{
//    int n, p, minIndex = 0;
//    pont *points;
//    float minTav;
//
//    scanf("%d", &n);
//
//    points = (pont*)malloc(n * sizeof (pont));
//
//    for (int i = 0; i < n; ++i) {
//        scanf("%f%f", &points[i].x, &points[i].y);
//    }
//
//    scanf("%d", &p);
//
//    printf("Legkozelebbi pont: %d. pont", LegkozelebbiPont(n, p, points));
//
//    free(points);
//}

int LegkozelebbiUjPont(int n, int p, pont * points, int * latogatott, int m){
    int minTav = INT_MAX, minIndex = 0;

    for (int i = 0; i < n; ++i) {
        if(i + 1 == p){
            continue;
        }
        else if(minTav > Tavolsag(points[i].x, points[i].y, points[p - 1].x, points[p - 1].y)){
            int valid = 1;
            for (int j = 0; j < m; ++j) {
                if(i == latogatott[j]){
                    valid = 0;
                }
            }
            minTav = Tavolsag(points[i].x, points[i].y, points[p - 1].x, points[p - 1].y);
            minIndex = i + 1;
        }
    }

    return minIndex;
}

float korutHossz(int n, int p, pont * pontok){
    int *latogatottIndex;
    latogatottIndex = malloc(n * sizeof (int));

    while()
}

int main()
{
    int n, p;
    pont *pontok;

    scanf("%d%d", &n, &p);

    pontok = malloc(n * sizeof (pont));

    for (int i = 0; i < n; ++i) {
        scanf("%f%f", pontok[i].x, pontok[i].y);
    }


}