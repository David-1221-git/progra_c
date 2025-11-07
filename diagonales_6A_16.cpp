#include <stdio.h>

#define MAX 5

int main() {
    int m, n;
    int matriz[MAX][MAX];
    int opcion;

    printf("Ingrese el número de filas (máx 5): ");
    scanf("%d", &m);
    printf("Ingrese el número de columnas (máx 5): ");
    scanf("%d", &n);

    if(m > 5 || n > 5) {
        printf("Las dimensiones exceden el tamaño máximo (5x5).\n");
        return 1;
    }

    printf("\nElija una opción:\n");
    printf("1. Diagonal principal\n");
    printf("2. Diagonal inversa\n");
    printf("3. Ambas diagonales\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("\nMatriz con diagonal principal:\n");
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == j) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = 0;
                    }
                }
            }
            break;

        case 2:
            printf("\nMatriz con diagonal inversa:\n");
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(i + j == (n - 1)) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = 0;
                    }
                }
            }
            break;

        case 3:
            printf("\nMatriz con diagonal principal:\n");
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == j) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = 0;
                    }
                }
            }
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    printf("%d\t", matriz[i][j]);
                }
                printf("\n");
            }
            printf("\nMatriz con diagonal inversa:\n");
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(i + j == (n - 1)) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = 0;
                    }
                }
            }
            break;

        default:
            printf("Opción no válida.\n");
            return 1;
    }

    if(opcion == 1 || opcion == 2) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}