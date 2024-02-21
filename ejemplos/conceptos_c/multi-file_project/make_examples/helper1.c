#include "helper1.h"
#include <stdio.h>    // Se incluye por que se uso la función printf (si se comenta sale warning)
#include <string.h>   // Se incluye por que se uso la función strlen (si se comenta sale warning)

int num;

void saludo(void) {
    printf("Hola mundo\n");
}

void incrementar_num(void) {
    num++;
}

int tam(const char *str) {
    return strlen(str);
}

