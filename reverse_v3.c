#include <stdio.h>    
#include <stdlib.h>
#include <sys/stat.h>


#define handle_error(msg)                                                      \
  do {                                                                         \
    fprintf(stderr, msg);                                                      \
    exit(EXIT_FAILURE);                                                        \
  } while (0)


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

      	//Test 4
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

	return 0;
} 