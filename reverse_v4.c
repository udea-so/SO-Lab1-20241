#include <stdio.h>    
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *in = NULL, *out = NULL;
	in = stdin;
	out = stdout;

	// Test 1
	if (argc > 3){
		fprintf(stderr,"usage: reverse <input> <output>\n");
		exit(1);
	}

	// Test 2
	if (argc == 2 && (in = fopen(argv[1], "r")) == NULL) {
    	fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
    	exit(1);
  	}

  	// Test 3
  	if (argc == 3){
  		if ((in = fopen(argv[1], "r")) == NULL) {
      		fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
      		exit(1);
      	}
      	if ((out = fopen(argv[2], "w")) == NULL) {
      		fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
      		exit(1);
      	}

      	//Test 4 y 5
      	struct stat sb1, sb2;
    	if (fstat(fileno(in), &sb1) == -1 || fstat(fileno(out), &sb2) == -1){
      		fprintf(stderr, "reverse: fstat error\n");
      		exit(1);
    	}

    	if (sb1.st_ino == sb2.st_ino){
      		fprintf(stderr, "reverse: input and output file must differ\n");
      		exit(1);
    	}
  	}

  	//Test 6 y 7

  	//Arreglo de punteros a caracteres
  	char **lines = NULL;

  	//Contador para el numero de lineas
  	int lineCount = 0;

  	// puntero 'line' para almacenar dinámicamente cada línea leída
	// 'len' para rastrear la longitud de la línea actual.
  	char *line = NULL;
  	size_t len = 0;

  	while (getline(&line, &len, in ) != -1){

  		lineCount++;
		
		// Redimensionar dinámicamente el arreglo 'lines' para acomodar la nueva línea.
		lines = realloc(lines, lineCount * sizeof(char *));

		// Verificar si la asignación de memoria fue exitosa.
		if (lines == NULL) {
        fprintf(stderr, "reverse: error allocating memory\n");
        exit(1);
    	}

    	// Duplicar la línea recién leída y almacenar su dirección en el arreglo 'lines'.
		lines[lineCount - 1] = strdup(line);

		// Verificar si la duplicación de la línea fue exitosa.
		if (lines[lineCount - 1] == NULL) {
        fprintf(stderr, "reverse: error duplicating line\n");
        exit(1);
    	}
  	}
  	free(line);

  	//imprimir arreglo desde su ultima posicion a la inicial
  	for (int i = lineCount - 1; i >= 0; i--) {
  		fprintf(out,"%s",lines[i]);
  		free(lines[i]);
  	}
  	free(lines);

  	//Cerrar archivos
  	fclose(in);
  	fclose(out);
	return 0;
} 