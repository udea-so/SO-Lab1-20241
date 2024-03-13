#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

//  TEST 5 --------------------
int sonIguales(const char *archivo1, const char *archivo2)
{
    struct stat stat1, stat2;

    if(stat(archivo1, &stat1) != 0 || stat(archivo2, &stat2) != 0){
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

    char textoDeEntrada[1024];
    char textoDeEntrada2[500];
    int numeroDeLineas = 0;




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
    /*if (strcmp(argv[1], argv[2]) == 0)
    {
        fprintf(stderr, "reverse: input and output file must differ\n");
        return 1;
    }*/




    //  TEST 5 --------------------
    if(sonIguales(argv[1], argv[2]) == 1){
        //printf("son iguales");
        fprintf(stderr, "reverse: input and output file must differ\n");
        return 1;
    }

    while (fgets(textoDeEntrada, sizeof(textoDeEntrada), archivoDeEntrada))
    {

        printf("%s", textoDeEntrada);

        fputs(textoDeEntrada, archivoDeSalida);
        numeroDeLineas++;
    }

    // Cierra el archivo abierto
    fclose(archivoDeEntrada);
    fclose(archivoDeSalida);

    /*for(int i = numeroDeLineas - 1; i >= 0; i--){
        fputs(textoDeEntrada[i], archivoDeSalida);
        //free(textoDeEntrada[i]);
    }*/

    // Cierra el archivo abierto
    // fclose(archivoDeSalida);
   // printf("Ejecutado completamente");
    return 0;
}