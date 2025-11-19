#include <stdio.h>

int main() {
    int arr[20];
    int suma_pares = 0;
    int mayor_impar = -1;   
    int pos_mayor_par = -1;
    int mayor_par = -1;

    printf("Ingrese 20 números enteros:\n");
    for (int i = 0; i < 20; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }


    for (int i = 0; i < 20; i++) {
        if (i % 2 == 0) {
            suma_pares += arr[i];
            if (arr[i] > mayor_par) {
                mayor_par = arr[i];
                pos_mayor_par = i;
            }
        } else { 
            if (arr[i] % 2 != 0) { 
                if (arr[i] > mayor_impar) {
                    mayor_impar = arr[i];
                }
            }
        }
    }


    printf("\na) Suma de elementos en posiciones pares: %d\n", suma_pares);
    
    if (mayor_impar == -1) {
        printf("b) No hay elementos impares en posiciones impares.\n");
    } else {
        printf("b) Mayor elemento en posiciones impares: %d\n", mayor_impar);
    }

    if (pos_mayor_par == -1) {
        printf("c) No hay elementos pares en posiciones pares.\n");
    } else {
        printf("c) Posición del mayor número par (en posiciones pares): %d (valor: %d)\n", pos_mayor_par, mayor_par);
    }

    return 0;
}