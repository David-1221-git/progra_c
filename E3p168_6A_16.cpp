#include <stdio.h>

int main() {
    int m, n;
    int matriz[10][10];
    int suma = 0;
    float promedio;
    int frecuencia[1000] = {0}; 
    int moda = 0, max_frecuencia = 0;

    printf("Ingrese el número de filas (m): ");
    scanf("%d", &m);
    printf("Ingrese el número de columnas (n): ");
    scanf("%d", &n);

    if (m > 10 || n > 10 || m <= 0 || n <= 0) {
        printf("Dimensiones inválidas. Deben estar entre 1 y 10.\n");
        return 1;
    }

    printf("\nIngrese los elementos de la matriz %d x %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
            suma += matriz[i][j]; 
            frecuencia[matriz[i][j] + 500]++; 
        }
    }

    promedio = (float)suma / (m * n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int valor = matriz[i][j];
            int freq_actual = frecuencia[valor + 500];
            if (freq_actual > max_frecuencia) {
                max_frecuencia = freq_actual;
                moda = valor;
            }
        }
    }

    // Imprimir resultados
    printf("\na) Suma de los elementos: %d\n", suma);
    printf("b) Promedio de los elementos: %.2f\n", promedio);
    printf("c) Moda (elemento que más se repite): %d\n", moda);

    return 0;
}