#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//mensaje de error para salir del programa


//funcion invertir cadena

//funcion para leer archivo de entrada y escribirlo en orden inverso

//abrir archivo de salida

//leer archivo de entrada linea a linea

//funcion principal
///////////////////////////////////////////////////////////////////////////////
//aclarrar lo del entrada de texto y archivos

int main(int argc, char *argv[]) {
  // Validar el número de argumentos
  if (argc > 3) {
    error("Demasiados argumentos");
  }

  // Si se proporcionó un solo argumento, usar la entrada estándar
  if (argc == 1) {
    invertir_archivo(NULL, NULL);
  } else if (argc == 2) {
    // Si se proporcionaron dos argumentos, usar el primero como entrada y el segundo como salida
    if (strcmp(argv[1], argv[2]) == 0) {
      error("El archivo de entrada y salida deben diferir");
    }
    invertir_archivo(argv[1], argv[2]);
  }

  return 0;
}
