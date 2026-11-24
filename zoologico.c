#include "zoologico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpiar_buffer()
{
    int c;
    while ((c=getchar())!='\n'&&c!=EOF);
}
void reservar_memoria(Panda poblacion[],int tp)
{

        poblacion[tp].nombre=malloc(20*sizeof(char));
        if (poblacion[tp].nombre==NULL)
        {
            printf("Memoria Insuficiente para Nombre\n");
        }
        //reservar_memoria_ingreso
        poblacion[tp].ingreso=malloc(sizeof(Fecha));

        if (poblacion[tp].ingreso==NULL)
        {
            printf("Memoria Insuficiente para Ingreso\n");
        }


}
void liberar_memoria(Panda poblacion[], int tp){
	for(int i=0;i<tp;i++){
		free(poblacion[i].nombre);
		poblacion[i].nombre=NULL;
		free(poblacion[i].ingreso);
		poblacion[i].ingreso=NULL;
	}
}

void agregar_panda(Panda poblacion[],int tp)
{

    int i;

        reservar_memoria(poblacion,tp);


        printf("================================\n");

        printf("Nombre:");
        fgets((poblacion[tp]).nombre,20,stdin);
        //quita el salto de linea de fgets
        poblacion[tp].nombre[strcspn(poblacion[tp].nombre,"\n")]='\0';
        printf("Peso:");
        scanf("%f",&poblacion[tp].peso);
        limpiar_buffer();
        printf("Ingresa, solo la Inicial H--Hembra /M--Macho\n ");
        printf("Sexo:");
        scanf("%c",&poblacion[tp].sexo);
        limpiar_buffer();
        printf("Anyo de nacimiento:");
        scanf("%d",&poblacion[tp].a_nac);
        limpiar_buffer();
        printf("Fecha de ingreso\n");
        printf("Dia\n");
        scanf("%d",&(poblacion+tp)->ingreso->dia);
        limpiar_buffer();
        printf("Mes\n");
        scanf("%d",&(poblacion+tp)->ingreso->mes);
        limpiar_buffer();
        printf("Anyo\n");
        scanf("%d",&(poblacion+tp)->ingreso->anyo);
        limpiar_buffer();


}
int edad_panda(Panda *p)
{
    int edad;
    edad=(2026 - p->a_nac);
    return edad;

}
int tener_bebe(Panda *p)
{
    int rep=0;



    if ((p->sexo=='H'||p->sexo=='h')&&edad_panda(p)>5)
    {

        rep=1;

    }

    return rep;
}

void  imprime_panda(Panda *p,int tp)
{
    for (int i=0;i<tp;i++){

        printf("===============================\n");
        printf("Nombre del panda:%s\n",p[i].nombre);
        printf("\nPeso:%.2fKg",p[i].peso);
        printf("\nSexo:%c\n",p[i].sexo);
        printf("Edad %d anyos del Panda\n",edad_panda(&p[i]));
        if (tener_bebe(&p[i])==1)
        {
            printf("\nSe mostrara 1 si es candidata para el programa de reproduccion\n");
        }
        else
        {
            printf("Se mostrara 0 si no es candidata para el programa de reproduccion\n");
        }

        printf("\nFecha de ingreso DIA MES ANYO %d/ %d/%d",p[i].ingreso->dia,p[i].ingreso->mes,p[i].ingreso->anyo);





    }//for

}

Panda* buscar_panda(Panda poblacion[], char *nombre,int tam)
{
    int i,cadena;
    for (i=0;i<tam;i++)
    {
        cadena=strcmp(poblacion[i].nombre,nombre);
        if (cadena==0)
        {
            return &poblacion[i];
        }

    }
    //No devuelve nada
    return NULL;
}
void bus_panda(Panda poblacion[],int tp)
{
    char buscar[20];
    Panda *encontrar_panda=NULL;

    printf("Buscar al ejemplar\n");
    fgets(buscar,20,stdin);
    //quitar el salto de linea para fgets
    buscar[strcspn(buscar,"\n")]='\0';
    //apunta a la direccion de buscar_panda
    encontrar_panda=buscar_panda(poblacion,buscar,1);
    if (encontrar_panda!=NULL)
    {
        imprime_panda(encontrar_panda,tp);
    }
    else
    {
        printf("No se encuentra ningun ejemplar con ese nombre.\n");
    }
}
