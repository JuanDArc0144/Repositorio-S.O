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
__Confidencialidad:__
Esta es una propiedad de los sistemas de seguridad que se encarga de garantizar que la información solo se encuentre disponibles para las personas, sistemas o procesos que tengan los permisos necesarios para interactuar con los archivos y elementos del equipo, ya sea para procesos de lectura o escritura. Esta propiedad existe principalmente con el fin de evitar el acceso no autorizado, esto a través de diferentes técnicas de autenticación o algún tipo de cifrado. 
Un ejemplo podría ser en un banco, en el cuál solo el propietario de la cuenta tenga accesos a sus propios datos bancarios. 
__Integridad:__
Esta propiedad se encarga de que la información se maneje de manera precisa, completa y sin alterar de manera indebida, ya sea a través de la transmisión de datos o la escritura de estos. Un ejemplo práctica sería en un hostipal o instalación médica, en el cual el historial de registros de los pacientes no pueda ser alterado por los médicos, solo agregar nuevos registros médicos. 
__Disponibilidad:__
Esta propiedad se encarga de asegurar que los sistemas, servicios y datos permanezcan accesibles cuado estos se necesiten por los usuarios autorizados, esto a con el fin de evitar malas prácticas como redundancia innecesaria y la capacidad de recuerar información ante desastres o ataques de denegación DoS. Un ejemplo sería en un sistema de emergencia, que los servicios especiales se encuentren disponibles las 24 horas. 
__Autenticación:__
Esta se encarga de confirmar la identidad de los diferentes usuarios o sistemas con el fin de evitar suplantaciones. 
__Auditoría:__
Esta permite el registro de las diferentes actividades con el fin de llevar una bitácora o registro con el fin de identificar anomalías o rastrear incidentes. 
__Autorización:__

## Clasificación de los mecanismos de seguridad
__Seguridad física:__
Esta se encarga de proteger los diferentes elementos físicos o de hardware del equipo, las instalaciones y el personal. Estos cuidados pueden ir desde lo particular como ataques de robos físicos de datos, hasta tomar enfoques más generales como desastres naturales. Este concepto implementa mecanismos como sistemas de vigilacia y alarmas y la creación de instalaciones adecuadas. Este se encarga de protege el hardware donde reside el sistema operativo, asegurando que personas no autorizadas no puedan manipular físicamente los dispositivos. Entre sus sistemas de autorización se encuentran 
__Seguridad Lógica:__
Esta se encarga de proteger los datos y el software de accesos no autorizados, o diferentes alteraciones o destrucciones, estos mediante a implementación de diferentes medidas y controles digitales. Este sus medidas de seguridad más importantes se encuentran el cifrado de datos y el soporte para anti-virus y malware. Se encarga de asegurar que los usuarios o procesos no autorizados puedan acceder a los S.O y sus funciones.
__Seguridad de red:__
Este se encarga de proteger la integridad, confidencialidad y disponibilidad de la información mientras es transmitida por medios de web o redes de comunicación, esto con el fin de evitar accesos no autorizados y ataques. Este se encarga de prevenir ejecuciones externas a través de firewalls, IPS y segmentación de la red, bloqueando bloques de intentos de acceso no autorizados. 

## Funciones del sistema de protección
Su objetivo principal consiste en determinar quien esta solicitando acceso al sistema, esto mediante su nombre de usuario o un ID único. Además se encarga de registrar y permitir que acciones se encuentran autorizadas para cada usuario, de esta manera permite que los archivos no puedan ser modificados o `mv`. 
__Ejemplo práctico:__
En un caso hipotetico, tenemos un usuario que instaló Linux, en el cual tiene sus archivos privados en una carpeta dentro del directorio raíz, para la cual puede realizar modificaciones a través del comando `sudo`. 
Después, tenemos un usuario malicioso, el cual quiere eliminar los archivos desde terminal, pero al tratarse de una carpeta en el directorio raíz, tiene que acceder desde `sudo`. 
```python
# Definir la matriz de acceso
matriz_acceso = {
    "Admin": {
        "DocumentosConfidenciales": ["R", "W", "X"],
        "Inventario": ["R", "W", "X"],
        "ReportesFinancieros": ["R", "W", "X"]
    },
    "Manager": {
        "DocumentosConfidenciales": ["R"],
        "Inventario": ["R", "W"],
        "ReportesFinancieros": ["R"]
    },
    "Employee": {
        "DocumentosConfidenciales": [],
        "Inventario": ["R"],
        "ReportesFinancieros": []
    }
}

# Función para verificar acceso
def verificar_acceso(usuario, recurso, permiso):
    """
    Verifica si un usuario tiene un permiso específico sobre un recurso.
    
    Args:
    usuario (str): Nombre del usuario.
    recurso (str): Nombre del recurso.
    permiso (str): Permiso a verificar ("R", "W", "X").
    
    Returns:
    bool: True si el usuario tiene permiso, False en caso contrario.
    """
    permisos = matriz_acceso.get(usuario, {}).get(recurso, [])
    return permiso in permisos

# Ejemplo de uso
usuarios = ["Admin", "Manager", "Employee"]
recursos = ["DocumentosConfidenciales", "Inventario", "ReportesFinancieros"]
permisos = ["R", "W", "X"]

# Probar acceso
for usuario in usuarios:
    for recurso in recursos:
        for permiso in permisos:
            tiene_acceso = verificar_acceso(usuario, recurso, permiso)
            print(f"¿{usuario} puede {permiso} en {recurso}? {'Sí' if tiene_acceso else 'No'}")
```
La matriz de acceso en un sistema operativo funciona como una tabla que asocia usuarios (o procesos) con recursos, especificando los permisos que tienen. En la práctica, esta matriz no se implementa literalmente como una tabla, sino que se organiza en estructuras más eficientes:
__Listas de Control de Acceso (ACL):__
Cada recurso almacena una lista con los permisos de los usuarios o grupos.
__Capacidades:__
Cada usuario o proceso tiene una lista de recursos a los que puede acceder junto con los permisos asociados.
__EJEMPLO:__
```python
# Matriz de acceso
matriz_acceso = {
    "Admin": {
        "DocumentosConfidenciales": ["R", "W", "X"],
        "Inventario": ["R", "W", "X"],
        "ReportesFinancieros": ["R", "W", "X"]
    },
    "Manager": {
        "DocumentosConfidenciales": ["R"],
        "Inventario": ["R", "W"],
        "ReportesFinancieros": ["R"]
    },
    "Employee": {
        "DocumentosConfidenciales": [],
        "Inventario": ["R"],
        "ReportesFinancieros": []
    }
}

# Función para verificar acceso
def verificar_acceso(usuario, recurso, permiso):
    permisos = matriz_acceso.get(usuario, {}).get(recurso, [])
    return permiso in permisos

# Intento de acceso
usuario = "Employee"
recurso = "DocumentosConfidenciales"
permiso = "W"

if verificar_acceso(usuario, recurso, permiso):
    print(f"Acceso concedido: {usuario} puede realizar '{permiso}' en {recurso}.")
else:
    print(f"Acceso denegado: {usuario} no tiene permisos para realizar '{permiso}' en {recurso}.")

    # Registro del intento fallido
    from datetime import datetime
    intento = {
        "Fecha": datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
        "Usuario": usuario,
        "Recurso": recurso,
        "Operación": permiso,
        "Resultado": "Acceso denegado",
        "IP": "192.168.1.101"
    }
    print("Registro de Auditoría:", intento)
```
Este modelo se utiliza principalmente para poder gestionar los permisos de los diferentes usuarios o procesos sobre los diferentes recursos que posee el equipo. Con este mecanismo nos aseguramos que cada interacción con los diferentes archivos, dispositivos u otros componentes del equipo se realicen dentro de los privilegios asignados, ya sea por el usuario o por el sistema de seguridad y protección en el sistema operativo. 
En este caso, cada fila representa un usuario o proceso creado, mientras que cada columna representa un recurso del sistema, mientras que en las celdas se despliegan los permisos especificos para la combinación de estos componentes. 
__Escenario simulado de protección de recursos__
En un caso hipotetico, supongamos que estamos en una empresa en la que se implementa una tabla similar para manejar los privilegios y los permisos sobre los recursos. En este escenario, un empleado intenta acceder a un archivo de caractér confidencial, con solo permisos de lectura para su tipo de usuario. En este caso, el sistema revisa la lista de privilegios, y le manda el siguiente mensaje al usuario: 
```
Acceso denegado: No tienes permisos para leer Archivo1.txt.
```
## Protección basada en el lenguaje 
Esta se refiere al uso de caracteristicas inherentes de un lenguaje de programación, en las cuales se garantiza que los programas diseñados en estos iguen una serie de reglas específicas de acceso y de uso de recursos. Este enfoque se centra en utilizar las capacidades del lenguaje para prevenir diferentes errores y violaciones de seguridad, con el fin de reducir la necesidad de depender de manera completa del sistema operativo o el hardware. 

__Ejemplo aplicado a Java__:
```java
public class memoria{
    public static void main(String[] args) {
        String despedida = "Buenas noches";
        System.out.println(despedida);
        saludo = null; 
        try {
            System.out.println(despedida.length());
        } catch (NullPointerException e) {
            System.out.println("Es nulo");
        }
    }
}
```
En el ejemplo anterior puede observarse esto, con el fin de reducir y eliminar la memoria que no se utiliza, Java implementa el Gargabe Collector, que se encarga de recolectar aquellos valores que quedan como null o son innutilizados, con el fin de reducir la memoria utilizada. 

### Diferentes entre protección de lenguaje y protección de los S.O
__Basado en Lenguaje:__
Este enfoque se encarga de utilizar las caracteristicas del propio lenguaje de programación, con el fin de garantizar un acceso seguro y un buen manejo de los recursos. Entre sus pricipales ventajas se encuentran la detección de errores en el tiempo de compilación o ejecución; la posibilidad de reducir errores humanos y ser independiente del harware. 

__Basada en el S.O:__
Este enfoque se centra en el acceso a los recursos del sistema mediante diferentes políticas y mecanismos. Entre sus ventajas se encuentran que poseen una tabla de permisos propia con sus propios niveles de privilegios, además de contar con diferentes espacios de memoria protegidos. 
   
## Amenazas del Sistema
1. __Malware:__
   Este consiste en diversos programas diseñados con el fin de dañar, interrumpir o robar la información de un sistema operativo. Entre ellos pueden encontrarse los virus (los más conocidos), los cuales consisten en adjuntar muchos archivos y  duplicarse ellos mismos; los troyanos que son programas de indole confiable pero que se encargar de realizar actividades maliciosas en el segundo plano; los ransomware que se encargan de cifrar los datos del usuario y exigir un rescate a través de un pago.

2. __Ataques de Fuerza Bruta:__
   Este consiste en probar diferentes combinaciones de contraseñas o claves hasta encontrar aquella que sea correcta, esto con el fin de acceder a archvos cifrados que requieran una clave (se requiere de un archivo que se le suele llamar "diccionario" que son un conjunto de posibles palabras que sean probables se encuentren incluidas en la clave).

3. __Inyección de Código:__
   Esta ocurre cuando un atacante inserta código malicioso en el sistema o aplicación que se encuentre vulnerable, logrando ejecutar comandos no autorizados (las más comunes suelen ser inyeccionesSQL, en las cuales se realizan acciones dentro de una BD).

## Mecanismos de verificación: 
__Autenticación Multifactor:__
Esta requiere que los usuarios proporcionen dos o más factores de autenticación de diferentes categorias, con el fin de verificar su identidad. 

__Control de integridad:__
Este se encarga de asegurar que los datos no han sido modificados, corrompidos o manipulados sin alguna autorización previa, esto con el fin de mantener la confianza en la exactitud y la consistencia de la información. 

| Usuario | Admin |No-Admin |
|----------|----------|----------|
| Sistema   | Lectura/Escritura   | Lectura   |
| Configuración    | Lectura/Escritura   | NO   |
| Aplicaciones   | Lectura/Escritura   | Lectura/Escritura   |

## Cifrado
__Cifrado simétrico:__
En este tipo de cifrado, la clave secreta o HASH se utiliza tanto para poder encriptar como desencriptar los diferentes tipos de datos. En este tipo de cifrado, tanto el emisor como el receptor deben conocer la clave y mantenerla en secreto con el fin de garantizar la seguridad. Este se utiliza comúnmente al hacer un cifrado completo del disco con el fin de mantener la seguridad en los datos, en este se utilizan diferentes algoritmos como AES (Advanced Encryption Standard).

__Cifrado asimetrico:__
En este tipo de cifrado, se utilizan dos claves diferentes pero que se encuentran relacionadas matemáticamente, en la cuales una es publica y la otra es privada. La púbica se encarga de cifrar los datos, mientras que la privada se encarga de descifrar el mensaje enviado. Este es altamente utilizado en protocolos SSH (Secure Shell), con el cual se puede acceder de forma segura a diferentes servidores remotos, en el cual en lugar de utilizar una contraseña normal, se utilizan un par de claves para autentificar al usuario. 

__EJEMPLO:__
```python
from cryptography.fernet import Fernet

def generar_clave():
    clave = Fernet.generate_key()
    return clave

def cifrar_archivo(nombre_archivo, clave):
    fernet = Fernet(clave)
    
    with open(nombre_archivo, 'rb') as archivo:
        contenido = archivo.read()
    
    contenido_cifrado = fernet.encrypt(contenido)
    
    with open(nombre_archivo + '.cifrado', 'wb') as archivo_cifrado:
        archivo_cifrado.write(contenido_cifrado)
    print(f"El archivo '{nombre_archivo}' ha sido cifrado y guardado como '{nombre_archivo}.cifrado'.")

def descifrar_archivo(nombre_archivo_cifrado, clave):
    fernet = Fernet(clave)
    
    with open(nombre_archivo_cifrado, 'rb') as archivo_cifrado:
        contenido_cifrado = archivo_cifrado.read()
    
    contenido_descifrado = fernet.decrypt(contenido_cifrado)
    
    nombre_archivo_original = nombre_archivo_cifrado.replace('.cifrado', '.descifrado')
    with open(nombre_archivo_original, 'wb') as archivo_descifrado:
        archivo_descifrado.write(contenido_descifrado)
    print(f"El archivo '{nombre_archivo_cifrado}' ha sido descifrado y guardado como '{nombre_archivo_original}'.")

if __name__ == "__main__":
    nombre_archivo = "archivo_ejemplo.txt"
    
    clave = generar_clave()
    print(f"Clave generada: {clave.decode()}")
    
    cifrar_archivo(nombre_archivo, clave)
    
    descifrar_archivo(nombre_archivo + '.cifrado', clave)
```





