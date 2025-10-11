/*Nombre del proyecto:Ejercicio 3 pág 77 Numero 1_v1
Elaboro:Merino Dominguez David  No Lista:16
Fecha:10/octubre/2025        No. Vercion:1
Descripcion:En un supermercado, se realizan descuentos por las compras a partir de unas bolitas de colores:
Verde 20%, amarilla 25%, negra del 30%; la blanca no aplica ningún descuento. 
Leer el importe de la compra y el color de la bolita e imprimir lo que debe pagar dicho cliente.*/
#include <stdio.h>

int main() {
    float compra, descuento = 0.0, total;
    int opcion;

    printf("Ingrese el importe de la compra: $");
    scanf("%f", &compra);

    printf("Seleccione el color de la bolita:\n");
    printf("1. Verde (20%% de descuento)\n");
    printf("2. Amarilla (25%% de descuento)\n");
    printf("3. Negra (30%% de descuento)\n");
    printf("4. Blanca (sin descuento)\n");
    printf("Ingrese su opción (1-4): ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            descuento = 0.20;
            break;
        case 2:
            descuento = 0.25;
            break;
        case 3:
            descuento = 0.30;
            break;
        case 4:
            descuento = 0.00;
            break;
        default:
            printf("Opción inválida. No se aplica descuento.\n");
            descuento = 0.00;
    }

    total = compra - (compra * descuento);
    printf("Debe pagar: $%.2f\n", total);

    return 0;
}