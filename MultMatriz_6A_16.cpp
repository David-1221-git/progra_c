/*Nombre del proyecto:Multiplicacion de matrices 1_v1
Elaboro:Merino Dominguez David  No Lista:16
Fecha:06/Noviembre/2025        No. Vercion:1
Descripcion:Realizar un código de multiplicación de dos matrices de máximo 10X10.*/
#include <stdio.h>

#define MAX 10

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int m, q, p, n;
    printf("=== PRIMERA MATRIZ ===\n");
    printf("Ingrese número de filas: ");
    scanf("%d", &m);
    printf("Ingrese número de columnas: ");
    scanf("%d", &q);
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

    printf("\nIngrese los elementos de la primera matriz (%dx%d):\n", m, q);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < q; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nIngrese los elementos de la segunda matriz (%dx%d):\n", p, n);
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

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
