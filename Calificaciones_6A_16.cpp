#include <stdio.h>
#include <stdlib.h>

#define m 30
#define c 4
#define max 30
#define act 4
#define tip 2

int main() {
    int opcion;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Ejecutar Programa 1 - Cálculo de Promedios (Matriz 2D)\n");
        printf("2. Ejecutar Programa 2 - Matriz 3D (Calif. + Promedio)\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            int fil, i, j, prom, promt;
            int par[m];
            int cali[m][c];

            printf("\n=== PROGRAMA 1: Cálculo de Promedios ===\n");
            printf("Ingresa el numero de estudiantes (1-30): ");
            scanf("%d", &fil);

            if (fil < 1 || fil > m) {
                printf("Número de estudiantes fuera de rango.\n");
            } else {
                int error = 0;
                for (i = 0; i < fil; i++) {
                    prom = 0;
                    for (j = 0; j < c; j++) {
                        printf("Calificación del estudiante %d en actividad %d: ", i+1, j+1);
                        scanf("%d", &cali[i][j]);

                        if (cali[i][j] < 0 || cali[i][j] > 10) {
                            printf("¡Calificación inválida! Debe estar entre 0 y 10.\n");
                            error = 1;
                            break;
                        }
                        prom += cali[i][j];
                    }
                    if (error) break;
                    promt = prom / c;
                    par[i] = promt;
                    printf("Promedio del estudiante %d: %d\n\n", i+1, promt);
                }
            }
            printf("Programa 1 finalizado.\n");

        } else if (opcion == 2) {
            int fil, i, j;
            int datos[max][act][tip];

            printf("\n=== PROGRAMA 2: Matriz 3D (Calif. + Promedio) ===\n");
            printf("Ingresa el numero de estudiantes (1-30): ");
            scanf("%d", &fil);

            if (fil < 1 || fil > max) {
                printf("Número de estudiantes fuera de rango.\n");
            } else {
                int error = 0;
                for (i = 0; i < fil; i++) {
                    int suma = 0;
                    for (j = 0; j < act; j++) {
                        printf("Calificación del estudiante %d en actividad %d: ", i+1, j+1);
                        scanf("%d", &datos[i][j][0]);

                        if (datos[i][j][0] < 0 || datos[i][j][0] > 10) {
                            printf("¡Calificación inválida! Debe estar entre 0 y 10.\n");
                            error = 1;
                            break;
                        }
                        suma += datos[i][j][0];
                    }
                    if (error) break;

                    int promedio = suma / act;
                    for (j = 0; j < act; j++) {
                        datos[i][j][1] = promedio; // Guarda el promedio en la segunda dimensión
                    }
                    printf("Promedio del estudiante %d: %d\n\n", i+1, promedio);
                }

                if (!error) {
                    // Mostrar matriz 3D completa
                    printf("\n--- MATRIZ 3D COMPLETA ---\n");
                    for (i = 0; i < fil; i++) {
                        printf("Estudiante %d:\n", i+1);
                        for (j = 0; j < act; j++) {
                            printf("  Actividad %d: calif=%d, prom=%d\n", j+1, datos[i][j][0], datos[i][j][1]);
                        }
                        printf("\n");
                    }
                }
            }
            printf("Programa 2 finalizado.\n");

        } else if (opcion == 3) {
            printf("\nSaliendo del programa... ¡Hasta pronto!\n");
        } else {
            printf("\nOpción inválida. Por favor, elige 1, 2 o 3.\n");
        }

    } while (opcion != 3);

    return 0;
}
