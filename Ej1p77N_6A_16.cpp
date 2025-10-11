/*Nombre del proyecto:Ejercicio 1 pág 77 Numero 1_v1
Elaboro:Merino Dominguez David  No Lista:16
Fecha:10/octubre/2025        No. Vercion:1
Descripcion:Leer un número entero obtenido al lanzar un dado de seis caras e imprimir el número en 
letras de la cara opuesta. En las caras opuestas de un dado de seis caras están los números: 1-6, 2-5 
y 3-4. Si el número del dado capturado es menor que 1 o 
mayor que 6, se mostrará: “Un DADO no tiene ese número”*/
#include <stdio.h>

int main() {
    int dado;

    printf("Ingrese el número obtenido al lanzar el dado (1-6): ");
    scanf("%d", &dado);

    if (dado < 1 || dado > 6) {
        printf("Un DADO no tiene ese número\n");
    } else {
        int opuesto;
        switch(dado) {
            case 1: opuesto = 6; break;
            case 2: opuesto = 5; break;
            case 3: opuesto = 4; break;
            case 4: opuesto = 3; break;
            case 5: opuesto = 2; break;
            case 6: opuesto = 1; break;
        }
        printf("La cara opuesta es: %d\n", opuesto);
    }

    return 0;
}