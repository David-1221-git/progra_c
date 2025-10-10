/*Realizar un programa que calcule el pago de n clientes de su recibo de luz de acuerdo con el consumo.
Checar el recibo de laCFE.
*/
#include <stdio.h>

#define TARIFA_KWH 5.00  // Precio por kWh (puedes ajustarlo)

int main() {
    int n;
    printf("=== Calculo de Recibo de Luz CFE ===\n");
    printf("Ingrese el numero de clientes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int lectura_actual, lectura_anterior;
        double dap_pagado, consumo_kwh, subtotal, total_pagar;

        printf("\n--- Cliente %d ---\n", i);
        printf("Ingrese la lectura actual del medidor (kWh): ");
        scanf("%d", &lectura_actual);
        printf("Ingrese la lectura anterior del medidor (kWh): ");
        scanf("%d", &lectura_anterior);
        printf("Ingrese lo que paga por el DAP (en pesos): $");
        scanf("%lf", &dap_pagado);

        // Validación de lecturas
        if (lectura_actual < lectura_anterior) {
            printf("❌ Error: La lectura actual no puede ser menor que la anterior.\n");
            i--; // Repetir este cliente
            continue;
        }

        consumo_kwh = lectura_actual - lectura_anterior;
        subtotal = consumo_kwh * TARIFA_KWH;
        total_pagar = subtotal + dap_pagado;

        // Mostrar recibo
        printf("\n📄 Recibo de Luz - Cliente %d\n", i);
        printf("Consumo: %.2f kWh\n", consumo_kwh);
        printf("Subtotal (energía): $%.2f MXN\n", subtotal);
        printf("DAP (cargo fijo): $%.2f MXN\n", dap_pagado);
        printf("TOTAL A PAGAR: $%.2f MXN\n", total_pagar);
        printf("-----------------------------------\n");
    }

    printf("\n✅ Cálculo completado para todos los clientes.\n");
    return 0;
}