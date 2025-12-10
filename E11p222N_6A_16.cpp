#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VECTOR 10
#define FILAS 5
#define COLS 5


void llenarImprimirVector(int vector[]);
void llenarColumnasImpares(int matriz[FILAS][COLS]);
void llenarColumnasPares(int matriz[FILAS][COLS]);
void imprimirMatrizYComunes(int matriz[FILAS][COLS], int vector[]);
void mostrarMenu();

int main() {
    srand(time(NULL)); 

    int vector[TAM_VECTOR];
    int matriz[FILAS][COLS];
    char opcion;

    do {
        mostrarMenu();
        printf("Elija una opción (a-e): ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case 'a':
            case 'A':
                llenarImprimirVector(vector);
                break;
            case 'b':
            case 'B':
                llenarColumnasImpares(matriz);
                break;
            case 'c':
            case 'C':
                llenarColumnasPares(matriz);
                break;
            case 'd':
            case 'D':
                imprimirMatrizYComunes(matriz, vector);
                break;
            case 'e':
            case 'E':
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 'e' && opcion != 'E');

    return 0;
}

void mostrarMenu() {
    printf("\n MENÚ \n");
    printf("a) Llenar e imprimir vector (25-75)\n");
    printf("b) Llenar columnas impares de la matriz (1-50)\n");
    printf("c) Llenar columnas pares de la matriz (51-100)\n");
    printf("d) Imprimir matriz y elementos comunes con el vector\n");
    printf("e) Salir\n");
}

void llenarImprimirVector(int vector[]) {
    printf("Llenando vector con números entre 25 y 75...\n");
    for (int i = 0; i < TAM_VECTOR; i++) {
        vector[i] = rand() % 51 + 25; 
    }

    printf("Vector generado:\n");
    for (int i = 0; i < TAM_VECTOR; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void llenarColumnasImpares(int matriz[FILAS][COLS]) {
    printf("Llenando columnas impares (1,3,5) con números entre 1 y 50...\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j % 2 == 0) { 
                matriz[i][j] = rand() % 50 + 1; 
            }
        }
    }
    printf("Columnas impares llenadas.\n");
}

void llenarColumnasPares(int matriz[FILAS][COLS]) {
    printf("Llenando columnas pares (2,4) con números entre 51 y 100...\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j % 2 == 1) {
                matriz[i][j] = rand() % 50 + 51; 
            }
        }
    }
    printf("Columnas pares llenadas.\n");
}

void imprimirMatrizYComunes(int matriz[FILAS][COLS], int vector[]) {
    printf("Matriz 5x5:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nElementos de la matriz que están en el vector:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            int encontrado = 0;
            for (int k = 0; k < TAM_VECTOR; k++) {
                if (matriz[i][j] == vector[k]) {
                    encontrado = 1;
                    break;
                }
            }
            if (encontrado) {
                printf("Matriz[%d][%d] = %d\n", i+1, j+1, matriz[i][j]);
            }
        }
    }
}