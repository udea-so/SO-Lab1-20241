# Laboratory: Tutorial

> En esta sección se toma nota de los principales conceptos tratados en el documento [lab tutorial](https://pages.cs.wisc.edu/~remzi/OSTEP/lab-tutorial.pdf)

## 1. Primeros pasos

### Compilacion y enlazado basicos

Se tiene el archivo fuente [hw.c](hw.c). Para compilar se emplea el siguiente comando:

```bash
gcc hw.c   
```

El anterior genera un ejecutable llamado `a.out`, para poder ejecutar este se ejecuta en consola el comando:

```bash
./a.out
```

### Compilacion y enlazado 

Al usar la opción `-o` en el compilador, se puede especificar el nombre del ejecuable tal y como se muestra en el siguiente comando:

```bash
gcc -o hw hw.c # -o: to specify the executable name  
```

El resultado del comando anterior es generar el ejecutable `hw`, de modo que para ejecutar el programa se llama al ejecutable de la siguiente manera:

```bash
./hw
```

La siguiente tabla resume diferentes formas de invocar la utilidad `gcc`:

|Comando|Observaciones|
|---|---|
|```gcc -o hw hw.c```|**`-o`**: to specify the executable name |
|```gcc -Wall hw.c```|**`-Wall`**: gives much better warnings|
|```gcc -g hw.c```|**`-g`**: to enable debugging with gdb|
|```gcc -O hw.c```|**`-O`**: to turn on optimization |

### Enlazando con librerias

Archivo ejemplo [cylinder.c](cylinder.c)

Cuando se deseen emplear funciones externas en una aplicación estas deben ser invocadas en el codigo fuente. En el caso del lenguaje C, esto se hace usando la directiva ```#include```. 

Si se desea conocer lo que hace una función y como invocarla se emplea el **manual** de la función tal y como se muestra a continuación:

```bash
man fork # Incovación del manual para la función fork
man tan # Invocación del manual para la función fork
```

La siguiente tabla ilustra los principales elementos de deben ser analizados cuando se consulta un manual:

|Función|Comando|Archivos cabecera|Flag en el gcc|
|---|---|---|---|
|```fork```|```man fork```|```#include <sys/types.h>```</br> ```#include <unistd.h>```||
|```tan```|```man tan```|```#include <math.h>```|```-lm```|
|```fwrite```|```man fwrite```|```#include <stdio.h>```||
|```pthread_create```|```man pthread_create```|```#include <pthread.h>```|```-lpthread```|

En el siguiente archivo se muestra un ejemplo de la compilación y enlazado del programa [cylinder.c](cylinder.c) el cual hace uso de la función ```pow()``` definida en la libreria matematica:

```bash
gcc -o cylinder cylinder.c -Wall -lm
```

### Compilación multiarchivo

Para entender el concepto compile y ejecute los ejemplos que se encuentran en el siguiente [link](../conceptos_c/multi-file_project/)

En construcción...

## Referencias

1. https://makefiletutorial.com/
2. https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html 
3. https://linuxhandbook.com/using-make/
4. https://github.com/vampy/Makefile 
