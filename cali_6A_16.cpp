#include <stdio.h>
#define m 30
#define c 4

int main() {
    int fil, i, j, prom, promt;
    int par[m];
    int cali[m][c];
    
    printf("Ingresa el numero de estudiantes\n");
    scanf("%d", &fil);
    
    if(fil >= 1 && fil <= 30) {
        for(i = 0; i < fil; i++) {
            prom = 0;
            
            for(j = 0; j < c; j++) {  
                printf("Ingresa la calificacion del estudiante %d de la actividad %d\n", i+1, j+1);
                scanf("%d", &cali[i][j]);
                if(cali[i][j]<=10 && cali[i][j]>=0){
                    prom = prom + cali[i][j];
                }else{
                    printf("\nLa calificacion porporcionada esta mal intente todo de nuevo\n");
                    return 1;
                }
            }
            
            promt = prom / c; 
            printf("El promedio del alumno %d es: %d\n", i+1, promt); 
            par[i] = promt;  
        }
    }
    
    return 0;
}