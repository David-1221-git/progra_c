/*Nombre del proyecto:Ejercicio 1 pág 75 Numero 1_v1
Elaboro:Merino Dominguez David  No Lista:16
Fecha:10/octubre/2025        No. Vercion:1
Descripcion:Calcular la paga de un trabajador según sean las horas trabajadas y el precio por hora para el trabajo que realice, entre las siguientes opciones:
a) Intendencia: $35 b) Asistente: $50 c) Administrativo: $80
d) Directivo: $120 e) Gerente: $150*/

#include <stdio.h>

int main() {
    int opcion;
    float horas, paga, precio_hora;

    printf("Seleccione el tipo de trabajo:\n");
    printf("1. Intendencia ($35/hora)\n");
    printf("2. Asistente ($50/hora)\n");
    printf("3. Administrativo ($80/hora)\n");
    printf("4. Directivo ($120/hora)\n");
    printf("5. Gerente ($150/hora)\n");
    printf("Ingrese su opción (1-5): ");
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > 5) {
        printf("Opción inválida.\n");
        return 1;
    }

    printf("Ingrese las horas trabajadas: ");
    scanf("%f", &horas);

    // Asignar precio por hora según la opción
    switch(opcion) {
        case 1: precio_hora = 35; break;
        case 2: precio_hora = 50; break;
        case 3: precio_hora = 80; break;
        case 4: precio_hora = 120; break;
        case 5: precio_hora = 150; break;
    }

    paga = horas * precio_hora;
    printf("La paga total es: $%.2f\n", paga);

    return 0;
}