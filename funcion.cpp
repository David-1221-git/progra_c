#include <stdio.h>
funcion_sum ();
funcion_res ();
funcion_multi ();
funcion_div ();
int main(){
    int v;
    printf("--Porfavor elija una opcion--\n");
    printf("1.-suma\n");
    printf("2.-resta\n");
    printf("3.-multiplicacion\n");
    printf("4.-divicion\n");
    printf("5.-salir\n");
    scanf("%d",&v);
    switch (v){
        case 1:
        funcion_sum();
        break;
        case 2:
        funcion_res();
        break;
        case 3:
        funcion_muilti();
        break;
        case 4:
        funcion_div();
        break;
        case 5:
        return 1;
        break;
    }
}
void funcion_sum(){
    float a,b,c;
    printf("--Binenvenido al apartado de suma--");
    printf("Ingresa el primer numero a sumar.-");
    scanf("%f",&a);
    printf("Ingresa el segundo numero a sumar.-")
    scanf("%f",&b);
    c=a+b;
    printf("El resultado de la suma es: %f",&c);
}