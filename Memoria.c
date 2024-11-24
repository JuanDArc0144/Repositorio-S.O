#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
typedef struct Proceso
{
    int valor;
    int memoria;
}Proceso;
typedef struct Particion
{
    int tamano;
    Proceso proceso;
}Particion;
void añadir(Particion DISK[]);
void liberar(Particion DISK[]);
void mostrar(Particion DISK[]);
int capacidad;
int particiones;
int main(){ 
    printf("Ingrese el tamaño total de memoria en KB: ");
    scanf("%d", &capacidad);
    printf("Ingrese el número de particiones: ");
    scanf("%d", &particiones);
    Particion DISK[particiones];
    for (size_t i = 0; i < particiones; i++)
    {
        int capacidadI;
        printf("Ingrese la cantidad de la partición %d: ", (i+1));
        scanf("%d", &capacidadI);
        if(capacidadI > capacidad){
            printf("NO PIDAS TANTO ESPACIO.\n");
            i--;
        } else {
            Particion p;
            Proceso pp;
            pp.valor = 0;
            p.tamano = capacidadI;
            p.proceso = pp;
            DISK[i] = p;
        }
    }
    int decision = 99;
    while(decision!=4){
        printf(" Selecciona una opción: \n 1.Crear proceso. \n 2.Liberar espacio \n 3.Mostrar espacios de memoria \n 4.Salir\n");
        scanf("%d", &decision);
        switch (decision)
        {
        case 1:
            añadir(DISK);
            break;
        case 2: 
            liberar(DISK);
            break;
        case 3:
            mostrar(DISK);
            break;
        case 4:
        printf("Un gusto!");
            break;
        }
    }
    return 0;
}

void añadir(Particion DISK[]){
    int id_proceso;
    int tamañoP;
    printf("Ingrese el ID del proceso: ");
    scanf("%d", &id_proceso);
    printf("Ingrese el tamaño del proceso: ");
    scanf("%d", &tamañoP);
    if(tamañoP<capacidad){
        for (size_t i = 0; i < particiones; i++)
        {
            if(tamañoP<DISK[i].tamano && DISK[i].proceso.valor==0){
                Proceso p;
                p.memoria = tamañoP;
                p.valor = id_proceso;
                DISK[i].proceso = p;
                printf("Proceso No. %d asignado a Particion %d\n", id_proceso, (i+1));
                break;
            } else {
                printf("Sin espacios de memoria listos en la partición %d\n", (i+1));
            }
        }
    } else {
        printf("El proceso exige más memoria de la disponible :(\n");
    }
}
void liberar(Particion DISK[]){
    int procesoB;
    printf("Seleccione el proceso a liberar: ");
    scanf("%d", &procesoB);
    for (size_t i = 0; i < particiones; i++)
    {
        if(DISK[i].proceso.valor == procesoB){
            DISK[i].proceso.valor = 0;
            printf("Proceso %d liberado", procesoB);
            break;
        }
    }
}
void mostrar(Particion DISK[]){
    for (size_t i = 0; i < particiones; i++)
    {
        if(DISK[i].proceso.valor == 0){
            printf("Partición %d vacia\n", (i+1));
        } else {
            printf("Particion %d con proceso %d con espacio de %d KB\n", (i+1), DISK[i].proceso.valor, DISK[i].proceso.memoria);
        }
    }
}