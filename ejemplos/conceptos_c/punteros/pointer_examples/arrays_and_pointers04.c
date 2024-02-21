/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/arrays_and_pointers01.c
*/


#include <stdio.h>

#define MAX 10

void print_array(int a[]);

int main() {
    int array[MAX];
    int i;

    // Fill some values in the array.
    for (i = 0; i < MAX; ++i) {
        array[i] = i;
    }

	print_array(array);

    return 0;
}

// An array can be passed as a pointer.
// Note the *a instead of a[] in parameters.
void print_array(int *a) {
	int i;
    for (i = 0; i < MAX; ++i) {
        printf("array[%d] = %d\n", i, a[i]);
    }
}
