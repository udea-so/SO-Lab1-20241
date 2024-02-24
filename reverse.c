#include <stdio.h>        //Entradas y salidas estandar
#include <stdlib.h>       //Para manejo dinámico de datos
#include <string.h>       //Manejo de cadenas de caracteres
#include <unistd.h>
//Tamaño del buffer
#define MAX_LENGTH 4000

int main(int argc, char *argv[]) {
    limpiarPantalla();
    mostrarAnimacion();
    mostrarPresentacion();
    esperarTecla();
    flujoPrograma(argc, argv);
    esperarTecla();
    limpiarPantalla();
    return 0;
}

void mostrarAnimacion() {
    const char listacaracteres[] = "|/-\\";       //".oOo."     "|/-\\"
    const int numCaracteres = sizeof(listacaracteres) - 1;

    printf("Iniciando con sistemas operativos:  ");
    fflush(stdout);

    for (int i = 0; i < 8; ++i) {
        printf("\b%c", listacaracteres[i % numCaracteres]);
        fflush(stdout);                              //Forza la escritura de caracteres  que se encuentran en un buffer o flujo de salida
        sleep(1);  // Pausa de 1 segundo
    }

    printf("\b \n");  // Limpiar el último carácter
    fflush(stdout);                                //Saca caracter de retroce esto nos ayuda en dar la ilusíon de movimiento
}