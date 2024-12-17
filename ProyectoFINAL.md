# Proyecto Final Sistemas Operativos

# Sistemas de Archivos
### Definición de Archivo Real
Un archivo real es un archivo que se encuentra almacenanado de manera física en un dispositivo de almacenamiento, como podría ser un SSD o un disco duro tipo HDD (incluso uno nmve). Estos poseeen una dirección especifica dentro del sistema de archivos, por lo que se accede a estos a través de la estructura que posea el Sistema Operativo, el cual se encarga de consumir espacio real en el dispositivo de almacenamiento. 
### Definición de Archivo Virtual
Es un tipo de archivo que no existe como tal dentro del disco duro o un medio fisico de almacenamiento, sino que son creados de manera dinamica a través del S.O o una aplicación, estos funcionan como una representación lógica de los datos que pueden ser calculados o recuperados al momento de ser solicitados (otorgando información sin que esta sea almacenada). 
### Ejemplos prácticos 
#### Archivos Reales
Entre los archivos reales dentro de un sistema operativo pueden encontrarse los diferentes datos a los que accedemos desde el explorador de archivos en una carpeta dentro del usuario (como podrian ser un arhcivo de texto o un formato especifico tipo Excel, Word, etc). 
#### Archivos Virtuales
Estos se almacenan dentro de la memoria volatil tipo RAM, por lo que, en el caso de Lunix, pueden encontrarse dentro de la carpeta `/tmp`. Al igual que archivos de formato FIFO, los cuales se encargan de mantener un control entre procesos. 

__Utilidades__
Un archivo del tipo virtual puede resultar más útil cuando se requiere para una operación que desaparece de manera rápida o inmediata, dado que es un tipo de archivo que no planea utilizarse a futuro al tratarse de uno que contiene datos que se aplican de manera especifica dependiento (en el caso de los tipos FIFO) del ID de los procesos y su espacio dentro de la memoria volatil, en los cual varía siempre la posición del proceso y su ID. 

## Componentes de un sistema de Archivos
### Componentes clave de un sistema de archivos
#### Bloques de datos: 
Estas son las unidades minimas de almacenamiento en las cuales se dividen los datos dentro de un sistema de archivos. Cada archivo es almacenado en uno o varios bloques de sistemas de datos. Estos bloques pueden ser de un tamaño especificado por el sistema de archivos, como podrían ser 4KB u 8KB. 
Esta forma de almacenamiento resulta más comoda que guardar en datos de bloques diferentes, ya que esto permite una mejor organización y simplicidad al momento de acceder a diferentes archivos (Por ejemplo, si tenemos bloques de 4KB y un archivo de 6Kb, es más sencillo especificar que se encuentra en la mitad de un bloque y en uno completo, que crear un bloque especifico de 2KB extra para el archivo). 
#### Metadatos
Estos se tratan de datos acerca de los datos en cuestión, los cuales se encargan de otorgar información valiosa sobre el tamaño del archivo, su nombre, su fecha de creación, propietario, ubicación en bloques de datos, etc. 
#### Tabla de asignación de archivos
Esta se trata de una estructura de datos que se encarga de registrar la ubicación precisa de los diferentes bloques de datos en un dispositivo de almacenamiento. Esto ayuda a mostrar los diferentes bloques que se encuentra disponibles y su espacio libre y aquellos que se encuentran ocupados. 
#### Directorios
Son un tipo de estructura lógica que se encarga de almacenar y agrupar archivos (esto puede depender del Sistema Operativo o del usuario). Estas comúnmente son comparadas con las carpetas que se utilizan tanto en Windows como en Linux. 
#### Caché del sistema de archivos
Este es un espacio dentro de la memoria RAM que se encarga de almacenar los datos de accesos más frecuente, ayudando a reducir el número de accesos al disco. 


| Componente | EXT4 | NTFS |
|----------|----------|----------|
| Bloque de Datos    | Tamaño de bloque configurable  | Tamaño de bloque predeterminado  |
| Metadatos   | Almacenados en inodos   | Guardados en el MFT   |
| Tabla de asignación   | Mapas de bits para asignar bloques   | MTF para rastrear archivos   |
| Directorios   | Guardados como archivos especiales   | Almacenados en el MTF  |

El uso de los componentes tanto en Linux (Ext4) y en Windows (NTFS) tienen diferentes ventajas y desventajas, entre las que se pueden destacar las siguientes: 
__NTFS__
1. Permite una alta compatibilidad entre diferentes dispositivos del ecosistema Windows. 
2. el MTF permite un facil acceso a los metadatos de una manera eficiente y organizada. 
3. Soporte una comprensión transparente entre las diferentes carpetas y archivos. 
4. Ofrece diferentes herramientas de desfragmentación. 

__EXT4__
1. Gracias a los mapas de bits, permite un rendimiento más eficiente, en especial en las operaciones de escritura y lectura. 
2. Es capaz de soportar desde 16TB hasta 1 ExaByte (EB). 
3. Es capaz de soportar enlaces duros y simbolicos, lo que permite la gestión avanzada de archivos. 

## Organización lógica y física de archivos. 
```
Raíz (/) o (C:\)
│
├── Sistema
│   ├── bin                
│   ├── boot               
│   ├── lib                
│   ├── System32           
│   └── drivers            
│
├── Usuarios
│   ├── usuario1
│   │   ├── Documentos     
│   │   ├── Descargas      
│   │   ├── Imágenes       
│   │   ├── Música         
│   │   ├── Videos         
│   │   └── Escritorio     
│   │
│   ├── usuario2
│   │   ├── Documentos
│   │   ├── Descargas
│   │   └── Música
│   │
│   └── Público            
│
├── Aplicaciones
│   ├── Office             
│   ├── Navegador          
│   ├── Juegos             
│   └── Utilidades         
│
├── Datos
│   ├── BasesDatos         
│   ├── Logs               
│   └── Backups            
│
├── Medios
│   ├── USB1               
│   ├── DiscoDuroExterno   
│   └── CDROM              
│
└── Temporal
    ├── Temp               
    └── Cache              
```
__Conversión de dirección física a lógica en el disco duro__
1. Se le asigna a cada bloque del disco duro un número secuencial a través de LBA. 
2. El Sistema Operativo se encarga de asignar archivos a diferentes bloques lógicos. 
3. El controlador de disco se encarga de traducir de la dirección LBA a una dirección física, todo esto mediante 3 protocolos: 

__Plato:__ El disco duro puede contar con diferentes discos magneticos, en los cuales puede almacenarse una dirección y por lo tanto, un espacio diferente de memoria. 

__Cabeza de lectura/escritura:__ Este se encarga de edeterminar que superficie del plato es la que se va a utilizar tanto para leer como para escribir archivos. 

__Cilindro:__ Este es un conjunto de vistas alineadas de manera vertical en los diferentes platos del disco duro. 

__Sector:__ Una división circular de la pista en la que se almacena la información. 

Por lo que podría quedar presente la siguiente premisa: 
#### Dirección física = Cilindro, Cabeza, Sector (CHS). 

### Ejemplo práctico: 
1. Primero se crea el archivo en cuestión y se almacena en una carpeta, esto envia una señal al sistema de archivos que se encarga de asignarle uno o varios bloques de memoria al archivo (este asigna un tamaño de bloque completo, de esta manera, llegando a desperdiciar espacio en el disco duro). 
2. El sistema de archivos se encarga de guardar los diferentes metadatos pertenecientes al archivo. 
3. El sistema de archivos se encarga de asignar una dirección física al archivo a través de los bloques lógicos (por ejemplo, digamos que el archivo esta en el bloque de memoria con la dirección LBA=2050, entonces el LBA se encarga de asignar una dirección física, la cual puede ser: 
Cilindro 5, Cabeza 1 y Sector 3). 
4. El sistema de archivos se encarga de escribir el archivo correspondiente en el espacio de memoria física correspondiente, asignando ahora ese espacio como un espacio de memoria ocupado. 

## Mecanismos de acceso a los archivos
__Acceso secuencial:__ Es un tipo de acceso en el cual los datos se leen o escriben de manera predefinida, uno despues de otro, este tipo de acceso es mayormente utilizado por cintas magneticas.Esto permite una mayor simplicidad y una mayor eficiencia en operaciones continuas. 

__Acceso aleatorio o directo:__
Este tipo de acceso permite escribir escribir o leer los datos en cualquier posición del medio de almacenamiento sin ninguna necesidad de leer los datos previos a este. Esto permite una mayor eficiencia en la busqueda de diferentes archivos y además ofrece una mayor flexibilidad al acceder a cualquier lugar del disco. 

__Acceso secuencial con indices:__
En este tipo de acceso, se utiliza una tabla de indices con las cuales se puede mejorar el acceso a aquellos datos que se encuentran almacenados de manera secuencial, sin necesidad de escanear toda la estructura. 

__Acceso con punteros o enlazado:__
Este utiliza una cadena de punteros que permite acceder a los datos, en el cual cada uno de los bloques tiene asignada una dirección al siguiente bloque (como si se tratara de una lista enlazada). 

__Acceso por bloques contiguos:__
Este tipo de acceso permite almacenar diferentes archivos en tipos de bloques que se encuentren juntos o de manera contigua, lo que evita el movimiento del disco a diferentes regiones de este con el fin de leer o escribir un mismo archivo, permitiendo una mayor eficiencia. 

### Acceso secuencial a un archivo: 
```
Si no se puede abrir el archivo, entonces{
    Mostrar "Error al abrir el archivo";
    Terminar;
}Fin Si
Mientras no se haya llegado al final del archivo, hacer{
    Leer bloque de datos
    Si la línea no está vacía, hacer{
        Procesar_dato();
    }Fin Si
}Fin Mientras

Cerrar archivo
```
### Acceso directo a un archivo mediante su posición: 
```
Si no se puede abrir el archivo, entonces{
    Mostrar "Error al abrir el archivo";
    Terminar;
}Fin Si

Posición = 1000;
Mover_archivo(Posición);

Leer_datos(Posición);
Si los datos leídos no están vacíos, entonces{
    Procesar_dato();
}Fin Si

Cerrar archivo
```
### Acceso mediante un índice: 
```
Si no se puede abrir el archivo, entonces{
    Mostrar "Error al abrir el archivo";
    Terminar;
}Fin Si

open_indice(archivo);
Si no se puede abrir el índice, entonces{
    Mostrar "Error al abrir el índice";
    Terminar;
}Fin Si

Índice = buscarIndice(archivo);
Si Índice no está vacío, entonces{
    Posición = obtenerDireccion(indice);
    move_archivo(Posición);
    Leer(datos);
    Procesar_dato();
Sino{
    Mostrar "Dato no encontrado";
    }
}Fin Si
close(archivo);
close(indice);
```
### VENTAJAS 
#### Acceso Secuencial: 
1. Posee una mayor simplicidad, por lo que es más facil de implementar y entender al capturar y leer los archivos de uno por uno hasta encontrar el que se esta buscando. 
2. Posee una mayor eficiencia para manejar grandes volumenes de datos secuenciales. 
3. Este acceso requiere menos espacio, ya que no requiere mantener indices de datos ni estructuras adicionales. 
#### Acceso directo o aleatorio:
1. Permite un acceso más rapido a cualquier ubicación del disco, en el cual se desea leer o escribir, lo cual mejora el acceso a datos especificos. 
2. Permite tambien una mayor eficiencia para manejar archivos de grandes volumenes pero para aplicar cambios especificos. 
#### Acceso por índice:
1. Permite una busqueda rápida y eficiente. Al tratarse de indices especificos para datos en particular, permite acceder a ello sin necesidad de realizar un escaneo completo. 
2. Permite un mejor manejo y rendimiento en las bases de datos grandes o de mayor volumen. 
3. Permite realizar una busqueda de texto o patrones. 

## Modelo jerarquico y mecanismos de recuperación en caso de fallas
### Tipos de respaldo
__Respaldo completo:__ 

Este consiste en una copia de seguridad de todos los archivos y datos seleccionados, esto independientemenete de si estos cambiaron o no desde el último respaldo. Este es facil de restaurar porque todos los archivos se encuentran en una sola copia, por lo que no depende de otros respaldos para recuperar archivos completos. Su suo recomendado es para realizar respaldos periodicos, ya sean semanales o mensuales. 

__Respaldo incremental:__

Este se encarga de realizar solamente respaldos de aquellos archivos que hayan cambiado desde este último. Este resulta ser más eficiente en cuanto a tiempo y espacio, ya que solo se encarga de respaldar datos modificados, por lo que es ideal para respaldos diarios. 

__Respaldo diferencial:__

Trabaja de forma similar al incremental, pero en lugar de solo modificar los archivos más recientes desde el último respaldo, cambia todos los archivos desde el último respaldo completo. Este permite una restauración más rápida que el incremental, muy útil para aquellos sistemas que requieren un equilibro entre velocidad y facilidad de restauración. 

# Protección y Seguridad
### Concepto de Protección: 
Este se refiere a los mecanismos internos que implementa el sistema para controlar el acceso a los recursos por parte tanto de usuarios como de procesos. Este tipo de ptotección se encarga de garantizar que solo las entidades autorizadas puedan acceder a un recurso y que lo hagan de una manera segura y correcta. 
### Concepto de Seguridad: 
Esta se encarga de proteger el sistema operativo contra amenazas tanto internas como externas, así como accesos no autorizados, malware, ataques de red y diferentes vulnerabilidades del sistema. Esto con el objetivo de garantizar la confidencialidad, integridad y disponibilidad de la información y los recursos del sistema. 

### Objetivos principales de Protección y Seguridad


   





