#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>
typedef struct Proceso
{
    int valor;
    struct Proceso *siguiente;
}Proceso;
typedef struct Particion
{
    struct Proceso *cabeza;
}Particion;
typedef struct DISCO
{
    struct Particion *cabeza;
}DISCO;

void crear();
int main(){
    DISCO* disco = (DISCO*) malloc(sizeof(DISCO));
    disco->cabeza = NULL;
    int particiones;
    printf("Seleccione el número de particiones: ");
    scanf("%d", &particiones);
    for (size_t i = 0; i < particiones; i++)
    {
        if(disco->cabeza==NULL){

        }
    }
    int decision = 99;
    while(decision!=4){
        printf("Selecciona una opción \n1.Crear proceso. \n2.Liberar espacio. \n3.Mostrar espacios de memoria. \n4.Salir");
        scanf("%d", &decision);
        switch (decision)
        {
        case 1:{

        }
        case 4:
        printf("FIN");
            break;
        }

    }
}

void crear(){

}