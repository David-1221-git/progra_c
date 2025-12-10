#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

void opcionCosechas();
void opcionMatriz();

int main() {
    int opcion;

    do {
        printf("\n--Bienvenido al programa porfavor elija una de las siguientes opciones--\n");
        printf("1. Analisis de cosechas anuales\n");
        printf("2. Procesamiento de matriz 5x5\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion porfavor: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                opcionCosechas();
                break;
            case 2:
                opcionMatriz();
                break;
            case 3:
                printf("Esta saliendo del programa vuelva pronto\n");
                break;
            default:
                printf("Opcion invalida porfavor intente de nuevo.\n");
        }
    } while (opcion != 3);

    return 0;
}


void opcionCosechas() {
    const int N = 12;
    double cosechas[N];
    double promedio = 0.0;
    int i;
    srand((unsigned int)time(NULL));
    for (i = 0; i < N; i++) {
        cosechas[i] = 50.0 + (rand() % 151) + (rand() % 100) / 100.0;
        printf("Mes %d: %.2f\n", i + 1, cosechas[i]);
        promedio += cosechas[i];
    }

    promedio /= N;

    int contadorSuperiores = 0;
    for (i = 0; i < N; i++) {
        if (cosechas[i] > promedio) {
            contadorSuperiores++;
        }
    }

    double maxToneladas = cosechas[0];
    int mesMaximo = 0;
    for (i = 1; i < N; i++) {
        if (cosechas[i] > maxToneladas) {
            maxToneladas = cosechas[i];
            mesMaximo = i;
        }
    }

    printf("\n--- RESULTADOS DE LAS COSECHAS SON ---\n");
    printf("El promedio anual es: %.2f\n", promedio);
    printf("Los meses superiores al promedio son: %d\n", contadorSuperiores);
    printf("La mayor cosecha es: %.2f en el mes %d\n", maxToneladas, mesMaximo + 1);
}
void opcionMatriz() {
    int m[MAX][MAX];
    int min[MAX * MAX];
    int max_arr[MAX * MAX];
    int filas, col, x;
    int i, j;

    printf("\n---ACONTINUACION INGRESE EL TAMAÑO DE LA MATRIZ (max 5x5)---\n");
    printf("Ingrese numero de filas (1-5): ");
    scanf("%d", &filas);
    printf("Ingrese numero de columnas (1-5): ");
    scanf("%d", &col);

    if (filas < 1 || filas > MAX || col < 1 || col > MAX) {
        printf("Error: dimensiones deben estar entre 1 y %d.\n", MAX);
        return;
    }

    for (i = 0; i < filas; i++) {
        for (j = 0; j < col; j++) {
            m[i][j] = rand() % 11; 
        }
    }
    printf("Ingrese el valor de x: ");
    scanf("%d", &x);

    int count = 0;
    int idx_min = 0;
    int idx_max = 0;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < col; j++) {
            if (m[i][j] == x) {
                count++;
            } else if (m[i][j] < x) {
                min[idx_min++] = m[i][j];
            } else {
                max_arr[idx_max++] = m[i][j];
            }
        }
    }

    printf("\n---LOS RESULTADOS DE MATRIZ SON---\n");
    printf("El valor de x(%d) aparece %d veces\n", x, count);

    if (idx_min == 0) {
        printf("No hay elementos menores que x(%d)\n", x);
    } else {
        printf("Los elementos menores que x(%d) son: ", x);
        for (i = 0; i < idx_min; i++) {
            printf("%d ", min[i]);
        }
        printf("\n");
    }

    if (idx_max == 0) {
        printf("No hay elementos mayores que x(%d)\n", x);
    } else {
        printf("Los elementos mayores que x(%d) son: ", x);
        for (i = 0; i < idx_max; i++) {
            printf("%d ", max_arr[i]);
        }
        printf("\n");
    }
}