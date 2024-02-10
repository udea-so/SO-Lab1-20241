#include <stdio.h>

#define MAXROW 3
#define MAXCOL 3

int main()
{
	int matrix[MAXROW][MAXCOL];

	int i;
	int j;

	// initialize the 2d-array.
	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			matrix[i][j] = i + j;
		}
	}

	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			printf("%d \t", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}

