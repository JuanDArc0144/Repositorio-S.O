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
Al conectar la memoria USB, y utilizar el comando `sudo fdisk -l`, muestra que el archivo se encuentra en la carpeta `/dev/sda`, siendo `sda` un archivo. 
Al intentar abrir el archivo con el comando 
`cat`, devuelve una serie de caracteres ilegibles. 
Sin embargo, al querer conocer las caracteristicas del archivo a través del comando `stat`, muestra los siguientes mensajes: 
```bash
[juanalbertosh@2806-103e-002d-0f7f-94f1-6177-0809-e5bf] - [/dev] - [dom dic 15, 14:56]
└─[$] <> stat sda     
  Fichero: sda
  Tamaño: 0         	Bloques: 0          Bloque E/S: 4096   fichero especial de bloques
Device: 0,6	Inode: 1125        Links: 1     Device type: 8,0
Acceso: (0660/brw-rw----)  Uid: (    0/    root)   Gid: (    6/    disk)
Contexto: system_u:object_r:fixed_disk_device_t:s0
      Acceso: 2024-12-15 14:56:20.756604997 -0600
Modificación: 2024-12-15 14:56:20.475606909 -0600
      Cambio: 2024-12-15 14:56:20.475606909 -0600
    Creación: 2024-12-15 14:52:38.857019037 -0600
```
Al momento de realizar el montaje, saltaba el error siguiente: 
```bash
mount: /mnt/USB/: can't find in /etc/fstab.
```
Esto porque al momento de querer realizar el montaje, se realizo con la condición `-t`, lo que implicaba un montaje de manera recursiva. 
Eliminando la condición anterior, se logró exitosamente montar el dispositivo USB. 


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
Una vez creado el archivo, se copia a una carpeta, de la siguiente manera. 
```bash
cp ejemplo.txt Descargas/
```
A lo cual suelta el siguiente error: 
```bash
cp: no se puede efectuar `stat' sobre 'ejemplo.txt': No existe el fichero o el directorio
```
Esto ocurre principalmente por el motivo de que, para poder acceder al documento a copiar, puede hacerse de dos maneras:

1. Accediendo a la carpeta donde se encuentra. 
2.  Haciendo referencia a este a través de una ruta completa. 
Con las debidas correcciones, queda de la siguiente manera: 
```bash
sudo cp ejemplo.txt /home/juanalbertosh/Descargas/
```
Una vez ejecutando el comando, quedaría el comando `ls` en la carpeta de Descargas de la siguiente manera: 
```bash
[juanalbertosh@192] - [~/Descargas] - [lun dic 16, 18:56]
└─[$] <> ls
 anki-24.06.3-linux-qt6.tar.zst                                        'Nuevos métodos(1).xlsm'
 ejemplo.txt                                                           'Nuevos métodos.xlsm'
'Ejercicio 2.xlsm'                                                     'Perelman Ya.I. - Geometria recreativa.pdf'
 google-chrome-stable_current_x86_64.rpm                                query.txt
 jdk-22_linux-x64_bin.rpm                                               VirtualBox-7.1-7.1.2_164945_fedora40-1.x86_64.rpm
'Landau L., Rumer Y. - Que es la teoria de la relatividad (1985).pdf'   VisualStudioSetup.exe
 mysql-workbench-community-8.0.38-1.fc40.x86_64.rpm
```
Posteriormente, hay que renombrarlo con el comando `mv`, el cual sirve principalmente para mover archivos, pero en este caso, al colocar la misma dirección de carpeta, solo se encarga de cambiar el nombre del archivo. 
Ejecutamos el siguiente comando:
```bash
sudo mv ejemplo.txt /home/juanalbertosh/Descargas/ejemploSO.txt
```
Quedando el `ls` de la siguiente manera: 
```bash
[juanalbertosh@192] - [~/Descargas] - [lun dic 16, 18:59]
└─[$] <> ls
 anki-24.06.3-linux-qt6.tar.zst                                        'Nuevos métodos(1).xlsm'
 ejemploSO.txt                                                         'Nuevos métodos.xlsm'
'Ejercicio 2.xlsm'                                                     'Perelman Ya.I. - Geometria recreativa.pdf'
 google-chrome-stable_current_x86_64.rpm                                query.txt
 jdk-22_linux-x64_bin.rpm                                               VirtualBox-7.1-7.1.2_164945_fedora40-1.x86_64.rpm
'Landau L., Rumer Y. - Que es la teoria de la relatividad (1985).pdf'   VisualStudioSetup.exe
 mysql-workbench-community-8.0.38-1.fc40.x86_64.rpm
```
Por ultimo, se pueden mover archivos sin necesidad de especificar el destino si este es la carpeta en la que nos encontramos, añadiendo un `.` en su lugar. 
Esto a través del comando: 
```bash
sudo mv /home/juanalbertosh/Descargas/ejemploSO.txt .
```

__Comprimir y descomprimir archivos__
Primero, creamos una carpeta con el nombre `/backup`, en la cual guardaremos una serie de archivos. Esto a través del comando `tar -czvf backup.tar.gz backup/`. 
Una vez creado, eliminamos el diretorio original a través del comando `rm`, de la siguiente manera: 
```bash
rm -rf backup
```
Posteriormente, es cuestión de descomprimir el archivo `.tar.gz`, a través del siguiente comando: `rm -rf backup`
Quedando de la siguiente manera: 
```bash
[juanalbertosh@192] - [~/Descargas] - [lun dic 16, 19:10]
└─[$] <> ls
 anki-24.06.3-linux-qt6.tar.zst                                         mysql-workbench-community-8.0.38-1.fc40.x86_64.rpm
 backup                                                                'Nuevos métodos(1).xlsm'
 backup.tar.gz                                                         'Perelman Ya.I. - Geometria recreativa.pdf'
 google-chrome-stable_current_x86_64.rpm                                VirtualBox-7.1-7.1.2_164945_fedora40-1.x86_64.rpm
 jdk-22_linux-x64_bin.rpm                                               VisualStudioSetup.exe
'Landau L., Rumer Y. - Que es la teoria de la relatividad (1985).pdf'
```

__Permisos y propiedades de archivos__
Primero, creamos un archivo a través del comando `touch`. 
```bash
touch archivoPrueba.txt
```
Posteriormente, otorgamos permisos al archivo con el fin de que solo el propietario pueda leer y escribir en este, a través del comando:
`chmod 600 archivoPrueba.txt `
Ahora, para convertir en propietario a otro usuario, se utiliza el siguiente comando: 
`sudo chown usuario privado.txt`, aqui se utiliza el `sudo` debido a que son operaciones que solo se pueden realizar como superUsuario (especialmente si se trata de cambiar u otorgar diferentes permisos). 

__Exploración de dispositivos__
El comando `lsblk` se encarga de mostrar los diferentes tipos de particiones de discos y almacenamiento que se guardan a través del formato de bloques. 
Para poder visualizar el tamaño de una carpeta, se utiliza el comando `du`, seguido de las condiciones `-sh`. 
Quedando el comando final de la siguiente manera: 
```bash
[juanalbertosh@192] - [~] - [lun dic 16, 19:16]
└─[$] <> du -sh /home/juanalbertosh/Documentos
17G	/home/juanalbertosh/Documentos
```
A través del comando `df -h`, se puede hacer una visualización del uso de los diferentes discos o dispositivos de almacenamiento. 
```bash
[juanalbertosh@192] - [~] - [lun dic 16, 19:17]
└─[$] <> df -h                                
S.ficheros     Tamaño Usados  Disp Uso% Montado en
/dev/nvme0n1p6   100G    37G   63G  37% /
devtmpfs         4.0M      0  4.0M   0% /dev
tmpfs            3.6G    24M  3.6G   1% /dev/shm
efivarfs         118K    56K   58K  49% /sys/firmware/efi/efivars
tmpfs            1.5G   2.0M  1.5G   1% /run
/dev/loop2       494M   494M     0 100% /var/lib/snapd/snap/netbeans/102
/dev/loop0        22M    22M     0 100% /var/lib/snapd/snap/bashtop/504
/dev/loop4        64M    64M     0 100% /var/lib/snapd/snap/core20/2318
/dev/loop9        39M    39M     0 100% /var/lib/snapd/snap/snapd/21759
/dev/loop1        64M    64M     0 100% /var/lib/snapd/snap/core20/2434
/dev/loop6       500M   500M     0 100% /var/lib/snapd/snap/netbeans/111
/dev/loop3        74M    74M     0 100% /var/lib/snapd/snap/core22/1663
/dev/loop7       122M   122M     0 100% /var/lib/snapd/snap/obsidian/40
/dev/loop5        75M    75M     0 100% /var/lib/snapd/snap/core22/1564
/dev/loop8        45M    45M     0 100% /var/lib/snapd/snap/snapd/23258
tmpfs            3.6G   3.0M  3.6G   1% /tmp
/dev/nvme0n1p6   100G    37G   63G  37% /home
/dev/nvme0n1p5   974M   412M  495M  46% /boot
/dev/nvme0n1p1   256M    55M  202M  22% /boot/efi
tmpfs            729M   3.7M  725M   1% /run/user/1000
```

__Crear y formatear particiones__
Primero, localizamos un disco que no contenga alguna partición, esto a través del comando `sudo fdisk -l`. 
Posteriomente, utilizamos el comando `sudo fdisk /dev/sdX`, esto con el fin de utilizar el disco duro que se encuentra almacenado en el directorio `/dev/sdX` y asignarle una partición. 
Posteriormente, se necesita formatear la partición con el tipo `sudo mkfs.ext4 /dev/sdX`, a este disco se le asigna un tipo de sistema de archivos del tipo `ext4`.
Posteriomente, montamos la partición y nos encargamos de mover o crear diferentes archivos en ella a través de los comandos antes vistos. 
Quedando de la siguiente manera: 
```bash
[juanalbertosh@192] - [~] - [lun dic 16, 19:27]
└─[$] <> sudo 'echo "Prueba de escritura" > /mnt/particion/test.txt'
``` 





