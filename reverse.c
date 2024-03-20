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




    //  TEST 4 ------------------- 
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
    char textoDeEntrada[24];

    // FGETS lee una linea de texto desde el archivo archivoDeEntrada
    // lo guarda en un array de caracteres 'textoDeEntrada'
    /*
        Tiene los siguientes argumentos:
            ARG1 (textoDeEntrada) = El array de caracteres donde se guardará la linea leida.
            ARG2 (sizeOf(textoDeEntrada)) = El tamaño maximo de caracteres que leerá.
            ARG3 (archivoDeEntrada) = El archivo que tienen el texto que se leerá.
    */

    // Cuenta el numero de lineas
    while (fgets(textoDeEntrada, sizeof(textoDeEntrada), archivoDeEntrada))
    {
        numeroDeLineas = numeroDeLineas + 1;
    }

    // Punteros que puntarán a cada unaa de las lineas leidas
    char *textoAlmacenado[numeroDeLineas];

    for (int i = 0; i < numeroDeLineas; i++)
    {
        textoAlmacenado[i] = malloc(sizeof(char) * 10);
    }

    //Reinicia el "puntero" de archivoDeEntrada
    fseek(archivoDeEntrada, 0, SEEK_SET);



    // Lee archivoDeEntrada linea por linea empezando por la última
    //  y las guarda en los espacios de memoria reservados para cada linea

    /*for (int i = numeroDeLineas - 1; i >= 0; i--)
    {
        fgets(apuntadorALineas[i], sizeof(apuntadorALineas), archivoDeEntrada);
    }*/
    for (int i = 0; i < numeroDeLineas; i++)
    {
        //Se guarda en la posición de memoria reservada la linea i del archivoDeEntrada
        fgets(textoAlmacenado[i], sizeof(textoAlmacenado), archivoDeEntrada);
    }

    // Agrega al archivo de salida las lineas leidas
    for (int i = numeroDeLineas - 1; i >= 0; i--)
    {
        fputs(textoAlmacenado[i], archivoDeSalida);
        free(textoAlmacenado[i]);
    }

    // Cierra el archivo abierto
    fclose(archivoDeEntrada);
    fclose(archivoDeSalida);

    return 0;
}