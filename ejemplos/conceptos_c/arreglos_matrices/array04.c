/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/array04.c 
*/

#include <stdio.h>

#define MAX 10

int main()
{
    int a[MAX];

    int i;

    // initialize the array to zeros.
    for (i = 0; i < MAX; ++i) {
        a[i] = 0;
    }

	// Name of an array points to the address of the first element in the array.
	printf("a = %p\n", a);

	// Where is this array stored in memory?
    for (i = 0; i < MAX; ++i) {
        printf("addr: %p | a[%d] = %d\n", &a[i], i, a[i]);
    }

    return 0;
}

