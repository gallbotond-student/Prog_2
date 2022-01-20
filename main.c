#include <stdio.h>
#include "stdlib.h"
#include "limits.h"

#define INF INT_MAX

typedef struct Person {
    char firstName[20], lastName[20];
    int gender;
    int age;
    int floor;
} PERSON;

// hatodik alpont
int oddNumbers(int n) {
    if(n == 0) return 0;
    if(n % 10 % 2 == 0) return oddNumbers(n / 10);
    else return oddNumbers(n / 10) + 1;
}

/* A utility function to print solution */
void printSolution(int **dist, int n)
{
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall (int **distances, int n)
{
    int i, j, k;

    for (k = 0; k < n; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < n; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < n; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (distances[i][k] + distances[k][j] < distances[i][j])
                    distances[i][j] = distances[i][k] + distances[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(distances, n);
}

int legkozelebbiszomszed(int akt, int **a, int n, int *visited){
    int minertek = INT_MAX, minpoz;
    for( int j = 0 ; j < n ; ++j ){
        if( a[akt][j] == 0 || visited[j] == 1 ){
            continue;
        }
        if( a[akt][j] < minertek ){
            minertek = a[akt][j];
            minpoz = j;
        }
    }
    if( minertek == INT_MAX ){
        return -1;
    }
    else{
        return minpoz;
    }
}

int main() {
    FILE *f = fopen("input.txt", "r");

    int n;

    fscanf(f, "%d", &n);

    PERSON *persons = malloc(n * sizeof(PERSON));

    for (int i = 0; i < n; ++i) {
        fscanf(f, "%s%s%d%d%d",
               persons[i].firstName,
               persons[i].lastName,
               &persons[i].gender,
               &persons[i].age,
               &persons[i].floor);
    }

    // harmadik alpont
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(persons[j].floor < persons[i].floor) {
                PERSON swap = persons[i];
                persons[i] = persons[j];
                persons[j] = swap;
            }
        }
    }

    float avg = 0;

    // elso, masodik alpont
    for (int i = 0; i < n; ++i) {
        printf("(%d) %s %s: %s, age: %d, %d. floor\n",
               i+1,
               persons[i].firstName,
               persons[i].lastName,
               persons[i].gender % 2 == 0 ? "male" : "female",
               persons[i].age,
               persons[i].floor);
        avg += persons[i].age;
    }

//    printf("Average age: %.2f\nOrder: \n", avg / n);

//    for (int i = 0; i < n; ++i) {
//        printf("%s %s: %d\n", persons[i].firstName, persons[i].lastName, i + 1);
//    }

    // otodik alpont
    int ** distances = malloc(n * sizeof (int *));
    for (int i = 0; i < n; ++i) {
        distances[i] = malloc(n * sizeof (int));
    }

    // negyedik alpont
    for (int i = 0; i < n; ++i) {
//        printf("\n");
        for (int j = i; j < n; ++j) {
            if(i != j){
//                printf("%s %s - %s %s\n", persons[i].firstName, persons[i].lastName, persons[j].firstName, persons[j].lastName);
                int distance = persons[i].age > persons[j].age ? persons[i].age - persons[j].age : persons[j].age - persons[i].age;
                distances[i][j] = distance;
                distances[j][i] = distance;
            }
            else{
                distances[i][j] = 0;
            }
        }
    }

    int num = 12321466;
//    printf("\nWrite a number: ");
//    scanf("%d", &num);
//    printf("Number of odd numbers in %d is: %d\nDistance matrix:\n", num, oddNumbers(num));

//    for (int i = 0; i < n; ++i) {
//        printf("\n");
//        for (int j = 0; j < n; ++j) {
//            printf("%d ", distances[i][j]);
//        }
//    }

    printf("\n\n");

    // otodik alpont

    floydWarshall(distances, n);

    int *visited = (int*)calloc(n,sizeof(int));
    int akt = 0, hossz = 0;
    visited[akt] = 1;
    for( int i = 1 ; i < n ; ++i ){
        int lksz = legkozelebbiszomszed(akt,distances,n,visited);
        if( lksz == -1 ){
            printf("Nincs korut!\n");
            return 0;
        }
        printf("%s %s - %s %s, distance: %d + %d\n",
               persons[akt].firstName,
               persons[akt].lastName,
               persons[lksz].firstName,
               persons[lksz].lastName,
               hossz,
               distances[akt][lksz]);
        hossz += distances[akt][lksz];
        akt = lksz; visited[akt] = 1;
    }
    if( distances[0][akt] != 0 ){
        printf("%s %s - %s %s\n", persons[akt].firstName, persons[akt].lastName, persons[0].firstName, persons[0].lastName);
        hossz += distances[akt][0];
        printf("Min-korut-hossz: %i\n", hossz);
    }
    else{
        printf("Nincs korut!\n");
    }


    for (int i = 0; i < n; ++i) {
        free(distances[i]);
    }

    free(persons);
    free(distances);
}
