# Ejemplo 

## Ejemplo un solo archivo

```bash
gcc -Wall -o app.out app_main.c -lm
```

### Ejecución

```bash
./app.out
```

## Ejemplo multiarchivo


### Compilacion

```bash
# Compilacion individual
gcc -Wall -O -c helper1.c
gcc -Wall -O -c helper2.c
gcc -Wall -O -c main.c
# Enlazado
gcc -o app.out main.o helper1.o helper2.o -lm 
```

Para el enlazado se pueden usar comodines:

```bash
gcc -o app.out *.o -lm 
```


### Ejecución

```bash
./main.out
```
