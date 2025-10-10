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