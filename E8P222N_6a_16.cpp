#include <stdio.h>

void imprimirArbol(int base) {
    int filas = (base + 1) / 2;
    for (int i = 1; i <= filas; i++) {
        int asteriscos = 2 * i - 1;
        int espacios = (base - asteriscos) / 2;
        for (int j = 0; j < espacios; j++) printf(" ");
        for (int j = 0; j < asteriscos; j++) printf("*");
        printf("\n");
    }
}

void imprimirRectangulo(int altura, int ancho, int anchoTotal) {
    int espacios = (anchoTotal - ancho) / 2;
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < espacios; j++) printf(" ");
        for (int j = 0; j < ancho; j++) printf("*");
        printf("\n");
    }
}

int main() {
    int base, h_rect, anc_rect;
    printf("Base del triangulo (impar): ");
    scanf("%d", &base);
    printf("Altura del rectangulo: ");
    scanf("%d", &h_rect);
    printf("Ancho del rectangulo: ");
    scanf("%d", &anc_rect);

    printf("\n");
    imprimirArbol(base);
    imprimirRectangulo(h_rect, anc_rect, base);
    return 0;
}