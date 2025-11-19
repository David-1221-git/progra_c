#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int vector[20];
    int lista1[20], lista2[20], lista3[20]; 
    int cont1 = 0, cont2 = 0, cont3 = 0;     
    srand(time(NULL));
    printf("Vector original:\n");
    for (int i = 0; i < 20; i++) {
        vector[i] = rand() % 151; 
        printf("%d ", vector[i]);
    }
    printf("\n\n");
    for (int i = 0; i < 20; i++) {
        if (vector[i] >= 0 && vector[i] <= 50) {
            lista1[cont1++] = vector[i];
        } else if (vector[i] >= 51 && vector[i] <= 100) {
            lista2[cont2++] = vector[i];
        } else if (vector[i] >= 101) {
            lista3[cont3++] = vector[i];
        }
    }

    printf("Lista 1 (0-50): ");
    for (int i = 0; i < cont1; i++) {
        printf("%d ", lista1[i]);
    }
    printf("\n");

    printf("Lista 2 (51-100): ");
    for (int i = 0; i < cont2; i++) {
        printf("%d ", lista2[i]);
    }
    printf("\n");

    printf("Lista 3 (>100): ");
    for (int i = 0; i < cont3; i++) {
        printf("%d ", lista3[i]);
    }
    printf("\n");

    return 0;
}