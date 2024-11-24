#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Nodo
{
    int valor;
    int numIsla;
    Nodo *superior;
    Nodo *derecho;
    Nodo *inferior;
    Nodo *izquierdo;
}Nodo;

void buscar(Nodo *n);
int islaActual = 1;
int main(){
    Nodo *arreglo[8][8];
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if(j==0 && i!=7 && i!=0){
                arreglo[i][j]->superior = NULL;
                arreglo[i][j]->derecho = arreglo[i+1][j];
                arreglo[i][j]->inferior = arreglo[i][j+1];
                arreglo[i][j]->izquierdo = arreglo[i-1][j];
                arreglo[i][j]->numIsla = 0;
                arreglo[i][j]->valor = rand() % 2;
            } else {
                arreglo[i][j]->derecho = arreglo[i+1][j];
                arreglo[i][j]->inferior = arreglo[i][j+1];
                arreglo[i][j]->izquierdo = arreglo[i-1][j];
                arreglo[i][j]->superior = arreglo[i][j+1];
            }
            if(i==0 && j!=0 && j!=7){
                arreglo[i][j]->izquierdo = NULL;
                arreglo[i][j]->superior = arreglo[i][j+1];
                arreglo[i][j]->derecho = arreglo[i+1][j];
                arreglo[i][j]->inferior = arreglo[i][j-1];
                arreglo[i][j]->numIsla = 0;
                arreglo[i][j]->valor = rand() % 2;
            } else {
                arreglo[i][j]->derecho = arreglo[i+1][j];
                arreglo[i][j]->inferior = arreglo[i][j+1];
                arreglo[i][j]->izquierdo = arreglo[i-1][j];
                arreglo[i][j]->superior = arreglo[i][j+1];
            }
            if(i==7 && j!=0 && j!=7){
                arreglo[i][j]->derecho = NULL;
                arreglo[i][j]->superior = arreglo[i][j+1];
                arreglo[i][j]->inferior = arreglo[i][j-1];
                arreglo[i][j]->izquierdo = arreglo[i-1][j];
                arreglo[i][j]->numIsla = 0;
                arreglo[i][j]->valor = rand() % 2;
            } else {
                arreglo[i][j]->derecho = arreglo[i+1][j];
                arreglo[i][j]->inferior = arreglo[i][j+1];
                arreglo[i][j]->izquierdo = arreglo[i-1][j];
                arreglo[i][j]->superior = arreglo[i][j+1];
            }
            if(j==7 && i!=7 && i!=0){
                arreglo[i][j]->inferior = NULL;
                arreglo[i][j]->izquierdo = arreglo[i-1][j];
                arreglo[i][j]->superior = arreglo[i][j+1];
                arreglo[i][j]->derecho = arreglo[i+1][j];
                arreglo[i][j]->numIsla = 0;
                arreglo[i][j]->valor = rand() % 2;
            } else {
                arreglo[i][j]->derecho = arreglo[i+1][j];
                arreglo[i][j]->inferior = arreglo[i][j+1];
                arreglo[i][j]->izquierdo = arreglo[i-1][j];
                arreglo[i][j]->superior = arreglo[i][j+1];
            }
        }
    }
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            printf("[%i]", arreglo[i][j]->valor);
        }
        printf("\n");
    }
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            buscar(arreglo[i][j]);
        }
        
    }
    printf("El número de islas es: %i", islaActual);
    return 0;
};
void buscar(Nodo *n){
    if(n->valor==1){
        n->numIsla = islaActual;
    } else {
        buscar(n->derecho);
    } if(n->derecho->valor == 0 && n->inferior->valor == 1 && n->inferior->numIsla != n->numIsla){
        n->numIsla=islaActual;
        buscar(n->inferior);
    } else if(n->inferior->valor == 0 && n->izquierdo->valor==1 && n->izquierdo->numIsla != n->numIsla){
        n->numIsla = islaActual;
        buscar(n->izquierdo);
    } else if(n->superior->valor == 1 && n->superior->numIsla != n->numIsla){
        n->numIsla = islaActual;
        buscar(n->superior);
    } else {
        islaActual++;
        buscar(n->derecho);
    }
}