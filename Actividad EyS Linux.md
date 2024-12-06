# Actividad de dispositivos de E/S en Linux
## Listar dispositivos conectados
#### lsblk: 
~~~
NAME        MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0         7:0    0    22M  1 loop /var/lib/snapd/snap/bashtop/504
loop1         7:1    0  63.9M  1 loop /var/lib/snapd/snap/core20/2318
loop2         7:2    0  63.7M  1 loop /var/lib/snapd/snap/core20/2434
loop3         7:3    0  74.3M  1 loop /var/lib/snapd/snap/core22/1564
loop4         7:4    0  73.9M  1 loop /var/lib/snapd/snap/core22/1663
loop5         7:5    0 493.4M  1 loop /var/lib/snapd/snap/netbeans/102
loop6         7:6    0 499.2M  1 loop /var/lib/snapd/snap/netbeans/111
loop7         7:7    0 121.8M  1 loop /var/lib/snapd/snap/obsidian/40
loop8         7:8    0  38.8M  1 loop /var/lib/snapd/snap/snapd/21759
loop9         7:9    0  44.3M  1 loop /var/lib/snapd/snap/snapd/23258
zram0       252:0    0   7.1G  0 disk [SWAP]
nvme0n1     259:0    0 476.9G  0 disk 
├─nvme0n1p1 259:1    0   260M  0 part /boot/efi
├─nvme0n1p2 259:2    0    16M  0 part 
├─nvme0n1p3 259:3    0 374.5G  0 part 
├─nvme0n1p4 259:4    0     2G  0 part 
├─nvme0n1p5 259:5    0     1G  0 part /boot
└─nvme0n1p6 259:6    0  99.3G  0 part /home
                                      /
~~~

#### lsusb: 
~~~
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 001 Device 003: ID 30c9:0053 Luxvisions Innotech Limited Integrated Camera
Bus 001 Device 004: ID 1d57:fa60 Xenta 2.4G Wireless Device
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 003 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 003 Device 002: ID 1c7a:0576 LighTuning Technology Inc. EgisTec EH576
Bus 003 Device 003: ID 0bda:4853 Realtek Semiconductor Corp. Bluetooth Radio
Bus 004 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
~~~

#### lspci
~~~
00:00.0 Host bridge: Advanced Micro Devices, Inc. [AMD] Renoir/Cezanne Root Complex
00:00.2 IOMMU: Advanced Micro Devices, Inc. [AMD] Renoir/Cezanne IOMMU
00:01.0 Host bridge: Advanced Micro Devices, Inc. [AMD] Renoir PCIe Dummy Host Bridge
00:01.2 PCI bridge: Advanced Micro Devices, Inc. [AMD] Renoir/Cezanne PCIe GPP Bridge
00:02.0 Host bridge: Advanced Micro Devices, Inc. [AMD] Renoir PCIe Dummy Host Bridge
00:02.2 PCI bridge: Advanced Micro Devices, Inc. [AMD] Renoir/Cezanne PCIe GPP Bridge
00:02.4 PCI bridge: Advanced Micro Devices, Inc. [AMD] Renoir/Cezanne PCIe GPP Bridge
00:08.0 Host bridge: Advanced Micro Devices, Inc. [AMD] Renoir PCIe Dummy Host Bridge
00:08.1 PCI bridge: Advanced Micro Devices, Inc. [AMD] Renoir Internal PCIe GPP Bridge to Bus
00:14.0 SMBus: Advanced Micro Devices, Inc. [AMD] FCH SMBus Controller (rev 51)
00:14.3 ISA bridge: Advanced Micro Devices, Inc. [AMD] FCH LPC Bridge (rev 51)
00:18.0 Host bridge: Advanced Micro Devices, Inc. [AMD] Cezanne Data Fabric; Function 0
00:18.1 Host bridge: Advanced Micro Devices, Inc. [AMD] Cezanne Data Fabric; Function 1
00:18.2 Host bridge: Advanced Micro Devices, Inc. [AMD] Cezanne Data Fabric; Function 2
00:18.3 Host bridge: Advanced Micro Devices, Inc. [AMD] Cezanne Data Fabric; Function 3
00:18.4 Host bridge: Advanced Micro Devices, Inc. [AMD] Cezanne Data Fabric; Function 4
00:18.5 Host bridge: Advanced Micro Devices, Inc. [AMD] Cezanne Data Fabric; Function 5
00:18.6 Host bridge: Advanced Micro Devices, Inc. [AMD] Cezanne Data Fabric; Function 6
00:18.7 Host bridge: Advanced Micro Devices, Inc. [AMD] Cezanne Data Fabric; Function 7
01:00.0 SD Host controller: O2 Micro, Inc. SD/MMC Card Reader Controller (rev 01)
02:00.0 Network controller: Realtek Semiconductor Co., Ltd. RTL8852BE PCIe 802.11ax Wireless Network Controller
03:00.0 Non-Volatile memory controller: Micron Technology Inc 2400 NVMe SSD (DRAM-less) (rev 03)
04:00.0 VGA compatible controller: Advanced Micro Devices, Inc. [AMD/ATI] Barcelo (rev c5)
04:00.1 Audio device: Advanced Micro Devices, Inc. [AMD/ATI] Renoir Radeon High Definition Audio Controller
04:00.2 Encryption controller: Advanced Micro Devices, Inc. [AMD] Family 17h (Models 10h-1fh) Platform Security Processor
04:00.3 USB controller: Advanced Micro Devices, Inc. [AMD] Renoir/Cezanne USB 3.1
04:00.4 USB controller: Advanced Micro Devices, Inc. [AMD] Renoir/Cezanne USB 3.1
04:00.5 Multimedia controller: Advanced Micro Devices, Inc. [AMD] ACP/ACP3X/ACP6x Audio Coprocessor (rev 01)
04:00.6 Audio device: Advanced Micro Devices, Inc. [AMD] Family 17h/19h HD Audio Controller
04:00.7 Signal processing controller: Advanced Micro Devices, Inc. [AMD] Sensor Fusion Hub
~~~

#### dmesg | grep usb
~~~
[    0.272495] usbcore: registered new interface driver usbfs
[    0.272501] usbcore: registered new interface driver hub
[    0.272508] usbcore: registered new device driver usb
[    0.697820] usb usb1: New USB device found, idVendor=1d6b, idProduct=0002, bcdDevice= 6.11
[    0.697822] usb usb1: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.697824] usb usb1: Product: xHCI Host Controller
[    0.697825] usb usb1: Manufacturer: Linux 6.11.8-200.fc40.x86_64 xhci-hcd
[    0.697827] usb usb1: SerialNumber: 0000:04:00.3
[    0.698481] usb usb2: We don't know the algorithms for LPM for this host, disabling LPM.
[    0.698502] usb usb2: New USB device found, idVendor=1d6b, idProduct=0003, bcdDevice= 6.11
[    0.698504] usb usb2: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.698506] usb usb2: Product: xHCI Host Controller
[    0.698507] usb usb2: Manufacturer: Linux 6.11.8-200.fc40.x86_64 xhci-hcd
[    0.698508] usb usb2: SerialNumber: 0000:04:00.3
[    0.699491] usb usb3: New USB device found, idVendor=1d6b, idProduct=0002, bcdDevice= 6.11
[    0.699493] usb usb3: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.699495] usb usb3: Product: xHCI Host Controller
[    0.699496] usb usb3: Manufacturer: Linux 6.11.8-200.fc40.x86_64 xhci-hcd
[    0.699497] usb usb3: SerialNumber: 0000:04:00.4
[    0.700195] usb usb4: We don't know the algorithms for LPM for this host, disabling LPM.
[    0.700216] usb usb4: New USB device found, idVendor=1d6b, idProduct=0003, bcdDevice= 6.11
[    0.700217] usb usb4: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.700219] usb usb4: Product: xHCI Host Controller
[    0.700220] usb usb4: Manufacturer: Linux 6.11.8-200.fc40.x86_64 xhci-hcd
[    0.700221] usb usb4: SerialNumber: 0000:04:00.4
[    0.700678] usbcore: registered new interface driver usbserial_generic
[    0.700685] usbserial: USB Serial support registered for generic
[    0.709762] usbcore: registered new interface driver usbhid
[    0.709764] usbhid: USB HID core driver
[    0.938372] usb 3-3: new high-speed USB device number 2 using xhci_hcd
[    0.938392] usb 1-2: new full-speed USB device number 2 using xhci_hcd
[    1.068781] usb 3-3: New USB device found, idVendor=1c7a, idProduct=0576, bcdDevice=15.72
[    1.068785] usb 3-3: New USB device strings: Mfr=1, Product=2, SerialNumber=3
[    1.068788] usb 3-3: Product: EgisTec EH576
[    1.068790] usb 3-3: Manufacturer: EgisTec
[    1.068791] usb 3-3: SerialNumber: 16D95CC2
~~~

#### ¿Qué tipos de dispositivos se muestran en la salida de `lsblk`?
Muestra los diferentes dispositivos como USB y discos duros que se encuentren en bloques, ya sean disponibles o especificados. 

#### ¿Cuál es la diferencia entre `lsusb` y `lspci`?
El comando `lsusb` muestra los dispositivos USB conectados o disponibles en el dispositivo, mientras que el comando `lspci` muestra los dispositivos conectados al puerto PCI. 

#### ¿Qué información adicional proporciona `dmesg | grep usb`?
El comando `dmesg | grep usb` estaf formado por dos partes, el `dmesg` significa __diagnostic message__, el comando `grep usb` funciona para buscar palabras especificas dentro de un comando. El comando completo se encarga de mostrar los mensajes salientes del Kernel. 

## Verificar dispositivos de almacenamiento
`fdisk -l`:
~~~
Device             Start        End   Sectors   Size Type
/dev/nvme0n1p1      2048     534527    532480   260M EFI System
/dev/nvme0n1p2    534528     567295     32768    16M Microsoft reserved
/dev/nvme0n1p3    567296  785864703 785297408 374.5G Microsoft basic data
/dev/nvme0n1p4 996118528 1000214527   4096000     2G Windows recovery environment
/dev/nvme0n1p5 785864704  787961855   2097152     1G Linux extended boot
/dev/nvme0n1p6 787961856  996118527 208156672  99.3G Linux filesystem
~~~

`blkid`: 
~~~
/dev/loop1: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/nvme0n1p5: UUID="1820a5bb-4459-430a-a377-7a8be41533ec" BLOCK_SIZE="4096" TYPE="ext4" PARTUUID="7f0b0f72-36d7-4061-b78d-c122d772eddd"
/dev/nvme0n1p3: LABEL="Windows-SSD" BLOCK_SIZE="512" UUID="01DAED07AC193CA0" TYPE="ntfs" PARTLABEL="Basic data partition" PARTUUID="30e9c45f-3424-409f-b696-a1c49d35e58a"
/dev/nvme0n1p1: LABEL_FATBOOT="SYSTEM_DRV" LABEL="SYSTEM_DRV" UUID="0E69-3A44" BLOCK_SIZE="512" TYPE="vfat" PARTLABEL="EFI System Partition" PARTUUID="b3af5265-c30c-4a79-ac4d-0ed5a0925c3e"
/dev/nvme0n1p6: LABEL="fedora" UUID="e289db9d-e076-4a28-b551-5b198d6543af" UUID_SUB="7a77e3cd-dfe9-4097-adaf-9566e7bad8f0" BLOCK_SIZE="4096" TYPE="btrfs" PARTUUID="39c58ae8-efdb-44dd-8a30-33ddd4518748"
/dev/nvme0n1p4: LABEL="WINRE_DRV" BLOCK_SIZE="512" UUID="005E6A2F5E6A1E22" TYPE="ntfs" PARTLABEL="Basic data partition" PARTUUID="1f8b35dd-3c8c-4d04-a4c0-f8529083d95f"
/dev/nvme0n1p2: PARTLABEL="Microsoft reserved partition" PARTUUID="91550202-a26a-4fb5-910d-814015173483"
/dev/loop8: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop6: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop4: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop2: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop0: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop9: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop7: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/zram0: LABEL="zram0" UUID="19d8cefa-f74b-454b-99b8-9e4c5daccb5c" TYPE="swap"
/dev/loop5: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop3: BLOCK_SIZE="131072" TYPE="squashfs"
~~~

`df -h`:
~~~
S.ficheros     Tamaño Usados  Disp Uso% Montado en
/dev/nvme0n1p6   100G    37G   62G  38% /
devtmpfs         4.0M      0  4.0M   0% /dev
tmpfs            3.6G    24M  3.6G   1% /dev/shm
efivarfs         118K    56K   58K  49% /sys/firmware/efi/efivars
tmpfs            1.5G   2.0M  1.5G   1% /run
/dev/loop1        64M    64M     0 100% /var/lib/snapd/snap/core20/2318
/dev/loop4        74M    74M     0 100% /var/lib/snapd/snap/core22/1663
/dev/loop9        45M    45M     0 100% /var/lib/snapd/snap/snapd/23258
/dev/loop8        39M    39M     0 100% /var/lib/snapd/snap/snapd/21759
/dev/loop6       500M   500M     0 100% /var/lib/snapd/snap/netbeans/111
/dev/loop5       494M   494M     0 100% /var/lib/snapd/snap/netbeans/102
/dev/loop2        64M    64M     0 100% /var/lib/snapd/snap/core20/2434
/dev/loop3        75M    75M     0 100% /var/lib/snapd/snap/core22/1564
/dev/loop0        22M    22M     0 100% /var/lib/snapd/snap/bashtop/504
/dev/loop7       122M   122M     0 100% /var/lib/snapd/snap/obsidian/40
tmpfs            3.6G   3.0M  3.6G   1% /tmp
/dev/nvme0n1p6   100G    37G   62G  38% /home
/dev/nvme0n1p5   974M   412M  495M  46% /boot
/dev/nvme0n1p1   256M    55M  202M  22% /boot/efi
tmpfs            729M   3.7M  725M   1% /run/user/1000
~~~

#### ¿Qué dispositivos de almacenamiento están conectados a su sistema?
Un SSD del tipo nvme, con 6 particiones diferentes, entre las que se encuentran una reservada para el sistema operativo Windows, otra para el SWAP de Linux y otra para el propio sistema operativo Linux. 

#### ¿Qué particiones están montadas actualmente?
6 particiones, entre las que se encuentran: 
~~~
/dev/nvme0n1p1      2048     534527    532480   260M EFI System
/dev/nvme0n1p2    534528     567295     32768    16M Microsoft reserved
/dev/nvme0n1p3    567296  785864703 785297408 374.5G Microsoft basic data
/dev/nvme0n1p4 996118528 1000214527   4096000     2G Windows recovery environment
/dev/nvme0n1p5 785864704  787961855   2097152     1G Linux extended boot
/dev/nvme0n1p6 787961856  996118527 208156672  99.3G Linux filesystem
~~~

#### ¿Qué tipo de sistemas de archivos se usan en las particiones? 
Tipo squashfs y tipo SWAP. 

## Examinar dispositivos de Entrada y Salida
 `xrandr`: 
 ~~~
 Screen 0: minimum 16 x 16, current 1920 x 1200, maximum 32767 x 32767
eDP-1 connected 1920x1200+0+0 (normal left inverted right x axis y axis) 300mm x 190mm
   1920x1200     59.88*+
   1600x1200     59.87  
   1440x1080     59.99  
   1400x1050     59.98  
   1280x1024     59.89  
   1280x960      59.94  
   1152x864      59.96  
   1024x768      59.92  
   800x600       59.86  
   640x480       59.38  
   320x240       59.52  
   1680x1050     59.95  
   1440x900      59.89  
   1280x800      59.81  
   1152x720      59.97  
   960x600       59.63  
   928x580       59.88  
   800x500       59.50  
   768x480       59.90  
   720x480       59.71  
   640x400       59.95  
   320x200       58.96  
   1920x1080     59.96  
   1600x900      59.95  
   1368x768      59.88  
   1280x720      59.86  
   1024x576      59.90  
   864x486       59.92  
   720x400       59.55  
   640x350       59.77  
 ~~~

`aplay -l`: 
~~~
**** List of PLAYBACK Hardware Devices ****
card 0: Generic [HD-Audio Generic], device 3: HDMI 0 [HDMI 0]
  Subdevices: 1/1
  Subdevice #0: subdevice #0
card 0: Generic [HD-Audio Generic], device 7: HDMI 1 [HDMI 1]
  Subdevices: 1/1
  Subdevice #0: subdevice #0
card 1: Generic_1 [HD-Audio Generic], device 0: ALC257 Analog [ALC257 Analog]
  Subdevices: 0/1
  Subdevice #0: subdevice #0
~~~

`lsof /dev/snd/*`: 
~~~
COMMAND    PID          USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
pipewire  3955 juanalbertosh  mem    CHR  116,6          1039 /dev/snd/pcmC1D0p
pipewire  3955 juanalbertosh   58u   CHR  116,9      0t0 1047 /dev/snd/controlC1
pipewire  3955 juanalbertosh   60u   CHR  116,6      0t0 1039 /dev/snd/pcmC1D0p
pipewire  3955 juanalbertosh   67u   CHR  116,1      0t0  642 /dev/snd/seq
pipewire  3955 juanalbertosh   68u   CHR  116,1      0t0  642 /dev/snd/seq
wireplumb 3961 juanalbertosh   24u   CHR  116,9      0t0 1047 /dev/snd/controlC1
wireplumb 3961 juanalbertosh   26u   CHR  116,5      0t0 1020 /dev/snd/controlC0
~~~

#### ¿Qué salidas de video están disponibles en su sistema?
~~~
Screen 0: minimum 16 x 16, current 1920 x 1200, maximum 32767 x 32767
eDP-1 connected 1920x1200+0+0 (normal left inverted right x axis y axis) 300mm x 190mm
~~~

#### ¿Qué dispositivos de sonido se detectaron?
~~~
card 0: Generic [HD-Audio Generic], device 3: HDMI 0 [HDMI 0]
card 0: Generic [HD-Audio Generic], device 7: HDMI 1 [HDMI 1]
card 1: Generic_1 [HD-Audio Generic], device 0: ALC257 Analog [ALC257 Analog]
~~~

#### ¿Qué procesos estan utilizando la tarjeta de sonido?
~~~
3955 juanalbertosh  mem    CHR  116,6          1039 /dev/snd/pcmC1D0p
3955 juanalbertosh   58u   CHR  116,9      0t0 1047 /dev/snd/controlC1
3955 juanalbertosh   60u   CHR  116,6      0t0 1039 /dev/snd/pcmC1D0p
3955 juanalbertosh   67u   CHR  116,1      0t0  642 /dev/snd/seq
3955 juanalbertosh   68u   CHR  116,1      0t0  642 /dev/snd/seq
3961 juanalbertosh   24u   CHR  116,9      0t0 1047 /dev/snd/controlC1
3961 juanalbertosh   26u   CHR  116,5      0t0 1020 /dev/snd/controlC0
~~~

## Crear un script para recopilar información
#### ¿Qué ventajas tiene usar un script para recopilar esta información?
Permite simplificar la busqueda de comandos para el usuario. 

#### ¿Qué cambios realizaría para personalizar el script?
Le cambiaria el nombre a las opciones de busqueda para hacerlo más rápido. 











