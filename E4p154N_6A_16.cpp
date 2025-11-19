#include <stdio.h>

int main() {
    int arr[30];
    int n;
    int suma_pares = 0, suma_impares = 0, suma_total = 0;

    printf("Ingrese la cantidad de elementos (máximo 30): ");
    scanf("%d", &n);

    if (n > 30 || n <= 0) {
        printf("Cantidad inválida. Debe estar entre 1 y 30.\n");
        return 1;
    }

    printf("Ingrese %d números enteros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        suma_total += arr[i];
        if (arr[i] % 2 == 0) {
            suma_pares += arr[i];
        } else {
            suma_impares += arr[i];
        }
    }

    printf("\na) Suma de números pares: %d\n", suma_pares);
    printf("b) Suma de números impares: %d\n", suma_impares);
    printf("c) Suma total de los elementos: %d\n", suma_total);

    return 0;
}