# Ejemplo multiarchivo

## Compilacion

```bash
# Compilacion individual
gcc -Wall -O -c helper1.c
gcc -Wall -O -c helper2.c
gcc -Wall -O -c main.c
# Enlazado
gcc -o myexe main.o helper1.o helper2.o -lm
```