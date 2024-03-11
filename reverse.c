#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if(argc >3){      
    fprintf(stderr, "usage: reverse <input> <output>\n");
    exit(1);
    }

    FILE *inputFile;
    
	inputFile = fopen(argv[1], "r");
    if(inputFile == NULL){
		fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
        exit(1);
	}
	fclose(inputFile);
	
	return 0;
}

