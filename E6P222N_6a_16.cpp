#include <stdio.h>
void leerVector(int *vec, int n) {
    printf("Ingrese %d numeros enteros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &vec[i]);
    }
}
int contarPares(int *vec, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}
int contarImpares(int *vec, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}
int encontrarMaximo(int *vec, int n) {
    int max = vec[0];
    for (int i = 1; i < n; i++) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }
    return max;
}
int contarMaximo(int *vec, int n, int max) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i] == max) {
            count++;
        }
    }
    return count;
}
int main() {
    int n;

    printf("Ingrese la cantidad de elementos (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("La cantidad debe ser positiva.\n");
        return 1;
    }
    int vector[n];
    leerVector(vector, n);
    int pares = contarPares(vector, n);
    int impares = contarImpares(vector, n);
    int maximo = encontrarMaximo(vector, n);
    int repeticionesMax = contarMaximo(vector, n, maximo);
    printf("\n--- Resultados ---\n");
    printf("Cantidad de valores pares: %d\n", pares);
    printf("Cantidad de valores impares: %d\n", impares);
    printf("Valor máximo del arreglo: %d\n", maximo);
    printf("Veces que se repite el valor máximo: %d\n", repeticionesMax);

    return 0;
}