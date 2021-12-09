#include <stdio.h>
#include "stdlib.h"
#include "functions.h"

int main() {
    int *t, n = 10;
    FILE *f, *g;

    f = fopen("input.txt", "r");
    g = fopen("output.txt", "w+");
//
//    fscanf(f, "%d", &n);
//
    t = (int *)malloc(n * sizeof (int));
//
    read(f, t, n);
//    read_rec(f, t, n, 0);
//
    print(g, t, n);
//    print_rec(g, t, n, 0);
//
//    printf("\n%d %d", sum(t, n), sum_rec(t, n, 0));
//    printf(is_in_array_rec(t, n, 0) ? "\n0 is in the array" : "\nno 0 is in the array");
//    printf("\n%d ", insert_digit_number(1234));
//    printf("\n%d ", number_digit_number_rec(123784, 0));
//    printf("\n%d ", power_rec(2, 3));
//    printf("\n%d ", *maxkereses(t, n));
    printf("\n%d ", binariskereses(t, 0, n - 1, 9));
}
