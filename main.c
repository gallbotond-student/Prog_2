#include <stdio.h>
#include "stdlib.h"

typedef struct Person {
    char firstName[20], lastName[20];
    int gender;
    int age;
    int floor;
} PERSON;

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
        printf("%s %s: %s, age: %d, %d. floor\n",
               persons[i].firstName,
               persons[i].lastName,
               persons[i].gender % 2 == 0 ? "male" : "female",
               persons[i].age,
               persons[i].floor);
        avg += persons[i].age;
    }

    printf("Average age: %.2f\nOrder: \n", avg / n);

    for (int i = 0; i < n; ++i) {
        printf("%s %s: %d\n", persons[i].firstName, persons[i].lastName, i + 1);
    }

    // negyedik alpont
    for (int i = 0; i < n; ++i) {
        printf("\n");
        for (int j = i; j < n; ++j) {
            if(i != j){
                printf("%s %s - %s %s\n", persons[i].firstName, persons[i].lastName, persons[j].firstName, persons[j].lastName);
            }
        }
    }
}
