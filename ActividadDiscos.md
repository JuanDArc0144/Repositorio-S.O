### Comandos de Entrada y Salida, Discos y Archivos
__Montar y desmontar discos__
Al ingresar el comando `lsblk` en la terminal se muestran los diferentes dispositivos de memoria en bloques disposibles o especificados. En este caso, el disco duro muestra particiones de la siguiente manera (al tratarse de un disco duro del tipo nvme):
```bash
nvme0n1     259:0    0 476.9G  0 disk 
├─nvme0n1p1 259:1    0   260M  0 part /boot/efi
├─nvme0n1p2 259:2    0    16M  0 part 
├─nvme0n1p3 259:3    0 374.5G  0 part 
├─nvme0n1p4 259:4    0     2G  0 part 
├─nvme0n1p5 259:5    0     1G  0 part /boot
└─nvme0n1p6 259:6    0  99.3G  0 part /home
```
De igual forma, se puede utilizar el comando `fdisk -l` para mostrar los diferentes discos duros en el dispositivo. 
```bash
Device             Start        End   Sectors   Size Type
/dev/nvme0n1p1      2048     534527    532480   260M EFI System
/dev/nvme0n1p2    534528     567295     32768    16M Microsoft reserved
/dev/nvme0n1p3    567296  785864703 785297408 374.5G Microsoft basic data
/dev/nvme0n1p4 996118528 1000214527   4096000     2G Windows recovery environment
/dev/nvme0n1p5 785864704  787961855   2097152     1G Linux extended boot
/dev/nvme0n1p6 787961856  996118527 208156672  99.3G Linux filesystem
```
En este caso, se puede observar diferentes particiones, entre ellas una especial para Windows con un tamaño de 370GB (utilizo una partición de disco).
Al conectar la memoria USB, se tiene que montar en un directorio //terminar en casa con la USB. 

__Redirección de Entrada y Salida__
Para poder listar los diferentes archivos en un archivo de texto, se utiliza el comando `ls -l > listado.txt`, para despues comprobar que el listado es correcto desde terminal, se utiliza el comando `cat` seguido del nombre del archivo a abrir. Ahora, para añadir la fecha actual a la parte final del archivo, se utiliza el comando `date >>` seguido igualmente del nombre del archivo, quedando finalmente de la siguiente manera: 
```bash
[juanalbertosh@fedora] - [~/Documentos/Repositorio S.O] - [mar dic 10, 14:53]
└─[$] <git:(master*)> cat listado.txt
total 244
-rw-r--r--. 1 juanalbertosh juanalbertosh  15571 dic  6 13:38 Actividad EyS Linux.md
-rw-r--r--. 1 juanalbertosh juanalbertosh   1475 dic 10 14:47 ActividadDiscos.md
-rw-r--r--. 1 juanalbertosh juanalbertosh   3955 nov 24 07:43 Conteo de islas.c
-rw-r--r--. 1 juanalbertosh juanalbertosh 160798 dic  2 09:52 diagrama.png
-rw-r--r--. 1 juanalbertosh juanalbertosh   2809 nov 13 14:52 EjemploLista.c
-rw-r--r--. 1 juanalbertosh juanalbertosh      0 dic 10 14:49 listado.txt
-rw-r--r--. 1 juanalbertosh juanalbertosh    972 nov 24 19:15 MDinamica.c
-rw-r--r--. 1 juanalbertosh juanalbertosh   3091 nov 24 08:25 Memoria.c
-rw-r--r--. 1 juanalbertosh juanalbertosh    704 nov  7 14:08 Recursividad2.c
-rw-r--r--. 1 juanalbertosh juanalbertosh  41745 dic  2 11:44 REPOSITORIO.md
mar 10 dic 2024 14:53:53 CST
```
__Copiar y mover archivos__
Con el objetivo de conocer los comandos para mover y copiar archivos, se utilizan dos comandos, el `cp` para copiar y el `mv` para mover. Además, se muestra el comando `echo` seguido de un texto y el simbolo `>` para añadir el contenido de texto al archivo creado. 
Una vez creado el archivo, se copia a una carpeta. 
