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

int number_digit_number_rec(int n, int i){
    if(n == 0)
        return i;
    else
        number_digit_number_rec(n / 10, ++i);
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

int power_rec(int a, int b){
    if(b == 0){
        return 1;
    }
    else
    {
        if(b % 2 == 0){
            int h = power_rec(a, b / 2);
            return h * h;
        }
        else{
            int h = power_rec(a, (b - 1) / 2);
            return h * h * a;
        }
    }
}

int *maxkereses(int *a, int n){
    if(n == 1){
        return a;
    }
    else{
        int *max = maxkereses(a+1, n-1);
        if(*a > *max){
            return a;
        }
        else {
            return max;
        }
    }
}

int max_kereses(int *a, int n){
    if(n == 0){
        return a[0];
    }
    else{
        int max = max_kereses(a, n-1);
        if(a[n] > max){
            return a[n];
        }
        else {
            return max;
        }
    }
}
int binariskereses(int *a, int ah, int fh, int szam){
    int kozep = (ah + fh) / 2;
    if(ah > fh){
        return -1;
    }
    if(a[kozep] == szam){
        return a[kozep];
    }
    else{
        if(szam > a[kozep]){
            binariskereses(a, kozep + 1, fh, szam);
        }
        else{
            binariskereses(a, ah, kozep - 1, szam);
        }
    }
}
bool letezik_e(int *a, int n, int szam){

}
//int hatvanyozas_1(int b, int exp);
//int hatvanyozas_2(int b, int exp);
//int lnko(int a, int b);

