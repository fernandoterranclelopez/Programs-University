    #include<stdio.h>
    void generarquiniela(int tabla[6]){
    int i;
    int j;
        for(i=0;i<6;i++) {
            int numero = rand()%49+1;
            tabla[i]=numero;
        }
        for(i=0;i<6;i++)
            for(j=0;j<6-i-1;j++){
                if(tabla[j]>tabla[j+1]){
                    int num = tabla[j];
                    tabla[j] = tabla[j+1];
                    tabla[j+1] = num;
                }
            }

        for(i=0; i<6; i++)
            printf(" %i ", tabla[i]);
        printf("\n");
        FILE *fichero = fopen("quiniela.txt","a+");
        for(i=0;i<6;i++)
            fprintf(fichero,"%i ",tabla[i]);
        fprintf(fichero, "\n");
        fclose(fichero);
    }
    void generarmultiplesapuestas(int napuestas, char nomfichero[255], int nsorteo){
    int quiniela[6];
    int i;
    int j;
    char identificador[10];
    FILE*nombrefichero=fopen(nomfichero,"w");
    fprintf(nombrefichero,"%i\n",nsorteo);
    for(i=0;i<10;i++)
        identificador[i]=rand()%41+41;
        fprintf(nombrefichero,"%s\n",identificador);
    do{
        for(i=0;i<6;i++){
            int num=rand()%49+1;
            quiniela[i]=num;
        }
        for(i=0;i<6;i++){
        for(j=0;j<6-1;j++){
            int num=quiniela[j];
            quiniela[j]=quiniela[j+1];
            quiniela[j+1]=num;
            }
        }
      for(i=0;i<6;i++)
            fprintf(nombrefichero,"%i ",quiniela[6]);
      fprintf(nombrefichero,"\n");
      napuestas--;

    }while(napuestas!=0);
    fclose(nombrefichero);
    }
void realizar_sorteo(int jornada){
    int quiniela[6];
    int numresult, i,j;
    char fecha[10];
    double recaudacion;
    double premioresult[4];
    printf("fecha: ");
    scanf(" %s", fecha);
    printf("recaudacion: ");
    scanf(" %lf", &recaudacion);
    for(numresult = 6, i=0 ; numresult>=3, i<4; numresult--, i++){
        printf("Introduce premio para %i aciertos: ", numresult);
        scanf(" %lf", &premioresult[i]);
    }
    for(i=0;i<6;i++){
            int num=rand()%49+1;
            quiniela[i]=num;
        }
        for(i=0;i<6;i++){
        for(j=0;j<6-i-1;j++){
            int num=quiniela[j];
            quiniela[j]=quiniela[j+1];
            quiniela[j+1]=num;
            }
        }
    FILE *fichero = fopen("historico.dat","a+");
    fprintf(fichero,"Sorteo: %i\n", jornada);
    for(i=0; i<6; i++)
        fprintf(fichero,"%i ",quiniela[i]);
    fprintf(fichero,"\n");
    fprintf(fichero,"Fecha: %s\n",fecha);
    fprintf(fichero,"Recaudacion: %lf€\n",recaudacion);
    for(numresult = 6, i=0 ; numresult>=3, i<4; numresult--, i++){
        fprintf(fichero, "%i aciertos: %lf.\n", numresult,premioresult[i]);
    }
    fprintf(fichero,"Nueva jornada: %i\n",jornada+1);
    fclose(fichero);
}
int main(){

    int opcion;
    int quiniela[6];
    int multiples;
    char nombre[255];
    int numero;
    int apuestas;
    FILE*sorteotubo= NULL;
    srand(time(NULL));


    do{
            sorteotubo=fopen("sorteo.txt","r");
            fscanf(sorteotubo,"%i",&numero);
            fclose(sorteotubo);
            printf("********APUESTAS - SORTEO PRIMITIVA Nª %i,*********** \n",numero);
    printf("----------------------------------------------------- \n");
    printf("1.-Generar quiniela aleatoria \n");
    printf("2.-Generar apuestas multiples \n");
    printf("3.-Realizar sorteo \n");
    printf("4.-Comprobar quiniela manualmente \n");
    printf("5.-Comprobar apuetas manualmente \n");
    printf("6.-Consultar sorteo actual \n");
    printf("7.-Consultar historico \n");
    printf("0.-Salir \n");
    printf("\n");

    printf("Elige una opcion:");
    scanf(" %d",&opcion);
    switch(opcion){
    case 1:
        generarquiniela(quiniela);
        break;
    case 2:
        printf("Numero de apuestas:");
        scanf("%i",&apuestas);
        printf("Numerode fichero:");
        scanf(" %s",nombre);
        generarmultiplesapuestas(apuestas,nombre,numero);
        break;
    case 3:
        realizar_sorteo(numero);
        numero++;
        sorteotubo=fopen("sorteo.txt","w");
        fprintf(sorteotubo,"%i",numero);
        fclose(sorteotubo);
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    default:
        printf("Error elija opcion del 1 al 8.\n");
        break;
    };
    }while(opcion!=8);
    return 0;
    }
