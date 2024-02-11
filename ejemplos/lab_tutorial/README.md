
## 1. Primeros pasos


### Compilacion y enlazado basicos

Se tiene el archivo fuente (hw.c)[./hw]. Para compilar se emplea el siguiente comando:

```bash
gcc hw.c   
```

El anterior genera un ejecutable llamado `a.out`, para poder ejecutar este se ejecuta en consola el comando:

```bash
./a.out
```

### Compilacion y enlazado 

Al usar la opción `-o` en el compilador, se puede especificar el nombre del ejecuable

```bash
gcc -o hw hw.c # -o: to specify the executable name  
```

El resultado del comando anterior es generar el ejecutable `hw`, de modo que para ejecutar el programa se llama al ejecutable de la siguiente manera:

```bash
./hw
```

La siguiente tabla resume diferentes formas de invocar la utilidad `gcc`:

|Comando|Observaciones|
|```gcc -o hw hw.c```|**`-o`**: to specify the executable name |
|```gcc -Wall hw.c```|**`-Wall`**: gives much better warnings|
|```gcc -g hw.c```|**`-g`**: to enable debugging with gdb|
|```gcc -O hw.c```|**`-O`**: to turn on optimization |


### Enlazando con librerias

Archivo ejemplo [cylinder.c](cylinder.c)

Sometimes, you may want to use a library routine in your program. Because so many routines are available in the C library (which is automatically linked with every program), all you usually have to do is find the right #include file. The best way to do that is via the manual pages, usually just called the man pages

```bash
man fork #
man tan #
```

However, some library routines do not reside in the C library, and
therefore you will have to do a little more work. For example, the math
library has many useful routines, such as sines, cosines, tangents, and the
like. If you want to include the routine tan() in our code, you should
again first check the man page. 

|Función|Comando|Archivos cabecera|Flag en el gcc|
|---|---|---|---|
|```fork```|```man fork```|```#include <sys/types.h>```, ```#include <unistd.h>```||
|```tan```|```man tan```|```#include <math.h>```|```-lm```|
|```fwrite```|```man fwrite```|```#include <stdio.h>```||
|```pthread_create```|```man pthread_create```|```#include <pthread.h>```|```-lpthread```|


```bash
gcc -o cylinder cylinder.c -Wall -lm
```

### Compilación multiarchivo

