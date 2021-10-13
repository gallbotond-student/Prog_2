//
// Created by Botond on 13/10/2021.
//

#include "functions.h"
#include "stdlib.h"

//n elemű számsorozat beolvasása iteratívan
void read(FILE *f, int *a, int n) {

    if(f == NULL) {
        printf("File does not exist.\n");
        return;
    }

    for (int i = 0; i < n; ++i) {
        fscanf(f, "%d", &a[i]);
    }
}
//n elemű számsorozat kiírása iteratívan
void print(FILE *f, int *a, int n) {

    if(f == NULL) {
        printf("File does not exist.\n");
        return;
    }

    for (int i = 0; i < n; ++i) {
        fprintf(f, "%d ", a[i]);
    }
}
//n elemű számsorozat beolvasása rekurzívan
void read_rec(FILE *f, int *a, int n, int i) {
    if(i == n) {
        return;
    }
    else {
        fscanf(f, "%d", &a[i++]);
        read_rec(f, a, n, i);
    }
}
//n elemű számsorozat kiírása rekurzívan
void print_rec(FILE *f, int *a, int n, int i) {
    if(i == n) {
        return;
    }
    else {
        fprintf(f, "%d ", a[i++]);
        print_rec(f, a, n, i);
    }
}
//n elemű számsorozat elemeinek összege iteratívan
int sum(int *a,int n) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
        sum += a[j];
    }

    return sum;
}
//n elemű számsorozat elemeinek összege rekurzívan
int sum_rec(int *a,int n,int i) {
    if(i == n - 1) {
        return a[i];
    }
    else {
        return a[i++] + sum_rec(a, n, i);
    }
}
//n elemű számsorozatban előfordul-e a nulla iteratívan
int is_in_array(int *a,int n) {
    for (int j = 0; j < n; ++j) {
        if(a[j] == 0)
            return 1;
    }
    return 0;
}
//n elemű számsorozatban előfordul-e a nulla rekurzívan
int is_in_array_rec(int *a,int n, int i) {
    if(i == n) {
        return 0;
    }
    else if(a[i] == 0){
        return 1;
    }
    else {
        is_in_array_rec(a, n, ++i);
    }
}
//szám számjegyeinek a kiírása
void print_digit_number(int n){
    while(n){
        printf("%d ", n % 10);
        n /= 10;
    }
}
//szám számjegyeinek a száma
int number_digit_number(int n){
    int i;
    for ( i = 0; n != 0; ++i) {
        n /= 10;
    }

    return i;
}
//szám páros számjegyeinek a kitörlése
int delete_digit_number(int n) {
    int num = 0, ten = 1;
    while (n) {
        if(n % 10 % 2 == 1) {
            num = n % 10 * ten + num;
            ten *= 10;
        }
        n /= 10;
    }

    return num;
}
//szám páros számjegyei után a 9-es számjegy beszúrása
int insert_digit_number(int n){
    int num = 0, ten = 1;
    while (n) {
        if(n % 10 % 2 == 0) {
            num = (n % 10) * (ten * 10) + (9 * ten) + num;
            ten *= 100;
        }
        else{
            num = n % 10 * ten + num;
            ten *= 10;
        }
        n /= 10;
    }

    return num;
}

