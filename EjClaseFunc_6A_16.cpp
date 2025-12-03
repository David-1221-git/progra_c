#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaración de funciones
void encmayo();         
void prommatr();
void burbuja(int vec[], int n);

int main() {
    srand(time(NULL));

    int opcion;

    do {
        printf("\nBienvenido al programa porfavor elija una opcion del menu\n");
        printf("1. Encontrar el mayor de tres numeros (ingresados por usuario)\n");
        printf("2. Calcular promedio de una matriz ALEATORIA (max 10x10)\n");
        printf("3. Ordenar un vector ALEATORIO (max 30 elementos) con burbuja\n");
        printf("4. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                encmayo();
                break;
            case 2:
                prommatr();
                break;
            case 3: {
                int vec[30];
                int n;
                printf("Ingrese la cantidad de elementos (1 a 30): ");
                scanf("%d", &n);
                if (n <= 0 || n > 30) {
                    printf("Cantidad invalida.\n");
                    break;
                }
                printf("El vector generado es:\n");
                for (int i = 0; i < n; i++) {
                    vec[i] = rand() % 100;  
                    printf("%d ", vec[i]);
                }
                printf("\n");
                burbuja(vec, n);
                printf("El vector ordenado es:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", vec[i]);
                }
                printf("\n");
                break;
            }
            case 4:
                printf("Esta saliendo del programa\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 0);

    return 0;
}
void encmayo() {
    int a, b, c, mayor;
    printf("Ingrese tres numeros enteros: ");
    scanf("%d %d %d", &a, &b, &c);
    mayor = a;
    if (b > mayor) mayor = b;
    if (c > mayor) mayor = c;

    printf("El numero mayor es: %d\n", mayor);
}
void prommatr() {
    int matriz[10][10];
    int m, n;
    int suma = 0;
    float promedio;
    printf("Ingrese filas y columnas (1 a 10): ");
    scanf("%d %d", &m, &n);
    if (m <= 0 || m > 10 || n <= 0 || n > 10) {
        printf("Dimensiones invalidas.\n");
        return;
    }
    printf("La matriz generada es:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100; 
            suma += matriz[i][j];
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
    promedio = (float)suma / (m * n);
    printf("\nEl promedio de la matriz es: %.2f\n", promedio);
}
void burbuja(int vec[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}