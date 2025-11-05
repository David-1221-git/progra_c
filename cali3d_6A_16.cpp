#include <stdio.h>
#define MAX_ESTUDIANTES 30
#define ACTIVIDADES 4
#define TIPOS 2  // 0 = calificación, 1 = promedio

int main() {
    int fil, i, j;
    int datos[MAX_ESTUDIANTES][ACTIVIDADES][TIPOS]; // [est][act][0=calif, 1=prom]

    printf("Ingresa el numero de estudiantes (1-30):\n");
    scanf("%d", &fil);

    if (fil < 1 || fil > MAX_ESTUDIANTES) {
        printf("Número de estudiantes fuera de rango.\n");
        return 1;
    }

    // Paso 1: Leer calificaciones y calcular promedio
    for (i = 0; i < fil; i++) {
        int suma = 0;
        // Leer las 4 calificaciones
        for (j = 0; j < ACTIVIDADES; j++) {
            printf("Calificación del estudiante %d en actividad %d: ", i + 1, j + 1);
            scanf("%d", &datos[i][j][0]); // tipo 0 = calificación

            if (datos[i][j][0] < 0 || datos[i][j][0] > 10) {
                printf("Calificación inválida (debe estar entre 0 y 10). Intente de nuevo.\n");
                return 1;
            }
            suma += datos[i][j][0];
        }
        int promedio = suma / ACTIVIDADES;

        // Guardar el promedio en la tercera dimensión (tipo 1) para todas las actividades
        for (j = 0; j < ACTIVIDADES; j++) {
            datos[i][j][1] = promedio; // tipo 1 = promedio del estudiante
        }

        printf("El promedio del estudiante %d es: %d\n\n", i + 1, promedio);
    }

    // Opcional: mostrar toda la matriz 3D
    printf("\n--- Matriz 3D: [estudiante][actividad][0=calif,1=prom] ---\n");
    for (i = 0; i < fil; i++) {
        printf("Estudiante %d:\n", i + 1);
        for (j = 0; j < ACTIVIDADES; j++) {
            printf("  Actividad %d: calif=%d, prom=%d\n",
                   j + 1,
                   datos[i][j][0],
                   datos[i][j][1]);
        }
        printf("\n");
    }

    return 0;
}