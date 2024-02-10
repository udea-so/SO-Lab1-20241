#include <stdio.h>

#define MAXROW 3
#define MAXCOL 3

void print_2darray(int a[][MAXCOL]);

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

	print_2darray(matrix);

	return 0;
}

void print_2darray(int a[][MAXCOL]) {
	int i;
	int j;
	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			printf("%d \t", a[i][j]);
		}
		printf("\n");
	}
}
