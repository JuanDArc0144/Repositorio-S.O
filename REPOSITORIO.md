
# Administración de memoria
## Política y Filosofía
### Fragmentación Interna
La fragmentación interna ocurre cuando los bloques de memoria asignados son mayores a los requeridos, por lo que el almacenamiento guarda memoria no utilizable o inútil (a no ser que el usuario los requiera para una función específica).

__Importancia en el rendimiento:__ Este tipo de fragmentación puede ocasionar que procesos que requieren un espacio mayor en memoria no puedan utilizar, realientizadolos y equivaliendo a tiempos de espera más largos. (Aunque hemos realizado unos programas en Java que se pueden considerar simples y poco eficientes, en el desarrollo de programas implementados de manera profesional es peligroso caer en este tipo de fragmentación, en especial en el desarrollo de Sistemas Operativos Complejos o peor aún, con un espacio de memoria muy reducido o Sistemas Operativos Embebidos). 

### Fragmentación Externa
Este tipo de fragmentación ocurre cuando el disco duro contiene suficiente memoria, pero esta contiene pequeños bloques de memoria dispersos alrededor del disco, quedando como pequeños "restos" e impidiendo la creación de bloques de memoria más grandes o utilizables. 

__Importancia en el rendimiento:__ Este tipo de fragmentación me parece la más importante a cosiderar dentro de un sistema operativo, yya que puede afectar en mayor medida el rendimiento al ser memoria dispersa que tarda más en eliminarse y la desfragmentación, a veces, tiene que hacerse manualmente por el usuario (y, personalmente, he tenido que desfragmentar varios discos duros viejos o utilizados con grandes cantidades de memoria, lo que ha aumentado el rendimiento de los equipos en mayor medida.)

## Politicas de reemplazo de pagínas en un Sistema Operativo
Estas politicas son algoritmos que se encargan de gestionar la memroia virtual dentro de un sistema operativo. 
Cuando un proceso necesita una página que no está en la memoria principal, el sistema operativo debe decidir qué página sacar de la memoria para hacer espacio a la nueva página.

### FIFO (First In - First Out)
Este se encarga de reemplazar la pagina que más tiempo ha permanecido en memoria, conforme vayan llegando, van saliendo. 
Su ventaja principal es que es facil de implementar, y su principal desventja es que al agregar más marcos de memoria puede aumentar el número de fallos en la página. 

### LRU (Least Recently Used)
Este se encarga de reemplzara la pagina que no ha sido utilizada por el periodo de tiempo en memoria más largo. 
Su principal ventaja es que se basa en el principio de localidad temporal, lo que lo vuelve más eficiente en muchas cargas de trabajo al mismo tiempo. 
Lo cual tambien es su principal desventaja, ya que puede resultar costoso realizar el seguimiento de multiples paginas. 

### LFU (Least Frequently Used)
Este hace lo contrario y se necarga de registrar la pagina con un menor numero de frecuencia y reemplazarla. 
Su ventaja es que puede resultar beneficiosa para páginas que son utilizadas con mayor frecuencia a lo largo del tiempo. 
Aunque su desventaja es que es dificil de adaptar a diferentes cambios repentinos en el patrón de acceso. 

### Clock (Second Chance)
Este es muy semejante al FIFO, ya que se necraga de mantener un bit de la página en memoria en caso de que la pagina haya sido referenciada. 
Su principal ventaja que es más eficiente que el FIFO y más facil de implementar que el LRU, al mantener un pequeño espacio de memoria, es mucho más facil de localizar las páginas referenciadas.
Aunque su desvenataj es que es más innexacta que el LRU solamente. 

### NRU (Not Recently Used)
Este se encarga de priorizar las páginas menos utilizadas en base a dos bits de referencia por página.
Su principal ventaja es que simpplifica bastante el criterio de selección de páginas a reemplazar, aunque puede ser menos precios que el LRU. 

### Optimal (OPT)
Este se encarga de reemplazar la página que será menos utilizada en el futuro, en base a suposiciones en el tiempo de uso registrados en memoria. 
Este garantiza el menor número de fallos posibles en la página, pero es impractico porque requiere poner ver el futuro (aún no llegamos tan lejos para utiizarlo, pero sería en mi opinión, el más práctico). 


Por lo tanto, considerando las definiciones encontradas, considero que el LRU es el más eficiente al tratarse del más exacto al momemto de localizar páginas a reemplazar.

## Memoria Real
__Programa en C encargado de simular espacio en disco duro__

~~~
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
        printf("El proceso exige más memoria de la disponible :(\n"));
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
~~~

__Programa con el algoritmo de "primera cabida"__

~~~
#include <stdio.h>
#include <stdbool.h>

#define MAX_PARTICIONES 10
#define MAX_PROCESOS 10

typedef struct {
    int tamano;
    bool libre;
} Particion;

typedef struct {
    int id;
    int tamano;
    bool asignado;
    int particionAsignada;
} Proceso;

void mostrarResultados(Proceso procesos[], int numProcesos, Particion particiones[], int numParticiones) {
    printf("\nResultados de la asignación:\n");
    printf("Proceso\tTamaño\tPartición asignada\n");
    for (int i = 0; i < numProcesos; i++) {
        if (procesos[i].asignado) {
            printf("%d\t%d\t%d\n", procesos[i].id, procesos[i].tamano, procesos[i].particionAsignada + 1);
        } else {
            printf("%d\t%d\tNo asignado\n", procesos[i].id, procesos[i].tamano);
        }
    }

    printf("\nEstado final de las particiones:\n");
    printf("Partición\tTamaño\tEstado\n");
    for (int i = 0; i < numParticiones; i++) {
        printf("%d\t\t%d\t%s\n", i + 1, particiones[i].tamano, particiones[i].libre ? "Libre" : "Ocupada");
    }
}

void primeraCabida(Particion particiones[], int numParticiones, Proceso procesos[], int numProcesos) {
    for (int i = 0; i < numProcesos; i++) {
        procesos[i].asignado = false;
        for (int j = 0; j < numParticiones; j++) {
            if (particiones[j].libre && particiones[j].tamano >= procesos[i].tamano) {
                procesos[i].asignado = true;
                procesos[i].particionAsignada = j;
                particiones[j].libre = false;
                break;
            }
        }
    }
}

int main() {
    int numParticiones, numProcesos;

    printf("Introduce el número de particiones: ");
    scanf("%d", &numParticiones);

    Particion particiones[MAX_PARTICIONES];
    for (int i = 0; i < numParticiones; i++) {
        printf("Introduce el tamaño de la partición %d: ", i + 1);
        scanf("%d", &particiones[i].tamano);
        particiones[i].libre = true;
    }

    printf("Introduce el número de procesos: ");
    scanf("%d", &numProcesos);

    Proceso procesos[MAX_PROCESOS];
    for (int i = 0; i < numProcesos; i++) {
        procesos[i].id = i + 1;
        printf("Introduce el tamaño del proceso %d: ", i + 1);
        scanf("%d", &procesos[i].tamano);
    }

    primeraCabida(particiones, numParticiones, procesos, numProcesos);

    mostrarResultados(procesos, numProcesos, particiones, numParticiones);

}
~~~

## Organización de Memoria Virtual
__Paginación__ La paginación consiste en dividir la memoria virtual en unos bloques de memoria de estado fijo llamados "páginas", y la memoria fisica en unos espacios de memoria llamados "bloques". Cuando un proceso requiere acceder a un espacio de memoria, la dirección virtual asignada se traduce a una tabla de páginas, que se encarga de mapear cada oágina diferente a un espacio físico de memoria. 

__¿En que consiste el proceso de páginación?__ 
#### División de páginas
Estos espacios de memoria se dividen en espacios pequeños de memoria (este espacio depende del sistema operativo que se este utilizando, por ejemplo, 4KB por página). 
#### Tabla de páginas
Cada proceso tiene una tabla de páginas que se encarga de mapear cada espacio de memoria virtual a un espacio de memoria física. 
#### Acceso a memoria
Como cada proceso necesita acceder a un espacio de memoria (ya sea tato virtual como física) es necesario que el CPU utilice su tabla de páginas correspondiente para obtener su propia dirección de memoria física. 

#### Proceso de Page Default
Si la página del proceso se encuentra solicitada, a esta se le asigna una tabla default, en la cual el disco duro debe cargar una página desde un espacio predeterminado de memoria física. 

### Principales ventajas de la paginación
Entre las principales ventajas de la páginación se encuentran: 

1. Debido al tamaño "personalizado" de las páginas, no produce una fragmentación externa en el disco duro. 
2. Las páginas pueden ser reubicadas en espacios de memoria de manera facil, aumentando la eficiencia entre la carga de procesos. 
3. Ocurre una especie de "encapsulamiento" en el cual un porceso cueta con su propio espacio de memoria, evitando que un proceso externo acceda al espacio de memoria de otro proceso. 
4. Cada proceso de mayor tamaño puede ser cargado facilmente en memoria. 

### Principales desvetajas de la páginación
1. No ocurre framentación externa, pero si fragmentación interna. Esto ocurre en el caso que el tamaño de la tabla de páginas no sea de un múltiplo exacto a una tabla de páginas preestablecida. (Ya que a pesar de que cada proceso tiene su propia tabla de páginas, todas tienen un tamaño personalizado) . 
2. Al final, si se tiene una gran cantidad de procesos, la carga de tablas de páginas en memoria puede llegar a ser importante para el usuario o significativa (esto especialmente si el Sistema Operativo es del tipo Embebido, en el cual el espacio de memoria y el acceso a los dispositivos y hardware es limitado). 
3. El buscar entre las tablas de memoria puede llevar a una latencia adicional, lo que se traduce en mayores tiempos de carga (que en un sistema que requiera un tiempo muy exacto, como diferentes programas de Física, puede llegar a ser un porcentaje de tiempo significativo). 

__Segmentación__ La segmentación se encarga de dividir los espacio de memoria en direcciones de segmentos lógicos (codigo, pilas, etc). Por lo que cada proceso puede llegar a tener un tamaño de memoria personalizado dependiendo de las necesidades del proceso, por lo que los segmentos de memoria no se encuentran obligados a ser del mismo tamaño. 

__¿En que consiste el proceso de páginación?__
#### División de segmentos
Al igual que en la páginación (pero esta vez, en el proceso) la memoria se divide en los segmentos de código personalizados. 
#### Tabla de segmentos
Ahora, en lugar de tener una tabla de páginas, se guarda en memoria una tabla de segmentos, que se encargan de mapear cada uno en una dirección de memoria física. 
#### Acceso a memoria
Cuando el CPU necesita acceder a un proceso en especifico, utiliza en esta ocasión la tabla de segmentos para acceder al proceso correspondiente. 

### Ventajas
1. Al tratarse de una manera mucho más facil de manejar los espacios de memoria, es mucho más facil el manejo de cada proceso. 
2. Al tratarse de tamaños personalizados, ocurre menos fragmentación interna dentro del disco duro. 
3. Los segmentos son capaces de personalizarse a las necesidades de cada proceso (por lo que po ejemplo, una pila puede aumentar de tamaño si así es requerido). 






