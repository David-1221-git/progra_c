#include <stdio.h>

int main() {
    int a, b;
    int res = 0;

    printf("Ingrese el primer numero entero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero entero: ");
    scanf("%d", &b);

    int ori_a = a;
    int ori_b = b;

    printf("\nProceso del algoritmo ruso:\n");
    while (a > 0) {
        if (a % 2 == 1) {  
            res += b;
            printf("%d - %d (sumamos %d)\n", a, b, b);
        } else {
            printf("%d - %d (no sumamos)\n", a, b);
        }
        a /= 2;  
        b *= 2;  
    }

    printf("\nProducto de %d y %d = %d\n", ori_a, ori_b, res);

    return 0;
}