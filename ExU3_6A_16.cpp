#include <stdio.h>

int main() {
    int opcion;
    int n, i;
    int a, b, siguiente;
    float Y, resultado;
    int salir = 0;  

    while (!salir) {
        printf("Bienvenido al menu del examen de fundamentos de programacion porfavor de ingresar una opcion valida\n");
        printf("1. Generar los primeros n terminos de la serie de Fibonacci\n");
        printf("2. Evaluar la funcion F(Y) para n valores\n");
        printf("3. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("\nIngresa el numero de terminos de Fibonacci: ");
            scanf("%d", &n);

            if (n <= 0) {
                printf("Por favor, ingresa un numero positivo.\n");
            } else {
                printf("Serie de Fibonacci:\n");
                a = 0;
                b = 1;
                for (i = 1; i <= n; i++) {
                    if (i == 1) {
                        printf("%d ", a);
                    } else if (i == 2) {
                        printf("%d ", b);
                    } else {
                        siguiente = a + b;
                        printf("%d ", siguiente);
                        a = b;
                        b = siguiente;
                    }
                }
                printf("\n");
            }
        }
        else if (opcion == 2) {
                printf("Ingresa el valor de Y %d: ", i);
                scanf("%f", &Y);
                if (Y > 0 && Y <= 15) {
                    resultado = (Y * Y) + 15;
                }
                else if (Y > 15 && Y <= 30) {
                    resultado = (Y * Y * Y) - (Y * Y) + 12;
                }
                else if (Y > 30 && Y <= 60) {
                    resultado = 4 * ((Y*Y*Y)/(Y*Y)) + 8; 
                }
                else {
                    resultado = 0; 
                }
                printf("F(%.2f) = %.2f\n", Y, resultado);
            
        }
        else if (opcion == 3) {
            printf("Esta saliendo del programa asta la proxima\n");
            salir = 1; 
        }
        else {
            printf("Esa no es una opcion valida.\n");
        }
    }

    return 0;
}