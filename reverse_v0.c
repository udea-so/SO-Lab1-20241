#include <stdio.h>    
#include <stdlib.h>


int main(int argc, char const *argv[])
{

	//Test 1
	if (argc > 3)
	{
		fprintf(stderr,"usage: reverse <input> <output>\n");
		exit(1);
	}

	return 0;
} 