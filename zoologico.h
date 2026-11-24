//
// Created by MLS on 29/10/2026.
//
typedef struct Fecha
{
    int dia;
    int mes;
    int anyo;
}Fecha;

typedef struct Panda
{
    char *nombre;
    float peso;
    int a_nac;
    char  sexo;
    Fecha *ingreso;
}Panda;
void reservar_memoria(Panda poblacion[],int tp);
void liberar_memoria(Panda poblacion[], int tp);
void limpiar_buffer();
void agregar_panda(Panda poblacion[],int tp);
int tener_bebe(Panda *p);
int edad_panda(Panda *p);
Panda* buscar_panda(Panda poblacion[], char *nombre,int tam);
void imprime_panda(Panda *p,int tp);
void bus_panda(Panda poblacion[],int tp);


















#ifndef PANDA_ZOOLOGICO_H
#define PANDA_ZOOLOGICO_H

#endif //PANDA_ZOOLOGICO_H
