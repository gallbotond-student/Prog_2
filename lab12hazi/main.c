#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("penzek.txt", "r");
    if(!f) {
        printf("File not found");
        return 1;
    }

    int n, *bankNotes;

    fscanf(f, "%d", &n);

    bankNotes = malloc(n * sizeof (int));

    if(!bankNotes) {
        printf("Allocation failed");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        fscanf(f, "%d", &bankNotes[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(bankNotes[i] > bankNotes[j]) {
                int swap = bankNotes[i];
                bankNotes[i] = bankNotes[j];
                bankNotes[j] = swap;
            }
        }
    }

    printf("\n");

    for (int i = 0; i < n; ++i) {
        printf("%d ", bankNotes[i]);
    }

    int amount, count = 0;
    fscanf(f, "%d", &amount);

    printf("\nPayed: ");
    while(amount) {
        if(amount / bankNotes[--n] > 0) {
            printf("%dx%d ",amount / bankNotes[n], bankNotes[n]);
            amount %= bankNotes[n];
        }
    }

    fclose(f);
    free(bankNotes);
}
