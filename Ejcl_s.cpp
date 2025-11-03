#include <stdio.h>

int main() {
    int opcion;
    int n, i;
    int a, b, siguiente, proceso;
    float resultado;
    int salir = 0;  

    while (!salir) {
        printf("Bienvenido al menu del examen de fundamentos de programacion porfavor de ingresar una opcion valida\n");
        printf("1. Generar los primeros n terminos de la serie de Fibonacci\n");
        printf("2. N factorial\n");
        printf("3. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("\nIngresa el numero de terminos de Fibonacci: ");
            scanf("%d", &n);

            if (n <= 0) {
                printf("Por favor, ingresa un numero positivo.\n");
            } else {//codigo de fibonacci
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
        }//codigo de N factorial
        else if (opcion == 2) {
            printf("Ingresa el numero para calcular su factorial: ");
            scanf("%d", &n);

            if (n < 0) {
                printf("El factorial no esta definido para numeros negativos.\n");
            } else {
                int factorial = 1;
                for (i = 1; i <= n; i++) {
                    factorial *= i;
                }
                printf("El factorial de %d es: %d\n", n, factorial);
            }
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