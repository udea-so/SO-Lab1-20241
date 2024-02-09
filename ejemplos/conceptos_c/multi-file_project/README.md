# Ejemplo 

## Ejemplo un solo archivo

```bash
gcc -Wall -O app_main.c -lm
```

## Ejemplo multiarchivo


### Compilacion

```bash
# Compilacion individual
gcc -Wall -O -c helper1.c
gcc -Wall -O -c helper2.c
gcc -Wall -O -c main.c
# Enlazado
gcc -o main.out main.o helper1.o helper2.o -lm 
```

Para el enlazado se pueden usar comodines:

```bash
gcc -o main.out *.o -lm 
```


### Ejecución

```bash
./main.out
```
