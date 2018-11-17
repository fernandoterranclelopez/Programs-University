#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define N 15
int main(int argc, char*argv[]){
int respuesta;
int response;
int numero = 0;
srand(time(NULL));
printf("Quieres echar una quiniela(0 si 1 no): " );
scanf(" %i", &respuesta);

if(respuesta == 0){
    do{
        int resultado= 0;
        do{
            numero = rand()%3;
            switch(numero){
            case 0:
                printf("%i 1\n",(resultado+1));
                break;
            case 1:
                printf("%i X\n",(resultado+1));
                break;
            case 2:
                printf("%i 2\n",(resultado+1));
                break;
            }
        resultado++;
        }while(resultado<=14);
        printf("Quieres echar otra(0 si 1 no)");
        scanf(" %i", &response);
        if(response != 0 || response != 1)
            response = 1;
    }while(response != 1);
    printf("Gracias por hacer las apuestas.\n");
}else
    printf("Gracias.\n");


return 0;
}


