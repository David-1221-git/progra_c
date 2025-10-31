#include <stdio.h>
//defino un tamaño maximo de las matrices
#define t 100

int main() {
    int fil, col;
    int m1[t][t];
    int m2[t][t];
    int suma[t][t];
    int i, j;
//pido el tamaño de las matrices 
    printf("Numero de filas: ");
    scanf("%d", &fil);
    printf("Numero de columnas: ");
    scanf("%d", &col);//verifico que el tamaño de las matrices esten en el tamaño que defini
    if (fil < 1 || col < 1 || fil > t || col > t) {
        printf("Error: dimensiones invalidas.\n");
        return 1;
    }
//pido los datos de la matriz 1 
    printf("\nIngresa los datos de la Matriz 1:\n");
    for (i = 0; i < fil; i++) {
        for (j = 0; j < col; j++) {
            printf("M1[%d][%d] = ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }
//pido los datos de la matriz 2 
    printf("\nIngresa los datos de la Matriz 1:\n");
    for (i = 0; i < fil; i++) {
        for (j = 0; j < col; j++) {
            printf("M2[%d][%d] = ", i, j);
            scanf("%d", &m2[i][j]);  
        }
    }
//sumo las 2 matrices 
    for (i = 0; i < fil; i++) {
        for (j = 0; j < col; j++) {
            suma[i][j] = m1[i][j] + m2[i][j];
        }
    }
//muestro el resultado 
    printf("\nEl resultado es:\n");
    for (i = 0; i < fil; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", suma[i][j]);
        }
        printf("\n");
    }

    return 0;
}