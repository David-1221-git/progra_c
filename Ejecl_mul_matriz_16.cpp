#include <stdio.h>

#define MAX 10

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int m, q, p, n; // m x q y p x n

    // Pedir tamaño de la primera matriz
    printf("=== PRIMERA MATRIZ ===\n");
    printf("Ingrese número de filas: ");
    scanf("%d", &m);
    printf("Ingrese número de columnas: ");
    scanf("%d", &q);

    // Pedir tamaño de la segunda matriz
    printf("\n=== SEGUNDA MATRIZ ===\n");
    printf("Ingrese número de filas: ");
    scanf("%d", &p);
    printf("Ingrese número de columnas: ");
    scanf("%d", &n);

    if(q != p) {
        printf("\nError: Las matrices no se pueden multiplicar.\n");
        printf("Número de columnas de la primera (%d) debe ser igual al número de filas de la segunda (%d).\n", q, p);
        return 1;
    }

    // Pedir datos de la primera matriz elemento por elemento
    printf("\nIngrese los elementos de la primera matriz (%dx%d):\n", m, q);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < q; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    // Pedir datos de la segunda matriz elemento por elemento
    printf("\nIngrese los elementos de la segunda matriz (%dx%d):\n", p, n);
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    // Inicializar matriz resultado
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    // Multiplicar matrices
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < q; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\n=== RESULTADO ===\n");
    printf("Resultado de la multiplicación:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
