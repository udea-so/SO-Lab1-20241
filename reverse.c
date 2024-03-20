#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

//  TEST 5 --------------------
int sonIguales(const char *archivo1, const char *archivo2)
{
    struct stat stat1, stat2;

    if (stat(archivo1, &stat1) != 0 || stat(archivo2, &stat2) != 0)
    {
        return -1;
    }

    if (stat1.st_dev != stat2.st_dev || stat1.st_ino != stat2.st_ino)
    {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{

    FILE *archivoDeEntrada;
    FILE *archivoDeSalida;

    char textoDeEntrada[24];
    // char textoDeEntrada2[500];

    //  TEST 1 --------------------
    if (argc >= 4)
    {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        return 1;
    }

    archivoDeEntrada = fopen(argv[1], "r");
    archivoDeSalida = fopen(argv[2], "w");

    //  TEST 2 Y 3 --------------------
    if (archivoDeEntrada == NULL || archivoDeSalida == NULL)
    {
        fprintf(stderr, "reverse: cannot open file '/no/such/file.txt'\n");
        return 1;
    }

    //  TEST 4 ------------------- comentar para probar el TEST 5
    /*strcmp compara dos cadenas. Si son identicas retorna 0
    si son diferentes, el programa sigue corriendo normal.*/
    if (strcmp(argv[1], argv[2]) == 0)
    {
        fprintf(stderr, "reverse: input and output file must differ\n");
        return 1;
    }

    //  TEST 5 --------------------
    if (sonIguales(argv[1], argv[2]) == 1)
    {
        // printf("son iguales");
        fprintf(stderr, "reverse: input and output file must differ\n");
        return 1;
    }

    //  TEST 6 --------------------------

    int numeroDeLineas = 0;

    // fgets lee una linea de texto desde el archivo archivoDeEntrada
    // lo guarda en un array de caracteres 'textoDeEntrada'
    /*
        Tiene los siguientes argumentos:
            ARG1 (textoDeEntrada) = El array de caracteres donde se guardará la linea leida.
            ARG2 (sizeOf(textoDeEntrada)) = El tamaño maximo de caracteres que leerá.
            ARG3 (archivoDeEntrada) = El archivo que tienen el texto que se leerá.
    */
    while (fgets(textoDeEntrada, sizeof(textoDeEntrada), archivoDeEntrada))
    {
        numeroDeLineas++;
        // printf("%s", textoDeEntrada);

        // fputs(textoDeEntrada, archivoDeSalida);
        // numeroDeLineas++;
    }
    // printf("Numero de Lineas: %d\n", numeroDeLineas);

    /*
    char **apuntador1 = malloc(sizeof(char *));
    char **apuntador2 = malloc(sizeof(char *));
    char **apuntador3 = malloc(sizeof(char *));
    char **apuntador4 = malloc(sizeof(char *));

    *apuntador1 = malloc(sizeof(char)*50);
    *apuntador2 = malloc(sizeof(char)*50);
    *apuntador3 = malloc(sizeof(char)*50);
    *apuntador4 = malloc(sizeof(char)*50);


    fseek(archivoDeEntrada, 0, SEEK_SET);

    fgets(*apuntador4, sizeof(apuntador4), archivoDeEntrada);
    fgets(*apuntador3,  sizeof(apuntador3),archivoDeEntrada);
    fgets(*apuntador2,  sizeof(apuntador2),archivoDeEntrada);
    fgets(*apuntador1,  sizeof(apuntador1),archivoDeEntrada);

    fputs(*apuntador1, archivoDeSalida);
    fputs(*apuntador2, archivoDeSalida);
    fputs(*apuntador3, archivoDeSalida);
    fputs(*apuntador4, archivoDeSalida);

    free(apuntador1);
    free(apuntador2);
    free(apuntador3);
    free(apuntador4);
    */

    // Cuenta el numero de lineas
    while (fgets(textoDeEntrada, sizeof(textoDeEntrada), archivoDeEntrada))
    {
        numeroDeLineas = numeroDeLineas + 1;
    }

    //int vectorApuntadores[numeroDeLineas];

    // Crea un apuntador a un apuntador de caracteres
    // reserva espacio de memoria suficiente para crear n de estos apuntadores
    // donde n es numeroDeLineas
    char **apuntadorALineas = malloc(sizeof(char *) * numeroDeLineas);
    for (int i = 0; i < numeroDeLineas; i++)
    {
        //Cada uno de los apuntadores creados arriba, apunta
        // a los siguientes apuntadores
        apuntadorALineas[i] = malloc(sizeof(char) * 10);
    }

    fseek(archivoDeEntrada, 0, SEEK_SET);

    //Lee archivoDeEntrada linea por linea empezando por la última
    // y las guarda en los espacios de memoria reservados para cada linea
    /*for (int i = numeroDeLineas - 1; i >= 0; i--)
    {
        fgets(apuntadorALineas[i], sizeof(apuntadorALineas), archivoDeEntrada);
    }*/
    for (int i = 0; i < numeroDeLineas; i++)
    {
        fgets(apuntadorALineas[i], sizeof(apuntadorALineas), archivoDeEntrada);
    }

    //Agrega al archivo de salida las lineas leidas
    /*for (int i = 0; i < numeroDeLineas; i++)
    {
        fputs(apuntadorALineas[i], archivoDeSalida);
        free(apuntadorALineas[i]);
    }*/
    for (int i = numeroDeLineas -1; i >= 0; i--)
    {
        fputs(apuntadorALineas[i], archivoDeSalida);
        free(apuntadorALineas[i]);
    }

    //    for(int i = 0; i < numeroDeLineas; i++){
    //     free(apuntadorALineas[i]);
    //    }
    free(apuntadorALineas);

    // Cierra el archivo abierto
    fclose(archivoDeEntrada);
    fclose(archivoDeSalida);

    return 0;
}