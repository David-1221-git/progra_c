#include <stdio.h>

int main() {
    int n, m;
    int matriz[10][10];
    int vector_max_col[10]; // Vector que guardará el máximo de cada columna

    printf("Ingrese el número de filas (n): ");
    scanf("%d", &n);
    printf("Ingrese el número de columnas (m): ");
    scanf("%d", &m);

    if (n > 10 || m > 10 || n <= 0 || m <= 0) {
        printf("Dimensiones inválidas. Deben estar entre 1 y 10.\n");
        return 1;
    }

    // Ingresar elementos de la matriz
    printf("\nIngrese los elementos de la matriz %d x %d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int j = 0; j < m; j++) { 
        int max_col = matriz[0][j];
        for (int i = 1; i < n; i++) { 
            if (matriz[i][j] > max_col) {
                max_col = matriz[i][j];
            }
        }
        vector_max_col[j] = max_col; 
    }

    
    printf("\nVector con el máximo de cada columna:\n");
    for (int j = 0; j < m; j++) {
        printf("%d ", vector_max_col[j]);
    }
    printf("\n");

    return 0;
}