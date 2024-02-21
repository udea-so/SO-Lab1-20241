/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/arrays_and_pointers01.c
*/


#include <stdio.h>

#define MAX 10

void print_array(int a[]);

int main() {
    int array[MAX];
    int *parray;
    int i;

    // Fill some values in the array.
    for (i = 0; i < MAX; ++i) {
        array[i] = i;
    }

	print_array(array);

    parray = &array[0];     // parray = array; also does the same thing.

    // Modify the array using the array index notation.
    printf("The array is modified using the array index notation!\n");
    for (i = 0; i < MAX; ++i) {
        array[i] = i * 2;
    }
	print_array(array);

    // Modify the array using the pointer notation.
    printf("The array is modified using the array name as a pointer!\n");
    for (i = 0; i < MAX; ++i) {
        *(array + i) = i * 3;
    }
	print_array(array);

    // Modify the array using the pointer notation.
    printf("The array is modified using the pointer named parray!\n");
    for (i = 0; i < MAX; ++i) {
        *(parray + i) = i * 4;
    }
	print_array(array);

    return 0;
}

void print_array(int a[]) {
	int i;
    for (i = 0; i < MAX; ++i) {
        printf("array[%d] = %d\n", i, a[i]);
    }
}
