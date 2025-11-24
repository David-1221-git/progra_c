#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15

int main() {
    int n;
    int matriz[MAX_SIZE][MAX_SIZE];
    int i, j;
    int sim = 1, ident = 1, tri_sup = 1, tri_inf = 1;
    srand(time(NULL));
    printf("Ingrese el tamano de la matriz cuadrada (maximo 15): ");
    scanf("%d", &n);
    if (n < 1 || n > 15) {
        printf("Tamano invalido. Debe estar entre 1 y 15.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = rand() % 2; 
        }
    }
    printf("\nMatriz generada (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                sim = 0;
                break;
            }
        }
        if (!sim) break;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                if (matriz[i][j] != 1) {
                    ident = 0;
                    break;
                }
            } else {
                if (matriz[i][j] != 0) {
                    ident = 0;
                    break;
                }
            }
        }
        if (!ident) break;
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (matriz[i][j] != 0) {
                tri_sup = 0;
                break;
            }
        }
        if (!tri_sup) break;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (matriz[i][j] != 0) {
                tri_inf = 0;
                break;
            }
        }
        if (!tri_inf) break;
    }
    printf("\nEl resultado de la matriz es : \n");
    if (sim)
        printf("La matriz es simetrica.\n");
    else
        printf("La matriz NO es simetrica.\n");
    if (ident)
        printf("La matriz es identidad.\n");
    else
        printf("La matriz NO es identidad.\n");
    if (tri_sup)
        printf("La matriz es triangular superior.\n");
    else
        printf("La matriz NO es triangular superior.\n");
    if (tri_inf)
        printf("La matriz es triangular inferior.\n");
    else
        printf("La matriz NO es triangular inferior.\n");
    return 0;
}