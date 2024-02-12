# Ejemplo 

## Ejemplo un solo archivo

En este caso todo el programa se encuentra en el archivo [app_main.c](app_main.c).

### Compilación y enlazado

```bash
gcc -Wall -o app.out app_main.c -lm
```

### Ejecución

```bash
./app.out
```

## Ejemplo multiarchivo

En este caso todo el programa se encuentra dividido en varios archivos:
* **Archivos cabecera**:
  * [helper1.h](helper1.h)
  * [helper2.h](helper2.h)
* **Archivos fuente**:
  * [helper1.c](helper1.c)
  * [helper2.c](helper2.c)
  * [main.c](main.c)

### Compilacion

```bash
# Compilacion individual
gcc -Wall -O -c helper1.c
gcc -Wall -O -c helper2.c
gcc -Wall -O -c main.c
```

### Enlazado

```bash
# Enlazado
gcc -o app.out main.o helper1.o helper2.o -lm 
```

Para el enlazado se pueden usar comodines (wildcards):

```bash
gcc -o app.out *.o -lm 
```

### Ejecución

```bash
./main.out
```

## Uso del make

1. **Forma 1**: Usando el comando make cuando el archivo con make tiene el nombre por defecto, esto es ```Makefile```:

   ```
   make
   ```

2. **Forma 2**: Usando el comando make cuando el archivo con make un nombre diferente al que se maneja por defecto. Por ejemplo si el archivo se llama ```makefile_basico```, el comando a aplicar es el siguiente:

   ```
   make -f makefile_basico
   ```

A continuación se muestran dos archivos makefiles, uno sencillo y otro que hace uso de comodines y puede ser empleado de manera generica:
1. Archivo make sencillo: [makefile_basico](makefile_basico)
2. Archivo make con comodines (wildcards): [makefile_mejorado](makefile_mejorado)

## Referencias

* https://makefiletutorial.com/
* https://diveintosystems.org/book/C2-C_depth/advanced_writing_libraries.html