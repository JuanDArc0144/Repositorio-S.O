#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _nodo { //Crea un tipo de dato abstracto
    int valor;
    int prioridad;
    struct _nodo *siguiente; //Sirve como un puntero a si mismo 
} nodo;

int numero_aleatorio() {
    return (rand() % 4) + 1;
}

nodo* genera_proceso() { //regresa direcciones del tipo nodo
    static int contador = 1; //ese dato se mantiene estatico con el fin de contar el número del proceso  
    nodo* nuevo = (nodo*)malloc(sizeof(nodo)); //el malloc se encarga de sacar la direccion de memoria, a un tipo de puntero de un nodo llamado nuevo.   
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n"); //Ups, se acabo la memoria. 
        exit(1);
    }
    nuevo->valor = contador++; //El operador flecha sirve para acceder a atributos de un espacio de memoria.
    nuevo->prioridad = numero_aleatorio();
    nuevo->siguiente = NULL; 
    return nuevo;
}

void insertar_final(nodo** cabeza) {  //mandar la direccion del primer puntero
    nodo* nuevoNodo = genera_proceso();
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        nodo* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}
void imprimir_lista(nodo* cabeza) {
    nodo* temp = cabeza;
    while (temp != NULL) {
        printf("|Proceso %p| (Prioridad %p)|direc %p| -> ", temp->valor, temp->prioridad, temp->siguiente);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void atender_prioridad(nodo** cabeza) {
    if (*cabeza == NULL) {
        printf("No hay procesos para atender.\n");
        return;
    }
    nodo* temp = *cabeza;
    nodo* maxNodo = temp;
    nodo* maxNodoPrevio = NULL;
    nodo* previo = NULL;
    // Buscar el nodo con la prioridad más alta
    
    // Atender el nodo con prioridad más alta
    printf("Atendiendo proceso %d", temp->valor);
    // Eliminar el nodo de la lista
    *cabeza = temp;
    free(temp);
}

int main() {
    srand(time(NULL));
    nodo* cabeza = NULL;
    int op = 0;

    do {
        printf("1. Genera proceso\n");
        printf("2. Atiende proceso\n");
        printf("3. Mostrar Lista de Procesos\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                insertar_final(&cabeza);
                break;
            case 2:
                atender_prioridad(&cabeza);
                break;
            case 3:
                imprimir_lista(cabeza);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while (op != 4);

    return 0;
}
