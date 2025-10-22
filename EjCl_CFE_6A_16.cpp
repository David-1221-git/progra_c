/*Realizar un programa que calcule el pago de n clientes de su recibo de luz de acuerdo con el consumo.
Checar el recibo de laCFE.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, tipo, i, temporada_calor;
    char servicio[20];

    printf("=== CALCULO DE RECIBO DE LUZ (CFE) ===\n");
    printf("Ingrese el numero de clientes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("\n--- CLIENTE %d ---\n", i);
        printf("Tipo de cliente:\n");
        printf("1) Domestico\n");
        printf("2) Comercial\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &tipo);

        switch (tipo) {
            case 1: {
                float lectura_anterior, lectura_actual, consumo;
                float DAP, cargo_consumo, iva, total;

                printf("Ingrese el No. de Servicio: ");
                scanf("%19s", servicio);
                printf("Ingrese la lectura anterior: ");
                scanf("%f", &lectura_anterior);
                printf("Ingrese la lectura actual: ");
                scanf("%f", &lectura_actual);

                if (lectura_actual < lectura_anterior) {
                    printf("\nError: la lectura actual no puede ser menor que la anterior.\n");
                    break;
                }

                consumo = lectura_actual - lectura_anterior;

                printf("¿Esta en temporada de calor (mayo a octubre)? (1=Si, 0=No): ");
                scanf("%d", &temporada_calor);

                // Asignar DAP (usamos tu valor real: $16.97 para tarifa 1)
                if (consumo <= 250.0f) {
                    DAP = 16.97f;
                } else if (consumo <= 500.0f) {
                    DAP = 46.76f;
                } else {
                    DAP = 93.52f;
                }

                // Precios oficiales CFE 2025
                const float precio_basico = 1.099f;
                const float precio_intermedio = 1.335f;
                const float precio_excedente = 3.903f;

                // Cálculo por estratos
                if (consumo <= 75.0f) {
                    cargo_consumo = consumo * precio_basico;
                } else if (temporada_calor && consumo <= 250.0f) {
                    // Temporada de calor: hasta 250 kWh sin excedente
                    cargo_consumo = 75.0f * precio_basico + (consumo - 75.0f) * precio_intermedio;
                } else if (!temporada_calor && consumo <= 140.0f) {
                    // Temporada fría: intermedio hasta 140 kWh
                    cargo_consumo = 75.0f * precio_basico + (consumo - 75.0f) * precio_intermedio;
                } else if (!temporada_calor) {
                    // Temporada fría: excedente después de 140 kWh
                    cargo_consumo = 75.0f * precio_basico +
                                   (140.0f - 75.0f) * precio_intermedio +
                                   (consumo - 140.0f) * precio_excedente;
                } else {
                    // Más de 250 kWh en temporada de calor
                    cargo_consumo = 75.0f * precio_basico +
                                   (250.0f - 75.0f) * precio_intermedio +
                                   (consumo - 250.0f) * precio_excedente;
                }

                // IVA: solo sobre consumo si hay subsidio (consumo <= 500)
                if (consumo <= 500.0f) {
                    iva = cargo_consumo * 0.16f;
                } else {
                    iva = (DAP + cargo_consumo) * 0.16f;
                }

                total = DAP + cargo_consumo + iva;

                // Mostrar recibo
                printf("\n--- RECIBO CLIENTE %d (DOMESTICO) ---\n", i);
                printf("Servicio: %s\n", servicio);
                printf("Consumo: %.2f kWh\n", consumo);
                printf("DAP: $%.2f\n", DAP);
                printf("Cargo por energia: $%.2f\n", cargo_consumo);
                printf("IVA (16%%): $%.2f\n", iva);
                printf("TOTAL A PAGAR: $%.2f\n", total);
                break;
            }

            case 2: {
                float consumo, demanda;
                const float cargo_fijo = 85.0f;
                const float precio_energia = 2.700f;
                const float precio_demanda = 150.0f;
                float subtotal, iva, total;

                printf("Ingrese el No. de Servicio: ");
                scanf("%19s", servicio);
                printf("Ingrese consumo en kWh: ");
                scanf("%f", &consumo);
                printf("Ingrese demanda en kW: ");
                scanf("%f", &demanda);

                subtotal = cargo_fijo + (consumo * precio_energia) + (demanda * precio_demanda);
                iva = subtotal * 0.16f;
                total = subtotal + iva;

                printf("\n--- RECIBO CLIENTE %d (COMERCIAL) ---\n", i);
                printf("Servicio: %s\n", servicio);
                printf("Consumo: %.2f kWh\n", consumo);
                printf("Demanda: %.2f kW\n", demanda);
                printf("Cargo fijo: $%.2f\n", cargo_fijo);
                printf("Cargo por energia: $%.2f\n", consumo * precio_energia);
                printf("Cargo por demanda: $%.2f\n", demanda * precio_demanda);
                printf("Subtotal: $%.2f\n", subtotal);
                printf("IVA (16%%): $%.2f\n", iva);
                printf("TOTAL A PAGAR: $%.2f\n", total);
                break;
            }

            default:
                printf("Opcion no valida. Solo 1 (Domestico) o 2 (Comercial).\n");
                i--; // Repetir este cliente
                break;
        }
    }

    return 0;
}