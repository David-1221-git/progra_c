#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int op;
    char seg;

    do {
        printf("\n=== MENÚ PRINCIPAL ===\n");
        printf("1.-Analizar temperaturas de la semana\n");
        printf("2.-Simular saltos de atletas\n");
        printf("3.-Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &op);

        switch (op) {
            case 1: {
                //Programa 1
                const int dia = 7;
                float temp[dia];
                float dif[dia];
                float sum = 0.0, prom;
                float min_temp, max_temp;
                int dia_min = 0, dia_max = 0;

                printf("\nIngrese las temperaturas de los 7 días\n");
                for (int i = 0; i < dia; i++) {
                    printf("Día %d: ", i + 1);
                    scanf("%f", &temp[i]);
                    sum += temp[i];
                }

                prom = sum / dia;

                for (int i = 0; i < dia; i++) {
                    dif[i] = temp[i] - prom;
                }

                min_temp = max_temp = temp[0];
                for (int i = 1; i < dia; i++) {
                    if (temp[i] < min_temp) {
                        min_temp = temp[i];
                        dia_min = i;
                    }
                    if (temp[i] > max_temp) {
                        max_temp = temp[i];
                        dia_max = i;
                    }
                }

                printf("\n=== RESULTADOS ===\n");
                printf("Temperatura promedio: %.2f\n", prom);
                printf("Diferencias respecto al promedio:\n");
                for (int i = 0; i < dia; i++) {
                    printf("  Día %d: %+.2f\n", i + 1, dif[i]);
                }
                printf("Temperatura mínima: %.2f (Día %d)\n", min_temp, dia_min + 1);
                printf("Temperatura máxima: %.2f (Día %d)\n", max_temp, dia_max + 1);
                break;
            }

            case 2: {
                //Programa 2
                const int Atle = 4;
                const int Altu = 6;
                double lista_alturas[Altu] = {2.00, 2.10, 2.20, 2.30, 2.35, 2.40};
                int Alt[Atle][Altu];
                int V[Atle] = {0};     
                int A[Altu] = {0};      
                srand(time(NULL));
                for (int i = 0; i < Atle; i++) {
                    for (int j = 0; j < Altu; j++) {
                        Alt[i][j] = rand() % 2;
                    }
                }
                for (int i = 0; i < Atle; i++) {
                    for (int j = 0; j < Altu; j++) {
                        V[i] += Alt[i][j];
                        A[j] += Alt[i][j];
                    }
                }
                printf("\nRESULTADOS DE LOS SALTOS\n");
                printf("Matriz Alt (%d atletas x %d alturas):\n", Atle, Altu);
                printf("         ");
                for (int j = 0; j < Altu; j++) {
                    printf("%6.2f ", lista_alturas[j]);
                }
                printf("\n");
                for (int i = 0; i < Atle; i++) {
                    printf("Atleta %d: ", i + 1);
                    for (int j = 0; j < Altu; j++) {
                        printf("%6d ", Alt[i][j]);
                    }
                    printf("\n");
                }
                printf("\nVector V (saltos válidos por atleta):\n");
                for (int i = 0; i < Atle; i++) {
                    printf("Atleta %d: %d\n", i + 1, V[i]);
                }

                printf("\nVector A (saltos válidos por altura):\n");
                for (int j = 0; j < Altu; j++) {
                    printf("Altura %.2f: %d\n", lista_alturas[j], A[j]);
                }
                break;
            }
            case 3:
                printf("Esta saliendo del programa \n");
                break;

            default:
                printf("Opción inválida pruebe otra vez\n");
        }
        if (op != 3) {
            printf("\n¿Quiere regresal al menu? (s/n): ");
            scanf(" %c", &seg); 
        } else {
            seg = 'n';
        }

    } while (seg == 's' || seg == 'S');

    return 0;
}