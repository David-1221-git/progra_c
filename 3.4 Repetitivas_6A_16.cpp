#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos de funciones
int programa11();
int programa19();
int programa21();
int esBisiesto(int anio);
int diasEnMes(int mes, int anio);

int main() {
    int opcion;

    do {
        printf("\n--- MENÚ DE PROGRAMAS ---\n");
        printf("1. Programa 11: Operaciones aritméticas aleatorias\n");
        printf("2. Programa 19: Verificar si un número es perfecto\n");
        printf("3. Programa 21: Calcular días vividos y años bisiestos\n");
        printf("4. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                programa11();
                break;
            case 2:
                programa19();
                break;
            case 3:
                programa21();
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    return 0;
}

// Programa 11
int programa11() {
    srand(time(NULL)); // Inicializar semilla aleatoria

    int aciertos = 0;
    char operadores[] = {'+', '-', '*', '/'};
    int num_operaciones = 5;

    for (int i = 0; i < num_operaciones; i++) {
        int a = rand() % 10 + 1; // Número entre 1 y 10
        int b = rand() % 10 + 1;
        char op = operadores[rand() % 4]; // Operador aleatorio

        // Asegurar que en división a >= b y división entera
        if (op == '/') {
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            // Asegurar que la división sea entera (a divisible entre b)
            while (a % b != 0) {
                b = rand() % 10 + 1;
                if (a < b) {
                    int temp = a;
                    a = b;
                    b = temp;
                }
            }
        }

        printf("%d %c %d = ", a, op, b);
        int respuesta_usuario;
        scanf("%d", &respuesta_usuario);

        if (respuesta_usuario == a + b && op == '+') {
            printf("¡Correcto!\n");
            aciertos++;
        } else if (respuesta_usuario == a - b && op == '-') {
            printf("¡Correcto!\n");
            aciertos++;
        } else if (respuesta_usuario == a * b && op == '*') {
            printf("¡Correcto!\n");
            aciertos++;
        } else if (respuesta_usuario == a / b && op == '/') {
            printf("¡Correcto!\n");
            aciertos++;
        } else {
            int resultado_correcto;
            switch(op) {
                case '+': resultado_correcto = a + b; break;
                case '-': resultado_correcto = a - b; break;
                case '*': resultado_correcto = a * b; break;
                case '/': resultado_correcto = a / b; break;
            }
            printf("Incorrecto. La respuesta correcta es %d.\n", resultado_correcto);
        }
    }

    int calificacion = (aciertos * 100) / num_operaciones;
    printf("\nTuviste %d aciertos, tu calificación es %d.\n", aciertos, calificacion);

    return 0;
}

// Programa 19
int programa19() {
    int numero, suma_divisores = 0;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Debe ingresar un número positivo.\n");
        return 1;
    }

    // Calcular suma de divisores (excepto el mismo número)
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) {
            suma_divisores += i;
        }
    }

    if (suma_divisores == numero) {
        printf("%d es un número perfecto.\n", numero);
    } else {
        printf("%d no es un número perfecto.\n", numero);
    }

    return 0;
}

// Función para verificar si un año es bisiesto
int esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// Función para obtener los días en un mes
int diasEnMes(int mes, int anio) {
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && esBisiesto(anio)) {
        return 29;
    }
    return dias[mes - 1];
}

// Programa 21
int programa21() {
    int dia_nac, mes_nac, anio_nac;
    int dia_actual, mes_actual, anio_actual;
    int dias_vividos = 0;
    int anos_bisiestos = 0;

    printf("Ingrese su fecha de nacimiento:\n");
    printf("Día: ");
    scanf("%d", &dia_nac);
    printf("Mes: ");
    scanf("%d", &mes_nac);
    printf("Año: ");
    scanf("%d", &anio_nac);

    // Validar rango de años
    if (anio_nac <= 0 || anio_nac >= 2100) {
        printf("El año debe estar entre 1 y 2099.\n");
        return 1;
    }

    // Validar mes
    if (mes_nac < 1 || mes_nac > 12) {
        printf("Mes inválido.\n");
        return 1;
    }

    // Validar día
    if (dia_nac < 1 || dia_nac > diasEnMes(mes_nac, anio_nac)) {
        printf("Día inválido.\n");
        return 1;
    }

    // Obtener fecha actual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    dia_actual = tm_info->tm_mday;
    mes_actual = tm_info->tm_mon + 1;
    anio_actual = tm_info->tm_year + 1900;

    // Calcular años bisiestos entre año de nacimiento y año actual
    for (int anio = anio_nac; anio < anio_actual; anio++) {
        if (esBisiesto(anio)) {
            anos_bisiestos++;
        }
    }

    // Calcular días vividos
    int anio = anio_nac;
    int mes = mes_nac;
    int dia = dia_nac;

    while (anio < anio_actual || (anio == anio_actual && mes < mes_actual) || (anio == anio_actual && mes == mes_actual && dia < dia_actual)) {
        dia++;
        if (dia > diasEnMes(mes, anio)) {
            dia = 1;
            mes++;
            if (mes > 12) {
                mes = 1;
                anio++;
            }
        }
        dias_vividos++;
    }

    printf("Días vividos: %d\n", dias_vividos);
    printf("Años bisiestos pasados: %d\n", anos_bisiestos);

    return 0;
}
