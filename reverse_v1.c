#include <stdio.h>    
#include <stdlib.h>


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

	return 0;
} 